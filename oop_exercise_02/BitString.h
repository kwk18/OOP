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


class BitString128;
std::ostream& operator <<(std::ostream&, const BitString128&);
class BitString128 {
public:
    uint64_t high=0, low=0;
    
    BitString128() = default;  
    
    BitString128(std::string num){                //конструктор класса
        int j =0;
        for (auto i = num.rbegin(); i!=num.rend(); ++i, ++j){
            j<64? low += (*i - '0')<<j : high += (*i - '0')<<(j-64);
        }
    }
    
    const BitString128 operator~() const{
        BitString128 res = *this;
        res.high = ~res.high;
        res.low = ~res.low;
        return res;
    }
    
    BitString128& operator^=(const BitString128& rhs){
        high ^= rhs.high;
        low ^= rhs.low;
        return *this;
    }
    
    friend const BitString128 operator^(const BitString128& rhs, const BitString128& lhs){ //две константые ссылки
        BitString128 res = lhs;
        return res^=rhs;
    }
    
    BitString128& operator|=(const BitString128& rhs){
        high |= rhs.high;
        low |= rhs.low;
        return *this;
    }
    
    friend const BitString128 operator|(const BitString128& rhs, const BitString128& lhs){
        BitString128 res = lhs;
        return res|=rhs;
    }
    
    BitString128& operator&=(const BitString128& rhs){
        high &= rhs.high;
        low &= rhs.low;
        return *this;
    }
    
    friend const BitString128 operator&(const BitString128& rhs, const BitString128& lhs){
        BitString128 res = lhs;
        return res &= rhs;;
    }
    
    BitString128& operator>>=(int rhs){
        for (int i = 0; i< rhs; ++i, r_bit_shift());
        return *this;
    }
    
    friend const BitString128 operator>>(const BitString128& lhs, const int& rhs){
        BitString128 res = lhs;
        return res>>=rhs;
    }
    
    BitString128& operator<<=(int rhs){
        for (int i = 0; i< rhs; ++i, l_bit_shift());
        return *this;
    }
    
    friend const BitString128 operator<<(const BitString128& lhs, const int& rhs){
        BitString128 res = lhs;
        return res<<=rhs;
    }
    
    bool operator<(const BitString128& rhs)const{
        return (high < rhs.high or (high == rhs.high and low < rhs.low));
    }
    
    bool operator>(const BitString128& rhs)const{
        return rhs < *this;
    }
    
    bool operator>=(const BitString128& rhs)const{
        return !(*this < rhs);
    }
    
    bool operator<=(const BitString128& rhs)const{
        return !(*this > rhs);
    }
    
    bool operator==(const BitString128& rhs)const{
        return high == rhs.high and low == rhs.low;
    }
    
    bool operator!=(const BitString128& rhs)const{
        return !(*this == rhs);
    }
    
    int get_bits() const{
        int count = 0;
        for (int i = 63; i >= 0; --i) count += (high >>i) & 1;
        for (int i = 63; i >= 0; --i) count += (low >>i) & 1;
        return count;
    }
    
    int compare_by_bits(const BitString128& rhs)const{
        return abs(this->get_bits() - rhs.get_bits());
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

#endif /* BitString_h */
