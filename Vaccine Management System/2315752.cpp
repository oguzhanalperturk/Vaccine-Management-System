/* Oğuzhan Alpertürk -2315752
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */


#include "Vaccine.h"
#include "Date.h"
#include "mRNA.h"
#include "AdenovirusBased.h"
#include "Inactivated.h"
#include "Batch.h"
#include "Vaccine_Center.h"

int main() {
	

	int selection;
	List Vaccinelist;
	Vaccine_Center newcenter;
	struct BatchNode* batchnode;
	struct Node* ins;
	
	cout << "Welcome to Vaccine Center Management System!\n\n";
	while (1) {
		cout << "1. Create a vaccine\n";
		cout << "2. Create a batch\n";
		cout << "3. Search a type of vaccine by ID, provide the total number of items in stock\n";
		cout << "4. List all types of vaccines and the number of items in stock\n";
		cout << "5. List total cost of the stock\n";
		cout << "6. List all types in a given batch\n";
		cout << "7. List all types of vaccines and the number of them according to their expiry date for a specific batch\n";
		cout << "8. Exit\n";
		cout << "Enter your selection: ";
		cin >> selection;
		cout << "\n";

		if (selection == 1) {
			char yesno = 'Y';
			int vac_id, vac_type;
			cout << "Enter Vaccine ID: ";
			cin >> vac_id;
			if (Vaccinelist.IsintheList(vac_id) == 1) {
				while (yesno == 'Y') {
					if (Vaccinelist.IsintheList(vac_id) == 1) {
						cout << "\nThere is a vaccine with ID " << vac_id << "!\n";
						cout << "Would you like to add another vaccine?(Y/N): ";
						cin >> yesno;
						cout << "\n";
						if (yesno == 'Y') {
							cout << "Enter Vaccine ID: ";
							cin >> vac_id;
						}
						else if(yesno == 'N') {
							break;
						}
					}
					else {
						break;
					}
				}	
			}
			if (yesno == 'Y') {
				cout << "Select Vaccine Type (1)mRNA,(2)Adenovirus-Based,(3)Inactivated: ";
				cin >> vac_type;
				if (vac_type == 1) {
					mRNA mrna;
					char tel[50];
					int dosenum, time, temp, redesigntime;
					double eff, costy;
					char name[50];
					char company[50];
					char origin[50];
					Date date;
					mrna.setvaccine_ID(vac_id);
					cout << "Storage Temperature: ";
					cin >> temp;
					mrna.setstorage_temp(temp);
					cout << "Time to re-design to combat mutations: ";
					cin >> redesigntime;
					mrna.settime_to_redesign(redesigntime);
					cin.ignore();
					cout << "Enter Vaccine Name: ";
					cin.getline(name, 50);
					mrna.setvaccine_Name(name);
					cout << "Enter Producer Company Name: ";
					cin.getline(company, 50);
					mrna.setproducer_company(company);
					cout << "Enter Country of Origin: ";
					cin.getline(origin, 50);
					mrna.setorigin(origin);
					cout << "Contact Telephone Number: ";
					cin.getline(tel, 50);
					mrna.settel_num(tel);
					cout << "EUA Date: ";
					cin >> date.day >> date.ch >> date.month >> date.ch >> date.year;
					mrna.setdate(date);
					cout << "Number of doses needed: ";
					cin >> dosenum;
					mrna.setneeded_dose_num(dosenum);
					cout << "Time between doses: ";
					cin >> time;
					mrna.settime_between_doses(time);
					cout << "Cost: ";
					cin >> costy;
					mrna.setcost(costy);
					cout << "Efficacy: ";
					cin >> eff;
					mrna.setefficacy(eff);
					struct Node* mrnanode = new Node;
					mrnanode->mrna = mrna;
					mrnanode->Vac_Type = 1;
					mrnanode->Num_of_Items = 0;
					Vaccinelist.Insert(mrnanode);
					cout << "\nThe vaccine with ID: " << mrna.getvaccine_ID() << " has been added to the system successfully!\n\n";
					cout << "---------------------------------------\n\n";
				}
				if (vac_type == 2) {
					AdenovirusBased aden;
					char tel[50];
					int dosenum_needed, time, seffect;
					Date date;
					double eff, drate, costy;
					char name[50];
					char company[50];
					char or [50];
					aden.setvaccine_ID(vac_id);
					cout << "Side Effect Type (1)Headache,(2)Stomachache,(3)Blood Clot: ";
					cin >> seffect;
					aden.setside_effect(seffect);
					cout << "Discount Rate: ";
					cin >> drate;
					aden.setdiscount_rate(drate);
					cin.ignore();
					cout << "Enter Vaccine Name: ";
					cin.getline(name, 50);
					aden.setvaccine_Name(name);
					cout << "Enter Producer Company Name: ";
					cin.getline(company, 50);
					aden.setproducer_company(company);
					cout << "Enter Country of Origin: ";
					cin.getline(or , 50);
					aden.setorigin(or );
					cout << "Contact Telephone Number: ";
					cin.getline(tel, 50);
					aden.settel_num(tel);
					cout << "EUA Date: ";
					cin >> date.day >> date.ch >> date.month >> date.ch >> date.year;
					aden.setdate(date);
					cout << "Number of doses needed: ";
					cin >> dosenum_needed;
					aden.setneeded_dose_num(dosenum_needed);
					cout << "Time between doses: ";
					cin >> time;
					aden.settime_between_doses(time);
					cout << "Cost: ";
					cin >> costy;
					aden.setcost(costy);
					cout << "Efficacy: ";
					cin >> eff;
					aden.setefficacy(eff);
					struct Node* adennode = new Node;
					adennode->aden = aden;
					adennode->Vac_Type = 2;
					adennode->Num_of_Items = 0;
					Vaccinelist.Insert(adennode);
					cout << "\nThe vaccine with ID: " << aden.getvaccine_ID() << " has been added to the system successfully!\n\n";
					cout << "---------------------------------------\n\n";
				}
				else if (vac_type == 3) {
					Inactivated inac;
					char tel[50];
					int dosenum_needed, time, inactype;
					Date date;
					char name[50];
					char company[50];
					char or [50];
					double eff, milofvaccine, costy;
					inac.setvaccine_ID(vac_id);
					cout << "\nInactivated type (1)SARS-CoV-2,(2)Weakened: ";
					cin >> inactype;
					inac.setinac_type(inactype);
					cout << "Millilitres of vaccine: ";
					cin >> milofvaccine;
					inac.setmililitresofvaccine(milofvaccine);
					cin.ignore();
					cout << "Enter Vaccine Name: ";
					cin.getline(name, 50);
					inac.setvaccine_Name(name);
					cout << "Enter Producer Company Name: ";
					cin.getline(company, 50);
					inac.setproducer_company(company);
					cout << "Enter Country of Origin: ";
					cin.getline(or , 50);
					inac.setorigin(or );
					cout << "Contact Telephone Number: ";
					cin.getline(tel, 50);
					inac.settel_num(tel);
					cout << "EUA Date: ";
					cin >> date.day >> date.ch >> date.month >> date.ch >> date.year;
					inac.setdate(date);
					cout << "Number of doses needed: ";
					cin >> dosenum_needed;
					inac.setneeded_dose_num(dosenum_needed);
					cout << "Time between doses: ";
					cin >> time;
					inac.settime_between_doses(time);
					cout << "Cost per 100 ml: ";
					cin >> costy;
					inac.setcost(costy);
					cout << "Efficacy: ";
					cin >> eff;
					inac.setefficacy(eff);
					struct Node* inacnode = new Node;
					inacnode->inac = inac;
					inacnode->Vac_Type = 3;
					inacnode->Num_of_Items = 0;
					Vaccinelist.Insert(inacnode);
					cout << "\nThe vaccine with ID: " << inac.getvaccine_ID() << " has been added to the system successfully!\n";
					cout << "-----------------------------------------------------------------\n\n";
				}
			}
		}
		else if (selection == 2) {
		char yesno = 'Y';
		int batchid, vac_id, amount;
		Date expiryd;
		while (yesno == 'Y') {
			cout << "Enter Batch ID: ";
			cin >> batchid;
			if (newcenter.IsBatchThere(batchid) == 1) {
				cout << "There is a batch with ID:" << batchid << "!\n";
				cout << "Would you like to add another batch? (Y/N): ";
				cin >> yesno;
			}
			else {
				break;
			}
		}
		batchnode = new BatchNode;
		while (yesno == 'Y') {
			cout << "Add a vaccine with ID: ";
			cin >> vac_id;
			if (Vaccinelist.IsintheList(vac_id) == 1) {
				ins = Vaccinelist.SearchreturnNode(vac_id);
				cout << "Amount: ";
				cin >> amount;
				cout << "Expiry Date: ";
				cin >> expiryd.day >> expiryd.ch >> expiryd.month >> expiryd.ch >> expiryd.year;
				ins->Expiry_Date.setday(expiryd.day);
				ins->Expiry_Date.setmonth(expiryd.month);
				ins->Expiry_Date.setyear(expiryd.year);
				batchnode->bat.setBatch_ID(batchid);
				batchnode->bat.AddNewType(ins);
				batchnode->bat.IncreaseItemNum(vac_id, amount);
				cout << "\n";

				if (ins->Vac_Type == 1) {
					cout << amount << " Vials of " << ins->mrna.getproducer_company() << "-" << ins->mrna.getvaccine_Name() << " is added to the batch!\n";
				}
				else if (ins->Vac_Type == 2) {
					cout << amount << " Vials of " <<  ins->aden.getproducer_company() << "-" << ins->aden.getvaccine_Name() << " is added to the batch!\n";
				}
				else {
					cout << amount*ins->inac.getmililitresofvaccine() << " ML of " << ins->inac.getproducer_company() << "-" << ins->inac.getvaccine_Name() << " is added to the batch!\n";
				}
			}
			else {
				cout << "There isn't any vaccine with ID:" << vac_id << "! Please enter a valid ID\n\n";
				continue;
			}

			cout << "Would you like to add another vaccine? (Y/N): ";
			cin >> yesno;
			if (yesno == 'N') {
				newcenter.AddBatch(batchnode);
				cout << "The batch with ID: " << batchid << " has been added to the system successfully!\n";
				cout << "---------------------------------------\n\n";
			}
		}		
	}
		else if (selection == 3) {
			int vac_id;
			cout << "Please enter vaccine ID: ";
			cin >> vac_id;
			if (Vaccinelist.IsintheList(vac_id) == 1) {
				struct Node* temp = Vaccinelist.SearchreturnNode(vac_id);
				cout << "Information about the vaccine is given below: \n";
				if (temp->Vac_Type == 1) {
					temp->mrna.printmrna();
					cout << "Total Stock: " << newcenter.OneVacTotalAmount(vac_id);
				}
				else if (temp->Vac_Type == 2) {
					temp->aden.printadebased();
					cout << "Total Stock: " << newcenter.OneVacTotalAmount(vac_id);
				}
				else {
					temp->inac.printinac();
					cout << "Total Stock: " << newcenter.OneVacTotalAmount(vac_id);
				}
				cout << "\n";
			}
			else {
				cout << "There isn't any vaccine with ID: " << vac_id << "!\n";
			}
			cout << "-----------------------------------------\n";
		}
		else if (selection == 4) {
			newcenter.GiveTotalStockInfo(Vaccinelist).printlist();
			cout << "------------------------------------------\n\n";
		}
		else if (selection == 5) {
			newcenter.PrintTotalExpenditure();
		}
		else if (selection == 6) {
			int batchid;
			cout << "Please enter batch ID: ";
			cin >> batchid;
			if (newcenter.IsBatchThere(batchid) == 1) {
				newcenter.BatchPrint(batchid);
			}
			else {
				cout << "There is not any batch with ID " << batchid << "!\n";
			}
		}
		else if (selection == 7) {
			int batchid;
			cout << "Enter batch ID: ";
			cin >> batchid;
			if (newcenter.IsBatchThere(batchid) == 1) {
				newcenter.PrintSortedBatch(batchid);
			}
			else {
				cout << "There is not any batch with ID " << batchid << "!!\n\n";
			}
		}
		else if(selection == 8) {
			cout << "\nGoodbye!\n\n";
			break;
		}
		else {
			cout << "\nPlease Enter Valid Command!!\n";
		}
	}

	return 0;
}


