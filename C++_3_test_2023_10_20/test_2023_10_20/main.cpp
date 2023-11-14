//#include <iostream>
//using namespace std;

/*
c with classes
*/

// 封装
// 1.将数据和方法放到定义一起
// 2.把想给你看到的数据定义成给你看，不想给你看的封装起来  ->  访问限定符
// 
//
//class Stack
//{
//	//1.成员函数   
//public:
//	void Push(int x) // 在类里面定义
//	{
//		// ... 
//	}
//	// 在类里面声明，在类外面定义
//	void Pop();
//	bool Empty(); 
//
//	//2.成员变量
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//// 在类外面定义
//void Stack::Pop()
//{
//	// ...
//}
//
//// 1.C语言中struct 是来用来定义结构体的
//// 2.C++中，兼容C的struct定义结构体的用法，但是同时struct可以用来定义类
//// 3.C++中，使用class 和 struct 定义类的区别在于：
////     默认的访问限定符，struct 默认是public
////                      class 默认是private
////
//struct ListNode_C
//{
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//};
//
//struct ListNode_CPP
//{
//	int _val;
//	struct ListNode_CPP* _next; // 兼容C语言的用法
//	ListNode_CPP* _prev;        // C++当成类的用法
//
//	// 这里面还可以定义函数 -> 成员函数
//	ListNode_CPP* CreatNode(int val);
//};
//
///*
//
//类的实例化
//
//*/
//// 声明和定义的区别是什么？
//// 声明可以理解成一种承诺，但是还没有做。
//// 定义呢，就是把这个承诺落地了
//// 施工图 与 建筑物的 关系
////
//
//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//	//char _ch;
//};
//
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//
//
//
//int main()
//{
//	// 类实例化出对象,相当于定义出了类的成员的变量
//	Stack s1;
//	Stack s2;
//	Stack s3;
//
//	// s1._a = nullptr; //err
//	s1.Push(1);
//
//	// 类的大小的计算：
//	// 类实例化的对象中，只存储成员变量，不存储成员函数
//	// why 我的想法：函数功能比较单一，存储的话浪费空间，变量因为不同所以要存储。或者就是内联函数，因为将函数展开了
//	
//	// 函数要用是通过this指针拿的 
//	// 函数是在代码区
//	// 真正的原因：一个类实例化出N个对象，每个对象的成员变量都可以存储不同的值，但是调用的函数却是同一个
//	// 如果每个对象都放成员函数，而这些函数却是一样的，浪费空间
//
//	cout << sizeof(s1) << endl;
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	// 没有成员变量的类，类的大小是1字节，哪为什么是1？而不是0
//	// 
//	A2 a2;
//	A2 aa2;
//	A2 aaa2;
//	// 如果大小是 0 怎么取地址 ？
//	// 这个地方开1个字节不是为了存放数据，是为了占位
//	return 0;
//}





//#include <iostream>
//using namespace std;
//
//class Data
//{
//
//public:
//	void init(int year, int month, int day)
//	// void init(Data*this, int year, int month, int day)
//	{
//		// 这个地方也体现了一下为什么要给成员变量加_
//		//year = year;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void prinf()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

// 隐含的 this 指针
/*
void prinf()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
被处理成：
void prinf(Data* this)
{
	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
}

d1.print();
被处理成：
d1.print(&d1); 谁调用就是谁的成员变量

位置一定是第一个位置，这个是约定好的，最后一个入栈
*/
//int main()
//{
//	Data d1;
//	d1.init(2023, 10, 20);
//	d1.prinf();
//	return 0;
//}
/*

this 指针存在哪里？
	栈上的（因为他是一个形参，ps：vs下是ecx寄存器传递）

*/



//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//	void Show()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();    //p->Print(p); 
//	//p->Show();
//	// 这个地方 p -> 
//	// 他不解引用，因为两个函数是存在公共代码段，不用去p指向的地址中找，而是去公共代码段找
//	// 访问成员变量，才会去找	
//	A a;
//	a.Print(); //a.Print(&a);
//	return 0;
//}

/*



*/

//#include <iostream>
//using namespace std;
//
//class Data
//{
//
//public:
//	//Data(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	//Data()
//	//{
//	//	_year = 0;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	
//	// 调用冲突
//
//	// 更好的方式 全缺省参数
//	Data(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	void init(int year, int month, int day)
//	{
//		// 构造函数 -> 在对象构造的时候调用的函数，这个函数
//		/*
//		构造函数是特殊的成员函数，需要注意的是，构造函数虽然名称叫构造，但是构造函数的主要任
//		务并不是开空间创建对象，而是初始化对象。
//		其特征如下：
//		1. 函数名与类名相同。
//		2. 无返回值。
//		3. 对象实例化时编译器自动调用对应的构造函数。
//		4. 构造函数可以重载。
//		*/
//		_year = year;
//		_month = month;
//		_day = day;
//
//		/*
//		5. 如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦
//			用户显式定义编译器将不再生成。
//		*/
//
//		/*
//		
//		无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
//		注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为
//		是默认构造函数。
//		
//		*/
//
//		/*
//		
//		关于编译器生成的默认成员函数，很多童鞋会有疑惑：不实现构造函数的情况下，编译器会
//		生成默认的构造函数。但是看起来默认构造函数又没什么用？d对象调用了编译器生成的默
//		认构造函数，但是d对象_year/_month/_day，依旧是随机值。也就说在这里编译器生成的
//		默认构造函数并没有什么用？？
//		解答：C++把类型分成内置类型(基本类型)和自定义类型。内置类型就是语言提供的数据类
//		型，如：int/char...，自定义类型就是我们使用class/struct/union等自己定义的类型，看看
//		下面的程序，就会发现编译器生成默认的构造函数会对自定类型成员_t调用的它的默认成员
//		函数。
//		
//		class 中 调用 class 
//
//		无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
//		注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为
//		是默认构造函数。
//
//		*/
//	}
//	
//	void prinf()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Data d1(2023, 10, 20);
//	Data d2;
//	//Data d2();
//	// 这里不能加 () 加了括号编译器不认识了
//	d1.prinf();
//
//	//d1.init(2023, 10, 21);
//	//d2.init(2023, 10, 21);
//	
//	d2.prinf();
//
//	return 0;
//}

/*

对象生命周期到了以后，自动调用；完成对象里面资源的清理(free)，不是完成销毁动作(销毁动作是由函数栈帧控制的)


析构函数是特殊的成员函数，其特征如下：
1. 析构函数名是在类名前加上字符 ~。
2. 无参数无返回值类型。
3. 一个类只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。注意：析构
函数不能重载
4. 对象生命周期结束时，C++编译系统系统自动调用析构函数

5. 关于编译器自动生成的析构函数，是否会完成一些事情呢？下面的程序我们会看到，编译器
生成的默认析构函数，对自定类型成员调用它的析构函数。

6.如果类中没有申请资源时，析构函数可以不写，直接使用编译器生成的默认析构函数，比如
Date类；有资源申请时，一定要写，否则会造成资源泄漏，比如Stack类。

*/