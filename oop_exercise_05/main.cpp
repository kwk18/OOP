#include <algorithm>
#include <iostream>

#include "DynamicArray.h"

void menu() {
	std::cout << "0 - Terminate\n";
	std::cout << "1 - Array initialization\n";
	std::cout << "2 - Show coordinates of the center by index (beginning with 0)\n";
	std::cout << "3 - Show number of items with square less than ...\n";
	std::cout << "4 - Show every step of iterator \n";
	std::cout << "5 - Insert a new item in vector before this one\n";
	std::cout << "6 - Erase this item in iterator\n";
	std::cout << "7 - Add item by index\n";
	std::cout << "8 - Delete item by index\n";
	std::cout << "> ";
}

int main() {
	int cmd;
	std::cout << "Enter size of your vector : ";
	int size;
	std::cin >> size;

	containers::DynamicArray< rectangle<int> > Vector(size);

	while (true) {
		menu();
		std::cin >> cmd;
		if (cmd == 0) return 0;
		else if (cmd == 1) {
			for (int i = 0; i < Vector.getSize(); i++) {
				std::cout << "Enter vertices : \n";
				rectangle<int> rect(std::cin);
				Vector.push_back(rect);
			} 
		} else if (cmd == 2) {
			std::cout << "Enter index : ";
			int index;
			std::cin >> index;
			std::cout << Vector[index].center();
		} else if (cmd == 3) {
			int res = 0;
			std::cout << "Enter your square : ";
			double square;
			std::cin >> square;

			int cmdcmd;
			std::cout << "Do you want to use std::count_if? \n Type '1' for yes or type '2' for no : ";
			std::cin >> cmdcmd;

			if (cmdcmd == 1) res = std::count_if(Vector.begin(), Vector.end(), [square](rectangle<int> i) {return i.area() < square;});
			else {
				auto it = Vector.begin();
				auto end = Vector.end();

				while (it != end) {
					if ((*it).area() < square) res++;
					++it;
				}
			}

			std::cout << "Number of items [with square less than "<< square<< "] is " << res << '\n';
		} else if (cmd == 4) {
			int cmdcmd;
			std::cout << "Do you want to use std::for_each? \n Type '1' for yes or type '2' for no : ";
			std::cin >> cmdcmd;

			if (cmdcmd == 1) std::for_each(Vector.begin(), Vector.end(), [](rectangle<int> i) -> void{i.print();});
			else {
				auto it = Vector.begin();
				auto end = Vector.end();

				int n = 0; 

				while (it != end) {
                    std::cout << "-- item number " << n << "--\n";
					std::cout << *it;
					++it;
					n++;
				}

			}

		} else if (cmd == 5) {
			std::cout << "Enter vertices of item you want to delete : ";
			rectangle<int> toDelete(std::cin);

			std::cout << "Enter vertices of item you want to add : ";
			rectangle<int> toInsert(std::cin);
			
			auto it = Vector.begin();
			auto end = Vector.end();

			while (it != end) {
				if (*it == toDelete) {
					Vector.insert(it, toInsert);
					break;
				}
				++it;
			}

			it = Vector.begin();
			end = Vector.end();

			std::cout << "Now vector is like : \n";
			int n = 0;

			while (it != end) {
                std::cout << "-- item number " << n << "--\n";
				std::cout << *it;
				++it;
				n++;
			}
		} else if (cmd == 6) {
			std::cout << "Enter vertices of item you want to erase : ";
			rectangle<int> toDelete(std::cin);

			auto it = Vector.begin();
			auto end = Vector.end();

			while (it != end) {
				if (*it == toDelete) {
					Vector.erase(it);
				}
				++it;
			}

			it = Vector.begin();

			std::cout << "Now vector is like : \n";
			int n = 0;

			while (it != end) {
                std::cout << "-- item number " << n << "--\n";
				std::cout << *it;
				++it;
				n++;
			}
		} else if (cmd == 7) {
			std::cout << "Enter vertices of item you want to insert : ";
			rectangle<int> toInsert(std::cin);
			std::cout << "Enter index : ";
			int id;
			std::cin >> id;
			auto it = Vector.begin();
			if (id >= Vector.getSize()) Vector.addOnOutOfRange(id, toInsert);
			else {
				for (int i = 0; i < id; i++) ++it;

				Vector.insert(it, toInsert);

			}
			std::cout << "Now vector is like : \n";
			int n = 0;

			it = Vector.begin();
			auto end = Vector.end();

			while (it != end) {
                std::cout << "-- item number " << n << "--\n";
				std::cout << *it;
				++it;
				n++;
			}
		} else if (cmd == 8) {
			std::cout << "Enter index : ";
			int id;
			std::cin >> id;

			auto it = Vector.begin();
			for (int i = 0; i < id; i++) ++it;

			Vector.erase(it);

			std::cout << "Now vector is like : \n";
			int n = 0;

			it = Vector.begin();
			auto end = Vector.end();

			while (it != end) {
                std::cout << "-- item number " << n << "--\n";
				std::cout << *it;
				++it;
				n++;
			}
		}
	}
}
