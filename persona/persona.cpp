#include "persona.h"

persona::persona()
{
    Nome = "sconosciuto";
    AnnoNascita = 0;
    AnnoMorte = 0;
}

persona::persona(string N, int BY, int DY)
{
    Nome = N;
    AnnoNascita = BY;
    AnnoMorte = DY;
}

string persona::getName() const { return Nome; }
int persona::getBirthYear() const { return AnnoNascita; }
int persona::getDeathYear() const { return AnnoMorte; }

void persona::changeYears(int BY, int DY)
{
   AnnoNascita = BY;
   AnnoMorte = DY;
}

ostream& operator<<(ostream& os, const persona& p)
{
    return os << "--------------- Dati Anagrafici -------------- " << endl
              << "Nome: " << p.getName() << endl
              << "Anno di nascita: " << p.getBirthYear() << endl
              << "Anno di morte: " << p.getDeathYear() << endl
              << "--------------------------------------------- " << endl;
}
