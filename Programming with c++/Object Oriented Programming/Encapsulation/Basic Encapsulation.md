## Encapsulation
Encapsulation is bundling data (variables) and methods (functions) into a single unit, usually a class.

Key Points:
- **Encapsulation:** Data hiding using access specifiers.
- **Importance:** Protects data, prevents unintended modification, and improves modularity.
- **Access specifiers:** public, private, protected – control how data and methods are accessed.
- **Getters and setters:** Provide controlled access to private members.

```cpp
class BasicOOP 
{ 
public: 
	int publicVar; // Accessible everywhere 
private: 
	int privateVar; // Only within class 
protected: 
	int protectedVar; // Within class and derived classes 
public: 
	void display() 
	{ 
		cout << "Basic OOP class" << endl; 
	} 
};
```

### Access Specifiers (public, private, protected)
Definition: Access specifiers control the visibility of class members (variables and functions).
Types:
- **public:** Accessible from anywhere in the program.
- **private:** Accessible only within the same class. _(default for class members)_
- **protected:** Accessible within the same class and its derived classes, but not from outside.

Example:

```cpp
class Example
{
public:
    int x;  // accessible everywhere
private:
    int y;  // accessible only inside Example
protected:
    int z;  // accessible inside Example and any derived class
};
```

Key Point: Proper use of access specifiers is the foundation of encapsulation.

### Getters and Setters (Accessor / Mutator Methods)
Definition: Special public functions that provide controlled access to private data.
Purpose:
    - Protect internal state.
    - Allow validation before changing values.
    - Hide internal implementation details.
	
**Example:**

```cpp
class BankAccount 
{
private:
    double balance;
public:
    void setBalance(double amount) // Setter
    { 
        if (amount >= 0) balance = amount; 
    }
    double getBalance() { return balance; } //Getter
};
```

Key Point: Always prefer getters/setters over making data public directly.

### Static Members (Class Variables and Functions)
Definition: Members shared by all objects of a class rather than each object having its own copy.
Characteristics:
    - Declared with the static keyword.
    - Stored in a single shared memory location.
    - Can be accessed using the class name directly.
    
Example (Static Variable):

```cpp
class Counter 
{
public:
    static int count; // declaration
    Counter() 
    { 
	    count++; 
    }
};
int Counter::count = 0;  // definition outside class

int main() 
{
    Counter a, b;
    cout << Counter::count;  // prints 2
}
```

Example (Static Function):

```cpp
class Utility 
{
public:
    static void greet() 
    {
        cout << "Hello!\n";
    }
};

int main() 
{
    Utility::greet();  // call without creating an object
}
```

Key Point: Use static members for information or functionality common to all objects of a class.




