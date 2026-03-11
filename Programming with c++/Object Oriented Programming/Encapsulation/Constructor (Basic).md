## Constructor

Key Points: 
- Special member function with same name as class 
- No return type 
- Automatically called when object is created 
- Types: Default, Parameterized, Copy

```cpp
class Student
{
private:
	string name;
	int age;

public:

// Default Constructor
Student()
{
	name = "Unknown";
	age = 0;
	cout << "Default constructor called" << endl;
}

// Parameterized Constructor
Student(string n, int a) : name(n), age(a)
{
	cout << "Parameterized constructor called" << endl;
}

// Copy Constructor
Student(const Student &other) : name(other.name), age(other.age)
{
	cout << "Copy constructor called" << endl;
}
};
```


