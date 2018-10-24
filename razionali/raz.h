#ifndef RAZ_H
#define RAZ_H

#include <iostream>

class Raz
{
    private:
        int num, den;
    public:
        // Raz();
        Raz(int = 0, int = 1);
        Raz inverso() const;
        operator double() const;
        Raz operator+ (const Raz&) const;
        Raz operator* (const Raz&) const;
        bool operator== (const Raz&) const;
        Raz operator++ (int); // postfisso
        Raz& operator++ (); // prefisso
        static Raz unTerzo();
};

std::ostream& operator<<(std::ostream&, const Raz&);

#endif // RAZ_H
