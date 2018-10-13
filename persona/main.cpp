#include "persona.h"

int main()
{
    persona Persona1("Mario Rossi", 1920, 1983);

    cout << Persona1;

    Persona1.changeYears(1930, 1984);

    cout << Persona1;
}
