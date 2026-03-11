**Key Points:** 
- Default copy constructor behavior 
- Copies pointer addresses, not actual data 
- Can lead to double deletion and dangling pointers 
- Generally avoided for classes with dynamic memory

```cpp
class Student
{
private:
	string name;
	int *marks;

public:
	Student(string n, int m) : name(n)
	{
		marks = new int(m);
	}

	// Shallow Copy (Default behavior - AVOID for dynamic memory)
	Student(const Student& other) : name(other.name), marks(other.marks) 
	{
		// Both objects point to same memory location - DANGEROUS!
	}

	// Problem: When one object is destroyed, the other has dangling pointer
};
```
