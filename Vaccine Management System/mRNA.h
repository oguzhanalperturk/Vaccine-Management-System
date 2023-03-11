#pragma once
#include "Vaccine.h"

class mRNA :
    public Vaccine
{
private:
    int storage_temp;
    int time_to_redesign;
public:
    mRNA();
    mRNA(int ID, char* name, char* company, char* origin, char* tel, Date EUA_date, int dosenum, int time_between_doses, double cost, double efficacy, int storage_temperature, int redesigntime);
    void setstorage_temp(int);
    void settime_to_redesign(int);
    int getstorage_temp();
    int gettime_to_redesign();
    void printmrna();
};

