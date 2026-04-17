#include "Serializer.hpp"

int main()
{
    Data a;

    a.a = 5;
    a.str = "hello";

    uintptr_t n = Serializer::serialize(&a);

    std::cout << "uintptr: " << n << std::endl;

    Data* aa = Serializer::deserialize(n);

    std::cout << "Data a: " << aa->a << std::endl;
    std::cout << "Data str: " << aa->str << std::endl;
}