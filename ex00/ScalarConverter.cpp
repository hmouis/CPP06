#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
}
ScalarConverter ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other;
    return *this;
}
ScalarConverter::~ScalarConverter()
{}

int PseudoLiterals(std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: " << str << std::endl;
        std::cout << "double: " << str.erase(3, 1) << std::endl;
        return 1;
    }
    else if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: " << str << "f\n";
        std::cout << "double: " << str << std::endl;
        return 1;
    }
    return 0;
}

void ScalarConverter::convert(std::string &str)
{
    char *endptr;
    double value;
    
    if (PseudoLiterals(str))
        return ;
    value = strtod(str.c_str(), &endptr);
    if (std::strlen(endptr) > 1 || (*endptr != '\0' && *endptr != 'f')){
        std::cout << "Invalid input\n";
        return ;
    }
    try{
        if (str.length() == 1 && *endptr != '\0')
            std::cout << "char: " << str << std::endl;
        else if (value >= 0 && value <= 127){
            if (!std::isprint(value))
                throw std::string("Non displayable");
            char c = static_cast<char>(value);
            std::cout << "char: " << c << std::endl;
        }
        else
            throw std::string("impossible");
    }
    catch (std::string e){
        std::cout << "char: " << e << std::endl;
    }
    try{
        if (value >=-2147483648 && value <= 2147483647){
            int i = static_cast<int>(value);
            std::cout << "int: " << i << std::endl;
        }
        else
            throw std::string("impossible");
    }
    catch (std::string e){
        std::cout << "int: " << e << std::endl;
    }


}





