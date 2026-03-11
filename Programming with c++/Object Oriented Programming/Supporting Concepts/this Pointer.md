Inside a **non-static member function**, this is a pointer to the **current object**.

**Usage:**
- Access members explicitly.
- Return the current object (method chaining).
 - Resolve naming conflicts between member variables and parameters.

Example:
```cpp
class Test 
{
    int x;
public:
    void setX(int x) { this->x = x; } // parameter x vs member x
    void print() { std::cout << this->x; }
};

int main() 
{
    Test t;
    t.setX(10);
    t.print();  // Outputs: 10
}
```

