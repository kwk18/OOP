#ifndef TSTACK_H
#define TSTACK_H

#include "TRectangle.h"
#include "TStackItem.h"
#include <memory>

class TStack {
public:
    TStack();

    void Push(std::shared_ptr<TBinTreeItem<Figure>> &&item);

    bool Empty();

    std::shared_ptr<TBinTreeItem<Figure>> Pop();

    virtual ~TStack();

private:
    std::shared_ptr<TStackItem> head;
};

#endif // TSTACK_H
