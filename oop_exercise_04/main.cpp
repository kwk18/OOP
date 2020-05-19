#include <iostream>
#include <tuple>
#include "Pair.h"
#include "trapezoid.h"
#include "rectangle.h"
#include "rhombus.h"
#include "templates.h"

template<class T>
void init(std::istream& is, std::ostream& os) {
    if constexpr (is_figurelike_tuple<T>::value) {
        int arg;
        std::cin >> arg;
        std::cout << "Input coordinates: " << std::endl;
        if (arg == 4) {
            Pair<double> A, B, C, D;
            is >> A >> B >> C >> D;
            auto object = std::make_tuple(A, B, C, D);
            print(os, object);
            os << "Area: " << area(object) << std::endl;
            os << "Center: " << center(object) << std::endl;
        }else if(arg == 3){
            Pair<double> A, B, C;
            is >> A >> B >> C;
            auto object = std::make_tuple(A, B, C);
            print(os, object);
            os << "Area: " << area(object) << std::endl;
            os << "Center: " << center(object) << std::endl;
        }
    }else {
        T object(is);
        print(os, object);
        os << '\n' <<"Area: " << area(object) << std::endl;
        os << "Center: " << center(object) << std::endl;
    }
}
//4
//3
//0 0 1 1 2 0

int main() {
    char obj_type;
    std:: cout<< " Available input:\n1 - input Trapezoid\n2 - input Rhombus\n3 - input Rectangle\n4 - Tuple\n5 - Exit" <<std::endl;
    while (std::cin >> obj_type){
        if(obj_type == '4') {
            std::cout << "Input number of vertices: " << std::endl;
            init<std::tuple<Pair<double>>> (std::cin, std::cout);
        }else if(obj_type == '1'){
            std::cout << "Input Trapezoid coordinates: " << std::endl;
            init<trapezoid<double>>(std::cin, std::cout);
        }else if(obj_type == '2'){
            std::cout << "Input Rhombus coordinates: " << std::endl;
            init<rhombus<double>>(std::cin, std::cout);
        }else if(obj_type == '3'){
            std::cout << "Input Rectangle coordinates: " << std::endl;
            init<rectangle<double>>(std::cin, std::cout);
        }else if(obj_type == '5'){
	        return 0;
        }else{
	        std::cout << "Try another key" << std::endl;
        }
    }
}
