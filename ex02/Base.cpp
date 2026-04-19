#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int r = rand() % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class: C" << std::endl;
}

void identify(Base& p)
{
    try{
        A a = dynamic_cast<A&>(p);
        std::cout << "Class: A" << std::endl;
    }
    catch(std::bad_cast){
    }
    try{
        B b = dynamic_cast<B&>(p);
        std::cout << "Class: B" << std::endl;
    }
    catch(std::bad_cast){
    }
    try{
        C c = dynamic_cast<C&>(p);
        std::cout << "Class: C" << std::endl;
    }
    catch(std::bad_cast){
    }
}

Base::~Base() {}