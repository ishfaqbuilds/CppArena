## Interfaces vs Implementation

#### What is an Interface?
- In many languages, an interface is a contract — it specifies what a class must do, but not how.
- C++ does not have a built-in interface keyword, but we can achieve the same behavior using abstract classes with pure virtual functions.
        
#### Abstract Class as Interface:
- A class that contains at least one pure virtual function (= 0) becomes abstract.
- You **cannot instantiate** an abstract class — only derive from it.
- It defines _what_ functions must exist without defining _how_ they work.
- **Example:**

```cpp
class Shape // Interface (abstract class)
{             
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape 
{
public:
    void draw() override { /* draw a circle */ }
};

class Rectangle : public Shape 
{
public:
    void draw() override { /* draw a rectangle */ }
};
```

#### Key Benefit:
- Promotes abstraction — the user of Shape only cares that it has `draw()`, not how each shape does it.
- Allows for polymorphism — `Shape* s = new Circle(); s->draw();` works for any derived class.
