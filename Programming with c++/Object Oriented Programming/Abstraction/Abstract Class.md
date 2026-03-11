An abstract class is a base class that cannot be instantiated (cannot create objects of an abstract class type) on its own and is designed to be inherited by other classes. It usually contains at least one **pure virtual function**.

**Why abstract class is needed?
1. Define common interfaces for derived classes.
2. Force derived classes to implement specific behavior.
3. Supports polymorphism and helps in designing scalable and flexible code.
#### Abstract Class:

```cpp
#include <iostream>
using namespace std;
class Base
{                               // Abstract class
public:
	virtual void show() = 0;    // Pure Virtual Function
	
	void normalFunction()       // Can Have Normal Functions
	{                           
		cout << "Normal function in abstract class\n";
	}
};

class Derv1 : public Base
{
public:
	void show()
	{                           // Must implement pure virtual function
		cout << "Derv1\n";
	}
};

int main()
{
  // Base b;                    // ERROR: Cannot Instantiate Abstract Class
  Base *arr[2];                 // OK: Can Create Pointers To Abstract Class
  Derv1 dv1;                    // Created Object Of Derived Class
  arr[0] = &dv1;                // OK: Can Point To Derived Class Objects
  arr[0]->show();               // Output: Derv1
  arr[0]->normalFunction();
}
```