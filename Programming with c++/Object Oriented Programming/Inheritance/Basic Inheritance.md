**Inheritance** is a feature of Object-Oriented Programming (OOP) that allows a class (**derived/child**) to **inherit properties and behavior** (data members and member functions) from another class (**base/parent**). It promotes **code reuse**, **extensibility**, and supports **polymorphism**.

## Access Specifiers in Inheritance
```cpp
#include <iostream>
using namespace std;
class Base
{
public:
	int publicValue = 1;
protected:
	int protectedValue = 2;
private:
	int privateValue = 3;
};

// Public inheritance
class PublicDerived : public Base
{
public:
	void display()
	{
		cout << "Public: " << publicValue << endl; // Accessible (public)
		cout << "Protected: " << protectedValue << endl; // Accessible (protected)
		// cout << privateVar; // ERROR: Not accessible
	}
};

// Private inheritance
class PrivateDerived : private Base
{
public:
	void display()
	{
	// Accessible (but private in derived)
	cout << "Public: " << publicValue << endl; 
	// Accessible (but private in derived)
	cout << "Protected: " << protectedValue << endl; 
	// cout << privateVar; // ERROR: Not accessible
	}
};

int main()
{
	PublicDerived pd;
	pd.publicValue = 10; // OK - public member accessible
	pd.display();

	PrivateDerived pvd;
	// pvd.publicValue = 10; // ERROR - became private in derived class
	pvd.display();
	return 0;
}
```

## Single Inheritance
One class is derived from another single class!
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

// Derived class
class Car : public Vehicle
{
public:
	Car()
	{
		cout << "This is a Car\n";
	}
};

int main()
{
	Car obj; // Output: This is a Vehicle
			 // This is a Car
	return 0;
}
```

## Parameterized Inheritance
```cpp
#include <iostream>
#include <string>
using namespace std;

class person
{
public:
	string name;
	int age;
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

class student : public person
{
public:
string id;
	student(string name, int age, string id) : person(name, age)
	{
		this->id = id;
	}
	void getinfo()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "ID: " << id << endl;
	}
};

int main()
{
	student s1("Ishfaqul Islam", 21, "C243021");
	s1.getinfo();
	return 0;
}
```

## Non Parameterized Inheritance
```cpp
#include <iostream>
#include <string>
using namespace std;

class person
{
public:
	string name;
	int age;
	person()
	{
	}
};

class student : public person
{
public:
	string id;
	void getinfo()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "ID: " << id << endl;
	}
};

int main()
{
	student s1;
	s1.name = "Mohammad Ishfaqul Islam";
	s1.age = 21;
	s1.id = "C243021";
	s1.getinfo();
	return 0;
}
```