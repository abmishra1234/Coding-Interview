using namespace std;
#include <iostream>

//#define FORREF
#ifndef FORREF

class Account
{
private:
protected:
	float balance;
public:
	Account() = default;
	Account(float bal) : balance(bal) {}
	virtual void Withdraw(float amount)
	{
		cout << "Account : withdraw method called!" << endl;

	}

	virtual void Deposit(float amount)
	{
		cout << "Account : Deposit method called!" << endl;

	}

	virtual void printBalance()
	{
		cout << "Account : printBalance method called!" << endl;
		cout << "balance : " << balance << endl;
	}
};

class Saving : public Account
{
private:
	const double interest_rate = 0.8;
protected:
public:
	Saving() = default;
	Saving(float bal) :Account(bal)	{}
	void Withdraw(float amount)
	{
		cout << "Saving : withdraw method called!" << endl;
		balance = balance - amount - (float)(amount*interest_rate);
	}
	void Deposit(float amount)
	{
		cout << "Saving : Deposit method called!" << endl;
		balance = balance + amount + (float)(amount * interest_rate);
	}
	void printBalance()
	{
		cout << "Saving : printBalance method called!" << endl;
		cout << "balance : " << balance << endl;
	}
};


class Current : public Account
{
private:
protected:
public:
	Current() = default;
	Current(float bal) :Account(bal) {}
	void Withdraw(float amount)
	{
		cout << "Current : withdraw method called!" << endl;
		balance -= amount;
	}
	void Deposit(float amount)
	{
		cout << "Current : Deposit method called!" << endl;
		balance += amount;
	}
	void printBalance()
	{
		cout << "Current : printBalance method called!" << endl;
		cout << "balance : " << balance << endl;
	}
};

int main()
{
	Saving sa(50000);
	Account* acc = &sa;
	acc->Deposit(1000);
	acc->printBalance();

	acc->Withdraw(3000);
	acc->printBalance();

	Current ca(50000);
	acc = &ca;

	acc->Deposit(1000);
	acc->printBalance();
	acc->Withdraw(3000);
	acc->printBalance();


	return 0;
}

#endif // FORREF