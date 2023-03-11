#include "mRNA.h"

mRNA::mRNA() {
	storage_temp = 0;
	time_to_redesign = 0;
}
mRNA::mRNA(int ID, char* name, char* company, char* or, char* tel, Date EUA_date, int dosenum, int time, double costy, double eff, int temp, int redesigntime) {
	vaccine_ID = ID;
	strcpy(vaccine_Name, name);
	strcpy(producer_company, company);
	strcpy(origin, or );
	strcpy(tel_num,tel);
	date = EUA_date; 
	if (dosenum < 0) {
		needed_dose_num = 0;
	}
	else {
		needed_dose_num = dosenum;
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
	storage_temp = temp;
	if (redesigntime < 0) {
		time_to_redesign = 0;
	}
	else {
		time_to_redesign = redesigntime;
	}
}
void mRNA::setstorage_temp(int temp) {
	storage_temp = temp;
}
void mRNA::settime_to_redesign(int redesigntime) {
	if (time_to_redesign < 0) {
		time_to_redesign = 0;
	}
	else {
		time_to_redesign = redesigntime;
	}
}
int mRNA::getstorage_temp() {
	return storage_temp;
}
int mRNA::gettime_to_redesign() {
	return time_to_redesign;
}
void mRNA::printmrna() {
	cout << "Type: mRNA\n" << "Vaccine ID: " << vaccine_ID << "\n" << "Vaccine_Name: " << vaccine_Name << "\n" << "Company: " << producer_company << "\n" << "Country of Origin: " << origin << "\n" << "Number of Doses: " << needed_dose_num << "\n" << "Time between doses: " << time_between_doses << "\n" << "Telephone number: " << tel_num << "\n" << "EUA Date: " << date.getday() << "/" << date.getmonth() << "/" << date.getyear() << "\n" << "Efficacy: " << efficacy*100 << "%" << "\n";
	cout << "Cost per vial: " << cost << "\n";
}
