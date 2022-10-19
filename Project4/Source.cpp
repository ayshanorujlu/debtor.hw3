//class: Debtor (debtor-borclu)
//fields: objectId, name, surname, workAddress, salary, phoneNumber
//fields : hasLatePayment(bool), liveAddress, debt, Id(static)
//methods : showDebtor
//
//
//class : Bank
//	fields : name, debtors(array)
//	method : showAllDebtors,
//	method : borcu 1000 den yuxari olanlari gostermek
//	method : gecikmesi olanlari gostermek
//
//
//	QEYD : Kechdiymiz her shey istifade olunsun.
//	static field, copy constructor ve s




#include<iostream>
using namespace std;
class Debtor {
	int myID;
	char* name;
	char* surname;
	char* workAdress;
	double salary;
	char* phoneNumber;
	bool hasLatePayment = false;
	char* liveAdress;
	double debt;
public:
	static int ID;
	static int MAX;

	Debtor() = default;

	Debtor(const Debtor& other) {
		cout << "copy constructor" << endl;
		SetID(other.myID);
		SetName(other.name);
		SetSurname(other.surname);
		SetWorkAdress(other.workAdress);
		SetPhoneNumber(other.phoneNumber);
		SetSalary(other.salary);
		SetLiveAdress(other.liveAdress);
		SetDebt(other.debt);
		SetLatePayment(other.hasLatePayment);
	}

	Debtor(const char* name, const char* surname, const char* workAdress, double salary, const char* phoneNumber, bool hasLatePayment, const char* liveAdress, double debt) {
		SetName(name);
		SetSurname(surname);
		SetWorkAdress(workAdress);
		SetSalary(salary);
		SetPhoneNumber(phoneNumber);
		SetLatePayment(hasLatePayment);
		SetLiveAdress(liveAdress);
		SetDebt(debt);
		if (ID < MAX) {

		}
		else {
			cout << "Garage is not empty." << endl;
		}
		myID = ID++;
	}

	int GetCurrentID() {
		return ID;
	}

	int GetMyID() {
		return myID;
	}

	char* GetName() {
		return name;
	}

	char* GetSurname() {
		return surname;
	}

	char* GetWorkAdress() {
		return workAdress;
	}

	double GetSalary() {
		return salary;
	}

	char* GetPhoneNumber() {
		return phoneNumber;
	}

	bool GetLatePayment() {
		return hasLatePayment;
	}

	char* GetLiveAdress() {
		return liveAdress;
	}

	double GetDebt() {
		return debt;
	}

	void SetID(const int myID) {
		this->myID = myID;
	}

	void SetName(const char* name) {
		if (name != nullptr)
		{
			int l = strlen(name);
			this->name = new char[l + 1]{};
			strcpy_s(this->name, l + 1, name);
		}
		else {
			cout << "Name should be full." << endl;
		}

	}

	void SetSurname(const char* surname) {
		if (surname != nullptr)
		{
			int l = strlen(surname);
			this->surname = new char[l + 1]{};
			strcpy_s(this->surname, l + 1, surname);
		}
		else {
			cout << "Surname should be full." << endl;
		}
	}

	void SetWorkAdress(const char* workAdress) {
		if (workAdress != nullptr)
		{
			int l = strlen(workAdress);
			this->workAdress = new char[l + 1]{};
			strcpy_s(this->workAdress, l + 1, workAdress);
		}
		else {
			cout << "Work adress should be full." << endl;
		}
	}

	void SetPhoneNumber(const char* phoneNumber) {
		if (phoneNumber != nullptr)
		{
			int l = strlen(phoneNumber);
			this->phoneNumber = new char[l + 1]{};
			strcpy_s(this->phoneNumber, l + 1, phoneNumber);
		}
		else {
			cout << "Phone number should be full." << endl;
		}
	}

	void SetSalary(const double& salary) {
		if (salary > 0) {
			this->salary = salary;
		}
		else {
			cout << "Salary should be more than 0." << endl;
		}
	}

	void SetLiveAdress(const char* liveAdress) {
		if (liveAdress != nullptr)
		{
			int l = strlen(liveAdress);
			this->liveAdress = new char[l + 1]{};
			strcpy_s(this->liveAdress, l + 1, liveAdress);
		}
		else {
			cout << "Live adress should be full." << endl;
		}
	}

	void SetDebt(const double& debt) {
		if (debt > 0) {
			this->debt = debt;
		}
		else { cout << "Salary should be more than 0." << endl; }
	}

	void SetLatePayment(const bool hasLatePayment) {
		this->hasLatePayment = hasLatePayment;
	}

	~Debtor() {
		delete[]name;
		delete[]surname;
		delete[]workAdress;
		delete[]phoneNumber;
		delete[]liveAdress;
	}
	void Show() {
		cout << "Name:" << name << endl;
		cout << "Surname:" << surname << endl;
		cout << "Work Adress:" << workAdress << endl;
		cout << "Salary:" << salary << endl;
		cout << "Phone number:" << phoneNumber << endl;
		cout << "Late payment:" << hasLatePayment << endl;
		cout << "Live adress:" << liveAdress << endl;
		cout << "Debtor:" << debt << endl<<endl<<endl;
	}
};

int Debtor::ID = 1;
int Debtor::MAX = 5;

class Bank {
	char* bankName;
	Debtor* debtors;
	int count;
public:
	Bank(Debtor* debtor, int count, const char* bankName) {
		this->debtors = debtor;
		this->count = count;
		SetBankName(bankName);
	}
	void SetBankName(const char* bankName) {
		if (bankName != nullptr) {
			int l = strlen(bankName);
			this->bankName = new char[l + 1]{};
			strcpy_s(this->bankName, l + 1, bankName);
		}
	}
	void Show() {
		cout << bankName << endl << endl;
		for (size_t i = 0; i < count; i++)
		{
			debtors[i].Show();
		}
	}
	~Bank() {
		delete[]debtors;
		delete[]bankName;
	}
};

void main() {
	Debtor* debtors = new Debtor[2]{
		Debtor("Nargiz","Orujova","Design Company",1500,"+994508798999",true,"Baku",2500),
		Debtor("Mamed", "Piriyev", " BP", 5000, "+994556788997", false, "Baku", 1200),
	};
	Bank b(debtors, 2, "Kapital Bank");
	b.Show();
}
