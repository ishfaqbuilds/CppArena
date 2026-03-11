A **class template** is a blueprint for creating classes that work with **any data type**. Instead of writing multiple classes for int, float, double, etc., you write **one template** that works for all. We also have [[Function Template]] similar to class template.
###  **Why Use Class Templates?**
- **Code reusability**: One class, multiple types.   
- **Type flexibility**: Works with any data type.
- **Cleaner code**: Avoids redundancy.
## Class Template (Single Parameter)
```cpp
#include <iostream>
using namespace std;
template <class T> // <typename T>
class weight
{
	T kg;
public:
	void setkgdata(T x)
	{
		kg = x;
	}

	T getdata()
	{
		return kg;
	}
};

int main()
{
	weight<int> obj1;
	obj1.setkgdata(9);
	cout << "Value is: " << obj1.getdata() << endl;

	weight<double> obj2;
	obj2.setkgdata(9.8);
	cout << "Value is: " << obj2.getdata() << endl;
	return 0;
}
```

## Class Template (Multiple Parameter)
```cpp
#include <iostream>
using namespace std;
template <class T, class U, class Z>
class CalculateMedian
{
private:
	T Integer = 0;
	U Double = 0;
	Z Character = '0';

public:
	void setkgdata(T x, U y, Z p)
	{
		Integer = x;
		Double = y;
		Character = p;
	}

	T getintdata()
	{
		return Integer;
	}

	U getdoubledata()
	{
		return Double;
	}

	Z getcharacterdata()
	{
		return Character;
	}
};

int main()
{
	CalculateMedian<int, double, char> obj1;
	obj1.setkgdata(8, 9.7, 'S');
	cout << "Integer: " << obj1.getintdata() << endl;
	cout << "Double: " << obj1.getdoubledata() << endl;
	cout << "Character: " << obj1.getcharacterdata() << endl;
	return 0;
}
```

## Generic Template (Sum)
```cpp
#include <iostream>
using namespace std;
template <class T>
class GenericArray
{
	T arr[100]; // Fixed-size array
	int size;
public:
	GenericArray(T input[], int n)
	{
		size = n;
		for (int i = 0; i < n; i++)
		{
			arr[i] = input[i];
		}
	}

	T getSum()
	{
		T sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
};

int main()
{
	int intArr[] = {1, 2, 3, 4, 5};
	GenericArray<int> g1(intArr, 5);
	cout << "Sum (int): " << g1.getSum() << endl;

	float floatArr[] = {1.1f, 2.2f, 3.3f};
	GenericArray<float> g2(floatArr, 3);
	cout << "Sum (float): " << g2.getSum() << endl;

	double doubleArr[] = {2.5, 3.5, 4.5};
	GenericArray<double> g3(doubleArr, 3);
	cout << "Sum (double): " << g3.getSum() << endl;
	return 0;
}
```
