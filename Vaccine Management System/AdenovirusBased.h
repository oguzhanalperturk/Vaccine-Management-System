#pragma once
#include "Vaccine.h"

enum side_effect_types { dummy, headache, stomachache, blood_clot };

class AdenovirusBased :
    public Vaccine
{
private:
    double discount_rate; 
    side_effect_types side_effect;
public:
    AdenovirusBased();
    AdenovirusBased(int ID, char* name, char* company, char* origin, char* tel, Date EUA_date, int dosenum, int time_between_doses, double cost, double efficacy, side_effect_types side_effect, double discount_rate);
    void setside_effect(int);
    void setdiscount_rate(double);
    side_effect_types getside_effect();
    double getdiscount_rate();
    double Calculate_Cost();
    void printadebased();
};

