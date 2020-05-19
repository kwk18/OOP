//
//  BitString.h

//
//  Created by kosha on 14/10/2019.
//  Copyright © 2019 kosha. All rights reserved.
//

#ifndef BitString_h
#define BitString_h
#include <string>
#include <iostream>
#include <string>


class BitString128;
std::ostream& operator <<(std::ostream&, const BitString128&);
class BitString128 {
public:
    uint64_t high=0, low=0;
    
    BitString128() = default;
    
    BitString128(std::string num){                //конструктор класса
        int j =0;
        for (auto i = num.rbegin(); i!=num.rend(); ++i, ++j){
            j<64? low += uint64_t(*i - '0')<<j : high += uint64_t(*i - '0')<<(j-64);
        }
    }
    
    BitString128& operator>>=(int k){
        for (int i = 0; i< k; ++i, r_bit_shift());
        return *this;
    }
    
    friend const BitString128 operator>>(const BitString128& a, const int& k){
        BitString128 res = a;
        return res>>=k;
    }
    
    BitString128& operator<<=(int k){
        for (int i = 0; i< k; ++i, l_bit_shift());
        return *this;
    }
    
    friend const BitString128 operator<<(const BitString128& a, const int& k){
        BitString128 res = a;
        return res<<=k;
    }

 

    //возвращает количество единичных битов в числе
    int get_bits() const{
        int count = 0;
        for (int i = 63; i >= 0; --i){
            count += (high >>i) & 1;
        }
        for (int i = 63; i >= 0; --i){
            count += (low >>i) & 1;
        }
        return count;
    }
    //возвращает разницу в количестве единичных битов
    int compare_by_bits(const BitString128& rhs)const{
        return abs(this->get_bits() - rhs.get_bits());
    }
    void lShift(int k){
        std::cout << ((*this)<<k);
    }
    
    void rShift(int k){
        std::cout << ((*this)>>k);
    }
    
private:
    void l_bit_shift(){
        std::cout << (*this);
        high <<= 1;
        high |= (low >>63) & 1;
        low <<= 1;
    }
    
    void r_bit_shift(){
        std::cout << (*this);
        low >>= 1;
        low |= (high & 1)<<63;
        high >>= 1;
    }
};

bool is_equal (const BitString128 a, const BitString128 b){
    return a.high == b.high and a.low == b.low;
}
bool is_less (const BitString128 a, const BitString128 b){
     return (a.high < b.high or (a.high == b.high and a.low < b.low));
}
bool is_greater (const BitString128 a, const BitString128 b){
    return (a.high > b.high or (a.high == b.high and a.low > b.low));
}

const BitString128 XOR(const BitString128 a, const BitString128 b ){
    BitString128 c;
    c.low = a.low ^ b.low;
    c.high = a.high ^ b.high;
    return c;
}
const BitString128 AND(const BitString128 a, const BitString128 b ){
    BitString128 c;
    c.low = a.low & b.low;
    c.high = a.high & b.high;
    return c;
}

const BitString128 OR(const BitString128 a, const BitString128 b){
    BitString128 c;
    c.low = a.low | b.low;
    c.high = a.high | b.high;
    return c;
}

BitString128 NOT(BitString128 res) {
    res.high = ~res.high;
    res.low = ~res.low;
    return res;
}

#endif /* BitString_h */

