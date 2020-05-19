// //
// //
// //
// //
// //  Created by kosha on 28/09/2019.
// //  Copyright © 2019 kosha. All rights reserved.
// //

#include <string>
#include <iostream>
#include "BitString.h"


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



int main(){
    BitString128 num1;
    BitString128 num2;
    BitString128 n_and;
    BitString128 n_or;
    BitString128 n_xor;
    
    std::cin >> num1;
    std::cin >> num2;
    
    std::cout<< "num1: " << num1;
    std::cout <<"num2: " << num2;
    
    std::cout<<"not1: "<< NOT(num1);
    std::cout<<"not2: "<< NOT(num2);
    
    n_and = AND(num1, num2);
    std::cout <<"AND:  "<< n_and;
    
    n_or = OR(num1, num2);
    std::cout << "OR:   " << n_or;
    
    n_xor = XOR(num1, num2);
    std::cout << "XOR:  " << n_xor<<"\nNUM1:   \n\nrShift:  \n";
    num1.rShift(2);
    
    printf("lShift: \n");
    num1.lShift(2);
    std::cout<< "\nNUM2:  \n\nrShift: \n";
    num2.rShift(2);
    std::cout<<"lShift:\n";
    num2.lShift(2);
    
    
    std::cout<< "\nQuantity of 1-bits: \nnum1:  \n" <<num1.get_bits()<<"\n";
    std::cout<< "num2:  \n"<<num2.get_bits()<<"\nDifference:\n";
    std::cout<< num1.compare_by_bits(num2)<<"\n";
    std::cout <<"Comparing by bits:\nnum1 < num2 ? :" << is_less(num1,num2) << "\n";
    std::cout <<"num 1 = num2 ? :"<< is_equal(num1, num2)<< "\n";
    std::cout <<"num1 > num2 ? :"<< is_greater(num1,num2) << "\n";
    
    return 0;
}

