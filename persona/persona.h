#ifndef PERSONA_H
#define PERSONA_H

#include<iostream>
#include<string>

using namespace std;

class persona
{
    public:
        persona(); // Costruttore standard
        persona(string);
        persona(string, int, int);
        string getName() const;
        int getBirthYear() const;
        int getDeathYear() const;
        void changeYears(int, int);
    private:
        string Nome;
        int AnnoNascita;
        int AnnoMorte;
};

ostream& operator<<(ostream&, const persona&);


#endif // PERSONA_H
