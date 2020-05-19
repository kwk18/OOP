#include <iostream>
#include <string>
#include "redactor.h" //

int main() {
    std::string str;
    std::string str1;
    
	editor r;
	
    std::cout << "Input M or m for print menu: " << std::endl;
	while (std::cin >> str) {
		if ( str == "I" or str =="i" ){
            std::cin >> str1;
            r.insert(str1);
        }else if (str == "M" or str =="m" ){
            std::cout << "! not case-sensitive program ! \n"
                      << "M - Print menu\n"
                      << "C - Create document\n"
                      << "Load - Load document\n"
                      << "S - Save document\n"
                      << "I - Insert text\n"
                      << "L - Cursor left\n"
                      << "R - Cursor right\n"
                      << "Backspace or B - Remove\n"
                      << "Undo or U - Undo\n"
                      << "Print or P - Print document\n"
                      << "Q - Exit\n";
		} else if (str == "Create" or str == "C" or str == "c" or str == "create") {
			std::cout << "Input name of file: ";
			std::string fileName;
			std::cin >> fileName;
			r.create(fileName);
		} else if (str == "Backspace" or str == "B" or str == "b" or str == "backspace") {
			r.delete_();
		} else if (str == "Undo" or str == "U" or str == "u" or str == "undo") {
			try {
				r.undo();
			} catch (std::logic_error &e) {
				std::cout << e.what();
			}
		} else if (str == "Load"  or str == "load") {
			std::cout << "Input name of file: ";
			std::string fileName;
			std::cin >> fileName;
			r.load(fileName);
		} else if (str == "Save" or str == "S" or str == "s" or str == "save") {
			r.save();
		} else if ( str == "Q" or str == "q") {
			break;
        } else if (str == "Right" or str == "R" or str == "r" or str == "right") {
            r.cursorRight();
        } else if (str == "Left" or str == "L" or str == "l" or str == "left") {
            r.cursorLeft();
        } else if (str == "Print" or str == "P" or str == "p" or str == "print") {
            r.print();
		} else {
		    std::cout << "Incorrect input\n"; }
	}

	return 0;
}