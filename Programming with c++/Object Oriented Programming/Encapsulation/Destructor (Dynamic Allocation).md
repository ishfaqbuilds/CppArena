## Destructor (Dynamic Allocation)

Key Points:*
- Essential when class allocates dynamic memory 
- Virtual destructors needed for polymorphism -
- RAII principle: Resource Acquisition Is Initialization 
- Prevents memory leaks

```cpp
class DynamicArray
{
private:
	int *arr;
	int size;

public:
	DynamicArray(int s) : size(s)
	{
		arr = new int[size];
		cout << "Array of size " << size << " created" << endl;
	}

	// Virtual destructor for inheritance
	virtual ~DynamicArray()
	{
		delete[] arr; // Note: delete[] for arrays
		cout << "Array memory freed" << endl;
	}

	void setValue(int index, int value)
	{
		if (index >= 0 && index < size)
		{
			arr[index] = value;
		}
	}
};
```
