#pragma once
#include "Vaccine.h"
#include "mRNA.h"
#include "AdenovirusBased.h"
#include "Inactivated.h"


struct Node {
	mRNA mrna;
	AdenovirusBased aden;
	Inactivated inac;
	int Vac_Type; //1->mRNA,2->AdenovirusBased,3->Inactivated
	Date Expiry_Date;
	int Num_of_Items;
	struct Node* next;
};
class List
{
public:
	struct Node* head;
	struct Node* tail;
	int size;
	List();
	List(const List&);
	~List();
	void printlist();
	void Insert(struct Node* insert);
	void IncreaseItems(int,int);
	double CostofList();
	void SearchList(int idnum);
	struct Node* SearchreturnNode(int idnum);
	int IsintheList(int idnum); // 1 ->yes, 0->no
	int RetVaccineAmount(int vac_id);
	struct Node* FindMin();
};
