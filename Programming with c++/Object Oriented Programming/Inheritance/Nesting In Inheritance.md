## Nesting In Inheritance

A nested class is a class declared within the scope of another class is referred as Nesting In Inheritance.

```cpp
#include <iostream>
using namespace std;

// NESTED CLASS: A class inside another class
class School
{
private:
	string schoolName;
public:
	// Constructor for outer class
	School(string name)
	{
		schoolName = name;
	}

	// NESTED CLASS - Student class inside School class
	class Student
	{
	private:
		string studentName;
	public:
		// Constructor for inner class
		Student(string name)
		{
			studentName = name;
		}
		// Simple function to show student info
		void showStudent()
		{
			cout << "Student: " << studentName << endl;
		}
		// Inner class can access outer class private data
		void showSchool(School &school)
		{
			cout << "School: " << school.schoolName << endl;
		}
	};

	// Function to create and use nested class
	void createStudent()
	{
		Student s("John"); // Create inner class object
		s.showStudent(); // Call inner class function
		s.showSchool(*this); // Access outer class data
	}
};

int main()
{
	// Create outer class object
	School mySchool("ABC High School");

	// Method 1: Create inner object through outer class
	mySchool.createStudent();
	cout << "---" << endl;

	// Method 2: Create inner object directly
	School::Student student2("Alice");
	student2.showStudent();
	return 0;
}
```
