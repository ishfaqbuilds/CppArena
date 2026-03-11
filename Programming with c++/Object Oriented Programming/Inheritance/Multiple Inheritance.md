When a class can inherit from more than one base class then it's referred as Multiple [[Basic Inheritance|Inheritance]].

```cpp
#include <iostream>
using namespace std;

// First base class
class Vehicle
{
public:
	Vehicle()
	{
		cout << "This is a Vehicle\n";
	}
};

// Second base class
class FourWheeler
{
public:
	FourWheeler()
	{
		cout << "This is a 4 wheeler Vehicle\n";
	}
};

// Derived class inheriting from both
class Car : public Vehicle, public FourWheeler
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
			 // This is a 4 wheeler Vehicle
             // This is a Car
	return 0;
}
```