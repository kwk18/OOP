#ifndef TRECTANGLE_H
#define TRECTANGLE_H

#include <cstdlib>
#include <iostream>
#include "Vector.cpp"
#include "Figure.h"

class TRectangle : public Figure {
public:
    TRectangle();

    TRectangle(Vector<int> initVector);

    TRectangle(std::istream &is);

    double Square() override;

    void Print() override;

    size_t GetSide() override;

    friend std::ostream &operator<<(std::ostream &os, const TRectangle &obj);

    friend std::istream &operator>>(std::istream &is, TRectangle &obj);

    virtual ~TRectangle();

private:
    Vector<int> *vector;
};

#endif /* TRECTANGLE_H */