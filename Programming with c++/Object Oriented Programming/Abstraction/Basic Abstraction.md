## Basic Abstraction

Abstraction shows what an object does, not how it works internally.

**Importance:** Simplifies usage and hides implementation details.
    
**Ways to achieve abstraction in C++:**
    
- Abstract classes and **pure virtual functions** (virtual void f( ) = 0;).   
- Separate interface (header files) from implementation (source files).

#### Example:
```cpp
class Shape 
{
public:
    virtual void draw() = 0;  // pure virtual function
};

class Circle : public Shape 
{
public:
    void draw()
    { /* code to draw circle */ }
};
```
