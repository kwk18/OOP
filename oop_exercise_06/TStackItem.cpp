#include "TStackItem.h"
#include <iostream>

TStackItem::TStackItem(const std::shared_ptr<TBinTreeItem<Figure>> &item) {
    this->item = item;
    this->next = nullptr;
}

std::shared_ptr<TStackItem> TStackItem::SetNext(std::shared_ptr<TStackItem> &next) {
    std::shared_ptr<TStackItem> old = this->next;
    this->next = next;
    return old;
}

std::shared_ptr<TBinTreeItem<Figure>> TStackItem::GetFigure() const {
    return this->item;
}

std::shared_ptr<TStackItem> TStackItem::GetNext() {
    return this->next;
}

TStackItem::~TStackItem() {
}
