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