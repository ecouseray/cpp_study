//#include <iostream>
//int main()
//{
//	std::cout << "HelloWorld!" << std::endl;
//	return 0;
//}

#include <iostream>
using namespace std;
//int main()
//{
//	int i = 10;
//	int& b = i;
//	b = 1024;
//	int& c = b;
//	cout << b << endl;
//	return 0;
//}


//int main()
//{
	// 权限的缩小
	//int i = 10;
	//int& b = i;
	//const int& c = b;
	// 权限的扩大
	//const int num1 = 10;
	//int& num2 = num1;

	//int x = 10.0;
	//int& y = x;

	// 权限的放大和缩小只适用于：引用和指针之间


	//const int i = 10;
	//int* pi = &i;
	
	//const int i = 10;
	//int& pi = i;

	//return 0;
//}


//int main()
//{
//	const double& b = 12.34;
//
//	const double& rb = b;
//	// 这个地方没有引用b，而是引用了中间变量
//	return 0;
//}


// 1.引用做参数
//void swap_c(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//// 引用的时候必须初始化
//// 传参数的时候才在初始化
//// 只要在同一个进程地址空间就可以做到，即使不在同一个栈帧
//void swap_cpp(int& p1, int& p2)
//{
//	int tmp = p1;
//	p1 = p2;
//	p2 = tmp;
//}
//int main() 
//{
//	int a = 0, b = 1;
//
//	swap_c(&a, &b);
//	printf("a = %d, b = %d\n", a, b);
//	swap_cpp(a, b);
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//int func1()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//// 在传值的时候，无论是参数还是返回值，都是会创建临时变量,凡是临时变量都具有常性
//int& func2(int a, int b)
//{
//	static int i = a + b; // 第二次进入函数的时候，此行再不执行，本函数就只看剩下的代码
//	return i;
//}
//// 这里不加static返回func2的栈帧被销毁，i所对应的空间并没有被销毁，而是使用权不是func2函数的了
//
//int main()
//{
//	static int x = 10;
//	//int& tmp1 = func1();
//	// 这个地方报错是因为，func1返回是n的临时变量，临时变量具有常性，所以加const就可以
//	const int& tmp1 = func1();
//	int& tmp2 = func2(2, 3);
//	//tmp2 = 100;
//	//tmp2 = 200;
//	printf("HelloWorld\n");
//	printf("%d\n", tmp2);
//
//	return 0;
//}
// 一个函数要使用引用返回，返回变量出了这个函数的作用域还存在(使用权还在)，
// 就可以引用返回，不然不安全（static的在这个地方的意义）
// 好处：少拷贝创建一个临时变量，提高效率
// 使用在传参，和返回值 用引用



/*

内联函数：
	在调用他的地方展开

	频繁调用函数需要建立栈帧，是有开销的
	C语言中 使用宏函数解决
	C++中   使用内联函数  展开，就是和宏替换那种展开一样

	适用与小函数 ( 20 行左右 )
	递归和较长的函数不适用

	空间还时间的做法

	C++中 inline 也是一种建议性的

	定义 和 声明不要分离
	展开之后没有地址，但是在链接是时候要去找他的地址
*/



/*

auto 关键字 自动推导变量
	

*/

//int main()
//{
//	int a = 0;
//	auto b = a; // b的类型是根据a的类型推导的
//	int& c = b;
//
//	auto& d = a;
//	auto* e = &a;
//	auto* f = &a;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	cout << typeid(f).name() << endl;
//	{
//		auto a = 1, b = 2;
//		//auto c = 3, d = 3.14; // err，同一行不可以推两种类型
//	}
//	{
//		//auto 不能作为参数 不能创建数组
//	}
//	{
//		// aotu 真正的作用？
//		// 
//	}
//	return 0;
//}


/*

范围 for

*/

//int main()
//{
//	int arr[] = { 1,3,5,7 };
//	// 要求将数据中的值 * 2 ，在打印一边
//
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	// 语法糖：写起来便捷
//	// 基于arr 的元素个数来遍历， 每次将元素给到e
//	// 这个地方不加 & 的话 里面的值不会改变，因为每个元素给到e，e改变不会影响arr数组，所以要加&
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 放在函数中不可以用了，因为放在函数中就不是数组了，而是首元素地址，范围for必须是数组
//	return 0;
//}


//int main()
//{
//	int* p = NULL;
//
//	// C++ 中 NULL是 0 不能更好的代表 空指针
//	// C语言中 这里是 (void*)0
//
//	// C++11 中推荐，像下面这样写
//	int* p2 = nullptr;//(void*)0
//	// 因为在向函数传参的时候 NULL 在函数重载传参的时候，会传入 int类型中，不是int* 
//	// nullptr 在重载的时候，传入int* 类型
//	return 0;
//}



/*

面向对象引入：
	类和对象
		简易理解对象，声明了的，开辟空间的都是对象

	面向过程，关注的是处理，解决问题的过程，(流程)
	面向对象，关注的是对象，对象之间的关系，

	C++中 结构体里面，不仅仅可以定义变量，还可以定义函数	
	可以用 class 代替



*/
// 类里面可以定义，1.成员变量，2.成员方法(函数)
class Person
{
private:
	char* _name;
	char* _sex;
	int _age;

	// 定义在类里面的函数，默认是内联函数
	void eatFood()
	{
		printf("吃饭\n");
	}

	// 定义在头文件里面，实现在源文件里面

	// 类的访问限定符以及封装
	// private:
	// pubilc:
	// protected:
	// 一般情况下，成员变量是比较隐私的，都会定义成保护或者私有
	
	// 类外无法访问私有的	, 类内不受限制，限定的是两个限定符之间的元素，没有第二个元素就限制到大括号之前

	// C++中 class 和 struct 都可以用来定义类
	// class 默认访问类型是 私有的， struct 默认是公有的
	// 因为C++兼容C

	// 封装 继承 多态

	// 类可以定义出一个作用，在将定义和声明分开写的时候要写 ::
};

