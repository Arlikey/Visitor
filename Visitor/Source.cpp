#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class House;
class Factory;
class Bank;

class IVisitor abstract
{
public:
	virtual void Visit(House* house) abstract;
	virtual void Visit(Factory* factory) abstract;
	virtual void Visit(Bank* bank) abstract;
};

class IBuilding abstract
{
	double price;
	double term;
public:
	void SetPrice(double price) { this->price = price; }
	double GetPrice() { return price; }
	void SetTerm(double term) { this->term = term; }
	double GetTerm() { return term; }

	virtual void Accept(IVisitor* visitor)abstract;
};

class House: public IBuilding
{
public:
	void Accept(IVisitor* visitor) override
	{
		visitor->Visit(this);
	}
};

class Factory: public IBuilding
{
public:
	void Accept(IVisitor* visitor) override
	{
		visitor->Visit(this);
	}
};

class Bank : public IBuilding
{
public:
	void Accept(IVisitor* visitor) override
	{
		visitor->Visit(this);
	}
};

class ConsoleVisitor : public IVisitor {
public:
	void Visit(House* house) override {
		cout << "Medical insurance:\n\tPrice : " << house->GetPrice() << "\n\tTerm : " << house->GetTerm() << endl;
	}
	void Visit(Factory* factory) override {
		cout << "Insurance from fire:\n\tPrice : " << factory->GetPrice() << "\n\tTerm : " << factory->GetTerm() << endl;
	}
	void Visit(Bank* bank) override {
		cout << "Insurance from robbery:\n\tPrice : " << bank->GetPrice() << "\n\tTerm : " << bank->GetTerm() << endl;
	}
};

int main()
{
	House* house = new House;
	Factory* factory = new Factory;
	Bank* bank = new Bank;

	IVisitor* visitor = new ConsoleVisitor;

	house->SetPrice(100);
	house->SetTerm(2);

	house->Accept(visitor);

	factory->SetPrice(1000);
	factory->SetTerm(4);

	factory->Accept(visitor);

	bank->SetPrice(5000);
	bank->SetTerm(5);

	bank->Accept(visitor);

	delete visitor;
	delete house;
	delete factory;
	delete bank;

	system("pause");
}
