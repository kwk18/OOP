

#include <iostream>
#include <cmath>
#include <string.h>
#define DEFAULT_MEMORY_LEAK 8

template<class T>
class Vector {
public :

    explicit Vector() : lengthOfMemory(DEFAULT_MEMORY_LEAK),
                        lengthOfArray(0) {
        vectorArray = new T[lengthOfMemory];

        for (size_t i = 0; i < lengthOfMemory; ++i) {

            vectorArray[i] = 0;
        }

    };


    Vector(const Vector &copyVec) : lengthOfArray(copyVec.lengthOfArray),
                                    lengthOfMemory(copyVec.lengthOfMemory) {
        vectorArray = new T[lengthOfMemory];

        for (size_t i = 0; i < lengthOfArray; ++i) {

            vectorArray[i] = copyVec.vectorArray[i];
        }


    };

    ~Vector() {

        lengthOfArray = 0;

        lengthOfMemory = 0;

        delete vectorArray;

    };


    void addElement(const T &elementToAdd) {

        if (lengthOfArray >= lengthOfMemory - 1) {

            resizeVector();

        }

        vectorArray[lengthOfArray] = elementToAdd;

        ++lengthOfArray;

    };

    T &operator[]
            (const int i) {
        return vectorArray[i];
    };


    bool isPerpendicular() {

        T v11 = 0, v12 = 0, v21 = 0, v22 = 0, v31 = 0, v32 = 0;
        v11 = vectorArray[2] - vectorArray[0]; // x1
        v12 = vectorArray[3] - vectorArray[1]; //  y1

        // направляющая второго вектора
        v21 = vectorArray[4] - vectorArray[2]; //  x2
        v22 = vectorArray[5] - vectorArray[3]; //  y2

        // направляющая  третьего вектора
        v31 = vectorArray[6] - vectorArray[4]; // x3
        v32 = vectorArray[7] - vectorArray[5]; //  y3

        double cos1 = v11 * v21 + v12 * v22;
        double cos2 = v21 * v31 + v22 * v32;

        return (cos1 == 0) && (cos2 == 0);

    };

    T GetSide() {
        T sideSize = 0;

        sideSize = sqrt((vectorArray[2] - vectorArray[0]) * (vectorArray[2] - vectorArray[0]) +
                        (vectorArray[3] - vectorArray[1]) * (vectorArray[3] - vectorArray[1]));

        return sideSize;
    };

    T Square() {

        T square = 0;

        for (int i = 0; i < lengthOfArray - 4; i += 2) {
            square += vectorArray[i] * vectorArray[i + 3];
        }
        square += vectorArray[lengthOfArray - 2] * vectorArray[1];

        for (int i = 1; i < lengthOfArray - 3; i += 2) {
            square -= vectorArray[i + 1] * vectorArray[i];
        }
        square -= vectorArray[lengthOfArray - 1] * vectorArray[0];

        return abs(square);

    };


    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &obj) {

        os << "[ ";
        for (int i = 0; i < obj.lengthOfArray; ++i) {
            os << obj.vectorArray[i] << " ";
        }
        os << "]";
        return os;
    };

    friend std::istream &operator>>(std::istream &is, Vector<T> &obj) {
        T element = 0;

        is >> element;
        obj.addElement(element);
        return is;
    };


private :

    void resizeVector() {
        T *newVectorArray = new T[lengthOfMemory * 2];
        std::copy(vectorArray, vectorArray + lengthOfArray, newVectorArray);
        delete[]vectorArray;
        vectorArray = newVectorArray;
        lengthOfMemory *= 2;
    };

    T *vectorArray;
    size_t lengthOfArray;
    size_t lengthOfMemory;

};
