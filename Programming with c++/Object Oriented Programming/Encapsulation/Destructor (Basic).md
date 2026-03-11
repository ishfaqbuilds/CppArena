## Destructor (Basic)

Key Points:
- Special function with `~` prefix 
- Automatically called when object goes out of scope 
- No parameters, no return type 
- Used for cleanup (deallocating memory, closing files)

```cpp
class Student
{
private:
	string name;
	int *marks;

public:
	// Constructor
	Student(string n, int m) : name(n)
	{
		marks = new int(m);
	}

	// Destructor
	~Student()
	{
		delete marks; // Free allocated memory
		cout << "Destructor called for " << name << endl;
	}
};
```

