The combination of more than one type of inheritance is known as Hybrid [[Basic Inheritance|Inheritance]].

```cpp
#include <iostream>
using namespace std;

// Base classes
class Vehicle
{
public:
	Vehicle()
	{
		cout << "This is a Vehicle\n";
	}
};

class Fare
{
public:
	Fare()
	{
		cout << "Fare of Vehicle\n";
	}
};

// Single inheritance
class Car : public Vehicle
{

};

// Multiple inheritance
class Bus : public Vehicle, public Fare
{

};

int main()
{
	Bus obj; 
	return 0;
}
```
