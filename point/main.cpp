#include "point.h"

int main() // main esercizio per prova.
{
    Point p1(2,3.4,-2.3), p2(1,2.4), p3;
      p1.negate();
      std::cout << "norma di p2 = " << p2.norm() << std::endl;
      std::cout << "p1 = " << p1 << std::endl;
      std::cout << "p1 + p2 = " << p1+p2 << std::endl;
      std::cout << "p2 + 4.3 = " << p2+4.3 << std::endl;
}
