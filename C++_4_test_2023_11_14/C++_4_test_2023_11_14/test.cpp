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

// ������м�����������operater���صĺ������м�������
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
	// ������ط���������Ҫ�Ƚϴ�С���
	d1 == d2; // operator==(d1, d2); 
	// һ�㲻������д����Ϊ�ɶ��Բ���
	//d1 > d2;
	return 0;
}


// ��Ȼ��������⣬�����������ǽ������޶����ı���˹��У����ǽ��ϲ�Ӧ���޸�
