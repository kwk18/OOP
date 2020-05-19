#ifndef TITERATOR_H
#define TITERATOR_H

#include <memory>
#include <iostream>
#include <stack>
#include "TStack.h"

template<class node, class T>
class TIterator {
public:
    TIterator(std::shared_ptr<node> n) {
        nodePtr = n;
    }

    std::shared_ptr<T> operator*() {
        return nodePtr->GetFigure();
    }

    std::shared_ptr<T> operator->() {
        return nodePtr->GetFigure();
    }

    void operator++() {


        if (nodePtr == nullptr) {
            return;
        }

        if (nodePtr->GetRight() != nullptr) {
            nodeStack.Push(nodePtr->GetRight());
        }

        if (nodePtr->GetLeft() != nullptr) {
            nodePtr = nodePtr->GetLeft();
        } else {
            nodePtr = nodeStack.Pop();
        }
    }

    TIterator operator++(int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator==(const TIterator &i) {
        return nodePtr == i.nodePtr;
    }

    bool operator!=(const TIterator &i) {
        return !(*this == i);
    }

private:
    std::shared_ptr<node> nodePtr;
    TStack nodeStack;
};

#endif // TITERATOR_H
