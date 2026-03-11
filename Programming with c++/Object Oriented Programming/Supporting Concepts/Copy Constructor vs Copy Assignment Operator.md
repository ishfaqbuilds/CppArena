## Copy Constructor vs Copy Assignment Operator

| **Feature**            | **Copy Constructor**                             | **Copy Assignment Operator**                          |
| ---------------------- | ------------------------------------------------ | ----------------------------------------------------- |
| **Purpose**            | Initialize a **new object** as a copy of another | Copy **existing object** into another existing object |
| **Syntax**             | ClassName(const ClassName &obj)                  | obj1 = obj2;                                          |
| **When called**        | On object creation                               | On assignment after creation                          |
| **Default behavior**   | Shallow copy of members                          | Shallow copy of members                               |
| **Can be overloaded?** | Yes                                              | Yes                                                   |
**Example:**
```cpp
class Demo 
{
    int x;
public:
    Demo(int val) : x(val) {}
    Demo(const Demo &d) 
    { 
	    x = d.x;  // Copy constructor
	}  
	
    void operator=(const Demo &d) 
    { 
	    x = d.x; // Copy assignment
    }  
    
    void print() 
    { 
	    cout << x << "\n"; 
	}
};

int main() 
{
    Demo d1(10);
    Demo d2 = d1;   // Copy constructor
    Demo d3(0);
    d3 = d1;        // Copy assignment
}
```

Key point:
- Copy constructor = new object initialized from another object.
- Copy assignment = existing object overwritten by another object.
