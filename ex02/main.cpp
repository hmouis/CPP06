#include "Base.hpp"

int main()
{
    srand(time(0));
    Base *base1 = generate();
    identify(base1);
    identify(*base1);

    Base *base2 = generate();
    identify(base2);
    identify(*base2);

    Base *base3 = generate();
    identify(base3);
    identify(*base3);
}