#include "Inactivated.h"

Inactivated::Inactivated() {
	inac_type = Sars_COV_2;
	mililitresofvaccine = 0;
}
Inactivated::Inactivated(int ID, char* name, char* company, char* or , char* tel, Date EUA_date, int dosenum_needed, int time, double costy, double eff, inactivated_type inac, double milofvaccine) {
	vaccine_ID = ID;
	strcpy(vaccine_Name, name);
	strcpy(producer_company, company);
	strcpy(origin, or );
	strcpy(tel_num,tel);
	date = EUA_date;
	if (dosenum_needed < 0) {
		needed_dose_num = 0;
	}
	else {
		needed_dose_num = dosenum_needed;
	}
	if (time < 0) {
		time_between_doses = 0;
	}
	else {
		time_between_doses = time;
	}
	if (costy < 0) {
		cost = 0;
	}
	else {
		cost = costy;
	}
	if (eff < 0) {
		efficacy = 0;
	}
	else if (eff > 1) {
		efficacy = 1;
	}
	else {
		efficacy = eff;
	}
	inac_type = inac;
	if (milofvaccine < 0) {
		mililitresofvaccine = 0;
	}
	else {
		mililitresofvaccine = milofvaccine;
	}
}
double Inactivated::getmililitresofvaccine() {
	return mililitresofvaccine;
}
inactivated_type Inactivated::getinac_type() {
	return inac_type;
}
void Inactivated::setmililitresofvaccine(double smof) {
	mililitresofvaccine = smof;
}
void Inactivated::setinac_type(int inac) {
	if (inac == 1) {
		inac_type = Sars_COV_2;
	}
	else {
		inac_type = Weakened_COV_19;
	}
}
double Inactivated::TotalCost() {
	double totalcost;
	if (inac_type == Sars_COV_2) {
		totalcost = (mililitresofvaccine / 100) * cost;
	}
	else {
		totalcost = (mililitresofvaccine / 100) * (1.5 * cost);
	}
	return totalcost;
}
void Inactivated::printinac() {
	cout << "Type: Inactivated\n";
	cout << "Inactivated Type: ";
	if (getinac_type() == 1) {
		cout << "SARS-CoV-2\n";
	}
	else {
		cout << "Weakened_COV_19\n";
	}
	cout << "Mililitres sold per unit: " << mililitresofvaccine << "\n" << "Vaccine ID: " << vaccine_ID << "\n" << "Vaccine_Name: " << vaccine_Name << "\n" << "Company: " << producer_company << "\n" << "Country of Origin: " << origin << "\n";
	cout << "Number of doses: " << needed_dose_num << "\n" << "Time Between Doses: " << time_between_doses << "\n" << "Telephone Number: " << tel_num << "\n" << "EUA Date: " << date.getday() << "/" << date.getmonth() << "/" << date.getyear() << "\n" << "Efficacy: " << efficacy*100 << "%" << "\n";
	cout << "Cost per 100 ml: " << getnewcost() << "\n";	
}
int Inactivated::getnewcost() {
	if (inac_type == Sars_COV_2) {
		return cost;
	}
	else {
		return (1.5 * cost);
	}
}