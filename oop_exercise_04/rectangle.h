#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include "Pair.h"
#include <cmath>

template<class T>
struct rectangle {
  Pair<T> p[4];
  rectangle(std::istream& is);
  double area() const;
  Pair<T> center() const;
  void print(std::ostream& os) const;
};

template<class T>
rectangle<T>::rectangle(std::istream& is) {
  for(int i = 0; i < 4; ++i){
    is >> p[i];
  }
  double a, b, c, d, d1, d2, ABC, BCD, CDA, DAB;
  a = sqrt((p[1].x - p[0].x) * (p[1].x - p[0].x) + (p[1].y - p[0].y) * (p[1].y - p[0].y));
  b = sqrt((p[2].x - p[1].x) * (p[2].x - p[1].x) + (p[2].y - p[1].y) * (p[2].y - p[1].y));
  c = sqrt((p[2].x - p[3].x) * (p[2].x - p[3].x) + (p[2].y - p[3].y) * (p[2].y - p[3].y));
  d = sqrt((p[3].x - p[0].x) * (p[3].x - p[0].x) + (p[3].y - p[0].y) * (p[3].y - p[0].y));
  d1 = sqrt((p[1].x - p[3].x) * (p[1].x - p[3].x) + (p[1].y - p[3].y) * (p[1].y - p[3].y));
  d2 = sqrt((p[2].x - p[0].x) * (p[2].x - p[0].x) + (p[2].y - p[0].y) * (p[2].y - p[0].y));
  ABC = (a * a + b * b - d2 * d2) / 2 * a * b;
  BCD = (b * b + c * c - d1 * d1) / 2 * b * c;
  CDA = (d * d + c * c - d2 * d2) / 2 * d * c;
  DAB = (a * a + d * d - d1 * d1) / 2 * a * d;
  if(ABC != BCD || ABC != CDA || ABC != DAB)
    throw std::logic_error("Wrong coordinates. It's not a rectangle.");
}

template<class T>
double rectangle<T>::area() const {
  const T a =  sqrt((p[1].x - p[0].x) * (p[1].x - p[0].x) + (p[1].y - p[0].y) * (p[1].y - p[0].y));
  const T b =  sqrt((p[2].x - p[1].x) * (p[2].x - p[1].x) + (p[2].y - p[1].y) * (p[2].y - p[1].y));
  return a * b;
}

template<class T>
Pair<T> rectangle<T>::center() const {
  Pair<T> res;
  res.x = (p[0].x + p[1].x + p[2].x + p[3].x) / 4;
  res.y = (p[0].y + p[1].y + p[2].y + p[3].y) / 4;
  return res;
}

template<class T>
void rectangle<T>::print(std::ostream& os) const {
  for(int i = 0; i < 4; ++i){
      os << p[i];
    if(i + 1 != 4){
      os << ' ';
    }
  }
}

#endif 
