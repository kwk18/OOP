#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    virtual double Square() = 0;

    virtual void Print() = 0;

    virtual size_t GetSide() = 0;

    virtual ~Figure() = default;
};

#endif //FIGURE_H