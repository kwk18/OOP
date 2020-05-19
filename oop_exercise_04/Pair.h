#ifndef Pair_H_
#define Pair_H_

#include <iostream>

template<class T>
struct Pair {
  T x;
  T y;
};

template<class T>
Pair<T> operator+(const Pair<T>& A, const Pair<T>& B) {
    Pair<T> res;
    res.x = A.x + B.x;
    res.y = A.y + B.y;
    return res;
}

template<class T>
Pair<T> operator/=(Pair<T>& A, const double B) { //деление на число
    A.x /= B;
    A.y /= B;
    return A;
}

template<class T>
std::istream& operator>> (std::istream& is, Pair<T>& p) {
  is >> p.x >> p.y;
  return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const Pair<T>& p) {
  os << '(' << p.x << ';' << p.y << ')' ;
  return os;
}

#endif
