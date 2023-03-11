#pragma once
#include "Batch.h"

struct BatchNode {
	Batch bat;
	struct BatchNode* next;
};

class Vaccine_Center
{
private:
	struct BatchNode* head;
	struct BatchNode* tail;
	int size;
public:
	Vaccine_Center();
	Vaccine_Center(const Vaccine_Center&);
	~Vaccine_Center();
	void AddBatch(struct BatchNode *b);
	void SearchVacDetails(int idnum);
	void BatchPrint(int batchid);
	void PrintTotalExpenditure();
	void PrintCostofGivenBatch(int idnum);
	int IsBatchThere(int batchid); // 1->Yes, 0->No
	int OneVacTotalAmount(int vac_id);
	void printcenter();
	int IsVacCenterEmpty(); //1->yes,0->no
	List GiveTotalStockInfo(List l);
	void PrintSortedBatch(int batchid);
};

