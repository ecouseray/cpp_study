#include <iostream>
using namespace std;

//class Stack
//{
//public:
//	Stack(int n = 10)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		_size = 0;
//		_capacity = n;
//	}
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;
//	size_t _size;
//	size_t _capacity;
//};
//
void test1()
{
	
}
/*

	void print() const
	{

	}

	void f(const Data& d)
	{
		d.print();
	}

	只要调用成员函数，都涉及this指针
	非const可以调用const，const不能调用非const

	全部加上const 如果报错，就删掉，这样最好，const对象和非const都可以调用
*/

//int main()
//{
//	test1();
//	return 0;
//}


/*

在初始化列表中初始化：
因为他们必须在定义的时候就初始化，所以一定得在初始化列表内初始化
const修饰的变量
没有默认构造函数的自定义类型
引用

*/

/*

类域 + 访问限定符   突破类域


static 函数不能够调用非static的函数
非static的函数 能够调用 static的函数
没有this指针
*/