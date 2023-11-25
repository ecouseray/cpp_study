#include <iostream>
#include <typeinfo>
using namespace std;

// const 修饰的变量类型是 距离 const 最近的变量类型
// const int* p;
// const 修饰的类型是 int ，将 int 拿走，剩下的就是 const 修饰的表达式 

// const是否参与类型，是看const右边是否还有 * ；
#if 0
int main()
{
	const int a = 10;
	int* p = (int*)&a;

	*p = 20;
	printf("%d %d %d \n", a, *p, *(&a));
	// 替换 C++中const任然可改
	return 0;
}
#endif



/*

const 与 一级指针的结合：两种

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

const 与 二级指针的结合：三种

*/


int main()
{
	int a = 10;
	int* p = &a;
	const int** q = &p; // 会将常量的地址给到普通变量
	// 假设可以：
	// *q == p
	// const int b = 20;
	// *q = &b
	// p = &b;
	// int* <= const int* err
	return 0;
}