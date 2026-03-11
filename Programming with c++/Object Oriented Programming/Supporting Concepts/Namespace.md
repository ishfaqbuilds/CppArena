## Namespace

A namespace is a **logical container** for identifiers (variables, functions, classes) to **avoid name conflicts**.

**Syntax:**
```cpp
namespace MySpace 
{
    int value = 42;
    void display() 
    { 
	    cout << "Hello from MySpace\n"; 
    }
}

int main() 
{
    MySpace::display();   // Access using scope resolution operator
    cout << MySpace::value;
}
```

**Using directive:**
```cpp
using namespace MySpace;  // Now we can directly call display()
display();
```

Key point: Organizes code in **large projects** to prevent naming collisions.

