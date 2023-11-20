// 6��Ĭ�ϳ�Ա����
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
	~Data() // ������Դ��(���������)
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
	// ���󴴽�ʱ���Զ����ã���ɳ�ʼ������
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int) * n);
		_size = 0;
		_capacity = n;
	}
	// �����������ڵ����Ժ����������
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
	//Data d1; // 1.���ǲ�д�������Զ����� 2.ȫȱʡ 3.�޲εģ�����һ�� -- Ĭ�Ϲ��캯�� -- �����ξͿ��Ե��õ�
	// Data d1(&d1); -- this ָ��
	//Data d2;
	// d1 �ȹ��죬d2 ���죬d2 ��������d1 ������
	// �������ڽ����Զ����ã�ջ�ռ䣬�Ƚ����

	Stack st;

	// ���캯��������ɳ�ʼ���Ĺ����������Ƕ�׵Ļ���Ĭ�����Ͳ����ʼ������Ƕ�׵�����ʼ��
	// ���������������������Դ�Ĺ����������Ƕ�׵Ļ���Ĭ�����Ͳ�����ʲô����Ƕ�׵������ø������������

	return 0;
}

*/

// ���캯��������ɳ�ʼ���Ĺ����������Ƕ�׵Ļ���Ĭ�����Ͳ����ʼ������Ƕ�׵�����ʼ��
// ���������������������Դ�Ĺ����������Ƕ�׵Ļ���Ĭ�����Ͳ�����ʲô����Ƕ�׵������ø������������




// ��������
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
//	Data d2(d1);// ��������
//	
//	func(d2);
//
//	return 0;
//}



// �����������

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
//	// ������м�����������operater���صĺ������м�������
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

// �Զ��������ǲ���ʹ��������ģ�Ҫ�þ͵�ʵ�����غ������Զ��������õ�ʹ�õȼ��ڵ���������غ���
//int main()
//{
//	Data d1(2023, 11, 15);
//	Data d2(2023, 11, 16);
//	// ������ط���������Ҫ�Ƚϴ�С���
//	d1 == d2; // d1.operator==(d2);
//	// operator==(d1, d2); 
//	// һ�㲻������д����Ϊ�ɶ��Բ���
//
//	d1 > d2;  // d1.operator>(d2);
//	return 0;
//}


// ��Ȼ��������⣬�����������ǽ������޶����ı���˹��У����ǽ��ϲ�Ӧ���޸�


// ʵ��һ�����Ƶ�������
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
			cout << "�Ƿ�����" << endl;
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

	// ���õ����ƣ��ھ۸ߣ�ά����ǿ
	bool operator<=(const Data& d)
	{
		// ���������ʵ��
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
	//��Ϊ�����this��������ڵģ����Կ����Ż���Data&
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


// �Ƿ�����һ���������Ҫ�����������Ƿ�������Ķ���������
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



























// ���̵������ַ�ռ�
// 
// ָ��������ʱ�������Ǹ�����
// ����� or .text��
// 0x00000000
// 
// 0x08048000  // use space   4GB
// 
// 
//   // .text��    
//             // .rodata(ֻ��) -> "Hello World!"
//             // .data -> ��ʼ���˵ģ����ҳ�ʼ����ֵ��Ϊ���
//             // .bss  -> û��ʼ���� �� ��ʼ����ֵΪ���
//             
//             // .heap
//           
//             // ���ع���� *.dll    *.so
// 
//             // .stack
// 
// 0xc0000000  // �����в��� �� ��������
// 
// 0xffffffff  //kernal space 1GB
//     ZONE_DMA      16M
//     ZONE_NORMAL   800��M
//     ZONE_HIGHMEN  �߶��ڴ棬ӳ��ߵ�ַ�������ڴ�ʱ������ӳ����
// 
// ȫ�ֱ����ڱ����Ժ� ������ ���ű����γɷ���
// �ֲ������ڱ����Ժ� ���� .text�� ������ָ��
// ��̬�ֲ����� Ҳ���� .data�� �����ڳ���������ʱ�򲻻��ʼ��
// ��һ�����е����ǵ�ʱ���ڳ�ʼ��
// ���� 0 �� !0 �Ĵ��λ��
// 
// int a = 12;
// ����֮�����ɵ���ָ������.text���У���������ִ�е�ʱ����ջ����4���ֽڵĿռ���
// 
// ÿһ�����̵��û��ռ���˽�еģ��ں˿ռ��ǹ����
// QQ�������ơ�VS ...
// 
// ����֮���ͨ�ŷ�ʽ����Щ��
// �����ܵ�ͨ��
//



// 





