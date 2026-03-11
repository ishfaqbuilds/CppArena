## Operator Overloading Using Friend Function

#### Addition Operator ( + ) using Friend Function 

```cpp
#include <iostream> 
using namespace std;
class Complex
{
private:
	int real, img;
public:
	Complex(int r = 0, int i = 0) : real(r), img(i) {}

	void display()
	{
		cout << real << "+" << img << "i";
	}
	
	// Friend Function Declaration
	friend Complex operator+(Complex &c1, Complex &c2);
};

// Friend Function Definition
Complex operator+(Complex &c1, Complex &c2)
{
	Complex result;
	result.real = c1.real + c2.real;
	result.img = c1.img + c2.img;
	return result;
}

int main()
{
	Complex c1(5, 3), c2(10, 5), c3;
	c1.display();
	cout << " + ";
	c2.display();
	cout << " = ";
	
	c3 = c1 + c2;                 // Calls operator+(c1, c2)
	c3.display();                 // Output: 5+i3 + 10+i5 = 15+i8
	cout << endl;
	return 0;
}
```
---

#### Logical And ( && ) using Friend Function

```cpp
#include <iostream>
using namespace std;
class MyClass
{
private:
	bool value;
public:
	MyClass(bool val) : value(val) {}
	
	// Friend Function Declaration
	friend bool operator&&(MyClass &obj1, MyClass &obj2);
};
  
// Friend Function Definition
bool operator&&(MyClass &obj1, MyClass &obj2)
{
	return (obj1.value && obj2.value);
}

int main()
{
	MyClass obj1(true);
	MyClass obj2(false);
	MyClass obj3(true);

	if (obj1 && obj2)
	{
		cout << "obj1 && obj2: true" << endl;
	}
	else
	{
		cout << "obj1 && obj2: false" << endl;
	}
	return 0;
}
```

---

#### Pre Increment ( ++p ) using Friend Function

```cpp
#include <iostream>
using namespace std;
class Counter
{
private:
	int value;
public:
	Counter(int v = 0) : value(v) {}
	
	// Friend function declaration for pre-increment
	friend Counter &operator++(Counter &obj);

	void display() const
	{
		cout << "Value: " << value << endl;
	}
};

// Friend function Unary Operator Overloading for pre-increment (++obj)
Counter &operator++(Counter &obj)
{
	++obj.value;
	return obj;      // return by reference to allow chaining
}

int main()
{
	Counter c1(5);
	cout << "Before Increment: ";
	c1.display();
	++c1;           // calls friend function operator++(Counter&)
	cout << "After Pre-Increment: ";
	c1.display();
	return 0;
}
```
