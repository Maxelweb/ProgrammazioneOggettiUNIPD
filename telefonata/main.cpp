#include "telefonata.h"

int main()
{
    telefonata t1(orario(8,25,30), orario(8,27,42), "0421394832");
    std::cout << t1 << std::endl;

    if(t1 == t1) cout << "1" << endl;
}
