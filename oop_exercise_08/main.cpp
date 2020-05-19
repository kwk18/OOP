#include <condition_variable>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <cstdlib>
#include "factory.h"
#include "figures.h"
#include "subscriber.h"// класс, для передачи в поток как функтора, который необходим для выполнения обработки на отдельном потоке

void menu() {
    std::cout  << "M - Print menu\n";
    std::cout << "A - Add figure\n";
    std::cout << "E - Exit\n\n";
}


int main(int argc, char *argv[]){
    if (argc != 2) {
        std::cout << "Enter size \n";
        return 1;
    }
    
    size_t vector_size = std::atoi(argv[1]); //передаем размер буффера
    Factory factory;
    
    Subscriber subscriber;
    subscriber.buffer.reserve(vector_size);
    subscriber.processes.push_back(std::make_shared<Console_process>());
    subscriber.processes.push_back(std::make_shared<File_process>());
    
    std::thread subscriber_thread(std::ref(subscriber));
    
    menu();
    std::string cmd;
    while(std::cin >> cmd) {
        std::unique_lock<std::mutex> main_lock(subscriber.mtx);
        if (cmd =="M") {
            menu();
            continue;
        } else if (cmd == "E") {
            subscriber.end = true;
            subscriber.cv.notify_all();
            break;
        } else if (cmd == "A"){
            std::string figure_type;
            
            for (size_t id = 0; id < vector_size; id++) {
                std::cout << "Enter name of figure: Rectangle[R], Trapezoid[T], Rhombus[Rh]\n";
                std::cin >> figure_type;
                if (figure_type == "R"){
                    Vertex *vertices = new Vertex[4];
                    std::cout << "Enter the coordinates separated by a space\n";
                    for (int i = 0; i < 4; i++) {
                        std::cin >> vertices[i];
                    }
                    try {
                        subscriber.buffer.push_back(factory.FigureCreate(Rec, vertices, id));
                    } catch (std::logic_error &e) {
                        std::cout << e.what() << "\n";
                        id--;
                    }
                } else if (figure_type == "T") {
                    Vertex *vertices = new Vertex[4];
                    std::cout << "Enter the coordinates separated by a space\n";
                    for (int i = 0; i < 4; i++) {
                        std::cin >> vertices[i];
                    }
                    try {
                        subscriber.buffer.push_back(factory.FigureCreate(Trapeze, vertices, id));
                    } catch (std::logic_error &e) {
                        std::cout << e.what() << "\n";
                        id--;
                    }
                } else if (figure_type == "Rh") {
                    Vertex *vertices = new Vertex[4];
                    std::cout << "Enter the coordinates separated by a space\n";
                    for (int i = 0; i < 4; i++) {
                        std::cin >> vertices[i];
                    }
                    try {
                        subscriber.buffer.push_back(factory.FigureCreate(Rhomb, vertices, id));
                    } catch (std::logic_error &e){
                        std::cout << e.what() << "\n";
                        id--;
                    }
                } else { std::cout << "Wrong input. Try another words." << "\n";}
            }
            if (subscriber.buffer.size() == vector_size) {
                subscriber.cv.notify_all(); //уведомляет все ожидающие потоки
                subscriber.cv.wait(main_lock, [&subscriber]() { //блокирует текущий поток до тех пор, пока переменная не будет пробужена
                    return subscriber.success;
                });
                subscriber.success = false;
            }
        }
    }
    subscriber_thread.join();
    return 0;
}

