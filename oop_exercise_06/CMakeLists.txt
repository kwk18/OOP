project(oop_exercise)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(oop_exercise lab6.cpp TRectangle.cpp TAllocationBlock.cpp TBinTree.cpp TBinTreeItem.cpp TList.cpp TListItem.cpp TStack.cpp TStackItem.cpp)
