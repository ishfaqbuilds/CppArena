## Constructor (Deep Copy)

Key Points:
- Creates separate memory for dynamic data 
- Prevents shallow copy problems 
- Essential when class has pointer members 
- Avoids double deletion errors

```cpp
class Student
{
private:
	string name;
	int *marks; // Dynamic memory

public:
	Student(string n, int m) : name(n)
	{
		marks = new int(m);
	}

	// Deep Copy Constructor
	Student(const Student &other) : name(other.name)
	{
		marks = new int(*(other.marks)); // Create new memory
		cout << "Deep copy constructor called" << endl;
	}
	
	~Student()
	{
		delete marks; // Safe deletion
	}
};
```
