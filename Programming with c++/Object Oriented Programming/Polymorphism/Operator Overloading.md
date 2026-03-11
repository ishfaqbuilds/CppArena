Operator Overloading is a feature in Programming Language that allows us to define **CUSTOM** behavior for operators (like +, -, /, == etc.) when they are used with user defined types like classes or structures.

#### *What it does?
When you overload an operator, you're essentially telling the compiler or interpreter what should happen when that operator is applied to objects of your custom type. Instead of the operator having only its built-in meaning (like + for adding numbers), you can make it work with your objects in a meaningful way.

#### **Types of Operators You Can Overload**

1. **Binary:** (Addition +) ,(Subtraction -) , (Multiplication x), (Division /) 
2. **Relational:** == , != , < , > , <= , >=
3. **Assignment:** =, +=, -= etc.
4. **Unary:** ++, --, ! etc.
#### **Operators You Cannot Overload**

Operators like Dot (member access), Ternary Operator ( ? : ), sizeof, typeid, Scope Resolution ( :: ) etc.
#### **In binary operator why only the right side operand is passed as argument?**
In binary operator overloading, the left-hand operand is the object that calls the function, and the right-hand operand is passed as an argument. This is because binary operators are implemented as **member functions**, where the **calling object is the left-hand side operand (this)**.

#### **When do we prefer friend function over member function for operator overloading**
We prefer **friend functions** over member functions for operator overloading when the left-hand operand is not an object of the class, such as when it’s a built-in type (e.g., 5 + obj). Member functions always treat the left-hand operand as the calling object (this), so if that operand is a primitive type, a member function won’t work. Friend functions also provide better symmetry for binary operations where both operands should be treated equally, and they allow access to the private members of both operands if necessary. On the other hand, member functions are typically preferred when the left-hand operand is an object of the class, especially for assignment (=, +=, etc.) and unary operators like ++ or --. Member Function (obj1 + obj2) and Friend Function (5 + obj1) works like this.

#### Quick Reference Table

| Operation Type        | Return    | Example              |
| --------------------- | --------- | -------------------- |
| `=`, `+=`, `-=`, `*=` | `*this`   | `obj1 = obj2`        |
| `+`, `-`, `*`, `/`    | `result`  | `obj3 = obj1 + obj2` |
| `==`, `!=`, `<`, `>`  | `bool`    | `if (obj1 == obj2)`  |
| `++obj` (pre)         | `*this`   | `++counter`          |
| `obj++` (post)        | `temp`    | `counter++`          |
| `<<`, `>>` (streams)  | `stream&` | `cout << obj`        |

#### Addition Operator ( + )

```cpp
#include <iostream>
using namespace std;                                          
class Complex
{
  private:
	  int real, imag;
  public:
	  Complex(int r = 0, int i = 0) : real(r), imag(i) {}   // CONSTRUCTOR
	
  // Overload + operator
	
	Complex operator+(Complex &obj)
	{
		Complex result;
		result.real = real + obj.real;
		result.imag = imag + obj.imag;
		return result;
	}
	
	void display()
	{
		cout << real << " + i" << imag << endl;
	}
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;          // Calls c1.operator+(c2)
	c3.display();                  // Output: 12 + i9
	return 0;
}
```

---

#### Subtraction Operator ( - )

```cpp
#include <iostream>
using namespace std;
class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0) : real(r), imag(i) {}     // CONSTRUCTOR

 // Overload + operator

	Complex operator-(Complex &obj)
	{
		Complex result;
		result.real = real - obj.real;
		result.imag = imag - obj.imag;
		return result;
	}
	
	void display()
	{
		cout << real << " + i" << imag << endl;
	}
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 - c2;               // Calls c1.operator-(c2)
	c3.display();                       // Output: 8 + i1
	return 0;
}
```

---

#### Assignment Operator ( = )

```cpp
#include <iostream>
using namespace std;
class Distance
{
private:
	int feet, inches;
public:
	Distance(int f = 0, int i = 0) : feet(f), inches(i) {}
	Distance operator=(Distance &obj)
	{
		feet = obj.feet;
		inches = obj.inches;
		return *this;
	}
	
	void display()
	{
		cout << "Feet: " << feet << " " << "Inches: " << inches << endl;
	}
};

int main()
{
	Distance d1(5, 10), d2;
	d2 = d1;                  // Calls overloaded = operator
	d2.display();             // Output: F: 5 I: 10
}
```

---

#### Less Than Operator ( < ) Single Relation

```cpp
#include <iostream>
using namespace std;
class height
{
private:
	int feet;
public:
	height(int h = 0)
	{
		feet = h;
	}

	bool operator<(height &obj)
	{
		if (feet < obj.feet)
		{
			return true;
		}
		return false;
				       // return(feet<obj.feet); ( We can also directly use this! )
	}
	
	void display()
	{
		cout << "Height: " << feet << " feet" << endl;
	}
};

int main()
{
	height p1(8), p2(7);
	p1.display();
	p2.display();
	
	if (p1 < p2)
	{
		cout << "p1 is less then p2" << endl;
	}
	else
	{
		cout << "p2 is less then p1" << endl;
	}
	return 0;
}
```

---

#### Less Than Operator ( < ) Multiple Relation

```cpp
#include <iostream>
using namespace std;
class Distance
{
private:
	int feet, inches;
public:
	Distance(int f, int i) : feet(f), inches(i) {}
	
	bool operator<(const Distance &d)
	{
		if (feet < d.feet)
		{
			return true;
		}
		if (feet == d.feet && inches < d.inches)
		{
			return true;
		}
		return false;
	}

	void display()
	{
		cout << "Feet: " << feet << " Inches: " << inches << endl;
	}
};

int main()
{
	Distance d1(11, 10), d2(5, 11);
	d1.display();
	d2.display();
	if (d1 < d2)
	{
		cout << "d1 is less than d2" << endl;
	}
	else
	{
		cout << "d2 is less than d1" << endl;
	}
	return 0;
}
```

---

#### Equality Operator ( == )

```cpp
#include <iostream>
using namespace std;
class Rectangle
{
	int length, breadth;
public:
	Rectangle(int l, int b) : length(l), breadth(b) {}
	
	bool operator==(Rectangle &r)
	{
		return (length == r.length && breadth == r.breadth);
	}
};

int main()
{
	Rectangle r1(4, 5);
	Rectangle r2(4, 5);
	Rectangle r3(3, 5);

	if (r1 == r2)
		cout << "r1 and r2 are equal.\n";
	else
		cout << "r1 and r2 are not equal.\n";
	
	if (r1 == r3)
		cout << "r1 and r3 are equal.\n";
	else
		cout << "r1 and r3 are not equal.\n";
	
	return 0;
}
```

---

#### Unary Operator ( ++p ) and ( p++ )

**Only Pre Increment ( ++p ) and Post Increment ( p++ )**
```cpp
#include <iostream>
using namespace std;
class weight
{
private:
	int kg;
public:
	weight(int k = 0)
	{
		kg = k;
	}

	void operator++()         // pre increment operator
	{
		++kg;
	}
	
	void operator++(int)      // post increment operator. pass int to create   difference
	{                        
		kg++;
	}

    void display()
	{
		cout << "Weight: " << kg << "kg" << endl;
	}
};

int main()
{
	weight p1;
	cout << "At The Beginning" << " ";
	p1.display();

	cout << "After Pre Increment" << " ";
	++p1;                     // p1.operator ++() This is what the operator sees.
	p1.display();

	cout << "After Post Increment" << " ";
	p1++;                     // p1.operator ++(int) This is what the operator sees.
	p1.display();

	return 0;
}
```

**Pre Increment( ++p ) and Post Increment( p++ ) and also Assignment ( = )
```cpp
#include <iostream>
using namespace std;
class weight
{
private:
	int kg;
public:
	weight(int k = 0)
	{
		kg = k;
	}

	weight operator++() // when we do pre increment and also assign the value to another
	{                 // object then we return the class. and here *this is used inside
						// class member functions to return the current object itself.
		++kg;
		return *this;
	}
	
	weight operator++(int) // post increment operator. We pass int data type inside
	{                      // just to differentiate between post and pre increment.
		kg++;
		return *this;
	}

	void display()
	{
		cout << "Weight: " << kg << "kg" << endl;
	}
};

int main()
{
	weight p1, p2;
	p1 = ++p2;
	p1.display();
	++p2;
	++p2;
	p2.display();
	return 0;
}
//Note: Using the second case we can both increment and also assign.
//That means it surves both the peropose while case 1 just increments and can't assign.
```

---

#### MASTER EXAMPLE (ALL IN ONE)
```cpp
#include <iostream>
using namespace std;
class Complex
{
	int real, imag;
public:
	Complex(int x = 0, int y = 0) : real(x), imag(y) {}

	// Addition Operator (+)
	Complex operator+(Complex &obj)
	{
		Complex result;
		result.real = real + obj.real;
		result.imag = imag + obj.imag;
		return result;
	}

	// Subtraction Operator (-)
	Complex operator-(Complex &obj)
	{
		Complex result;
		result.real = real - obj.real;
		result.imag = imag - obj.imag;
		return result;
	}

	// Assignment Operator (=)
	Complex operator=(Complex &obj)
	{
		real = obj.real;
		imag = obj.imag;
		return *this;
	}

	// Equality Operator (==)
	bool operator==(Complex &obj)
	{
		return (real == obj.real && imag == obj.imag);
	}

	// Logical And Opeartor (&&)
	bool operator&&(Complex &obj)
	{
		return (real && obj.real && imag && obj.imag);
	}

	// Pre Increment Operator (++p)
	void operator++()
	{
		++real;
		++imag;
	}

	// Post Increment Operator (p++)
	void operator++(int)
	{
		real++;
		imag++;
	}

	void display()
	{
		cout << real << " + " << imag << "i" << endl;
	}
};

int main()
{
	Complex c1(4, 7), c2(8, 9);
	
	// For Addition Operator
	Complex sum = c1 + c2;
	sum.display();

	// For Subtraction Operator
	Complex sub = c1 - c2;
	sub.display();
	
	// For Assignment Operator
	c1 = c2;
	c1.display();

	// For Equality Operator
	if (c1 == c2)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "Not Equal" << endl;
	}
	
	// For Logical And Operator
	if (c1 && c2)
	{
		cout << "obj1 && obj2: true" << endl;
	}
	else
	{
		cout << "obj1 && obj2: false" << endl;
	}
	
	// For Pre Increment Operator
	++c1;
	cout << "After Pre Increment: ";
	c1.display();

	// For Post Increment Operator
	c2++;
	cout << "After Post Increment: ";
	c2.display();
	return 0;
}
```




