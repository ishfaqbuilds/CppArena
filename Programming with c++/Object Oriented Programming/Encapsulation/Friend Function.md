**Key Points:** 
- Not member functions but can access private/protected members 
- Declared with `friend` keyword inside class 
- Breaks encapsulation but provides flexibility 
- Useful for operator overloading


#### Friend Function

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    Box(int w) : width(w) {}

    // Declare friend function
    friend void showWidth(Box b);
};

// Friend function definition
void showWidth(Box b) {
    cout << "Width of box: " << b.width << endl;  // can access private data
}

int main() {
    Box b1(10);
    showWidth(b1);  // Call friend function
}
```

#### Friend Class

A friend class can access private members of another class.
```cpp
#include <iostream>
using namespace std;

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    // Declare Car as a friend class
    friend class Car;
};

class Car {
public:
    void showPower(Engine e) {
        cout << "Engine horsepower: " << e.horsepower << endl;  // can access private                                                                      data
    }
};

int main() {
    Engine eng(200);
    Car c;
    c.showPower(eng);
}
```