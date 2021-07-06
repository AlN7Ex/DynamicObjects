#include <iostream>

class MyClass
{
private:
	static const size_t SIZE = 3;
	static int count;
	int * a;
	int b;

public:
	MyClass()
	{
		std::cout << "Default constructor called " << this << std::endl;
		a = new int[SIZE];
		IncCount();
	}

	MyClass(int value)
	{
		std::cout << "Constructor with param called " << this << std::endl;
		a = new int[SIZE];
		b = value;
		IncCount();
	}

	MyClass(const MyClass & other)
	{
		for(size_t i = 0; i < SIZE; ++i)
		{
			this->a[i] = other.a[i];
		}
	}

	~MyClass()
	{
		std::cout << "Called destructor: " << this;
		delete [] a;
	}

	void IncCount()
	{
		++count;
	}

	static int ShowCount()
	{
		return count;
	}

	int * ShowA()
	{
		return a; 
	}

	void ShowAddress()
	{
		std::cout << "Address of array 'a': " << a << std::endl;
	}

	void operator=(const MyClass & other)
	{
		for(size_t i = 0; i < SIZE; ++i)
		{
			this->a[i] = other.a[i];
		}
	}
};

int MyClass::count = 0;

int main()
{
	size_t rows = 2;
	size_t cols = 3;

	MyClass ** arr = new MyClass * [rows];

	for (size_t i = 0; i < rows; ++i)
	{
		arr[i] = new MyClass[cols];
		std::cout << "Create class" << std::endl;
	}

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			arr[i][j] = MyClass(1);
			std::cout << "[" << i << "],[" << j << "] - a: " << arr[i][j].ShowA() << "\n";
		}

		std::cout << std::endl;
	}

	std::cout << "Amount of created objects: " << MyClass::ShowCount() << std::endl;

	for (size_t i = 0; i < rows; ++i)
	{
		delete [] arr[i];
	}

	delete [] arr;

	system ("pause");

	return 0;
}