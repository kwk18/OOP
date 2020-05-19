// //
// //
// //
// //
// //  Created by kosha on 28/09/2019.
// //  Copyright © 2019 kosha. All rights reserved.
// //
#include "BitString.h"
#include <string>
#include <iostream>


std::ostream& operator<<(std::ostream& os, const BitString128& obj){
    for (int i = 63; i >= 0; --i) os << ((obj.high >>i) & 1);
    for (int i = 63; i >= 0; --i) os << ((obj.low >>i) & 1);
    os << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, BitString128& obj){
    std::string input_number;
    is >> input_number;
    obj = BitString128(input_number);
    return is;
}

// long double operator"" _null ( long double num )
// {
//     return num*0;
// }

    

int main(){
    BitString128 num1;
    BitString128 num2;
    std::cin >> num1;
    std::cin >> num2;
    printf("num1: ");
    std::cout<< num1;
    printf("num2: ");
    std::cout << num2;
    printf("not1: ");
    std::cout<< (~num1);
    printf("not2: ");
    std::cout<< (~num2);

    printf("|:    ");
    std::cout<<(num1 | num2);
    printf("^:    ");

    std::cout<< (num1 ^ num2);
    printf("&:    ");

    std::cout<< (num1 & num2);
    printf("NUM 1:  \n");
    printf("rShift: \n");
    std::cout<< (num1>>2) <<"\n";
   
    printf("lShift \n");
    std::cout<< (num1<<2);
    std::cout<< "\n";
    printf("NUM2:  \n");
    printf("rShift \n");
    std::cout<< (num2>>2) <<"\n";
    
    printf("lShift \n");
    std::cout<< (num2<<2);
    std::cout<< "\n";
    printf("num1:  \n");
    std::cout<< num1.get_bits()<<"\n";
    printf("num2:  \n");
    std::cout<< num2.get_bits()<<"\n";
    std::cout<< num1.compare_by_bits(num2)<<"\n";
    std::cout <<"num1 < num2 ? :" << (num1 < num2) << "\n";
    std::cout <<"num 1 = num2 ? :"<< (num1 == num2)<< "\n";
    std::cout <<"num1 > num2 ? :"<< (num1 > num2) << "\n";

    // uint64_t m;
    // m = num1.high;
    // m= m_nul;
    // num1.high = m;
    // std::cout << num1;



    return 0;
}
