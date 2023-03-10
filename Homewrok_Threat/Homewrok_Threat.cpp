
#include <iostream>
#include <math.h>

class Stack
{
private:
	char* stack = nullptr;
	int size = 0;
	int endIndx = 0;
public:
	Stack()
	{
		size = 10;
		stack = new char[10];
		endIndx = -1;
	}
	Stack(int _size)
	{
		try
		{
			if (_size == 0)
			{
				throw _size;
			}
			stack = new char[_size];
			size = _size;
			endIndx = -1;
		}
		catch(int a)
		{
			std::cerr << "ERROR: SIZE " << a << "IS MAY CAUSE ERROR;\n";
		}
	}

	void add(char _add)
	{
		try
		{
			if (isFull)
			{
				throw "stackOverflow!";
			}
			else
			{
				stack[++endIndx] = _add;
			}
		}
		catch (const char* a)
		{
			std::cerr << a << '\n';
		}
	}
	char pop()
	{
		try
		{
			if (isEmpty())
			{
				throw "EMPTY!";
			}
			return stack[endIndx--];
		}
		catch (const char* a)
		{
			std::cerr << a << '\n';
		}
	}

	bool isFull()
	{
		if (endIndx + 1 == size)
		{
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (endIndx == -1)
		{
			return true;
		}
		return false;
	}


	~Stack()
	{
		delete[] stack;
	}
};

int transfer(char* &bit)
{
	int dump = 0;
	try
	{
		if (strlen(bit) < 32 || strlen(bit) > 32)
		{
			for (int i = strlen(bit) - 2; i > 0; i--)
			{
				if (bit[i] == '1')
				{
					dump += pow(2, strlen(bit) - 2 - i);
				}
				throw - 1;
			}
			if (strlen(bit) - 1 == '1')
			{
				dump *= -1;
			}
			throw - 1;
		}
	}
	catch (int a)
	{
		std::cout << "ERROR: " << a << " INCORRECT LENGHT;\n";
	}
	for (int i = 30; i > -1; i--)
	{
		if (bit[i] == '1')
		{
			dump += pow(2, 30 - i);
		}
	}
	if (bit[31] == '1')
	{
		dump *= -1;
	}
	return dump;
}

int main()
{
	std::cout << "task1: " << '\n';
	char* bit = new char[33]; bit[32] = '\0';
	for (int i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
		{
			bit[i] = '1';
		}
		else
		{
			bit[i] = '0';
		}
	}
	int dump = transfer(bit);
	std::cout << "result: " << dump << '\n';
	delete[] bit;

}
