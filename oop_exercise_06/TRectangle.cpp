#include "TRectangle.h"
#include <iostream>

TRectangle::TRectangle() : vector(nullptr) {}

TRectangle::TRectangle(Vector<int> initVector) {


    vector = new Vector<int>(initVector);
}

TRectangle::TRectangle(std::istream &is) {

    vector = new Vector<int>();
    int i = 0;
    while (i < 8) {

        is >> *vector;
        ++i;
    }
    if (!(vector->isPerpendicular())) {
        throw std::logic_error("Wrong coordinates. It is not a Square.");

    }

    //std::cout << "TRectangle: Created" << std::endl;
}


double TRectangle::Square() {
    return vector->Square();
}

size_t TRectangle::GetSide() {
    return vector->GetSide();
}

void TRectangle::Print() {
    std::cout << *vector << " " << vector->GetSide() << std::endl;

}

std::ostream &operator<<(std::ostream &os, const TRectangle &obj) {
    os << *obj.vector << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, TRectangle &obj) {
    int i = 0;
    while (i < 8) {
        is >> *obj.vector;
        ++i;
    }
    return is;
}

TRectangle::~TRectangle() {
    delete vector;
}
