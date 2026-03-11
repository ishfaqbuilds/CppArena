#### Generic Function To Add using Vector
```cpp
#include <iostream>
#include <vector>
using namespace std;
template <class T>
T Add(vector<T> v)
{
	T sum = 0;
	int size = v.size();

	for (int i = 0; i < size; i++)
	{
		sum += v[i];
	}
	return sum;
}

int main()
{
	vector<int> integer = {1, 3, 5, 7, 8};
	cout << Add(integer) << endl;
	vector<double> dd = {1.4, 5.6, 3.6};
	cout << Add(dd) << endl;
	return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Template function to calculate median
template <typename T>
T CalculateMedian(vector<T> v)
{
	sort(v.begin(), v.end());
	int size = v.size();
	if (size % 2 == 0)
	{
		return (v[size / 2 - 1] + v[size / 2]) / 2;
	}
	else
	{
		return v[size / 2];
	}
}

int main()
{
	// Integer vector
	vector<int> intVec = {5, 3, 1, 4, 2};
	cout << "Median (int): " << CalculateMedian(intVec) << endl;

	// Double vector
	vector<double> doubleVec = {2.5, 1.0, 4.0, 3.5};
	cout << "Median (double): " << CalculateMedian(doubleVec) << endl;

	// Char vector
	vector<char> charVec = {'e', 'a', 'c', 'b', 'd'};
	cout << "Median (char): " << CalculateMedian(charVec) << endl;
	return 0;
}
```

#### Generic Function To Sum using Array
```cpp
#include <iostream>
using namespace std;
template <class T>

T Add(T arr[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum / n;
}

int main()
{
	int integer[] = {1, 3, 5, 7, 8};
	int size1 = sizeof(integer) / sizeof(integer[0]);
	cout << Add(integer, size1) << endl;

	double dd[] = {1.4, 5.6, 3.6};
	int size2 = sizeof(dd) / sizeof(dd[0]);
	cout << Add(dd, size2) << endl;
	return 0;
}
```

#### Generic Function (Multiple Parameter)
```cpp
#include <iostream>
#include <string>
using namespace std;
template <class T>

T Add(T a, T b)
{
	return a + b;
}

int main()
{
	cout << "Addition of Integers: " << Add(5, 10) << endl;
	cout << "Addition of Double: " << Add(3.14, 2.71) << endl;
	
	string s1 = "Hello", s2 = "World";
	cout << "Addition of Strings: " << Add(s1, s2) << endl;
	return 0;
}
```
