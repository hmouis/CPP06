#ifndef Base_hpp
#define Base_hpp

#include <iostream>
#include <cstdlib>
#include <typeinfo>

class Base
{
    public:
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif