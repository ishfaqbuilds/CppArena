
- **Definition:** The type of inheritance (public, protected, private) determines how base class members are inherited by the derived class.

- **Rules Table:**

| **Base Class Member** | **Public Inheritance** | **Protected Inheritance** | **Private Inheritance** |
| --------------------- | ---------------------- | ------------------------- | ----------------------- |
| public                | public                 | protected                 | private                 |
| protected             | protected              | protected                 | private                 |
| private               | Not inherited          | Not inherited             | Not inherited           |

- **Example:**
```cpp
class Base 
{
public: 
		int a;
protected: 
		int b;
private: 
		int c;
};

class Derived : public Base 
{
    // a -> public, b -> protected, c -> not inherited
};

class Derived2 : protected Base 
{
    // a -> protected, b -> protected
};

class Derived3 : private Base 
{
    // a -> private, b -> private
};
```

- **Key Point:** Use public inheritance for “is-a” relationships. Protected/private are rarely used outside specific design needs.
