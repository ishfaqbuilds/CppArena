## Basic Polymorphism

Polymorphism allows one interface to represent many forms.
Importance: Makes code extensible and reusable.
Types in C++:
- Compile-time (static): Function overloading, operator overloading.
- Run-time (dynamic): Virtual functions and overriding.
  
Virtual functions: Enable runtime behavior changes via base class pointers.

###### Example
```cpp
class Shape 
{
public:
    virtual void draw() { /* default draw */ }
};

class Circle : public Shape 
{
public:
    void draw() override { /* draw a circle */ }
};

void render(Shape* s) 
{
    s->draw();  // behavior depends on actual object type
}
```
