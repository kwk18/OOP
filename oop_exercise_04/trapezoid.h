#ifndef trapezoid_H_
#define trapezoid_H_
#include <iostream>
#include <cmath>
#include "Pair.h"


template<class T>
struct trapezoid {
  Pair<T> p[4];  
  trapezoid(std::istream& is);
  double area() const;
  Pair<T> center() const;
  void print(std::ostream& os) const;
};
//0 0 1 1 2 1 3 0
template<class T>
trapezoid<T>::trapezoid(std::istream& is) {
  for(int i = 0; i < 4; ++i){
    is >> p[i];
  }
  if((p[2].y - p[1].y) / (p[2].x - p[1].x) != (p[3].y - p[0].y) / (p[3].x - p[0].x))
      throw std::logic_error("Wrong coordinates. It's not a trapezoid");
}

template<class T>
double trapezoid<T>::area() const {
  
  return 0.5 * std::abs( p[0].x * p[1].y + p[1].x * p[2].y + p[2].x * p[3].y + p[3].x * p[0].y - p[1].x * p[0].y - p[2].x * p[1].y - p[3].x * p[2].y - p[0].x * p[3].y);
}

template<class T>
Pair<T> trapezoid<T>::center() const {
  Pair<T> res;
  res.x = (p[0].x + p[1].x + p[2].x + p[3].x) / 4;
  res.y = (p[0].y + p[1].y + p[2].y + p[3].y) / 4;
  return res;

}

template<class T>
void trapezoid<T>::print(std::ostream& os) const {
  for(int i = 0; i < 4; ++i){
    os << p[i];
    if(i + 1 != 4){
      os << ' ';
    }
  }
}

#endif 
