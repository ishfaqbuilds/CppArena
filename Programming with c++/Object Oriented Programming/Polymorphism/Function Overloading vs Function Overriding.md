
|**Feature**|**Overloading**|**Overriding**|
|---|---|---|
|**Definition**|Same function name, **different parameters** (signature)|Same function signature in **derived class**|
|**Polymorphism type**|Compile-time (Static)|Runtime (Dynamic)|
|**Class relationship**|Same class|Base & Derived classes|
|**Keyword**|None|virtual (base class) + override (derived class, optional)|

**Example:**
```cpp
// Overloading
class Test 
{
public:
    void show(int x) { std::cout << x; }
    void show(double y) { std::cout << y; }
};

// Overriding
class Base 
{
public:
    virtual void print() { std::cout << "Base\n"; }
};
class Derived : public Base 
{
public:
    void print() override { std::cout << "Derived\n"; }
};
```
