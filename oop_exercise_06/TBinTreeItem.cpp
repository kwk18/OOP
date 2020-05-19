#include "TBinTreeItem.h"
#include <iostream>

template<class T>
TBinTreeItem<T>::TBinTreeItem(const std::shared_ptr<T> &figure) {
    this->figure = figure;
    this->left = nullptr;
    this->right = nullptr;
    std::cout << "BinTree Item: Created" << std::endl;
}

template<class T>
TBinTreeItem<T>::TBinTreeItem(const TBinTreeItem<T> &orig) {
    this->figure = orig.figure;
    this->left = orig.left;
    this->right = orig.right;
}

template<class T>
TAllocationBlock TBinTreeItem<T>::bintreeitem_allocator(sizeof(TBinTreeItem<T>), 100);

template<class T>
void *TBinTreeItem<T>::operator new(size_t size) {
    return bintreeitem_allocator.Allocate();
}

template<class T>
void TBinTreeItem<T>::operator delete(void *ptr) {
    bintreeitem_allocator.Deallocate(ptr);
}

template<class T>
std::shared_ptr<TBinTreeItem<T>> TBinTreeItem<T>::SetLeft(std::shared_ptr<TBinTreeItem<T>> left) {
    std::shared_ptr<TBinTreeItem<T>> oldLeft = this->left;
    this->left = left;
    return oldLeft;
}

template<class T>
std::shared_ptr<TBinTreeItem<T>> TBinTreeItem<T>::SetRight(std::shared_ptr<TBinTreeItem<T>> right) {
    std::shared_ptr<TBinTreeItem<T>> oldRight = this->right;
    this->right = right;
    return oldRight;
}

template<class T>
std::shared_ptr<T> TBinTreeItem<T>::GetFigure() {
    return this->figure;
}

template<class T>
std::shared_ptr<TBinTreeItem<T>> TBinTreeItem<T>::GetLeft() {
    return this->left;
}

template<class T>
std::shared_ptr<TBinTreeItem<T>> TBinTreeItem<T>::GetRight() {
    return this->right;
}

template<class T>
TBinTreeItem<T>::~TBinTreeItem() {
    std::cout << "BinTree Item: Deleted" << std::endl;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const TBinTreeItem<T> &obj) {
    os << "[" << obj.figure << "]" << std::endl;
    return os;
}

#include "Figure.h"

template
class TBinTreeItem<Figure>;

template std::ostream &operator<<(std::ostream &os, const TBinTreeItem<Figure> &obj);
