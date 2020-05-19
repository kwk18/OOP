#ifndef RHOMBUS_H_
#define RHOMBUS_H_
#include <iostream>
#include <cmath>
#include "Pair.h"


template<class T>
struct rhombus {
  Pair<T> p[4];  
  rhombus(std::istream& is);
  double area() const;
  Pair<T> center() const;
  void print(std::ostream& os) const;
};

template<class T>
rhombus<T>::rhombus(std::istream& is) {
  for(int i = 0; i < 4; ++i){
    is >> p[i];
  }
  double a, b, c, d;
  a = sqrt((p[1].x - p[0].x) * (p[1].x - p[0].x) + (p[1].y - p[0].y) * (p[1].y - p[0].y));
  b = sqrt((p[2].x - p[1].x) * (p[2].x - p[1].x) + (p[2].y - p[1].y) * (p[2].y - p[1].y));
  c = sqrt((p[2].x - p[3].x) * (p[2].x - p[3].x) + (p[2].y - p[3].y) * (p[2].y - p[3].y));
  d = sqrt((p[3].x - p[0].x) * (p[3].x - p[0].x) + (p[3].y - p[0].y) * (p[3].y - p[0].y));
  if(a != b || a != c || a != d)
      throw std::logic_error("Wrong coordinates. It's not a rhombus.");
}

template<class T>
double rhombus<T>::area() const {
  const T d1 =  sqrt((p[0].x - p[2].x) * (p[0].x - p[2].x) + (p[0].y - p[2].y) * (p[0].y - p[2].y));
  const T d2 =  sqrt((p[1].x - p[3].x) * (p[1].x - p[3].x) + (p[1].y - p[3].y) * (p[1].y - p[3].y));
  return d1 * d2 / 2;
}

template<class T>
Pair<T> rhombus<T>::center() const {
  Pair<T> res;
  res.x = (p[0].x + p[1].x + p[2].x + p[3].x) / 4;
  res.y = (p[0].y + p[1].y + p[2].y + p[3].y) / 4;
  return res;
}

template<class T>
void rhombus<T>::print(std::ostream& os) const {
  for(int i = 0; i < 4; ++i){
      os << p[i];
    if(i + 1 != 4){
      os << ' ';
    }
  }
}

#endif 
