#ifndef ORARIO_H
#define ORARIO_H


class orario
{
    public:
        orario(); // default costructor
        orario(int, int); // costructor for hours and minutes
        orario (int, int, int);
        int Ore();
        int Minuti();
        int Secondi();
    private:
        int sec;
};



#endif // ORARIO_H
