#ifndef TBINTREE_H
#define TBINTREE_H

#include "TRectangle.h"
#include "TBinTreeItem.h"
#include "TIterator.h"

#include <memory>

template<class T>
class TBinTree { 
public:
    TBinTree();

    void Insert(const std::shared_ptr<T> &figure); //!

    bool Empty();

    void Print();

    std::shared_ptr<TBinTreeItem<T>> GetLeast(std::shared_ptr<TBinTreeItem<T>> node);

    void DeleteItem(size_t elem);

    friend std::ostream &operator<<(std::ostream &os, const TBinTree &binTree);

    TIterator<TBinTreeItem<T>, T> begin();

    TIterator<TBinTreeItem<T>, T> end();

    virtual ~TBinTree(); //check

private:
    std::shared_ptr<TBinTreeItem<T>> root;

    void InsertSearch(std::shared_ptr<TBinTreeItem<T>> node, std::shared_ptr<T> &figure);

    void PrintFurther(std::shared_ptr<TBinTreeItem<T>> node);

    std::shared_ptr<TBinTreeItem<T>> GetLeastFurther(std::shared_ptr<TBinTreeItem<T>> node);

    void DeleteSearch(std::shared_ptr<TBinTreeItem<T>> node, size_t elem);

    std::shared_ptr<TBinTreeItem<T>> DeleteNode(std::shared_ptr<TBinTreeItem<T>> node);

    template<class T>
    void Insert(std::shared_ptr<T> &figure);
};

#endif /* TBINTREE_H */
