#include "AdenovirusBased.h"


AdenovirusBased::AdenovirusBased() {
	side_effect = headache;
	discount_rate = 0;
}
AdenovirusBased::AdenovirusBased(int ID, char* name, char* company, char* or , char* tel, Date EUA_date, int dosenum_needed, int time, double costy, double eff, side_effect_types seffect, double drate) {
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
	side_effect = seffect;
	if (drate > 0.20) {
		discount_rate = 0.20;
	}
	else if (drate < 0) {
		discount_rate = 0;
	}
	else {
		discount_rate = drate;
	}
}
void AdenovirusBased::setside_effect(int seffect) {
	if (seffect == 1) {
		side_effect = headache;
	}
	else if (seffect == 2) {
		side_effect = stomachache;
	}
	else if (seffect == 3) {
		side_effect = blood_clot;
	}
}
void AdenovirusBased::setdiscount_rate(double drate) {
	if (drate > 0.20) {
		discount_rate = 0.20;
	}
	else if (drate < 0) {
		discount_rate = 0;
	}
	else {
		discount_rate = drate;
	}
}
side_effect_types AdenovirusBased::getside_effect() {
	return side_effect;
}
double AdenovirusBased::getdiscount_rate() {
	return discount_rate;
}
double AdenovirusBased::Calculate_Cost() {
	double newcost,newdiscountrate;
	if (side_effect == 1) {
		newdiscountrate = discount_rate;
		newcost = cost - (cost * newdiscountrate);
	}
	else if (side_effect == 2) {
		newdiscountrate = discount_rate * 1.5;
		newcost = cost - (cost * discount_rate);
	}
	else {
		newdiscountrate = discount_rate * 2;
		newcost = cost - (cost * newdiscountrate);
	}
	return newcost;
}
void AdenovirusBased::printadebased() {
	cout << "Type: Adenovirus-Based\n";
	cout << "Side-Effect type: ";
	if (getside_effect() == 1) {
		cout << "Headache\n";
	}
	else if (getside_effect() == 2) {
		cout << "Stomachache\n";
	}
	else {
		cout << "Blood Clot\n";
	}
	cout << "Vaccine ID: " << vaccine_ID << "\n" << "Vaccine_Name: " << vaccine_Name << "\n" << "Company: " << producer_company << "\n" << "Country of Origin: " << origin << "\n" << "Number of Doses: " << needed_dose_num << "\n" << "Time Between Doses: " << time_between_doses << "\n" << "Telephone Number: " << tel_num << "\n" << "EUA Date: " << date.getday() << "/" << date.getmonth() << "/" << date.getyear() << "\n" << "Efficacy: " << efficacy*100 << "%" << "\n";
	cout  << "Cost per vial: " << Calculate_Cost() << "\n";
}
