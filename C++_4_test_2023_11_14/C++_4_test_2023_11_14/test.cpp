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
//	// 运算符有几个操作数，operater重载的函数就有几个参数
//	// operator==(&d1, d2)
//	bool operator==(const Data& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	// bool operator(Data* d1, const Data& d2)
//	bool operator>(const Data& d)
//	{
//		if (this->_year > d._year)
//			return true;
//		if (this->_year == d._year)
//			if (_month > d._month)
//				return true;
//		if (this->_year == d._year)
//			if (_month = d._month)
//				if (_day > d._day)
//					return true;
//
//		return false;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//bool IsDataEqual(const Data& d1, const Data& d2)
//{
//	//...
//}

// 自定义类型是不能使用运算符的，要用就得实现重载函数，自定义类型用的使用等价于调用这个重载函数
//int main()
//{
//	Data d1(2023, 11, 15);
//	Data d2(2023, 11, 16);
//	// 在这个地方，加入想要比较大小相等
//	d1 == d2; // d1.operator==(d2);
//	// operator==(d1, d2); 
//	// 一般不会这样写，因为可读性不好
//
//	d1 > d2;  // d1.operator>(d2);
//	return 0;
//}


// 虽然解决了问题，但是这里我们将访问限定符改变成了公有，但是将上不应该修改


// 实现一个完善的日期类
#include <iostream>
using namespace std;

class Data
{
public:
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return days[2] + 1;

		return days[month];
	}

	Data(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0
			&& month >= 1 && month <= 12 && day >= 0
			&& day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}

	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Data& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const Data& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// 复用的优势，内聚高，维护性强
	bool operator<=(const Data& d)
	{
		// 复用上面的实现
		return (*this < d) || (*this == d);
	}

	bool operator>(const Data& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Data& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Data& d)
	{
		return !(*this == d);
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Data operator+(int day)
	{
		Data ret = *this;
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}
	//Data operator+=(int day)
	Data& operator+=(int day)
	//因为这里的this是外面存在的，所以可以优化成Data&
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	Data& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			_day += GetMonthDay(_year, _month);
			
			if (_month == 0)
			{
				_year--;
				_month = 13;
			}
		}
		return *this;
	}

	Data& operator++()
	{
		*this += 1;
		return *this;
	}
	Data& operator--()
	{
		*this -= 1;
		return *this;
	}
	int operator-(const Data& d)
	{
		if (*this < d)
			return -1;
		if (*this == d)
			return 0;

		int ret = 0;

	}
private:
	int _year;
	int _month;
	int _day;
};


// 是否重载一个运算符，要看这个运算符是否对这个类的对象有意义
int main()
{
	Data d1(2003, 1, 23);
	d1.print();
	Data d2(2023, 2, 28);
	d2.print();

	Data d3 = d2 + 10;
	d3.print();

	Data d5 = d1 + 30000;
	d5.print();

	Data d4(2003, 1, 1);
	--d4;
	d4.print();
	return 0;
}



























// 进程的虚拟地址空间
// 
// 指令在运行时候存放在那个区域？
// 代码段 or .text段
// 0x00000000
// 
// 0x08048000  // use space   4GB
// 
// 
//   // .text段    
//             // .rodata(只读) -> "Hello World!"
//             // .data -> 初始化了的，并且初始化的值不为零的
//             // .bss  -> 没初始化的 和 初始化的值为零的
//             
//             // .heap
//           
//             // 加载共享库 *.dll    *.so
// 
//             // .stack
// 
// 0xc0000000  // 命令行参数 和 环境变量
// 
// 0xffffffff  //kernal space 1GB
//     ZONE_DMA      16M
//     ZONE_NORMAL   800多M
//     ZONE_HIGHMEN  高端内存，映射高地址的物理内存时做物理映射用
// 
// 全局变量在编译以后 都会在 符号表中形成符号
// 局部变量在编译以后 会在 .text段 中生成指令
// 静态局部变量 也放在 .data段 但是在程序启动的时候不会初始化
// 第一次运行到他们的时候在初始化
// 符合 0 和 !0 的存放位置
// 
// int a = 12;
// 编译之后，生成的是指令，存放在.text段中，他在运行执行的时候，在栈上找4个字节的空间存放
// 
// 每一个进程的用户空间是私有的，内核空间是共享的
// QQ、网易云、VS ...
// 
// 进程之间的通信方式有哪些？
// 匿名管道通信
//



// 





