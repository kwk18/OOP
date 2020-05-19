#include <iostream>
#include "Figures.hpp"
#include <string>



double sum(std::vector<Figure*> v) {
    double res= 0;
    for (auto i = v.begin(); i!= v.end(); ++i){
        res += (*i)->area();
    }
    return res;
}
 
void remove_elem(int index, std::vector<Figure*>& v){
    v.erase(v.begin() + index);
}

void print(std::vector<Figure*>& v){
    for (auto i = v.begin(); i!= v.end(); ++i) {
        std::cout << (**i) << "center : " << (*i)->center()<< "\narea : " << (*i)->area()<< "\n";
    }
}


int main() {
    std::cout << "\nPlease, enter coordinates of Figure, beginning with down left point\n";
    std:: cout<< "Available input:\n1 - input Trapezoid\n2 - input Rectangle\n3 - input Rhombus\n4 - Print Figures\n5 - Remove Figure\n6 - Print Sum\n7 - Exit\n";
    std::vector<Figure*> v;
    
    while (1){
        std::cout << "\n---Enter new command---\n\n";
        int input;
        std::cin >> input;
        int i = 0;
        switch (input) {
            case 1: v.push_back(new Trapezoid());
                std::cin >> (*(v.back()));
                break;
            case 2: v.push_back(new Rectangle());
                std::cin >> (*(v.back()));
                break;
            case 3: v.push_back(new Rhombus());
                std::cin >> (*(v.back()));
                break;
            case 4: print(v);
                break;
            case 5: std::cout << "Enter index to delete\n";
                std::cin >> i;
                if (i>= v.size()) {
                    std::cout << "incorrect index\n";
                    break;
                }
                remove_elem(i, v);
                break;
            case 6: std::cout<< sum(v) << "\n";
                break;
            case 7: return 0;
        }
    }
    return 0;
}
