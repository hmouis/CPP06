#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp


#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>

class ScalarConverter
{
    private:
        bool ConvertToInt(std::string &str);
        bool ConvertToChar(std::string &str);
        bool ConvertToFloat(std::string &str);
        bool ConvertToDouble(std::string &str);

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static void convert(std::string &str);
};



#endif