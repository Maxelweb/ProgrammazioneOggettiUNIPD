#include "orario.h"

/** \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     Implementazione di orario
   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */

// Costruttori


orario::orario(){
    sec = 0;
}

orario::orario(int o, int m){
    if(o<0 || o>23 || m < 0 || m > 59) sec = 0;
    else sec = o*3600 + m*60;
}

orario::orario(int o, int m, int s){
    if(o<0 || o>23 || m < 0 || m > 59 || s < 0 || s > 59) sec = 0;
    else sec = o*3600 + m*60 + s;
}

int orario::Ore() const
{
    return sec/3600;
}

int orario::Minuti() const
{
    return (sec/60) % 60;
}

int orario::Secondi() const
{
    return (sec%60);
}

int orario::getSec() const
{
    return sec;
}

orario orario::operator+(orario o)
{
    orario aux;
    aux.sec = (sec + o.sec) % 86400;
    return aux;
}

bool orario::operator==(const orario& o) const
{
    return sec == o.getSec();
}

ostream& operator<<(ostream& os, const orario &o)
{
    return os << o.Ore() << ":" << o.Minuti() << ":" << o.Secondi();
}
