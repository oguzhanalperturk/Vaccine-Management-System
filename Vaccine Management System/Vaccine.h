#pragma once
#include <iostream>
#include "Date.h"
using std::cin;
using std::cout;

class Vaccine
{
protected:
	int vaccine_ID;
	char vaccine_Name[50];
	char producer_company[50];
	char origin[50];
	char tel_num[50];
	int needed_dose_num;
	int time_between_doses;
	double cost;
	double efficacy;
public:
	Date date;
	Vaccine(); 
	Vaccine(int ID,char* name,char* company,char* origin,char* tel,Date EUA_date,int dosenum, int time_between_doses, double cost,double efficacy);
	int getvaccine_ID();
	char* getvaccine_Name();
	char* getproducer_company();
	char* getorigin();
	char* gettel_num();
	Date getdate(); 
	int getneeded_dose_num();
	int gettime_between_doses();
	int getcost();
	double getefficacy();
	void setvaccine_ID(int);
	void setvaccine_Name(char*);
	void setproducer_company(char*);
	void setorigin(char*);
	void settel_num(char*);
	void setdate(Date d); 
	void setneeded_dose_num(int);
	void settime_between_doses(int);
	void setcost(double);
	void setefficacy(double);
	void printVaccine();
};

