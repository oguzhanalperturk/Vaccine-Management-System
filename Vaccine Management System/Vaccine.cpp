#include "Vaccine.h"


Vaccine::Vaccine() {
	vaccine_ID = 0;
	strcpy(vaccine_Name, "No name");
	strcpy(producer_company, "No name");
	strcpy(origin,"No name");
	strcpy(tel_num,"No name");
	date.setday(0);
	date.setmonth(0);
	date.setyear(0);
	needed_dose_num = 0;
	time_between_doses = 0;
	cost = 0;
	efficacy = 0;
}
Vaccine::Vaccine(int ID, char* name, char* company, char* or, char* tel, Date EUA_date, int dosenum_needed, int time, double costy,double eff) {
	vaccine_ID = ID;
	strcpy(vaccine_Name,name);
	strcpy(producer_company,company);
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
}
int Vaccine::getvaccine_ID() {
	return vaccine_ID;
}
char* Vaccine::getvaccine_Name() {
	return vaccine_Name;
}
char* Vaccine::getproducer_company() {
	return producer_company;
}
char* Vaccine::getorigin() {
	return origin;
}
char* Vaccine::gettel_num() {
	return tel_num;
}
Date Vaccine::getdate() {  
	return date;
}
int Vaccine::getneeded_dose_num() {
	return needed_dose_num;
}
int Vaccine::gettime_between_doses() {
	return time_between_doses;
}
int Vaccine::getcost() {
	return cost;
}
double Vaccine::getefficacy() {
	return efficacy;
}
void Vaccine::setvaccine_ID(int ID) {
	vaccine_ID = ID;
}
void Vaccine::setvaccine_Name(char* name) {
	strcpy(vaccine_Name, name);
}
void Vaccine::setproducer_company(char* company) {
	strcpy(producer_company, company);
}
void Vaccine::setorigin(char* or) {
	strcpy(origin, or );
}
void Vaccine::settel_num(char* tel) {
	strcpy(tel_num,tel);
}
void Vaccine::setdate(Date d) {  
	date = d;
}
void Vaccine::setneeded_dose_num(int dosenum) {
	if (dosenum < 0) {
		needed_dose_num = 0;
	}
	else {
		needed_dose_num = dosenum;
	}
}
void Vaccine::settime_between_doses(int tbdoses) {
	if (tbdoses < 0) {
		time_between_doses = 0;
	}
	else {
		time_between_doses = tbdoses;
	}
}
void Vaccine::setcost(double costy) {
	if (costy < 0) {
		cost = 0;
	}
	else {
		cost = costy;
	}
}
void Vaccine::setefficacy(double eff) {
	if (eff < 0) {
		efficacy = 0;
	}
	else if (eff > 1) {
		efficacy = 1;
	}
	else {
		efficacy = eff;
	}
}
void Vaccine::printVaccine() {
	cout << "Vaccine ID: " << vaccine_ID << "\n" << "Vaccine_Name: " << vaccine_Name << "\n" << "Producer Company: " << producer_company << "\n" << "Country of Origin: " << origin << "\n" << "Number of doses: " << needed_dose_num << "\n" << "Time between doses: " << time_between_doses << "\n" << "Telephone number: " << tel_num << "\n" << "EUA Date: " << date.getday() << "/" << date.getmonth() << "/" << date.getyear() << "\n" << "Efficacy: " << efficacy << "\n\n";

}