#include "raz.h"

int main()
{

    Raz r1(1,4), r2(3), r3, r4(2,6);
      std::cout << r1+r2 << std::endl;
      Raz r5= (++r1)*r2;
      std::cout << r5++ << std::endl;
      std::cout << r3.inverso() + Raz::unTerzo() << std::endl;
      std::cout << (r1 == r1++ + Raz(-1)) << std::endl;
}
