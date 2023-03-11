#pragma once
#include "List.h"
#include "Vaccine.h"

struct Vaccines_Node {
	List mRNA;
	List AdenovirusBased;
	List Inactivated;
};

class Batch
{
private:
	int Batch_ID;
protected:
	struct Vaccines_Node vaccines;
public:
	Batch();
	Batch(int batchid);
	int getBatch_ID();
	void setBatch_ID(int);
	void AddNewType(struct Node*);
	void IncreaseItemNum(int idnum,int amount);
	void printbatch();
	double CostofBatch();
	void SearchBatch(int idnum);
	int IsVacinBatch(int vac_id); //1->Yes,0->No
	int GetVaccineAmount(int vac_id);
	int IsBatchNull(); // 1->yes,0->no
	void SortandPrintBatchVaccines();
};

