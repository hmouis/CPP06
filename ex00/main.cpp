#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
    ScalarConverter a;
    if (ac != 2){
        std::cout << "Invalid argument\n";
        return 1;
    }
    std::string str = av[1];
    ScalarConverter::convert(str);

    return 0;
}