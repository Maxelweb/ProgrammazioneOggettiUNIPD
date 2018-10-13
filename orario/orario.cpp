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

int orario::Ore()
{
    return sec/3600;
}

int orario::Minuti()
{
    return (sec/60) % 60;
}

int orario::Secondi()
{
    return (sec%60);
}


