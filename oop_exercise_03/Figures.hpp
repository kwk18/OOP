

#ifndef Figures_hpp
#define Figures_hpp

#include <iostream>
#include <vector>

#endif /* Figures_hpp */



struct Pair {
    double first;
    double second;
    Pair() = default;
    Pair(double a, double b) : first(a), second(b) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Pair& obj){
        return os <<"x : "<< obj.first << " y : "<< obj.second<< '\n';
    }

    friend std::istream& operator>>(std::istream& is, Pair& obj){
         return is >> obj.first >> obj.second;
    }
};

class Figure {
public:
    virtual double area() const = 0;
    virtual Pair center() const = 0;
    
    friend inline std::ostream& operator <<(std::ostream& os, const Figure& obj) {
         return obj.output(os);
    }

    friend inline std::istream& operator >>(std::istream& is, Figure& obj){
         return obj.input(is);
    }
protected:
    virtual std::istream& input(std::istream& is) = 0;
    virtual std::ostream& output(std::ostream& os) const = 0;
    
    double edge_length(const Pair& a, const Pair& b) const;
    Pair edge_center(const Pair& a, const Pair& b) const;
};

class Quadrangle: public Figure {
protected:
    Pair a[4];
public:
    double area() const;
    
    std::istream& input(std::istream& is);
    std::ostream& output(std::ostream& os) const;
};

class Rectangle: public Quadrangle {
public:
    std::istream& input(std::istream& is);
    std::ostream& output(std::ostream& os) const;
//    bool Rectangle::true_();
    Pair center() const;
    double area() const;
};

class Rhombus: public Quadrangle {
public:
    std::istream& input(std::istream& is);
    std::ostream& output(std::ostream& os) const;

    double area() const;
    Pair center() const;
};

class Trapezoid: public Quadrangle {
public:
    std::istream& input(std::istream& is);
    std::ostream& output(std::ostream& os) const;

    double area() const;
    Pair center() const;
};
