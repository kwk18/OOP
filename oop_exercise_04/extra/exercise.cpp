#include <iostream>

#include <iostream>
#include <type_traits>

template<typename T>
struct reduce_pointer  //Просто будет запоминать тип T как внутренний тип type.
{
    using type = T;
};

template<typename T>
struct reduce_pointer<T*> //сли тип T оказался типом, который можно представить как T*, то нужно использовать эту специализацию, а не основную реализацию.
{
    using type = typename reduce_pointer<T>::type;
};

int main()
{
    reduce_pointer<int********>::type x;
    std::cout << (std::is_same_v<decltype(x), int> ? "true" : "false") << std::endl;
}
