#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp


#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cerrno>
#include <iomanip>


class ScalarConverter
{
    private:
        static bool PseudoLiterals(std::string &str);
        static bool ConvertToInt(std::string &str);
        static bool ConvertToChar(std::string &str);
        static bool ConvertToFloat(std::string &str);
        static bool ConvertToDouble(std::string &str);

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static void convert(std::string &str);
};



#endif