#include "List.h"


List::List() {
	head = NULL;
	tail = NULL;
	size = 0;
}
List::~List() {
	struct Node* iter;
	while (head != NULL) {
		iter = head;
		head = head->next;
		delete iter;
	}
}
List::List(const List& l) {
	if (l.head == NULL) {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	else {
		Node* iterl = l.head;
		Node* iterlink;
		head = new Node;
		iterlink = head;
		while (iterl != NULL) {
			if (iterl->next == NULL) {
				iterlink->next = NULL;
				break;
			}
			else {
				iterlink->next = new Node;
				iterlink->next->Num_of_Items = iterl->next->Num_of_Items;
				iterlink->next->Expiry_Date = iterl->next->Expiry_Date;
				iterlink->next->Vac_Type = iterl->next->Vac_Type;
				if (iterl->next->Vac_Type == 1) {
					iterlink->next->mrna = iterl->next->mrna;
				}
				else if (iterl->next->Vac_Type == 2) {
					iterlink->next->aden = iterl->next->aden;
				}
				else {
					iterlink->next->inac = iterl->next->inac;
				}
				iterlink = iterlink->next;
				iterl = iterl->next;
			}
		}
		tail = iterlink;
		size = l.size;
	}
}
void List::printlist() {
	cout << "\n\n";
	if (head == NULL) {
		return;
	}
	else {
		struct Node* iter;
		cout << "\n";
		for (iter = head->next;iter != NULL;iter = iter->next) {
			if (iter->Vac_Type == 1) {
				iter->mrna.printmrna();
			}
			else if (iter->Vac_Type == 2) {
				iter->aden.printadebased();
			}
			else {
				iter->inac.printinac();
			}
			cout << "Total Stock: " << iter->Num_of_Items;
			if (iter->Expiry_Date.getyear() != 0) {
				cout << "\n";
				cout << "Expiry Date: ";
				iter->Expiry_Date.printdate();
			}
			cout << "\n\n";
		}
	}
	cout << "\n\n";
}
void List::Insert(struct Node *insert) {
	if (head == NULL) {
		head = new Node;
		head->next = insert;
		tail = insert;
		insert->next = NULL;
	}
	else {
		tail->next = insert;
		tail = insert;
		insert->next = NULL;
	}
	size++;
}
void List::IncreaseItems(int idnum,int amount) {
	struct Node* iter = head;
	while (iter != NULL) {
		if (iter->Vac_Type == 1) {
			if (iter->mrna.getvaccine_ID() == idnum) {
				iter->Num_of_Items = iter->Num_of_Items + amount;
			}
		}
		else if (iter->Vac_Type == 2) {
			if (iter->aden.getvaccine_ID() == idnum) {
				iter->Num_of_Items = iter->Num_of_Items + amount;
			}
		}
		else {
			if (iter->inac.getvaccine_ID() == idnum) {
				iter->Num_of_Items = iter->Num_of_Items + amount;
			}
		}
		iter = iter->next;
	}
}
double List::CostofList() {
	double cost = 0;
	struct Node* iter = head;
	while (iter!=NULL) {
		if (iter->Vac_Type == 1) {
			cost = (iter->mrna.getcost() * iter->Num_of_Items) + cost;
		}
		else if (iter->Vac_Type == 2) {
			cost = (iter->aden.Calculate_Cost() * iter->Num_of_Items) + cost;
		}
		else{
			cost = (iter->inac.TotalCost() * iter->Num_of_Items) + cost;
		}
		iter = iter->next;
	}
	return cost;
}
void List::SearchList(int idnum) {
	struct Node* iter = head;
	while (iter != NULL) {
		if (iter->Vac_Type == 1) {
			if (iter->mrna.getvaccine_ID() == idnum) {
				iter->mrna.printmrna();
			}
		}
		else if (iter->Vac_Type == 2) {
			if (iter->aden.getvaccine_ID() == idnum) {
				iter->aden.printadebased();
			}
		}
		else {
			if (iter->inac.getvaccine_ID() == idnum) {
				iter->inac.printinac();
			}
		}
		iter = iter->next;
	}
}
struct Node* List::SearchreturnNode(int idnum) {
	struct Node* iter = head->next;
	struct Node* rnode = new Node;
	while (iter != NULL) {
		if (iter->Vac_Type == 1) {
			if (iter->mrna.getvaccine_ID() == idnum) {
				rnode->mrna = iter->mrna;
				rnode->Expiry_Date.setday(iter->Expiry_Date.getday());
				rnode->Expiry_Date.setmonth(iter->Expiry_Date.getmonth());
				rnode->Expiry_Date.setyear(iter->Expiry_Date.getyear());
				rnode->Num_of_Items = iter->Num_of_Items;
				rnode->Vac_Type = iter->Vac_Type;
				return rnode;
			}
		}
		else if (iter->Vac_Type == 2) {
			if (iter->aden.getvaccine_ID() == idnum) {
				rnode->aden = iter->aden;
				rnode->Expiry_Date.setday(iter->Expiry_Date.getday());
				rnode->Expiry_Date.setmonth(iter->Expiry_Date.getmonth());
				rnode->Expiry_Date.setyear(iter->Expiry_Date.getyear());
				rnode->Num_of_Items = iter->Num_of_Items;
				rnode->Vac_Type = iter->Vac_Type;
				return rnode;
			}
		}
		else if(iter->Vac_Type == 3) {
			if (iter->inac.getvaccine_ID() == idnum) {
				rnode->inac = iter->inac;
				rnode->Expiry_Date.setday(iter->Expiry_Date.getday());
				rnode->Expiry_Date.setmonth(iter->Expiry_Date.getmonth());
				rnode->Expiry_Date.setyear(iter->Expiry_Date.getyear());
				rnode->Num_of_Items = iter->Num_of_Items;
				rnode->Vac_Type = iter->Vac_Type;
				return rnode;
			}
		}
		iter = iter->next;
	}
}
int List::IsintheList(int idnum) {
	if (head == NULL) {
		return 0;
	}
	else {
		struct Node* iter = head;
		while (iter != NULL) {
			if (iter->Vac_Type == 1) {
				if (iter->mrna.getvaccine_ID() == idnum) {
					return 1;
				}
			}
			else if (iter->Vac_Type == 2) {
				if (iter->aden.getvaccine_ID() == idnum) {
					return 1;
				}
			}
			else if (iter->Vac_Type == 3) {
				if (iter->inac.getvaccine_ID() == idnum) {
					return 1;
				}
			}
			iter = iter->next;
		}
	}
	return 0;
}
int List::RetVaccineAmount(int vac_id) {
	if (head == NULL) {
		return 0;
	}
	if (IsintheList(vac_id) == 0) {
		return 0;
	}
	int amount;
	struct Node* iter = head->next;
	while (iter != NULL) {
		if (iter->Vac_Type == 1) {
			if (iter->mrna.getvaccine_ID() == vac_id) {
				amount = iter->Num_of_Items;
				return amount;
			}
		}
		else if (iter->Vac_Type == 2) {
			if (iter->aden.getvaccine_ID() == vac_id) {
				amount = iter->Num_of_Items;
				return amount;
			}

		}
		else if (iter->Vac_Type == 3) {
			if (iter->inac.getvaccine_ID() == vac_id) {
				amount = iter->Num_of_Items;
				return amount;
			}
		}
		iter = iter->next;
	}
}
struct Node* List::FindMin() {
	struct Node* iter = head->next;
	struct Node* ret;
	int minday = iter->Expiry_Date.getday();
	int minmonth = iter->Expiry_Date.getmonth();
	int minyear = iter->Expiry_Date.getyear();
	struct Node* min;
	while (iter != NULL) {
		if (iter->Expiry_Date.getyear() < minyear) {
			minyear = iter->Expiry_Date.getyear();
			minday = iter->Expiry_Date.getday();
			minmonth = iter->Expiry_Date.getmonth();
		}
		else if (iter->Expiry_Date.getyear() == minyear) {
			if (iter->Expiry_Date.getmonth() < minmonth) {
				minyear = iter->Expiry_Date.getyear();
				minday = iter->Expiry_Date.getday();
				minmonth = iter->Expiry_Date.getmonth();
			}
			else if (iter->Expiry_Date.getmonth() == minmonth) {
				if (iter->Expiry_Date.getday() < minday) {
					minyear = iter->Expiry_Date.getyear();
					minday = iter->Expiry_Date.getday();
					minmonth = iter->Expiry_Date.getmonth();
				}
			}
		}
		iter = iter->next;
	}
	struct Node* del;
	iter = head;
	while (iter != NULL) {
		if (iter->next->Expiry_Date.getday() == minday && iter->next->Expiry_Date.getmonth() == minmonth && iter->next->Expiry_Date.getyear() == minyear) {
			ret = new Node;
			if (iter->next->Vac_Type == 1) {
				ret->mrna = iter->next->mrna;
				ret->Expiry_Date = iter->next->Expiry_Date;
				ret->Num_of_Items = iter->next->Num_of_Items;
				ret->Vac_Type = iter->next->Vac_Type;
			}
			else if (iter->next->Vac_Type == 2) {
				ret->aden = iter->next->aden;
				ret->Expiry_Date = iter->next->Expiry_Date;
				ret->Num_of_Items = iter->next->Num_of_Items;
				ret->Vac_Type = iter->next->Vac_Type;
			}
			else {
				ret->inac = iter->next->inac;
				ret->Expiry_Date = iter->next->Expiry_Date;
				ret->Num_of_Items = iter->next->Num_of_Items;
				ret->Vac_Type = iter->next->Vac_Type;
			}
			del = iter->next;
			iter->next = iter->next->next;
			delete del;
			return ret;
		}
		iter = iter->next;
	}
}

