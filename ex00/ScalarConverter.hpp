#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp


#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>

class ScalarConverter
{
    public:

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static void convert(std::string &str);
};



#endif