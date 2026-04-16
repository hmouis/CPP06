#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other){
    (void) other;
}
ScalarConverter ScalarConverter::operator=(const ScalarConverter &other){
    (void) other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::ConvertToChar(std::string &str)
{
    char *endptr;
    double value;
    errno = 0;

    value = strtod(str.c_str(), &endptr);
    if (errno == ERANGE || str.length() != 1 || !*endptr)
        return false;
    std::cout << "char: " << static_cast<char>(*endptr) << std::endl;
    std::cout << "int: " << static_cast<int>(*endptr) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(*endptr) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(*endptr) << std::endl;

    return true;
}
bool ScalarConverter::ConvertToInt(std::string &str)
{
    char *endptr;
    long value;
    int base;
    errno = 0;
    
    value = strtol(str.c_str(), &endptr, 10);
    if (value < -2147483648 || value > 2147483647 || errno == ERANGE || *endptr)
        return false;
    base = value;
    if (base >= 0 && base <= 127){
        if (std::isprint(base))
            std::cout << "char: " << static_cast<char>(base) << std::endl;
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    std::cout << "int: " << base << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(base) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(base) << std::endl;
    
    return true;
}
bool ScalarConverter::ConvertToFloat(std::string &str)
{
    char *endptr;
    float value;
    errno = 0;

    value = strtof(str.c_str(), &endptr);
    if (errno == ERANGE || endptr == str || std::strlen(endptr) != 1 || *endptr != 'f')
        return false;
    if (str[str.size() - 2] == '.' || (std::isdigit(str[str.size() - 2]) && str.find('.') == std::string::npos)){
        std::cout << "Invalid input\n";
        return true;
    }
    if (value >= 0 && value <= 127){
        if (std::isprint(value))
            std::cout << "char: " << static_cast<char>(value) << std::endl;
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    if (static_cast<double>(value) >= -2147483648 && static_cast<double>(value) <= 2147483647)
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;

    return true;
}
bool ScalarConverter::ConvertToDouble(std::string &str)
{
    char *endptr;
    double value;
    errno = 0;

    value = strtod(str.c_str(), &endptr);
    if (errno == ERANGE)
        return false;
    else if (*endptr){
        std::cout << "Invalid input\n";
        return true;
    }
    else
    if (value >= 0 && value <= 127){
        if (std::isprint(value))
            std::cout << "char: " << static_cast<char>(value) << std::endl;
        else
            std::cout << "char: Non displayable\n";
    }
        std::cout << "char: impossible\n";
    if (value >= -2147483648 && value <= 2147483647)
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;

    return true;
}

bool ScalarConverter::PseudoLiterals(std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: " << str << std::endl;
        std::cout << "double: " << str.erase(3, 1) << std::endl;
        return true;
    }
    else if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: " << str << "f\n";
        std::cout << "double: " << str << std::endl;        
        return true;
    }
    return false;
}

void ScalarConverter::convert(std::string &str)
{
    if (!(PseudoLiterals(str) || ConvertToChar(str) || ConvertToInt(str) || ConvertToFloat(str) || ConvertToDouble(str))){
        std::cout << "char: impossible" << std::endl; 
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: impossible" << std::endl; 
        std::cout << "double: impossible" << std::endl; 
    }
}
