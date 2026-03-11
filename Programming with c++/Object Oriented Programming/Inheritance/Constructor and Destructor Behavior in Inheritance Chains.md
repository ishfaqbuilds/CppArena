- **Constructor Call Order:**
    
    - **Base class constructors are called before derived class constructors**.
        
    - Order of constructor calls follows the inheritance hierarchy (top to bottom).
        
    - If there are multiple base classes, they are called in the order they appear in the inheritance list.
    
- **Destructor Call Order:**
    
    - **Reverse of constructors:** Derived class destructors run first, then base class destructors.
    
- **Example:**

Input:
```cpp
class A 
{
public:
    A() { cout << "A constructor\n"; }
    ~A() { cout << "A destructor\n"; }
};

class B : public A 
{
public:
    B() { cout << "B constructor\n"; }
    ~B() { cout << "B destructor\n"; }
};

int main() 
{
    B obj;
}
```

Output:
```cpp
A constructor
B constructor
B destructor
A destructor
```

- **Key Point:** Always make destructors virtual in base classes if you expect polymorphic deletion (using base pointers).
