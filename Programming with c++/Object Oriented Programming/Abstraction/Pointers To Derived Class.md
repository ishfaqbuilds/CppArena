## Imp. Note
Base class pointers always call base class functions. It doesn't matter weather the "ptr" (pointer) is pointing to base object or derived object. its always gonna call the base class function. Unless the function is marked "virtual" in the base class which is known as virtual function.
## **Example 1

```cpp
include <iostream>
using namespace std;
class Animal
{
public:
	void speak()
	{
		cout << "Animal sound" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "Woof!" << endl;
	}
};

int main()
{
	Animal *ptr;       // Base class pointer
	Animal animal;     // Base class object
	Dog myDog;         // Derived class object

	// Case 1: Points to base object
	ptr = &animal;     // Base pointer points to base object
	ptr->speak();      // Calls Animal::speak()

	// Case 2: Points to derived object
	ptr = &myDog;      // Base pointer points to derived object
	ptr->speak();      // Calls Animal::speak() (not Dog::speak())

    myDog.speak();     // Calls Dog::speak()
	animal.speak();    // Calls Animal::speak();
```

Here, even tho i'm pointing the pointer at the derived object its still calling the speak function of the base class. This happened because we didn’t use "virtual" keyword in the speak function of the base class.
## Virtual Function

```cpp
#include <iostream>
using namespace std;
class Animal
{
public:
	virtual void food()
	{
		cout << "Every Animal has their own food habits!" << endl;
	}
};

class Cat : public Animal
{
public:
	void food()
	{
		cout << "Cats like to have fishes!" << endl;
	}
};

class Dog : public Animal
{
public:
	void food()
	{
		cout << "Dogs like to have meat!" << endl;
	}
};

int main()
{
	Animal *ptr;
	
	Animal animalObj;
	ptr = &animalObj;
	ptr->food();

	Cat catObj;
	ptr = &catObj;
	ptr->food();

	Dog dogObj;
	ptr = &dogObj;
	ptr->food();

	return 0;
}
```

Note: Using the "virtual" keyword we can access other derived classes member functions as
well using the base pointer. Though we know that when we create a base class pointer and pointing it to the base class pointer we still can just access base class member functions but using the virtual keyword allows us to point the base pointer to any derived class object and access the member functions from the derived classes.
## Difference Between Early Binding and Late Binding
### **Early Binding (Static Binding)**
1. The function call is resolved **at compile time**.
2. Uses **function overloading** or **compile-time polymorphism**.
3. Typically occurs with **non-virtual functions**.
4. It is **faster** because there’s no overhead at runtime.

```cpp
class Base {
public:
    void show() { cout << "Base" << endl; }
};
Base b;
b.show();  // Early binding
```

### **Late Binding (Dynamic Binding)**
1. The function call is resolved **at runtime**.
2. Achieved using **virtual functions**.
3. Enables **runtime polymorphism**, where the derived class function is called via a base class pointer.
4. It is **slightly slower** due to the virtual function table (vtable) lookup.

```cpp
class Base {
public:
    virtual void show() { cout << "Base" << endl; }
};
class Derived : public Base {
public:
    void show() override { cout << "Derived" << endl; }
};
Base *ptr;
Derived obj;
ptr = &obj;
ptr->show();  // Late binding (calls Derived's show)
```

## Key Differences

|**Feature**|**Early Binding**|**Late Binding**|
|---|---|---|
|Resolved at|Compile time|Runtime|
|Speed|Faster|Slightly slower|
|Usage|Function overloading, templates|Virtual functions|
|Flexibility|Less flexible|More flexible (supports polymorphism)|
|Syntax|Normal function calls|Uses virtual keyword|
