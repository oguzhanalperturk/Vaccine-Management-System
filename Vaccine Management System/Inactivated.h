#pragma once
#include "Vaccine.h"

enum inactivated_type { Dummy, Sars_COV_2, Weakened_COV_19 };

class Inactivated :
    public Vaccine
{
private:
    inactivated_type inac_type;
    double mililitresofvaccine;
public:
    Inactivated();
    Inactivated(int ID, char* name, char* company, char* origin, char* tel, Date EUA_date, int dosenum, int time_between_doses, double cost, double efficacy, inactivated_type inac, double mililitresofvaccine);
    double getmililitresofvaccine();
    inactivated_type getinac_type();
    void setmililitresofvaccine(double smof);
    void setinac_type(int inac);
    double TotalCost();
    void printinac();
    int getnewcost();
};

