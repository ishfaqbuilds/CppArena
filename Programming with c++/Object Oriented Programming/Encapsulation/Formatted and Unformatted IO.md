#### Formatting using Manipulators
**What is it?
1. Uses functions from "iomanip" to control how output appears.
2. It’s cleaner and easier to read.
3. - Examples: setw( ), setfill( ), setprecision( ), fixed, showpos, etc.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float num = 123.456;
	cout << "Using manipulators:\n";
    cout << setw(10)         // total width = 10
         << setfill('*')     // fill unused space with '*'
         << fixed            // fixed-point notation
         << setprecision(2)  // 2 digits after decimal
         << showpos          // show + for positive numbers
         << num << endl;
	return 0;
}
```

#### Formatting using ios class flag
**What is it?
1. Uses **ios class member functions or flags** to format output.
2. More low-level control.
3. Examples: ios::showpos, ios::fixed, ios::left, etc.
4. Use cout.setf( ), cout.unsetf( ), and cout.precision( )

```cpp
#include <iostream>
using namespace std;

int main() {
    float num = 123.456;
	cout << "Using ios class flags:\n";
	cout.setf(ios::showpos);         // Show +
    cout.setf(ios::fixed);           // Fixed-point notation
    cout.setf(ios::right);           // Right justify
    cout.width(10);                  // Set width to 10
    cout.precision(2);               // 2 digits after decimal
	cout << num << endl;
return 0;
}
```
