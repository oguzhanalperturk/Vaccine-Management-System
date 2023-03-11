#include "Vaccine_Center.h"
Vaccine_Center::Vaccine_Center() {
	head = NULL;
	tail = NULL;
	size = 0;
}
Vaccine_Center::Vaccine_Center(const Vaccine_Center& v) {
	if (v.head == NULL) {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	else {
		BatchNode* iterl = v.head;
		BatchNode* iterlink;
		head = new BatchNode;
		iterlink = head;
		while (iterl != NULL) {
			if (iterl->next == NULL) {
				iterlink->next = NULL;
				break;
			}
			else {
				iterlink->next = new BatchNode;
				iterlink->next->bat = iterl->next->bat;
				iterlink = iterlink->next;
				iterl = iterl->next;
			}
		}
		tail = iterlink;
		size = v.size;
	}
}
Vaccine_Center::~Vaccine_Center() {
	struct BatchNode* iter;
	while (head != NULL) {
		iter = head;
		head = head->next;
		delete iter;
	}
}
void Vaccine_Center::AddBatch(struct BatchNode *b) {
	if (head == NULL) {
		head = new BatchNode;
		head->next = b;
		b->next = NULL;
		tail = b;
	}
	else {
		tail->next = b;
		tail = tail->next;
		b->next = NULL;
	}
	size++;
}
void Vaccine_Center::SearchVacDetails(int idnum) {
	if (head == NULL) {
		cout << "";
	}
	else {
		struct BatchNode* iter = head;
		while (iter != NULL) {
			iter->bat.SearchBatch(idnum);
			iter = iter->next;
		}
	}
}
void Vaccine_Center::BatchPrint(int batchid) {
	if (head == NULL) {
		cout << "NULL";
	}
	else {
		struct BatchNode* iter = head->next;
		while (iter != NULL) {
			if (iter->bat.getBatch_ID() == batchid) {
				iter->bat.printbatch();
			}
			iter = iter->next;
		}
	}
}
void Vaccine_Center::PrintTotalExpenditure() {
	if (head == NULL) {
		cout << "Total cost of the stock is: 0$\n";
	}
	else {
		double totalexp = 0;
		struct BatchNode* iter = head->next;
		while (iter != NULL) {
			cout << "Total cost of batch with ID: " << iter->bat.getBatch_ID() << " is " << iter->bat.CostofBatch() << "$\n";
			totalexp += iter->bat.CostofBatch();
			iter = iter->next;
		}
		cout << "Total cost of the stock is: " << totalexp << "$\n";
	}
	cout << "-----------------------------------------------\n\n";
}
void Vaccine_Center::PrintCostofGivenBatch(int idnum) {
	struct BatchNode* iter = head;
	while (iter != NULL) {
		if (iter->bat.getBatch_ID() == idnum) {
			cout << "\nCost of Batch ID " << iter->bat.getBatch_ID() << ": " << iter->bat.CostofBatch() << "\n";
		}
		iter = iter->next;
	}
}
int Vaccine_Center::IsBatchThere(int batchid) {
	if (head == NULL) {
		return 0;
	}
	else {
		struct BatchNode* iter = head;
		while (iter != NULL) {
			if (iter->bat.getBatch_ID() == batchid) {
				return 1;
			}
			iter = iter->next;
		}
		return 0;
	}
}
int Vaccine_Center::OneVacTotalAmount(int vac_id) {
	if (head == NULL) {
		return 0;
	}
	struct BatchNode* iter = head->next;
	int totalamount = 0;
	while (iter != NULL) {
		totalamount = iter->bat.GetVaccineAmount(vac_id) + totalamount;
		iter = iter->next;
	}
	return totalamount;
}
void Vaccine_Center::printcenter() {
	cout << "\n----------------------VACCİNE CENTER START-----------------------\n";
	if (head == NULL) {
		cout << "";
	}
	else {
		struct BatchNode* iter = head->next;
		while (iter != NULL) {
			cout << "ID: " << iter->bat.getBatch_ID() << "\n\n";
			iter = iter->next;
		}
	}
	cout << "\n------------------------VACCİNE CENTER END-------------------------------\n";
}
int Vaccine_Center::IsVacCenterEmpty() {
	if (head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
List Vaccine_Center::GiveTotalStockInfo(List l) {
	if (l.head == NULL) {
		return l;
	}
	if (head == NULL) {
		return l;
	}
	struct Node* iter = l.head->next;
	while (iter != NULL) {
		if (iter->Vac_Type == 1) {
			iter->Num_of_Items = OneVacTotalAmount(iter->mrna.getvaccine_ID());
		}
		else if (iter->Vac_Type == 2) {
			iter->Num_of_Items = OneVacTotalAmount(iter->aden.getvaccine_ID());
		}
		else {
			iter->Num_of_Items = OneVacTotalAmount(iter->inac.getvaccine_ID());
		}
		iter = iter->next;
	}
	return l;
}
void Vaccine_Center::PrintSortedBatch(int batchid) {
	struct BatchNode* iter = head->next;
	while (iter != NULL) {
		if (iter->bat.getBatch_ID() == batchid) {
			iter->bat.SortandPrintBatchVaccines();
		}
		iter = iter->next;
	}
}
