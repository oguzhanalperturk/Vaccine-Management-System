#include "Batch.h"
Batch::Batch() {
	Batch_ID = 0;
}
Batch::Batch(int batchid) {
	Batch_ID = batchid;
}
int Batch::getBatch_ID() {
	return Batch_ID;
}
void Batch::setBatch_ID(int batchid) {
	Batch_ID = batchid;
}
void Batch::AddNewType(struct Node *node) {
	if (node->Vac_Type == 1) {
		vaccines.mRNA.Insert(node);
	}
	else if (node->Vac_Type == 2) {
		vaccines.AdenovirusBased.Insert(node);
	}
	else {
		vaccines.Inactivated.Insert(node);
	}
}
void Batch::IncreaseItemNum(int idnum, int amount) {
	vaccines.mRNA.IncreaseItems(idnum, amount);
	vaccines.AdenovirusBased.IncreaseItems(idnum, amount);
	vaccines.Inactivated.IncreaseItems(idnum, amount);
}
void Batch::printbatch() {
	int mrna = vaccines.mRNA.size;
	int aden = vaccines.AdenovirusBased.size;
	int inac = vaccines.Inactivated.size;

	cout << "---------BATCH ID: " << Batch_ID << "------------\n\n";
	cout << "mRNA: " << mrna << "\n" << "AdenovirusBased: " << aden << "\n" << "Inactivated: " << inac << "\n\n";
	if (mrna == 0 && aden == 0 && inac == 0) {
		cout << "Empty Batch\n\n";
	}
	else {
		if (vaccines.mRNA.head != NULL) {
			vaccines.mRNA.printlist();
		}
		if (vaccines.AdenovirusBased.head != NULL) {
			vaccines.AdenovirusBased.printlist();
		}
		else {
			vaccines.Inactivated.printlist();
		}
	}
	cout << "---------END----------\n\n";
}
double Batch::CostofBatch() {
	double totalcost = 0;
	totalcost = vaccines.mRNA.CostofList() + totalcost;
	totalcost = vaccines.AdenovirusBased.CostofList() + totalcost;
	totalcost = vaccines.Inactivated.CostofList() + totalcost;

	return totalcost;
}
void Batch::SearchBatch(int idnum) {
	vaccines.mRNA.SearchList(idnum);
	vaccines.AdenovirusBased.SearchList(idnum);
	vaccines.Inactivated.SearchList(idnum);
}
int Batch::IsVacinBatch(int vac_id) {
	if (vaccines.mRNA.IsintheList(vac_id) == 1 || vaccines.AdenovirusBased.IsintheList(vac_id) == 1 || vaccines.Inactivated.IsintheList(vac_id) == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int Batch::GetVaccineAmount(int vac_id) {
	if (vaccines.AdenovirusBased.head == NULL && vaccines.mRNA.head == NULL && vaccines.Inactivated.head == NULL) {
		return 0;
	}
	if (vaccines.mRNA.IsintheList(vac_id) == 1) {
		return vaccines.mRNA.SearchreturnNode(vac_id)->Num_of_Items;
	}
	else if (vaccines.AdenovirusBased.IsintheList(vac_id) == 1) {
		return vaccines.AdenovirusBased.SearchreturnNode(vac_id)->Num_of_Items;
	}
	else if(vaccines.Inactivated.IsintheList(vac_id) == 1) {
		return vaccines.Inactivated.SearchreturnNode(vac_id)->Num_of_Items;
	}
	else {
		return 0;
	}
}
int Batch::IsBatchNull() {
	if (vaccines.AdenovirusBased.head == NULL && vaccines.mRNA.head == NULL && vaccines.Inactivated.head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void Batch::SortandPrintBatchVaccines() {
	List Allvacs;
	List SortedVacs;
	List mrna = vaccines.mRNA;
	List aden = vaccines.AdenovirusBased;
	List inac = vaccines.Inactivated;
	struct Node* iter;
	struct Node* ins;
	if (vaccines.mRNA.head != NULL) {
		iter = mrna.head->next;
		while (iter != NULL) {
			ins = new Node;
			ins->mrna = iter->mrna;
			ins->Expiry_Date = iter->Expiry_Date;
			ins->Num_of_Items = iter->Num_of_Items;
			ins->Vac_Type = iter->Vac_Type;
			Allvacs.Insert(ins);
			iter = iter->next;
		}
	}
	if (vaccines.AdenovirusBased.head != NULL) {
		iter = aden.head->next;
		while (iter != NULL) {
			ins = new Node;
			ins->aden = iter->aden;
			ins->Expiry_Date = iter->Expiry_Date;
			ins->Num_of_Items = iter->Num_of_Items;
			ins->Vac_Type = iter->Vac_Type;
			Allvacs.Insert(ins);
			iter = iter->next;
		}
	}
	if (vaccines.Inactivated.head != NULL) {
		iter = inac.head->next;
		while (iter != NULL) {
			ins = new Node;
			ins->inac = iter->inac;
			ins->Expiry_Date = iter->Expiry_Date;
			ins->Num_of_Items = iter->Num_of_Items;
			ins->Vac_Type = iter->Vac_Type;
			Allvacs.Insert(ins);
			iter = iter->next;
		}
	}

	while (Allvacs.size != 0) {
		ins = new Node;
		ins = Allvacs.FindMin();
		SortedVacs.Insert(ins);
		Allvacs.size--;
	}
	
	iter = SortedVacs.head->next;
	while (iter != NULL) {
		cout << "Type: ";
		if (iter->Vac_Type == 1) {
			cout << "mRNA\n";
			cout << "Vaccine ID: " << iter->mrna.getvaccine_ID() << "\n";
			cout << "Amount: " << iter->Num_of_Items << "\n";
			cout << "Expiry Date: ";
			iter->Expiry_Date.printdate();
			cout << "\n\n";
		}
		else if (iter->Vac_Type == 2) {
			cout << "Adenovirus-Based\n";
			cout << "Side-Effect type: ";
			if (iter->aden.getside_effect() == 1) {
				cout << "Headache\n";
			}
			else if (iter->aden.getside_effect() == 2) {
				cout << "Stomachache\n";
			}
			else {
				cout << "Blood Clot\n";
			}
			cout << "Vaccine ID: " << iter->aden.getvaccine_ID() << "\n";
			cout << "Amount: " << iter->Num_of_Items << "\n";
			cout << "Expiry Date: ";
			iter->Expiry_Date.printdate();
			cout << "\n\n";
		}
		else {
			cout << "Inactivated\n";
			cout << "Inactivated type: ";
			if (iter->inac.getinac_type() == 1) {
				cout << "SARS-CoV-2\n";
			}
			else {
				cout << "Weakened_COV_19\n";
			}
			cout << "Mililitres sold per unit: " << iter->inac.getmililitresofvaccine() << "\n";
			cout << "Vaccine ID: " << iter->inac.getvaccine_ID() << "\n";
			cout << "Amount: " << iter->Num_of_Items << "\n";
			cout << "Expiry Date: ";
			iter->Expiry_Date.printdate();
			cout << "\n\n";
		}
		iter = iter->next;
	}

}
