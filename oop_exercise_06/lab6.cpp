#include "TRectangle.h"
#include "TBinTree.h"
#include <algorithm>

int main(int argc, char **argv) {
    TBinTree<Figure> binTree;

    int size;
    int menuOpt = 5;
//	int index =0 ;

    std::shared_ptr<Figure> figure;
    while (menuOpt != 0) {
        if (menuOpt >= 0 && menuOpt <= 5) {
            switch (menuOpt) {
                case 0:
                    break;
                case 1:
                    std::cout << "Input coordinates beginning with the left point:\n ";
                    figure = std::make_shared<TRectangle>(std::cin);
                    binTree.Insert(figure);
                    std::cout << "Square Added" << std::endl;
                    break;
                case 2:
                    std::cout << "Enter length of side to delete Square: "; //!
                    std::cin >> size;
                    binTree.DeleteItem(size);
                    break;
                case 3:
                    binTree.Print();
                    break;
                case 4:
                    if (!binTree.Empty()) {
                        for (auto i : binTree) {
                            i->Print();
                        }
//                        std::for_each(binTree.begin(), binTree.end(), std::mem_fn(&TBinTree<int>::Print));
                    } else {
                        std::cout << "BinTree is Empty" << std::endl;
                    }
                    break;
                case 5:
                    std::cout << "****************MENU****************" << std::endl;
                    std::cout << "1. Add a new Square to the BinTree" << std::endl;
                    std::cout << "2. Delete a Square from the BinTree" << std::endl;
                    std::cout << "3. Print the BinTree" << std::endl;
                    std::cout << "4. Print the BinTree with Iterator" << std::endl;
                    std::cout << "5. Print the MENU" << std::endl;
                    std::cout << "0. Exit " << std::endl;
                    std::cout << "************************************" << std::endl;
                    break;
            }
        } else {
            std::cout << "Input ERROR" << std::endl;
        }
        std::cout << "Enter the Number of an Action: ";
        std::cin >> menuOpt;
    }
    return 0;
}