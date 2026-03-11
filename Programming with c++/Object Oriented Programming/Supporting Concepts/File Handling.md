File handling is the process of creating, reading, writing, and manipulating files using programming languages. In C++, file handling allows us to:
- Store data permanently (data persists after program ends)
- Read data from external files
- Process large amounts of data
- Create logs and reports
- Exchange data between programs

## Why Use File Handling?
1. **Permanent Storage**: Data in variables is lost when program ends, but files preserve data
2. **Large Data Processing**: Handle datasets too large for memory
3. **Data Exchange**: Share data between different programs
4. **Backup and Recovery**: Create backups of important data
5. **Configuration**: Store program settings and preferences

## File Stream Classes in C++
C++ provides three main classes for file operations:

### 1. `ifstream` (Input File Stream)

- Used for **reading** from files
- Inherits from `istream`
- Opens files in read mode by default

### 2. `ofstream` (Output File Stream)

- Used for **writing** to files
- Inherits from `ostream`
- Opens files in write mode by default

### 3. `fstream` (File Stream)

- Used for both **reading and writing**
- Inherits from both `istream` and `ostream`
- Most versatile but requires explicit mode specification

## File Opening Modes

|Mode|Description|Use Case|
|---|---|---|
|`ios::in`|Input (read)|Reading data from file|
|`ios::out`|Output (write)|Writing data to file (overwrites existing)|
|`ios::app`|Append|Add data to end of existing file|
|`ios::ate`|At end|Open and move to end of file|
|`ios::trunc`|Truncate|Clear file contents when opening|
|`ios::binary`|Binary mode|Handle binary data (images, executables)|

## File Handling Example

```cpp
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	string name;
	int id;
	double cgpa;
	cin >> name >> id >> cgpa;

	/// Write Data To The File ///
	ofstream write("student.txt");
	write << name << endl;
	write << id << endl;
	write << cgpa << endl;
	write.close();

	/// Read Data From The File ///
	ifstream read("student.txt");
	string readName;
	int readId;
	double Cgpa;

	getline(read, readName);
	read >> readId;
	read >> Cgpa;
	read.close();

	/// Output Data To The Display
	cout << readName << endl;
	cout << readId << endl;
	cout << Cgpa << endl;
	return 0;
}
```

