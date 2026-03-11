**Key Points:** 
- `try-catch-throw` mechanism 
- Custom exception classes 
- Multiple catch blocks for different exceptions 
- `catch(...)` for any exception

```cpp
#include <iostream>
using namespace std;

int main() {
    try 
    {
        int x, y;
        cout << "Enter two numbers: ";
        cin >> x >> y;

        if (y == 0) 
        {
            throw "Division by zero error!";  // throwing a string literal
        }

        cout << "Result: " << x / y << endl;
    }
    catch (char* msg) 
    {  
        cout << "Caught exception: " << msg << endl;
    }
}
```
