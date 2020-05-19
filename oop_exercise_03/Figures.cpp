
#include "Figures.hpp"
#include <cmath>
#
//проверить скалярные произведения у прямоугольника , проверить авенство сторон у ромба и у трапеции парарллельность
    
double Figure::edge_length(const Pair& a, const Pair& b) const {
     return std::sqrt(std::pow(b.first - a.first, 2) + std::pow(b.second - a.second, 2));
}

Pair Figure::edge_center(const Pair& a, const Pair& b) const {
     return Pair((a.first + b.first)/2, (a.second + b.second)/2);
}

double Quadrangle::area() const {
    double sum = this->a[3].first*this->a[0].second - this->a[0].first*this->a[3].second;
    for (int i = 0; i < 3; ++i) sum += this->a[i].first*this->a[i+1].second - this->a[i+1].first*this->a[i].second;
    return std::abs(sum)/2.;
}
    
std::istream& Quadrangle::input(std::istream& is) {
    return is >> a[0] >> a[1] >> a[2] >> a[3];
}
std::ostream& Quadrangle::output(std::ostream& os) const {
    return os << a[0] << "   " << a[1] << "   " << a[2] << "   " << a[3] << "\n";
}


std::istream& Rectangle::input(std::istream& is) {
    std::cout << "Input Rectangle coordinates:\n";
    return Quadrangle::input(is);
}
std::ostream& Rectangle::output(std::ostream& os) const {
    
    
    if( (((a[1].first - a[0].first) * (a[2].first - a[1].first) + (a[1].second - a[0].second) * (a[2].second - a[1].second)) == 0) && (( (a[3].first - a[2].first) * (a[2].first - a[1].first) + (a[3].second - a[2].second) * (a[2].second - a[1].second)) == 0) &&(( (a[3].first - a[2].first) * (a[0].first - a[3].first) + (a[3].second - a[2].second) * (a[0].second - a[3].second)) == 0) )  { // проверить три угла
    os << "Rectangle coordinates:\n";
        return Quadrangle::output(os);
    }else {
        return os << "It is not a Rectangle!  \n ";
        }
}

Pair Rectangle::center() const {
     return edge_center(a[0], a[2]);
}
double Rectangle::area() const {
    return edge_length(a[0], a[1]) * edge_length(a[2], a[3]);
}


std::istream& Rhombus::input(std::istream& is) {
    
    std::cout<< "Input Rhombus coordinates:\n";
    return Quadrangle::input(is);
    
}

std::ostream& Rhombus::output(std::ostream& os) const { //проверить все стороны и сравнить каждую
    if ( (edge_length(a[0], a[1]) == edge_length(a[1], a[2])) && ( edge_length(a[0], a[1]) == edge_length(a[2], a[3])) && (edge_length(a[1], a[2]) == edge_length(a[2], a[3])) && (edge_length(a[0], a[1]) == edge_length(a[3], a[0]) )) {
        os << "Rhombus coordinates:\n";
        return  Quadrangle::output(os);
    }else {
        return os << "It is not a Rhombus !  \n ";
    }
}

double Rhombus::area() const {
    return (edge_length(a[0], a[2]) * edge_length(a[1], a[3]))/2;
}

Pair Rhombus::center() const  {
    return edge_center(a[0], a[2]);
}

std::istream& Trapezoid::input(std::istream& is) {
    std::cout<< "Input Trapezoid coordinates:\n";
    return Quadrangle::input(is);
}

std::ostream& Trapezoid::output(std::ostream& os) const {
    if (( (a[3].second - a[0].second) * (a[2].first - a[1].first) ) == ( (a[2].second - a[1].second) * (a[3].first - a[0].first))) {
    os << "Trapezoid coordinates:\n";
    return Quadrangle::output(os);
    }else{
        return os << "It is not a Trapezoid !  \n ";
    }
}

double Trapezoid::area() const {
    return Quadrangle::area();
}

Pair Trapezoid::center() const {
    double x = 0, y = 0;
    for (int i = 0; i < 4; ++i) {
        x += a[i].first;
        y += a[i].second;
    }
    return Pair(x/4, y/4);
}
