#### Purpose: Separating _declarations_ (interface) from _definitions_ (implementation) keeps projects organized and improves compile times.
    
#### Header file (.h):
    
- Contains **class declarations, function prototypes, constants, macros**, and documentation.
- No actual logic — just says _what exists_.    
- **Source file (.cpp):** Contains **function definitions (implementations)** and any internal logic.
    
- **Example:**

 **Shape.h** _(interface)_
```cpp
#ifndef SHAPE_H
#define SHAPE_H

class Shape 
{
public:
    virtual void draw() = 0;  // Pure virtual function
};

#endif
```

 **Circle.h** _(interface for Circle)_
 ```cpp
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape 
{
public:
    void draw() override;  // Declaration only
};

#endif
 ```

**Circle.cpp** _(implementation)_
```cpp
#include "Circle.h"
#include <iostream>
using namespace std;

void Circle::draw() 
{
    cout << "Drawing a circle\n";
}
```

**Key Benefit:**

- **Abstraction at project level:** Users include only .h files — they know what functions exist but not how they are implemented.
- Easier to maintain and update implementations without changing the interface.

