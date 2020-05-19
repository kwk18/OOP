#include "TAllocationBlock.h"

TAllocationBlock::TAllocationBlock(int32_t size, int32_t count) { //конструктор класса
    _used_blocks = (char *) malloc(size * count);

    for (int32_t i = 0; i < count; ++i) {
        void *ptr;
        ptr = _used_blocks + i * size;
        _free_blocks.AddLast(ptr);
    }
    std::cout << "Allocator: Constructor" << std::endl;
}

void *TAllocationBlock::Allocate() {
    if (!_free_blocks.Empty()) {
        void *res = _free_blocks.GetBlock();
        int first = 1;
        _free_blocks.DelElement(first);
        std::cout << "Allocator: Allocate" << std::endl;
        return res;
    }

}

void TAllocationBlock::Deallocate(void *ptr) {
    _free_blocks.AddFirst(ptr);
    std::cout << "Allocator: Deallocate" << std::endl;
}

bool TAllocationBlock::Empty() {
    return _free_blocks.Empty();
}

int32_t TAllocationBlock::Size() {  //получение количества выделенных блоков
    return _free_blocks.Length();
}

TAllocationBlock::~TAllocationBlock() {
    while (!_free_blocks.Empty()) {
        int first = 1;
        _free_blocks.DelElement(first);
    }
    free(_used_blocks);

}
