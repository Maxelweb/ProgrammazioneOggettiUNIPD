#include <iostream>
#include <math.h>
#include "point.h"


// Costruttore di default + costruttore a 1,2,3 argomenti
Point::Point(double xx, double yy, double zz)
{
    x = xx;
    y = yy;
    z = zz;
}

// Distanza di un punto dall'origine (0, 0, 0)
double Point::norm() const { return sqrt(x*x + y*y + z*z); }

// Recupero i campi dati dell'oggetto
double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

// Trasformo il punto nel suo opposto, facendo side effect.
void Point::negate()
{
    x *= -1;
    y *= -1;
    z *= -1;
}

// overloading dell'operatore di stampa
std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << "Point (" << p.getX() << ',' << p.getY() << ',' << p.getZ() << ')';
}

// overloading dell'operatore di somma
Point operator+(const Point& x, const Point& y)
{
    return Point(x.getX() + y.getX(), x.getY() + y.getY(), x.getZ() + y.getZ());
}

