#include <iostream>
#include <typeinfo>
using namespace std;

// const ���εı��������� ���� const ����ı�������
// const int* p;
// const ���ε������� int ���� int ���ߣ�ʣ�µľ��� const ���εı��ʽ 

// const�Ƿ�������ͣ��ǿ�const�ұ��Ƿ��� * ��
#if 0
int main()
{
	const int a = 10;
	int* p = (int*)&a;

	*p = 20;
	printf("%d %d %d \n", a, *p, *(&a));
	// �滻 C++��const��Ȼ�ɸ�
	return 0;
}
#endif



/*

const �� һ��ָ��Ľ�ϣ�����

*/
#if 0
int main()
{
	int a = 10;
	const int* p = &a;
	int const* p = &a;
	int* const p = &a;
	return  0;
}
#endif
// int ** <= const int **  err
// const int ** <= int **  err
//
/*

const �� ����ָ��Ľ�ϣ�����

*/


int main()
{
	int a = 10;
	int* p = &a;
	const int** q = &p; // �Ὣ�����ĵ�ַ������ͨ����
	// ������ԣ�
	// *q == p
	// const int b = 20;
	// *q = &b
	// p = &b;
	// int* <= const int* err
	return 0;
}