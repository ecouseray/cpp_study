#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int) * n);
		_size = 0;
		_capacity = n;
	}
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}
private:
	int* _a;
	size_t _size;
	size_t _capacity;
};

void test1()
{
	Stack st;
}

int main()
{
	test1();
	return 0;
}