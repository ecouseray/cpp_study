// 6个默认成员函数
// 

/*
#include <iostream>
using namespace std;

class Data
{
public:
	Data(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Data()" << ":" << this << endl;
	}
	~Data() // 清理资源的(完成清理工作)
	{
		cout << "~Data()" << ":" <<this <<endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


class Stack
{
public:
	// 对象创建时候自动调用，完成初始化工作
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int) * n);
		_size = 0;
		_capacity = n;
	}
	// 对象生命周期到了以后，完成清理工作
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_size = _capacity = 0;
	}

	void Push(int x)
	{

	}
	void Pop()
	{

	}
	size_t Size()
	{

	}

private:
	int* _a;
	int _size;
	int _capacity;
};

int main()
{
	//Data d1; // 1.我们不写编译器自动生成 2.全缺省 3.无参的（三必一） -- 默认构造函数 -- 不传参就可以调用的
	// Data d1(&d1); -- this 指针
	//Data d2;
	// d1 先构造，d2 后构造，d2 先析构，d1 后析构
	// 生命周期结束自动调用，栈空间，先进后出

	Stack st;

	// 构造函数，是完成初始化的工作，如果类嵌套的话，默认类型不会初始化，被嵌套的类会初始化
	// 析构函数，是完成清理资源的工作，如果类嵌套的话，默认类型不会做什么，被嵌套的类会调用该类的析构函数

	return 0;
}

*/

// 构造函数，是完成初始化的工作，如果类嵌套的话，默认类型不会初始化，被嵌套的类会初始化
// 析构函数，是完成清理资源的工作，如果类嵌套的话，默认类型不会做什么，被嵌套的类会调用该类的析构函数




// 拷贝构造
//#include <iostream>
//using namespace std;
//class Data
//{
//public:
//	Data(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Data()" << ":" << this << endl;
//	}
//	
//	// Data d2(d1);
//	Data(const Data& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		//d._day = _day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void func(Data d)
//{
//}
//
//int main()
//{
//	Data d1(2023, 11, 15);
//	//Data d2(2023, 11, 15);
//	Data d2(d1);// 拷贝构造
//	
//	func(d2);
//
//	return 0;
//}



// 运算符的重载

#include <iostream>
using namespace std;
class Data
{
public:
	Data(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Data()" << ":" << this << endl;
	}
	
	// Data d2(d1);
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		//d._day = _day;
	}

//private:
	int _year;
	int _month;
	int _day;
};

//bool IsDataEqual(const Data& d1, const Data& d2)
//{
//	//...
//}

// 运算符有几个操作数，operater重载的函数就有几个参数
bool operator==(const Data& d1, const Data& d2)
{
	return d1._year  == d2._year
		&& d1._month == d2._month
		&& d1._day   == d2._day;
}

int main()
{
	Data d1(2023, 11, 15);
	Data d2(2023, 11, 16);
	// 在这个地方，加入想要比较大小相等
	d1 == d2; // operator==(d1, d2); 
	// 一般不会这样写，因为可读性不好
	//d1 > d2;
	return 0;
}


// 虽然解决了问题，但是这里我们将访问限定符改变成了公有，但是将上不应该修改
