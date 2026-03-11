
## Pure Virtual Function
A pure virtual function in c++ is a virtual function for which we do not have an implementation. The pure virtual function is initialized to zero (0).

```cpp
#include <iostream>
using namespace std;
class Base
{
public:
	virtual void s() = 0; // Pure Virtual Function
};

class Derived : public Base
{
public:
	void s()              // Must implement this function
	{ 
		cout << "Virtual Function in Derived class\n";
	}
};

int main()
{
	Base *ptr;    // Created Base Pointer
	Derived obj;  // Created derived class object
	ptr = &obj;   // Base pointer points to derived object
	ptr->s();     // Base pointer points to derived class function.
}
```
[[Pointers To Derived Class|Check Out Pointers To Derived Class]]

**Why pure virtual function is needed?**
A pure virtual function tells the compiler “Every subclass must implement this function, or else it will also be an [[Abstract Class]].”
This is useful when:
  - We don’t want to provide a default implementation in the base class.
  - You want to make sure **each derived class must override** that method.