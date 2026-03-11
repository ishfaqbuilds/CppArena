A derived class is created from another derived class (chain of inheritance) is known as Multilevel [[Basic Inheritance|Inheritance]].

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

// First level derived class
class FourWheeler : public Vehicle
{
public:
	FourWheeler()
	{
		cout << "Objects with 4 wheels are vehicles\n";
	}
};

// Second level derived class
class Car : public FourWheeler
{
public:
	Car()
	{
		cout << "Car has 4 Wheels\n";
	}
};

int main()
{
	Car obj; // Output: This is a Vehicle
			 // Objects with 4 wheels are vehicles
			 // Car has 4 Wheels
	return 0;
}
```
