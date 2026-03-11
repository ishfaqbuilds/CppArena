## Hierarchical Inheritance
When more than one subclass is inherited from a single base class then it's referred as Hierarchical Inheritance.

#### Example 1
```cpp
#include <iostream>
using namespace std;

// Base class
class Vehicle
{
public:
	Vehicle()
	{
		cout << "This is a Vehicle\n";
	}
};

// First derived class
class Car : public Vehicle
{
public:
	Car()
	{
		cout << "This is a Car\n";
	}
};

// Second derived class
class Bus : public Vehicle
{
public:
	Bus()
	{
		cout << "This is a Bus\n";
	}
};

int main()
{
	Car obj1; 
	Bus obj2;
	return 0;
}
```

#### Example 2
```cpp
#include <iostream>
using namespace std;

class Account
{
public:
	int money;
	Account(int x = 0) : money(x) {}

	virtual void show()
	{
		cout << "Account Balance: " << money << endl;
	}
};

class Savings : public Account
{
public:
	Savings(int x = 0) : Account(x) {}
	void show()
	{
		cout << "Saving Balance: " << money << endl;
	}
};

class Checking : public Account
{
public:
	Checking(int x = 0) : Account(x) {}
	void show()
	{
		cout << "Checking Balance: " << money << endl;
	}
};

int main()
{
	Account *ptr;
	Account account(0);
	ptr = &account;
	ptr->show();

	Savings save(10000);
	ptr = &save;
	ptr->show();
	
	Checking check(2000);
	ptr = &check;
	ptr->show();
	return 0;
}
```
#### Example 3
```cpp
#include <iostream>
using namespace std;

class Employee
{
public:
	int salary;
	Employee(int x = 0) : salary(x) {}
	virtual void show()
	{
		cout << "Employee Salary: " << salary << endl;
	}
};

class Faculty : public Employee
{
public:
	Faculty(int x = 0) : Employee(x) {}
	void show()
	{
		cout << "Faculty Salary: " << salary << endl;
	}
};

class Staff : public Employee
{
public:
	Staff(int x = 0) : Employee(x) {}
	void show()
	{
		cout << "Staff Salary: " << salary << endl;
	}
};

int main()
{
	Employee *ptr;
	Faculty falty(10000);

	ptr = &falty;
	ptr->show();
	
	Staff staff(2000);
	ptr = &staff;
	ptr->show();
	return 0;
}
```
