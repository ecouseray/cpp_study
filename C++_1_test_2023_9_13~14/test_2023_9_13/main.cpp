#define _CRT_SECURE_NO_WARNINGS 

/*
	命名空间
	缺省参数
	函数重载
	引用
*/


// 命名空间
// C语言没办法解决类似这样的命名冲突问题，所以C++提出了namespace来解决
// 命名空间中可以定义变量/函数/结构体类型
// 
// 命名空间可以嵌套
// 
// 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
// 
// 一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中
//
// std是C++标准库的命名空间名，C++将标准库的定义实现都放到这个命名空间中


//#include <iostream>
//using namespace std;
//// 上面一行代码的意思：c++库中所有的东西都是放到std命名空间中的
//// 如果定义到了和库里面重名的东西，会冲突,可以通过定义自己的命名空间解决
//
//namespace n
//{
//	int a = 10;
//	int b = 20;
//	int ADD(int a, int b)
//	{
//		return a + b;
//	}
//}
//
////using n::b;// 第二种：展开命名空间中的一个成员
////using namespace n; // 第三种：展开命名空间
//int main(void)
//{
//	//printf("%d", a);
//	printf("%d", n::a);// 第一种：加命名空间名称及作用域限定符
//	return 0;
//}


//#include <iostream>
//// 在日常练习中，不在乎与库命名冲突，可以将std 整个展开
//using namespace std;
//
//int main()
//{
//	// cout 可以自动识别类型
//	cout << "Hello World!" << endl;
//	int i = 1;
//	double d = 1.11;
//	cout << i << " " << d << endl;
//	return 0;
//}


//#include <iostream>
//// 在日常练习中，不在乎与库命名冲突，可以将std 整个展开
////using namespace std;
//int cout = 10;
//int main()
//{
//	// cout 可以自动识别类型
//	std::cout << "Hello World!" << std::endl;
//	int i = 1;
//	double d = 1.11;
//	std::cout << i << " " << d << " " << cout << std::endl;
//	return 0;
//}

//#include <iostream>
//// 在日常练习中，不在乎与库命名冲突，可以将std 整个展开
//// 
//// 工程中常用的：常用的库里面一些对象或者类型可以展开
////
////using namespace std;
//using std::cout;
//using std::endl;
//using std::cin;
//int main()
//{
//	
//	cout << "Hello World!" << endl;
//	int i = 1;
//	double d = 1.11;
//	cout << i << " " << d << endl;
//
//	cin >> i >> d;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "Hello World!" << endl;
//	return 0;
//}


// 缺省参数
// 缺省参数是声明或定义函数时为函数的参数指定一个缺省值。在调用该函数时，如果没有指定实参则采用该形参的缺省值，否则使用指定的实参。

//#include <iostream>
//using namespace std;
//
//// 缺省参数 =》 备胎
//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//
//// 全缺省，半缺省(缺省部分参数)
//
//// 全缺省
//void Func1(int a = 10, int  b = 20, int c = 0)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	
//}
//
//// 半缺省， 从右往左连续缺省
//void Func2(int a, int  b = 20, int c = 0)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//
//}
//int main()
//{
//	//Func();
//	//Func(10);
//	Func1();
//	Func1(20, 10);
//	// 调用时候，传参数的时候，必须从左向右依次传参，不能中间空缺
//	return 0;
//}



// 函数重载：是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，这
// 些同名函数的形参列表(参数个数 或 类型 或 类型顺序)不同，常用来处理实现功能类似数据类型
// 不同的问题。


// 函数名相同，参数不同（参数个数，参数类型，参数顺序）
//#include <iostream>
//using namespace std;
//
//void func()
//{
//}
//void func(int a)
//{
//}
//void func(char a)
//{
//}
//
//// 如果只是返回值不同，是不能构成重载的
////void func1(int a)
////{}
////int func1(int a)
////{}
//
//// 10L,的类型是 long
//int main()
//{
//	// 调用的时候，类型会自动识别
//	return 0;
//}

// 面试问题：1.什么是函数重载
// 在C++当中，函数名称相同，参数不同（个数、类型、参数顺序），对返回值没有要求
// 
// 2.C++是如果支持函数重载的，为什么C语言不支持
// 
// 
// 
// 
// 
// 引用：
//

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	int& ra = a; // 表示ra 是 a 的引用，引用也就是别名，就是给a再取了一个名称，ra
//	int& b = a;
//	int& c = b;
//	c = 20;
//
//	int d = 2;
//	c = d;  // 这句话的意思是，将d的值赋值给c？ 还是将 c 修改为 d 的别名呢？
//	// 一旦引用确定后，就再不可以称为别的变量的引用（再不能引用别的实体）
//
//	cout << c << endl;
//	return 0;
//}
// 引用必须在定义的时候初始化，一个变量可以有多个变量



#include <iostream>
using namespace std;

//int main()
//{
//	int a = 10;
//	int& b = a;
//	// b的类型是什么呢？  ——int
//
//	const int x = 10;  
//	// int& y = x;
//	// 编译不通过，原因：x是只读的，y是可读可写的，所以不行，那怎么给x取别名呢？
//	const int& y = x;
//
//
//	int c = 1;
//	int& d = c;
//	const int& e = c;  // 这样行不行？
//	// 这样是可以的，因为：c是可读可写的，e变成别名，赋予的意义是只读的，所以是可以的
//	// 总结：引用取别名时候，变量访问的权限可以缩小，但是不行放大。	
//
//	return 0;
//}


int main()
{
	int i = 10;
	double d = i; // 隐式的类型转换，编译器运行。

	//float& rd = i; // 这个地方与大小没有关系
	// 上面一行代码 语法不允许，但是 加上const 就行了，怎么解释?
	const float& rd = i;
	


	return 0;
}