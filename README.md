# C/C++ 面{U+8BD5}知{U+8BC6}{U+603B}{U+7ED3}

C/C++ 面{U+8BD5}知{U+8BC6}{U+603B}{U+7ED3}，只{U+4E3A}複{U+4E60}、分享。部分知{U+8BC6}{U+70B9}與{U+56FE}片{U+6765}自網{U+7EDC}，侵{U+5220}。

勘{U+8BEF}新增{U+8BF7} Issue、PR，建{U+8BAE}、{U+8BA8}{U+8BBA}{U+8BF7} [#issues/12](https://github.com/huihut/interview/issues/12)，排版使用 [中文文案排版指北](https://github.com/mzlogin/chinese-copywriting-guidelines)

使用建{U+8BAE}：

* `Ctrl + F`：快速查找定位知{U+8BC6}{U+70B9}
* `TOC {U+5BFC}航`：[jawil/GayHub](https://github.com/jawil/GayHub) 插件快速目{U+5F55}跳{U+8F6C}

## 目{U+5F55}

* [C/C++](#cc)
* [STL](#stl)
* [{U+6570}據{U+7ED3}構](#%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84)
* [算法](#%E7%AE%97%E6%B3%95)
* [Problems](#problems)
* [操作系{U+7EDF}](#%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F)
* [{U+8BA1}算機網{U+7EDC}](#%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C)
* [網{U+7EDC}{U+7F16}程](#%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B)
* [{U+6570}據{U+5E93}](#%E6%95%B0%E6%8D%AE%E5%BA%93)
* [{U+8BBE}{U+8BA1}模式](#%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F)
* [{U+94FE}接{U+88C5}{U+8F7D}{U+5E93}](#%E9%93%BE%E6%8E%A5%E8%A3%85%E8%BD%BD%E5%BA%93)
* [海量{U+6570}據{U+5904}理](#%E6%B5%B7%E9%87%8F%E6%95%B0%E6%8D%AE%E5%A4%84%E7%90%86)
* [音{U+89C6}{U+9891}](#%E9%9F%B3%E8%A7%86%E9%A2%91)
* [其他](#%E5%85%B6%E4%BB%96)
* [{U+4E66}籍](#%E4%B9%A6%E7%B1%8D)
* [複{U+4E60}刷{U+9898}網站](#%E5%A4%8D%E4%B9%A0%E5%88%B7%E9%A2%98%E7%BD%91%E7%AB%99)
* [招聘{U+65F6}{U+95F4}{U+5C97}位](#%E6%8B%9B%E8%81%98%E6%97%B6%E9%97%B4%E5%B2%97%E4%BD%8D)
* [面{U+8BD5}{U+9898}目{U+7ECF}{U+9A8C}](#%E9%9D%A2%E8%AF%95%E9%A2%98%E7%9B%AE%E7%BB%8F%E9%AA%8C)

## C/C++

### const

#### 作用

1. 修{U+9970}{U+53D8}量，{U+8BF4}明{U+8BE5}{U+53D8}量不可以被改{U+53D8}；
2. 修{U+9970}指{U+9488}，分{U+4E3A}指向常量的指{U+9488}和指{U+9488}常量；
3. 常量引用，{U+7ECF}常用於形{U+53C2}{U+7C7B}型，即避免了拷{U+8D1D}，又避免了函{U+6570}{U+5BF9}值的修改；
4. 修{U+9970}成{U+5458}函{U+6570}，{U+8BF4}明{U+8BE5}成{U+5458}函{U+6570}{U+5185}不能修改成{U+5458}{U+53D8}量。

#### 使用

<details><summary>const 使用</summary> 

```cpp
// {U+7C7B}
class A
{
private:
    const int a;                // 常{U+5BF9}象成{U+5458}，只能在初始化列表{U+8D4B}值

public:
    // 構造函{U+6570}
    A() { };
    A(int x) : a(x) { };        // 初始化列表

    // const可用於{U+5BF9}重{U+8F7D}函{U+6570}的{U+533A}分
    int getValue();             // 普通成{U+5458}函{U+6570}
    int getValue() const;       // 常成{U+5458}函{U+6570}，不得修改{U+7C7B}中的任何{U+6570}據成{U+5458}的值
};

void function()
{
    // {U+5BF9}象
    A b;                        // 普通{U+5BF9}象，可以{U+8C03}用全部成{U+5458}函{U+6570}
    const A a;                  // 常{U+5BF9}象，只能{U+8C03}用常成{U+5458}函{U+6570}、更新常成{U+5458}{U+53D8}量
    const A *p = &a;            // 常指{U+9488}
    const A &q = a;             // 常引用

    // 指{U+9488}
    char greeting[] = "Hello";
    char* p1 = greeting;                // 指{U+9488}{U+53D8}量，指向字符{U+6570}{U+7EC4}{U+53D8}量
    const char* p2 = greeting;          // 指{U+9488}{U+53D8}量，指向字符{U+6570}{U+7EC4}常量
    char* const p3 = greeting;          // 常指{U+9488}，指向字符{U+6570}{U+7EC4}{U+53D8}量
    const char* const p4 = greeting;    // 常指{U+9488}，指向字符{U+6570}{U+7EC4}常量
}

// 函{U+6570}
void function1(const int Var);           // {U+4F20}{U+9012}{U+8FC7}{U+6765}的{U+53C2}{U+6570}在函{U+6570}{U+5185}不可{U+53D8}
void function2(const char* Var);         // {U+53C2}{U+6570}指{U+9488}所指{U+5185}容{U+4E3A}常量
void function3(char* const Var);         // {U+53C2}{U+6570}指{U+9488}{U+4E3A}常指{U+9488}
void function4(const int& Var);          // 引用{U+53C2}{U+6570}在函{U+6570}{U+5185}{U+4E3A}常量

// 函{U+6570}返回值
const int function5();      // 返回一{U+4E2A}常{U+6570}
const int* function6();     // 返回一{U+4E2A}指向常量的指{U+9488}{U+53D8}量，使用：const int *p = function6();
int* const function7();     // 返回一{U+4E2A}指向{U+53D8}量的常指{U+9488}，使用：int* const p = function7();
```

</details>

### static

#### 作用

1. 修{U+9970}普通{U+53D8}量，修改{U+53D8}量的存{U+50A8}{U+533A}域和生命周期，使{U+53D8}量存{U+50A8}在{U+9759}{U+6001}{U+533A}，在 main 函{U+6570}{U+8FD0}行前就分配了空{U+95F4}，如果有初始值就用初始值初始化它，如果{U+6CA1}有初始值系{U+7EDF}用默{U+8BA4}值初始化它。
2. 修{U+9970}普通函{U+6570}，表明函{U+6570}的作用範{U+56F4}，{U+4EC5}在定{U+4E49}{U+8BE5}函{U+6570}的文件{U+5185}才能使用。在多人{U+5F00}{U+53D1}{U+9879}目{U+65F6}，{U+4E3A}了防止與他人命令函{U+6570}重名，可以{U+5C06}函{U+6570}定位{U+4E3A} static。
3. 修{U+9970}成{U+5458}{U+53D8}量，修{U+9970}成{U+5458}{U+53D8}量使所有的{U+5BF9}象只保存一{U+4E2A}{U+8BE5}{U+53D8}量，而且不需要生成{U+5BF9}象就可以{U+8BBF}{U+95EE}{U+8BE5}成{U+5458}。
4. 修{U+9970}成{U+5458}函{U+6570}，修{U+9970}成{U+5458}函{U+6570}使得不需要生成{U+5BF9}象就可以{U+8BBF}{U+95EE}{U+8BE5}函{U+6570}，但是在 static 函{U+6570}{U+5185}不能{U+8BBF}{U+95EE}非{U+9759}{U+6001}成{U+5458}。

### this 指{U+9488}

1. `this` 指{U+9488}是一{U+4E2A}{U+9690}含於每一{U+4E2A}非{U+9759}{U+6001}成{U+5458}函{U+6570}中的特殊指{U+9488}。它指向正在被{U+8BE5}成{U+5458}函{U+6570}操作的那{U+4E2A}{U+5BF9}象。
2. {U+5F53}{U+5BF9}一{U+4E2A}{U+5BF9}象{U+8C03}用成{U+5458}函{U+6570}{U+65F6}，{U+7F16}{U+8BD1}程序先{U+5C06}{U+5BF9}象的地址{U+8D4B}{U+7ED9} `this` 指{U+9488}，然後{U+8C03}用成{U+5458}函{U+6570}，每次成{U+5458}函{U+6570}存取{U+6570}據成{U+5458}{U+65F6}，由{U+9690}含使用 `this` 指{U+9488}。
3. {U+5F53}一{U+4E2A}成{U+5458}函{U+6570}被{U+8C03}用{U+65F6}，自{U+52A8}向它{U+4F20}{U+9012}一{U+4E2A}{U+9690}含的{U+53C2}{U+6570}，{U+8BE5}{U+53C2}{U+6570}是一{U+4E2A}指向{U+8FD9}{U+4E2A}成{U+5458}函{U+6570}所在的{U+5BF9}象的指{U+9488}。
4. `this` 指{U+9488}被{U+9690}含地{U+58F0}明{U+4E3A}: `ClassName *const this`，{U+8FD9}意味{U+7740}不能{U+7ED9} `this` 指{U+9488}{U+8D4B}值；在 `ClassName` {U+7C7B}的 `const` 成{U+5458}函{U+6570}中，`this` 指{U+9488}的{U+7C7B}型{U+4E3A}：`const ClassName* const`，{U+8FD9}{U+8BF4}明不能{U+5BF9} `this` 指{U+9488}所指向的{U+8FD9}種{U+5BF9}象是不可修改的（即不能{U+5BF9}{U+8FD9}種{U+5BF9}象的{U+6570}據成{U+5458}{U+8FDB}行{U+8D4B}值操作）；
5. `this` 並不是一{U+4E2A}常{U+89C4}{U+53D8}量，而是{U+4E2A}右值，所以不能取得 `this` 的地址（不能 `&this`）。
6. 在以下{U+573A}景中，{U+7ECF}常需要{U+663E}式引用 `this` 指{U+9488}：
    1. {U+4E3A}{U+5B9E}{U+73B0}{U+5BF9}象的{U+94FE}式引用；
    2. {U+4E3A}避免{U+5BF9}同一{U+5BF9}象{U+8FDB}行{U+8D4B}值操作；
    3. 在{U+5B9E}{U+73B0}一些{U+6570}據{U+7ED3}構{U+65F6}，如 `list`。

### inline {U+5185}{U+8054}函{U+6570}

#### 特征

* 相{U+5F53}於把{U+5185}{U+8054}函{U+6570}裏面的{U+5185}容{U+5199}在{U+8C03}用{U+5185}{U+8054}函{U+6570}{U+5904}；
* 相{U+5F53}於不用{U+6267}行{U+8FDB}入函{U+6570}的步{U+9AA4}，直接{U+6267}行函{U+6570}體；
* 相{U+5F53}於宏，{U+5374}比宏多了{U+7C7B}型{U+68C0}查，真正具有函{U+6570}特性；
* 不能包含循{U+73AF}、{U+9012}{U+5F52}、switch 等複{U+6742}操作；
* 在{U+7C7B}{U+58F0}明中定{U+4E49}的函{U+6570}，除了{U+865A}函{U+6570}的其他函{U+6570}都{U+4F1A}自{U+52A8}{U+9690}式地{U+5F53}成{U+5185}{U+8054}函{U+6570}。

#### 使用

<details><summary>inline 使用</summary> 


```cpp
// {U+58F0}明1（加 inline，建{U+8BAE}使用）
inline int functionName(int first, int secend,...);

// {U+58F0}明2（不加 inline）
int functionName(int first, int secend,...);

// 定{U+4E49}
inline int functionName(int first, int secend,...) {/****/};

// {U+7C7B}{U+5185}定{U+4E49}，{U+9690}式{U+5185}{U+8054}
class A {
    int doA() { return 0; }         // {U+9690}式{U+5185}{U+8054}
}

// {U+7C7B}外定{U+4E49}，需要{U+663E}式{U+5185}{U+8054}
class A {
    int doA();
}
inline int A::doA() { return 0; }   // 需要{U+663E}式{U+5185}{U+8054}
```

</details>

#### {U+7F16}{U+8BD1}器{U+5BF9} inline 函{U+6570}的{U+5904}理步{U+9AA4}

1. {U+5C06} inline 函{U+6570}體複制到 inline 函{U+6570}{U+8C03}用{U+70B9}{U+5904}； 
2. {U+4E3A}所用 inline 函{U+6570}中的局部{U+53D8}量分配{U+5185}存空{U+95F4}； 
3. {U+5C06} inline 函{U+6570}的的{U+8F93}入{U+53C2}{U+6570}和返回值映射到{U+8C03}用方法的局部{U+53D8}量空{U+95F4}中； 
4. 如果 inline 函{U+6570}有多{U+4E2A}返回{U+70B9}，{U+5C06}其{U+8F6C}{U+53D8}{U+4E3A} inline 函{U+6570}代{U+7801}{U+5757}末尾的分支（使用 GOTO）。

#### 優缺{U+70B9}

優{U+70B9}

1. {U+5185}{U+8054}函{U+6570}同宏函{U+6570}一{U+6837}{U+5C06}在被{U+8C03}用{U+5904}{U+8FDB}行代{U+7801}展{U+5F00}，省去了{U+53C2}{U+6570}{U+538B}{U+6808}、{U+6808}{U+5E27}{U+5F00}辟與回收，{U+7ED3}果返回等，{U+4ECE}而提高程序{U+8FD0}行速度。
2. {U+5185}{U+8054}函{U+6570}相比宏函{U+6570}{U+6765}{U+8BF4}，在代{U+7801}展{U+5F00}{U+65F6}，{U+4F1A}做安全{U+68C0}查或自{U+52A8}{U+7C7B}型{U+8F6C}{U+6362}（同普通函{U+6570}），而宏定{U+4E49}{U+5219}不{U+4F1A}。 
3. 在{U+7C7B}中{U+58F0}明同{U+65F6}定{U+4E49}的成{U+5458}函{U+6570}，自{U+52A8}{U+8F6C}化{U+4E3A}{U+5185}{U+8054}函{U+6570}，因此{U+5185}{U+8054}函{U+6570}可以{U+8BBF}{U+95EE}{U+7C7B}的成{U+5458}{U+53D8}量，宏定{U+4E49}{U+5219}不能。
4. {U+5185}{U+8054}函{U+6570}在{U+8FD0}行{U+65F6}可{U+8C03}{U+8BD5}，而宏定{U+4E49}不可以。

缺{U+70B9}

1. 代{U+7801}膨{U+80C0}。{U+5185}{U+8054}是以代{U+7801}膨{U+80C0}（複制）{U+4E3A}代價，消除函{U+6570}{U+8C03}用{U+5E26}{U+6765}的{U+5F00}{U+9500}。如果{U+6267}行函{U+6570}體{U+5185}代{U+7801}的{U+65F6}{U+95F4}，相比於函{U+6570}{U+8C03}用的{U+5F00}{U+9500}{U+8F83}大，那麼效率的收{U+83B7}{U+4F1A}很少。另一方面，每一{U+5904}{U+5185}{U+8054}函{U+6570}的{U+8C03}用都要複制代{U+7801}，{U+5C06}使程序的{U+603B}代{U+7801}量增大，消耗更多的{U+5185}存空{U+95F4}。
2. inline 函{U+6570}{U+65E0}法{U+968F}{U+7740}函{U+6570}{U+5E93}升{U+7EA7}而升{U+7EA7}。inline函{U+6570}的改{U+53D8}需要重新{U+7F16}{U+8BD1}，不像 non-inline 可以直接{U+94FE}接。
3. 是否{U+5185}{U+8054}，程序{U+5458}不可控。{U+5185}{U+8054}函{U+6570}只是{U+5BF9}{U+7F16}{U+8BD1}器的建{U+8BAE}，是否{U+5BF9}函{U+6570}{U+5185}{U+8054}，{U+51B3}定{U+6743}在於{U+7F16}{U+8BD1}器。

#### {U+865A}函{U+6570}（virtual）可以是{U+5185}{U+8054}函{U+6570}（inline）{U+5417}？

[Are "inline virtual" member functions ever actually "inlined"?](http://www.cs.technion.ac.il/users/yechiel/c++-faq/inline-virtuals.html)

* {U+865A}函{U+6570}可以是{U+5185}{U+8054}函{U+6570}，{U+5185}{U+8054}是可以修{U+9970}{U+865A}函{U+6570}的，但是{U+5F53}{U+865A}函{U+6570}表{U+73B0}多{U+6001}性的{U+65F6}候不能{U+5185}{U+8054}。
* {U+5185}{U+8054}是在{U+7F16}{U+8BD1}器建{U+8BAE}{U+7F16}{U+8BD1}器{U+5185}{U+8054}，而{U+865A}函{U+6570}的多{U+6001}性在{U+8FD0}行期，{U+7F16}{U+8BD1}器{U+65E0}法知道{U+8FD0}行期{U+8C03}用哪{U+4E2A}代{U+7801}，因此{U+865A}函{U+6570}表{U+73B0}{U+4E3A}多{U+6001}性{U+65F6}（{U+8FD0}行期）不可以{U+5185}{U+8054}。
* `inline virtual` 唯一可以{U+5185}{U+8054}的{U+65F6}候是：{U+7F16}{U+8BD1}器知道所{U+8C03}用的{U+5BF9}象是哪{U+4E2A}{U+7C7B}（如 `Base::who()`），{U+8FD9}只有在{U+7F16}{U+8BD1}器具有{U+5B9E}{U+9645}{U+5BF9}象而不是{U+5BF9}象的指{U+9488}或引用{U+65F6}才{U+4F1A}{U+53D1}生。

<details><summary>{U+865A}函{U+6570}{U+5185}{U+8054}使用</summary> 


```cpp
#include <iostream>  
using namespace std;
class Base
{
public:
	inline virtual void who()
	{
		cout << "I am Base\n";
	}
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	inline void who()  // 不{U+5199}inline{U+65F6}{U+9690}式{U+5185}{U+8054}
	{
		cout << "I am Derived\n";
	}
};

int main()
{
	// 此{U+5904}的{U+865A}函{U+6570} who()，是通{U+8FC7}{U+7C7B}（Base）的具體{U+5BF9}象（b）{U+6765}{U+8C03}用的，{U+7F16}{U+8BD1}期{U+95F4}就能確定了，所以它可以是{U+5185}{U+8054}的，但最{U+7EC8}是否{U+5185}{U+8054}取{U+51B3}於{U+7F16}{U+8BD1}器。 
	Base b;
	b.who();

	// 此{U+5904}的{U+865A}函{U+6570}是通{U+8FC7}指{U+9488}{U+8C03}用的，呈{U+73B0}多{U+6001}性，需要在{U+8FD0}行{U+65F6}期{U+95F4}才能確定，所以不能{U+4E3A}{U+5185}{U+8054}。  
	Base *ptr = new Derived();
	ptr->who();

	// 因{U+4E3A}Base有{U+865A}析構函{U+6570}（virtual ~Base() {}），所以 delete {U+65F6}，{U+4F1A}先{U+8C03}用派生{U+7C7B}（Derived）析構函{U+6570}，再{U+8C03}用基{U+7C7B}（Base）析構函{U+6570}，防止{U+5185}存泄漏。
	delete ptr;
	ptr = nullptr;

	system("pause");
	return 0;
} 
```

</details>

### assert()

{U+65AD}言，是宏，而非函{U+6570}。assert 宏的原型定{U+4E49}在 `<assert.h>`（C）、`<cassert>`（C++）中，其作用是如果它的{U+6761}件返回{U+9519}{U+8BEF}，{U+5219}{U+7EC8}止程序{U+6267}行。可以通{U+8FC7}定{U+4E49} `NDEBUG` {U+6765}{U+5173}{U+95ED} assert，但是需要在源代{U+7801}的{U+5F00}{U+5934}，`include <assert.h>` 之前。

<details><summary>assert() 使用</summary> 

```cpp
#define NDEBUG          // 加上{U+8FD9}行，{U+5219} assert 不可用
#include <assert.h>

assert( p != NULL );    // assert 不可用
```

</details>

### sizeof()

* sizeof {U+5BF9}{U+6570}{U+7EC4}，得到整{U+4E2A}{U+6570}{U+7EC4}所占空{U+95F4}大小。
* sizeof {U+5BF9}指{U+9488}，得到指{U+9488}本身所占空{U+95F4}大小。

### #pragma pack(n)

{U+8BBE}定{U+7ED3}構體、{U+8054}合以及{U+7C7B}成{U+5458}{U+53D8}量以 n 字{U+8282}方式{U+5BF9}{U+9F50}

<details><summary>#pragma pack(n) 使用</summary> 


```cpp
#pragma pack(push)  // 保存{U+5BF9}{U+9F50}{U+72B6}{U+6001}
#pragma pack(4)     // {U+8BBE}定{U+4E3A} 4 字{U+8282}{U+5BF9}{U+9F50}

struct test
{
    char m1;
    double m4;
    int m3;
};

#pragma pack(pop)   // 恢複{U+5BF9}{U+9F50}{U+72B6}{U+6001}
```

</details>

### 位域

```cpp
Bit mode: 2;    // mode 占 2 位
```

{U+7C7B}可以{U+5C06}其（非{U+9759}{U+6001}）{U+6570}據成{U+5458}定{U+4E49}{U+4E3A}位域（bit-field），在一{U+4E2A}位域中含有一定{U+6570}量的二{U+8FDB}制位。{U+5F53}一{U+4E2A}程序需要向其他程序或硬件{U+8BBE}{U+5907}{U+4F20}{U+9012}二{U+8FDB}制{U+6570}據{U+65F6}，通常{U+4F1A}用到位域。

* 位域在{U+5185}存中的布局是與機器有{U+5173}的
* 位域的{U+7C7B}型必{U+987B}是整型或枚{U+4E3E}{U+7C7B}型，{U+5E26}符{U+53F7}{U+7C7B}型中的位域的行{U+4E3A}{U+5C06}因具體{U+5B9E}{U+73B0}而定
* 取地址{U+8FD0}算符（&）不能作用於位域，任何指{U+9488}都{U+65E0}法指向{U+7C7B}的位域

### volatile

```cpp
volatile int i = 10; 
```

* volatile {U+5173}{U+952E}字是一種{U+7C7B}型修{U+9970}符，用它{U+58F0}明的{U+7C7B}型{U+53D8}量表示可以被某些{U+7F16}{U+8BD1}器未知的因素（操作系{U+7EDF}、硬件、其它{U+7EBF}程等）更改。所以使用 volatile 告{U+8BC9}{U+7F16}{U+8BD1}器不{U+5E94}{U+5BF9}{U+8FD9}{U+6837}的{U+5BF9}象{U+8FDB}行優化。
* volatile {U+5173}{U+952E}字{U+58F0}明的{U+53D8}量，每次{U+8BBF}{U+95EE}{U+65F6}都必{U+987B}{U+4ECE}{U+5185}存中取出值（{U+6CA1}有被 volatile 修{U+9970}的{U+53D8}量，可能由於{U+7F16}{U+8BD1}器的優化，{U+4ECE} CPU 寄存器中取值）
* const 可以是 volatile （如只{U+8BFB}的{U+72B6}{U+6001}寄存器）
* 指{U+9488}可以是 volatile

### extern "C"

* 被 extern 限定的函{U+6570}或{U+53D8}量是 extern {U+7C7B}型的
* 被 `extern "C"` 修{U+9970}的{U+53D8}量和函{U+6570}是按照 C {U+8BED}言方式{U+7F16}{U+8BD1}和{U+8FDE}接的

`extern "C"` 的作用是{U+8BA9} C++ {U+7F16}{U+8BD1}器{U+5C06} `extern "C"` {U+58F0}明的代{U+7801}{U+5F53}作 C {U+8BED}言代{U+7801}{U+5904}理，可以避免 C++ 因符{U+53F7}修{U+9970}{U+5BFC}致代{U+7801}不能和C{U+8BED}言{U+5E93}中的符{U+53F7}{U+8FDB}行{U+94FE}接的{U+95EE}{U+9898}。

<details><summary>extern "C" 使用</summary> 

```cpp
#ifdef __cplusplus
extern "C" {
#endif

void *memset(void *, int, size_t);

#ifdef __cplusplus
}
#endif
```

</details>

### struct 和 typedef struct

#### C 中

```c
// c
typedef struct Student {
    int age; 
} S;
```

等價於

```c
// c
struct Student { 
    int age; 
};

typedef struct Student S;
```

此{U+65F6} `S` 等價於 `struct Student`，但{U+4E24}{U+4E2A}{U+6807}{U+8BC6}符名{U+79F0}空{U+95F4}不相同。

另外{U+8FD8}可以定{U+4E49}與 `struct Student` 不{U+51B2}突的 `void Student() {}`。

#### C++ 中

由於{U+7F16}{U+8BD1}器定位符{U+53F7}的{U+89C4}{U+5219}（搜索{U+89C4}{U+5219}）改{U+53D8}，{U+5BFC}致不同於C{U+8BED}言。

一、如果在{U+7C7B}{U+6807}{U+8BC6}符空{U+95F4}定{U+4E49}了 `struct Student {...};`，使用 `Student me;` {U+65F6}，{U+7F16}{U+8BD1}器{U+5C06}搜索全局{U+6807}{U+8BC6}符表，`Student` 未找到，{U+5219}在{U+7C7B}{U+6807}{U+8BC6}符{U+5185}搜索。

即表{U+73B0}{U+4E3A}可以使用 `Student` 也可以使用 `struct Student`，如下：

```cpp
// cpp
struct Student { 
    int age; 
};

void f( Student me );       // 正確，"struct" {U+5173}{U+952E}字可省略
```

二、若定{U+4E49}了與 `Student` 同名函{U+6570}之後，{U+5219} `Student` 只代表函{U+6570}，不代表{U+7ED3}構體，如下：

```cpp
typedef struct Student { 
    int age; 
} S;

void Student() {}           // 正確，定{U+4E49}後 "Student" 只代表此函{U+6570}

//void S() {}               // {U+9519}{U+8BEF}，符{U+53F7} "S" 已{U+7ECF}被定{U+4E49}{U+4E3A}一{U+4E2A} "struct Student" 的{U+522B}名

int main() {
    Student(); 
    struct Student me;      // 或者 "S me";
    return 0;
}
```

### C++ 中 struct 和 class

{U+603B}的{U+6765}{U+8BF4}，struct 更適合看成是一{U+4E2A}{U+6570}據{U+7ED3}構的{U+5B9E}{U+73B0}體，class 更適合看成是一{U+4E2A}{U+5BF9}象的{U+5B9E}{U+73B0}體。

#### {U+533A}{U+522B}

* 最本{U+8D28}的一{U+4E2A}{U+533A}{U+522B}就是默{U+8BA4}的{U+8BBF}{U+95EE}控制
    1. 默{U+8BA4}的{U+7EE7}承{U+8BBF}{U+95EE}{U+6743}限。struct 是 public 的，class 是 private 的。  
    2. struct 作{U+4E3A}{U+6570}據{U+7ED3}構的{U+5B9E}{U+73B0}體，它默{U+8BA4}的{U+6570}據{U+8BBF}{U+95EE}控制是 public 的，而 class 作{U+4E3A}{U+5BF9}象的{U+5B9E}{U+73B0}體，它默{U+8BA4}的成{U+5458}{U+53D8}量{U+8BBF}{U+95EE}控制是 private 的。

### union {U+8054}合

{U+8054}合（union）是一種{U+8282}省空{U+95F4}的特殊的{U+7C7B}，一{U+4E2A} union 可以有多{U+4E2A}{U+6570}據成{U+5458}，但是在任意{U+65F6}刻只有一{U+4E2A}{U+6570}據成{U+5458}可以有值。{U+5F53}某{U+4E2A}成{U+5458}被{U+8D4B}值後其他成{U+5458}{U+53D8}{U+4E3A}未定{U+4E49}{U+72B6}{U+6001}。{U+8054}合有如下特{U+70B9}：

* 默{U+8BA4}{U+8BBF}{U+95EE}控制符{U+4E3A} public
* 可以含有構造函{U+6570}、析構函{U+6570}
* 不能含有引用{U+7C7B}型的成{U+5458}
* 不能{U+7EE7}承自其他{U+7C7B}，不能作{U+4E3A}基{U+7C7B}
* 不能含有{U+865A}函{U+6570}
* 匿名 union 在定{U+4E49}所在作用域可直接{U+8BBF}{U+95EE} union 成{U+5458}
* 匿名 union 不能包含 protected 成{U+5458}或 private 成{U+5458}
* 全局匿名{U+8054}合必{U+987B}是{U+9759}{U+6001}（static）的

<details><summary>union 使用</summary> 

```cpp
#include<iostream>

union UnionTest {
    UnionTest() : i(10) {};
    int i;
    double d;
};

static union {
    int i;
    double d;
};

int main() {
    UnionTest u;

    union {
        int i;
        double d;
    };

    std::cout << u.i << std::endl;  // {U+8F93}出 UnionTest {U+8054}合的 10

    ::i = 20;
    std::cout << ::i << std::endl;  // {U+8F93}出全局{U+9759}{U+6001}匿名{U+8054}合的 20

    i = 30;
    std::cout << i << std::endl;    // {U+8F93}出局部匿名{U+8054}合的 30

    return 0;
}
```

</details>

### C {U+5B9E}{U+73B0} C++ {U+7C7B}

[C {U+8BED}言{U+5B9E}{U+73B0}封{U+88C5}、{U+7EE7}承和多{U+6001}](http://dongxicheng.org/cpp/ooc/)

### explicit（{U+663E}式）構造函{U+6570}

explicit 修{U+9970}的構造函{U+6570}可用{U+6765}防止{U+9690}式{U+8F6C}{U+6362}

<details><summary>explicit 使用</summary> 

```cpp
class Test1
{
public:
    Test1(int n)            // 普通構造函{U+6570}
    {
        num=n;
    }
private:
    int num;
};

class Test2
{
public:
    explicit Test2(int n)   // explicit（{U+663E}式）構造函{U+6570}
    {
        num=n;
    }
private:
    int num;
};

int main()
{
    Test1 t1=12;            // {U+9690}式{U+8C03}用其構造函{U+6570}，成功
    Test2 t2=12;            // {U+7F16}{U+8BD1}{U+9519}{U+8BEF}，不能{U+9690}式{U+8C03}用其構造函{U+6570}
    Test2 t2(12);           // {U+663E}式{U+8C03}用成功
    return 0;
}
```

</details>

### friend 友元{U+7C7B}和友元函{U+6570}

* 能{U+8BBF}{U+95EE}私有成{U+5458}  
* 破壞封{U+88C5}性
* 友元{U+5173}系不可{U+4F20}{U+9012}
* 友元{U+5173}系的{U+5355}向性
* 友元{U+58F0}明的形式及{U+6570}量不受限制

### using

#### using {U+58F0}明

一{U+6761} `using {U+58F0}明` {U+8BED}句一次只引入命名空{U+95F4}的一{U+4E2A}成{U+5458}。它使得我{U+4EEC}可以清楚知道程序中所引用的到底是哪{U+4E2A}名字。如：

```cpp
using namespace_name::name;
```

#### 構造函{U+6570}的 using {U+58F0}明【C++11】

在 C++11 中，派生{U+7C7B}能{U+591F}重用其直接基{U+7C7B}定{U+4E49}的構造函{U+6570}。

```cpp
class Derived : Base {
public:
    using Base::Base;
    /* ... */
};
```

如上 using {U+58F0}明，{U+5BF9}於基{U+7C7B}的每{U+4E2A}構造函{U+6570}，{U+7F16}{U+8BD1}器都生成一{U+4E2A}與之{U+5BF9}{U+5E94}（形{U+53C2}列表完全相同）的派生{U+7C7B}構造函{U+6570}。生成如下{U+7C7B}型構造函{U+6570}：

```cpp
derived(parms) : base(args) { }
```

#### using 指示

`using 指示` 使得某{U+4E2A}特定命名空{U+95F4}中所有名字都可{U+89C1}，{U+8FD9}{U+6837}我{U+4EEC}就{U+65E0}需再{U+4E3A}它{U+4EEC}添加任何前{U+7F00}限定符了。如：

```cpp
using namespace_name name;
```

#### {U+5C3D}量少使用 `using 指示` 汙染命名空{U+95F4}

> 一般{U+8BF4}{U+6765}，使用 using 命令比使用 using {U+7F16}{U+8BD1}命令更安全，{U+8FD9}是由於它**只{U+5BFC}入了制定的名{U+79F0}**。如果{U+8BE5}名{U+79F0}與局部名{U+79F0}{U+53D1}生{U+51B2}突，{U+7F16}{U+8BD1}器{U+5C06}**{U+53D1}出指示**。using{U+7F16}{U+8BD1}命令{U+5BFC}入所有的名{U+79F0}，包括可能並不需要的名{U+79F0}。如果與局部名{U+79F0}{U+53D1}生{U+51B2}突，{U+5219}**局部名{U+79F0}{U+5C06}覆{U+76D6}名{U+79F0}空{U+95F4}版本**，而{U+7F16}{U+8BD1}器**並不{U+4F1A}{U+53D1}出警告**。另外，名{U+79F0}空{U+95F4}的{U+5F00}放性意味{U+7740}名{U+79F0}空{U+95F4}的名{U+79F0}可能分散在多{U+4E2A}地方，{U+8FD9}使得{U+96BE}以准確知道添加了哪些名{U+79F0}。

<details><summary>using 使用</summary> 

{U+5C3D}量少使用 `using 指示`

```cpp
using namespace std;
```

{U+5E94}{U+8BE5}多使用 `using {U+58F0}明`

```cpp
int x;
std::cin >> x ;
std::cout << x << std::endl;
```

或者

```cpp
using std::cin;
using std::cout;
using std::endl;
int x;
cin >> x;
cout << x << endl;
```

</details>

### :: 範{U+56F4}解析{U+8FD0}算符

#### 分{U+7C7B}

1. 全局作用域符（`::name`）：用於{U+7C7B}型名{U+79F0}（{U+7C7B}、{U+7C7B}成{U+5458}、成{U+5458}函{U+6570}、{U+53D8}量等）前，表示作用域{U+4E3A}全局命名空{U+95F4}
2. {U+7C7B}作用域符（`class::name`）：用於表示指定{U+7C7B}型的作用域範{U+56F4}是具體某{U+4E2A}{U+7C7B}的
3. 命名空{U+95F4}作用域符（`namespace::name`）:用於表示指定{U+7C7B}型的作用域範{U+56F4}是具體某{U+4E2A}命名空{U+95F4}的

<details><summary>:: 使用</summary> 

```cpp
int count = 0;        // 全局（::）的 count

class A {
public:
    static int count; // {U+7C7B} A 的 count（A::count）
};

int main() {
    ::count = 1;      // {U+8BBE}置全局的 count 的值{U+4E3A} 1

    A::count = 2;     // {U+8BBE}置{U+7C7B} A 的 count {U+4E3A} 2

    int count = 0;    // 局部的 count
    count = 3;        // {U+8BBE}置局部的 count 的值{U+4E3A} 3

    return 0;
}
```

</details>

### enum 枚{U+4E3E}{U+7C7B}型

#### 限定作用域的枚{U+4E3E}{U+7C7B}型

```cpp
enum class open_modes { input, output, append };
```

#### 不限定作用域的枚{U+4E3E}{U+7C7B}型

```cpp
enum color { red, yellow, green };
enum { floatPrec = 6, doublePrec = 10 };
```

### decltype

decltype {U+5173}{U+952E}字用於{U+68C0}查{U+5B9E}體的{U+58F0}明{U+7C7B}型或表{U+8FBE}式的{U+7C7B}型及值分{U+7C7B}。{U+8BED}法：

```cpp
decltype ( expression )
```

<details><summary>decltype 使用</summary> 

```cpp
// 尾置返回允{U+8BB8}我{U+4EEC}在{U+53C2}{U+6570}列表之後{U+58F0}明返回{U+7C7B}型
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // {U+5904}理序列
    return *beg;    // 返回序列中一{U+4E2A}元素的引用
}
// {U+4E3A}了使用模板{U+53C2}{U+6570}成{U+5458}，必{U+987B}用 typename
template <typename It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
{
    // {U+5904}理序列
    return *beg;    // 返回序列中一{U+4E2A}元素的拷{U+8D1D}
}
```

</details>

### 引用

#### 左值引用

常{U+89C4}引用，一般表示{U+5BF9}象的身份。

#### 右值引用

右值引用就是必{U+987B}{U+7ED1}定到右值（一{U+4E2A}{U+4E34}{U+65F6}{U+5BF9}象、{U+5C06}要{U+9500}{U+6BC1}的{U+5BF9}象）的引用，一般表示{U+5BF9}象的值。

右值引用可{U+5B9E}{U+73B0}{U+8F6C}移{U+8BED}{U+4E49}（Move Sementics）和精確{U+4F20}{U+9012}（Perfect Forwarding），它的主要目的有{U+4E24}{U+4E2A}方面：

* 消除{U+4E24}{U+4E2A}{U+5BF9}象交互{U+65F6}不必要的{U+5BF9}象拷{U+8D1D}，{U+8282}省{U+8FD0}算存{U+50A8}{U+8D44}源，提高效率。
* 能{U+591F}更{U+7B80}潔明確地定{U+4E49}泛型函{U+6570}。

#### 引用折{U+53E0}

* `X& &`、`X& &&`、`X&& &` 可折{U+53E0}成 `X&`
* `X&& &&` 可折{U+53E0}成 `X&&`

### 宏

* 宏定{U+4E49}可以{U+5B9E}{U+73B0}{U+7C7B}似於函{U+6570}的功能，但是它{U+7EC8}{U+5F52}不是函{U+6570}，而宏定{U+4E49}中括弧中的「{U+53C2}{U+6570}」也不是真的{U+53C2}{U+6570}，在宏展{U+5F00}的{U+65F6}候{U+5BF9} 「{U+53C2}{U+6570}」 {U+8FDB}行的是一{U+5BF9}一的替{U+6362}。

### 成{U+5458}初始化列表

好{U+5904}

* 更高效：少了一次{U+8C03}用默{U+8BA4}構造函{U+6570}的{U+8FC7}程。
* 有些{U+573A}合必{U+987B}要用初始化列表：
  1. 常量成{U+5458}，因{U+4E3A}常量只能初始化不能{U+8D4B}值，所以必{U+987B}放在初始化列表裏面
  2. 引用{U+7C7B}型，引用必{U+987B}在定{U+4E49}的{U+65F6}候初始化，並且不能重新{U+8D4B}值，所以也要{U+5199}在初始化列表裏面
  3. {U+6CA1}有默{U+8BA4}構造函{U+6570}的{U+7C7B}{U+7C7B}型，因{U+4E3A}使用初始化列表可以不必{U+8C03}用默{U+8BA4}構造函{U+6570}{U+6765}初始化，而是直接{U+8C03}用拷{U+8D1D}構造函{U+6570}初始化。

### initializer_list 列表初始化【C++11】

用花括{U+53F7}初始化器列表列表初始化一{U+4E2A}{U+5BF9}象，其中{U+5BF9}{U+5E94}構造函{U+6570}接受一{U+4E2A} `std::initializer_list` {U+53C2}{U+6570}.

<details><summary>initializer_list 使用</summary> 

```cpp
#include <iostream>
#include <vector>
#include <initializer_list>
 
template <class T>
struct S {
    std::vector<T> v;
    S(std::initializer_list<T> l) : v(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }
    std::pair<const T*, std::size_t> c_arr() const {
        return {&v[0], v.size()};  // 在 return {U+8BED}句中複制列表初始化
                                   // {U+8FD9}不使用 std::initializer_list
    }
};
 
template <typename T>
void templated_fn(T) {}
 
int main()
{
    S<int> s = {1, 2, 3, 4, 5}; // 複制初始化
    s.append({6, 7, 8});      // 函{U+6570}{U+8C03}用中的列表初始化
 
    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";
 
    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';
 
    std::cout << "Range-for over brace-init-list: \n";
 
    for (int x : {-1, -2, -3}) // auto 的{U+89C4}{U+5219}令此{U+5E26}範{U+56F4} for 工作
        std::cout << x << ' ';
    std::cout << '\n';
 
    auto al = {10, 11, 12};   // auto 的特殊{U+89C4}{U+5219}
 
    std::cout << "The list bound to auto has size() = " << al.size() << '\n';
 
//    templated_fn({1, 2, 3}); // {U+7F16}{U+8BD1}{U+9519}{U+8BEF}！「 {1, 2, 3} 」不是表{U+8FBE}式，
                             // 它{U+65E0}{U+7C7B}型，故 T {U+65E0}法推{U+5BFC}
    templated_fn<std::initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // 也 OK
}
```

</details>

### 面向{U+5BF9}象

面向{U+5BF9}象程序{U+8BBE}{U+8BA1}（Object-oriented programming，OOP）是種具有{U+5BF9}象概念的程序{U+7F16}程典範，同{U+65F6}也是一種程序{U+5F00}{U+53D1}的抽象方{U+9488}。

![面向{U+5BF9}象特征](http://img.my.csdn.net/uploads/201211/22/1353564524_6375.png)

面向{U+5BF9}象三大特征 —— 封{U+88C5}、{U+7EE7}承、多{U+6001}

### 封{U+88C5}

* 把客{U+89C2}事物封{U+88C5}成抽象的{U+7C7B}，並且{U+7C7B}可以把自己的{U+6570}據和方法只{U+8BA9}可信的{U+7C7B}或者{U+5BF9}象操作，{U+5BF9}不可信的{U+8FDB}行信息{U+9690}藏。
* {U+5173}{U+952E}字：public, protected, friendly, private。不{U+5199}默{U+8BA4}{U+4E3A} friendly。

| {U+5173}{U+952E}字 | {U+5F53}前{U+7C7B} | 包{U+5185} | 子{U+5B59}{U+7C7B} | 包外 |
| --- | --- | --- | --- | --- |
| public | √ | √ | √ | √ |
| protected | √ | √ | √ | × |
| friendly | √ | √ | × | × |
| private | √ | × | × | × |

### {U+7EE7}承

* 基{U+7C7B}（父{U+7C7B}）——&gt; 派生{U+7C7B}（子{U+7C7B}）

### 多{U+6001}

* 多{U+6001}，即多種{U+72B6}{U+6001}，在面向{U+5BF9}象{U+8BED}言中，接口的多種不同的{U+5B9E}{U+73B0}方式即{U+4E3A}多{U+6001}。
* C++ 多{U+6001}有{U+4E24}種：{U+9759}{U+6001}多{U+6001}（早{U+7ED1}定）、{U+52A8}{U+6001}多{U+6001}（晚{U+7ED1}定）。{U+9759}{U+6001}多{U+6001}是通{U+8FC7}函{U+6570}重{U+8F7D}{U+5B9E}{U+73B0}的；{U+52A8}{U+6001}多{U+6001}是通{U+8FC7}{U+865A}函{U+6570}{U+5B9E}{U+73B0}的。
* 多{U+6001}是以封{U+88C5}和{U+7EE7}承{U+4E3A}基{U+7840}的。

#### {U+9759}{U+6001}多{U+6001}（早{U+7ED1}定）

函{U+6570}重{U+8F7D}

```cpp
class A
{
public:
    void do(int a);
    void do(int a, int b);
};
```

#### {U+52A8}{U+6001}多{U+6001}（晚{U+7ED1}定）

* {U+865A}函{U+6570}：用 virtual 修{U+9970}成{U+5458}函{U+6570}，使其成{U+4E3A}{U+865A}函{U+6570}

**注意：**

* 普通函{U+6570}（非{U+7C7B}成{U+5458}函{U+6570}）不能是{U+865A}函{U+6570}
* {U+9759}{U+6001}函{U+6570}（static）不能是{U+865A}函{U+6570}
* 構造函{U+6570}不能是{U+865A}函{U+6570}（因{U+4E3A}在{U+8C03}用構造函{U+6570}{U+65F6}，{U+865A}表指{U+9488}並{U+6CA1}有在{U+5BF9}象的{U+5185}存空{U+95F4}中，必{U+987B}要構造函{U+6570}{U+8C03}用完成後才{U+4F1A}形成{U+865A}表指{U+9488}）
* {U+5185}{U+8054}函{U+6570}不能是表{U+73B0}多{U+6001}性{U+65F6}的{U+865A}函{U+6570}，解{U+91CA}{U+89C1}：[{U+865A}函{U+6570}（virtual）可以是{U+5185}{U+8054}函{U+6570}（inline）{U+5417}？](https://github.com/huihut/interview#%E8%99%9A%E5%87%BD%E6%95%B0virtual%E5%8F%AF%E4%BB%A5%E6%98%AF%E5%86%85%E8%81%94%E5%87%BD%E6%95%B0inline%E5%90%97)

<details><summary>{U+52A8}{U+6001}多{U+6001}使用</summary> 

```cpp
class Shape                     // 形{U+72B6}{U+7C7B}
{
public:
    virtual double calcArea()
    {
        ...
    }
    virtual ~Shape();
};
class Circle : public Shape     // {U+5706}形{U+7C7B}
{
public:
    virtual double calcArea();
    ...
};
class Rect : public Shape       // 矩形{U+7C7B}
{
public:
    virtual double calcArea();
    ...
};
int main()
{
    Shape * shape1 = new Circle(4.0);
    Shape * shape2 = new Rect(5.0, 6.0);
    shape1->calcArea();         // {U+8C03}用{U+5706}形{U+7C7B}裏面的方法
    shape2->calcArea();         // {U+8C03}用矩形{U+7C7B}裏面的方法
    delete shape1;
    shape1 = nullptr;
    delete shape2;
    shape2 = nullptr;
    return 0;
}
```

</details>

### {U+865A}析構函{U+6570}

{U+865A}析構函{U+6570}是{U+4E3A}了解{U+51B3}基{U+7C7B}的指{U+9488}指向派生{U+7C7B}{U+5BF9}象，並用基{U+7C7B}的指{U+9488}{U+5220}除派生{U+7C7B}{U+5BF9}象。

<details><summary>{U+865A}析構函{U+6570}使用</summary> 

```cpp
class Shape
{
public:
    Shape();                    // 構造函{U+6570}不能是{U+865A}函{U+6570}
    virtual double calcArea();
    virtual ~Shape();           // {U+865A}析構函{U+6570}
};
class Circle : public Shape     // {U+5706}形{U+7C7B}
{
public:
    virtual double calcArea();
    ...
};
int main()
{
    Shape * shape1 = new Circle(4.0);
    shape1->calcArea();    
    delete shape1;  // 因{U+4E3A}Shape有{U+865A}析構函{U+6570}，所以delete{U+91CA}放{U+5185}存{U+65F6}，先{U+8C03}用子{U+7C7B}析構函{U+6570}，再{U+8C03}用基{U+7C7B}析構函{U+6570}，防止{U+5185}存泄漏。
    shape1 = NULL;
    return 0；
}
```

</details>

### {U+7EAF}{U+865A}函{U+6570}

{U+7EAF}{U+865A}函{U+6570}是一種特殊的{U+865A}函{U+6570}，在基{U+7C7B}中不能{U+5BF9}{U+865A}函{U+6570}{U+7ED9}出有意{U+4E49}的{U+5B9E}{U+73B0}，而把它{U+58F0}明{U+4E3A}{U+7EAF}{U+865A}函{U+6570}，它的{U+5B9E}{U+73B0}留{U+7ED9}{U+8BE5}基{U+7C7B}的派生{U+7C7B}去做。

```cpp
virtual int A() = 0;
```

### {U+865A}函{U+6570}、{U+7EAF}{U+865A}函{U+6570}

[CSDN . C++ 中的{U+865A}函{U+6570}、{U+7EAF}{U+865A}函{U+6570}{U+533A}{U+522B}和{U+8054}系](https://blog.csdn.net/u012260238/article/details/53610462)

* {U+7C7B}裏如果{U+58F0}明了{U+865A}函{U+6570}，{U+8FD9}{U+4E2A}函{U+6570}是{U+5B9E}{U+73B0}的，哪怕是空{U+5B9E}{U+73B0}，它的作用就是{U+4E3A}了能{U+8BA9}{U+8FD9}{U+4E2A}函{U+6570}在它的子{U+7C7B}裏面可以被覆{U+76D6}，{U+8FD9}{U+6837}的{U+8BDD}，{U+8FD9}{U+6837}{U+7F16}{U+8BD1}器就可以使用後期{U+7ED1}定{U+6765}{U+8FBE}到多{U+6001}了。{U+7EAF}{U+865A}函{U+6570}只是一{U+4E2A}接口，是{U+4E2A}函{U+6570}的{U+58F0}明而已，它要留到子{U+7C7B}裏去{U+5B9E}{U+73B0}。 
* {U+865A}函{U+6570}在子{U+7C7B}裏面也可以不重{U+8F7D}的；但{U+7EAF}{U+865A}函{U+6570}必{U+987B}在子{U+7C7B}去{U+5B9E}{U+73B0}。
* {U+865A}函{U+6570}的{U+7C7B}用於 「{U+5B9E}作{U+7EE7}承」，{U+7EE7}承接口的同{U+65F6}也{U+7EE7}承了父{U+7C7B}的{U+5B9E}{U+73B0}。{U+5F53}然大家也可以完成自己的{U+5B9E}{U+73B0}。{U+7EAF}{U+865A}函{U+6570}{U+5173}注的是接口的{U+7EDF}一性，{U+5B9E}{U+73B0}由子{U+7C7B}完成。 
* {U+5E26}{U+7EAF}{U+865A}函{U+6570}的{U+7C7B}叫{U+865A}基{U+7C7B}，{U+8FD9}種基{U+7C7B}不能直接生成{U+5BF9}象，而只有被{U+7EE7}承，並重{U+5199}其{U+865A}函{U+6570}後，才能使用。{U+8FD9}{U+6837}的{U+7C7B}也叫抽象{U+7C7B}。抽象{U+7C7B}和大家口{U+5934}常{U+8BF4}的{U+865A}基{U+7C7B}{U+8FD8}是有{U+533A}{U+522B}的，在 C# 中用 abstract 定{U+4E49}抽象{U+7C7B}，而在 C++ 中有抽象{U+7C7B}的概念，但是{U+6CA1}有{U+8FD9}{U+4E2A}{U+5173}{U+952E}字。抽象{U+7C7B}被{U+7EE7}承後，子{U+7C7B}可以{U+7EE7}{U+7EED}是抽象{U+7C7B}，也可以是普通{U+7C7B}，而{U+865A}基{U+7C7B}，是含有{U+7EAF}{U+865A}函{U+6570}的{U+7C7B}，它如果被{U+7EE7}承，那麼子{U+7C7B}就必{U+987B}{U+5B9E}{U+73B0}{U+865A}基{U+7C7B}裏面的所有{U+7EAF}{U+865A}函{U+6570}，其子{U+7C7B}不能是抽象{U+7C7B}。

### {U+865A}函{U+6570}指{U+9488}、{U+865A}函{U+6570}表

* {U+865A}函{U+6570}指{U+9488}：在含有{U+865A}函{U+6570}{U+7C7B}的{U+5BF9}象中，指向{U+865A}函{U+6570}表，在{U+8FD0}行{U+65F6}確定。
* {U+865A}函{U+6570}表：在程序只{U+8BFB}{U+6570}據段（`.rodata section`，{U+89C1}：[目{U+6807}文件存{U+50A8}{U+7ED3}構](#%E7%9B%AE%E6%A0%87%E6%96%87%E4%BB%B6%E5%AD%98%E5%82%A8%E7%BB%93%E6%9E%84)），存放{U+865A}函{U+6570}指{U+9488}，如果派生{U+7C7B}{U+5B9E}{U+73B0}了基{U+7C7B}的某{U+4E2A}{U+865A}函{U+6570}，{U+5219}在{U+865A}表中覆{U+76D6}原本基{U+7C7B}的那{U+4E2A}{U+865A}函{U+6570}指{U+9488}，在{U+7F16}{U+8BD1}{U+65F6}根據{U+7C7B}的{U+58F0}明{U+521B}建。

### {U+865A}{U+7EE7}承

{U+865A}{U+7EE7}承用於解{U+51B3}多{U+7EE7}承{U+6761}件下的菱形{U+7EE7}承{U+95EE}{U+9898}（浪{U+8D39}存{U+50A8}空{U+95F4}、存在二{U+4E49}性）。

底{U+5C42}{U+5B9E}{U+73B0}原理與{U+7F16}{U+8BD1}器相{U+5173}，一般通{U+8FC7}**{U+865A}基{U+7C7B}指{U+9488}**和**{U+865A}基{U+7C7B}表**{U+5B9E}{U+73B0}，每{U+4E2A}{U+865A}{U+7EE7}承的子{U+7C7B}都有一{U+4E2A}{U+865A}基{U+7C7B}指{U+9488}（占用一{U+4E2A}指{U+9488}的存{U+50A8}空{U+95F4}，4字{U+8282}）和{U+865A}基{U+7C7B}表（不占用{U+7C7B}{U+5BF9}象的存{U+50A8}空{U+95F4}）（需要{U+5F3A}{U+8C03}的是，{U+865A}基{U+7C7B}依{U+65E7}{U+4F1A}在子{U+7C7B}裏面存在拷{U+8D1D}，只是{U+4EC5}{U+4EC5}最多存在一份而已，並不是不在子{U+7C7B}裏面了）；{U+5F53}{U+865A}{U+7EE7}承的子{U+7C7B}被{U+5F53}做父{U+7C7B}{U+7EE7}承{U+65F6}，{U+865A}基{U+7C7B}指{U+9488}也{U+4F1A}被{U+7EE7}承。

{U+5B9E}{U+9645}上，vbptr 指的是{U+865A}基{U+7C7B}表指{U+9488}（virtual base table pointer），{U+8BE5}指{U+9488}指向了一{U+4E2A}{U+865A}基{U+7C7B}表（virtual table），{U+865A}表中{U+8BB0}{U+5F55}了{U+865A}基{U+7C7B}與本{U+7C7B}的偏移地址；通{U+8FC7}偏移地址，{U+8FD9}{U+6837}就找到了{U+865A}基{U+7C7B}成{U+5458}，而{U+865A}{U+7EE7}承也不用像普通多{U+7EE7}承那{U+6837}{U+7EF4}持{U+7740}公共基{U+7C7B}（{U+865A}基{U+7C7B}）的{U+4E24}份同{U+6837}的拷{U+8D1D}，{U+8282}省了存{U+50A8}空{U+95F4}。

### {U+865A}{U+7EE7}承、{U+865A}函{U+6570}

* 相同之{U+5904}：都利用了{U+865A}指{U+9488}（均占用{U+7C7B}的存{U+50A8}空{U+95F4}）和{U+865A}表（均不占用{U+7C7B}的存{U+50A8}空{U+95F4}）
* 不同之{U+5904}：
    * {U+865A}{U+7EE7}承
        * {U+865A}基{U+7C7B}依{U+65E7}存在{U+7EE7}承{U+7C7B}中，只占用存{U+50A8}空{U+95F4}
        * {U+865A}基{U+7C7B}表存{U+50A8}的是{U+865A}基{U+7C7B}相{U+5BF9}直接{U+7EE7}承{U+7C7B}的偏移
    * {U+865A}函{U+6570}
        * {U+865A}函{U+6570}不占用存{U+50A8}空{U+95F4}
        * {U+865A}函{U+6570}表存{U+50A8}的是{U+865A}函{U+6570}地址

### 模板{U+7C7B}、成{U+5458}模板、{U+865A}函{U+6570}

* 模板{U+7C7B}中可以使用{U+865A}函{U+6570}
* 一{U+4E2A}{U+7C7B}（{U+65E0}{U+8BBA}是普通{U+7C7B}{U+8FD8}是{U+7C7B}模板）的成{U+5458}模板（本身是模板的成{U+5458}函{U+6570}）不能是{U+865A}函{U+6570}

### 抽象{U+7C7B}、接口{U+7C7B}、聚合{U+7C7B}

* 抽象{U+7C7B}：含有{U+7EAF}{U+865A}函{U+6570}的{U+7C7B}
* 接口{U+7C7B}：{U+4EC5}含有{U+7EAF}{U+865A}函{U+6570}的抽象{U+7C7B}
* 聚合{U+7C7B}：用{U+6237}可以直接{U+8BBF}{U+95EE}其成{U+5458}，並且具有特殊的初始化{U+8BED}法形式。{U+6EE1}足如下特{U+70B9}：
    * 所有成{U+5458}都是 public
    * {U+6CA1}有有定於任何構造函{U+6570}
    * {U+6CA1}有{U+7C7B}{U+5185}初始化
    * {U+6CA1}有基{U+7C7B}，也{U+6CA1}有 virtual 函{U+6570}

### {U+5185}存分配和管理

#### malloc、calloc、realloc、alloca

1. malloc：申{U+8BF7}指定字{U+8282}{U+6570}的{U+5185}存。申{U+8BF7}到的{U+5185}存中的初始值不確定。
2. calloc：{U+4E3A}指定{U+957F}度的{U+5BF9}象，分配能容{U+7EB3}其指定{U+4E2A}{U+6570}的{U+5185}存。申{U+8BF7}到的{U+5185}存的每一位（bit）都初始化{U+4E3A} 0。
3. realloc：更改以前分配的{U+5185}存{U+957F}度（增加或{U+51CF}少）。{U+5F53}增加{U+957F}度{U+65F6}，可能需{U+5C06}以前分配{U+533A}的{U+5185}容移到另一{U+4E2A}足{U+591F}大的{U+533A}域，而新增{U+533A}域{U+5185}的初始值{U+5219}不確定。
4. alloca：在{U+6808}上申{U+8BF7}{U+5185}存。程序在出{U+6808}的{U+65F6}候，{U+4F1A}自{U+52A8}{U+91CA}放{U+5185}存。但是需要注意的是，alloca 不具可移植性, 而且在{U+6CA1}有{U+4F20}{U+7EDF}堆{U+6808}的機器上很{U+96BE}{U+5B9E}{U+73B0}。alloca 不宜使用在必{U+987B}{U+5E7F}泛移植的程序中。C99 中支持{U+53D8}{U+957F}{U+6570}{U+7EC4} (VLA)，可以用{U+6765}替代 alloca。

#### malloc、free

用於分配、{U+91CA}放{U+5185}存

<details><summary>malloc、free 使用</summary> 

申{U+8BF7}{U+5185}存，確{U+8BA4}是否申{U+8BF7}成功

```cpp
char *str = (char*) malloc(100);
assert(str != nullptr);
```

{U+91CA}放{U+5185}存後指{U+9488}置空

```cpp
free(p); 
p = nullptr;
```

</details>

#### new、delete

1. new / new[]：完成{U+4E24}件事，先底{U+5C42}{U+8C03}用 malloc 分了配{U+5185}存，然後{U+8C03}用構造函{U+6570}（{U+521B}建{U+5BF9}象）。
2. delete/delete[]：也完成{U+4E24}件事，先{U+8C03}用析構函{U+6570}（清理{U+8D44}源），然後底{U+5C42}{U+8C03}用 free {U+91CA}放空{U+95F4}。
3. new 在申{U+8BF7}{U+5185}存{U+65F6}{U+4F1A}自{U+52A8}{U+8BA1}算所需字{U+8282}{U+6570}，而 malloc {U+5219}需我{U+4EEC}自己{U+8F93}入申{U+8BF7}{U+5185}存空{U+95F4}的字{U+8282}{U+6570}。

<details><summary>new、delete 使用</summary> 

申{U+8BF7}{U+5185}存，確{U+8BA4}是否申{U+8BF7}成功

```cpp
int main()
{
    T* t = new T();     // 先{U+5185}存分配 ，再構造函{U+6570}
    delete t;           // 先析構函{U+6570}，再{U+5185}存{U+91CA}放
    return 0;
}
```

</details>

#### 定位 new

定位 new（placement new）允{U+8BB8}我{U+4EEC}向 new {U+4F20}{U+9012}{U+989D}外的{U+53C2}{U+6570}。

```cpp
new (palce_address) type
new (palce_address) type (initializers)
new (palce_address) type [size]
new (palce_address) type [size] { braced initializer list }
```

* `palce_address` 是{U+4E2A}指{U+9488}
* `initializers` 提供一{U+4E2A}（可能{U+4E3A}空的）以逗{U+53F7}分隔的初始值列表

### delete this 合法{U+5417}？

[Is it legal (and moral) for a member function to say delete this?](https://isocpp.org/wiki/faq/freestore-mgmt#delete-this)

合法，但：

1. 必{U+987B}保{U+8BC1} this {U+5BF9}象是通{U+8FC7} `new`（不是 `new[]`、不是 placement new、不是{U+6808}上、不是全局、不是其他{U+5BF9}象成{U+5458}）分配的
2. 必{U+987B}保{U+8BC1}{U+8C03}用 `delete this` 的成{U+5458}函{U+6570}是最後一{U+4E2A}{U+8C03}用 this 的成{U+5458}函{U+6570}
3. 必{U+987B}保{U+8BC1}成{U+5458}函{U+6570}的 `delete this ` 後面{U+6CA1}有{U+8C03}用 this 了
4. 必{U+987B}保{U+8BC1} `delete this` 後{U+6CA1}有人使用了

### 如何定{U+4E49}一{U+4E2A}只能在堆上（{U+6808}上）生成{U+5BF9}象的{U+7C7B}？

[如何定{U+4E49}一{U+4E2A}只能在堆上（{U+6808}上）生成{U+5BF9}象的{U+7C7B}?](https://www.nowcoder.com/questionTerminal/0a584aa13f804f3ea72b442a065a7618)

#### 只能在堆上

方法：{U+5C06}析構函{U+6570}{U+8BBE}置{U+4E3A}私有

原因：C++ 是{U+9759}{U+6001}{U+7ED1}定{U+8BED}言，{U+7F16}{U+8BD1}器管理{U+6808}上{U+5BF9}象的生命周期，{U+7F16}{U+8BD1}器在{U+4E3A}{U+7C7B}{U+5BF9}象分配{U+6808}空{U+95F4}{U+65F6}，{U+4F1A}先{U+68C0}查{U+7C7B}的析構函{U+6570}的{U+8BBF}{U+95EE}性。若析構函{U+6570}不可{U+8BBF}{U+95EE}，{U+5219}不能在{U+6808}上{U+521B}建{U+5BF9}象。

#### 只能在{U+6808}上

方法：{U+5C06} new 和 delete 重{U+8F7D}{U+4E3A}私有

原因：在堆上生成{U+5BF9}象，使用 new {U+5173}{U+952E}{U+8BCD}操作，其{U+8FC7}程分{U+4E3A}{U+4E24}{U+9636}段：第一{U+9636}段，使用 new 在堆上{U+5BFB}找可用{U+5185}存，分配{U+7ED9}{U+5BF9}象；第二{U+9636}段，{U+8C03}用構造函{U+6570}生成{U+5BF9}象。{U+5C06} new 操作{U+8BBE}置{U+4E3A}私有，那麼第一{U+9636}段就{U+65E0}法完成，就不能{U+591F}在堆上生成{U+5BF9}象。

### 智能指{U+9488}

#### C++ {U+6807}准{U+5E93}（STL）中

{U+5934}文件：`#include <memory>`

#### C++ 98

```cpp
std::auto_ptr<std::string> ps (new std::string(str))；
```

#### C++ 11

1. shared_ptr
2. unique_ptr
3. weak_ptr
4. auto_ptr（被 C++11 {U+5F03}用）

* Class shared_ptr {U+5B9E}{U+73B0}共享式{U+62E5}有（shared ownership）概念。多{U+4E2A}智能指{U+9488}指向相同{U+5BF9}象，{U+8BE5}{U+5BF9}象和其相{U+5173}{U+8D44}源{U+4F1A}在 「最後一{U+4E2A} reference 被{U+9500}{U+6BC1}」 {U+65F6}被{U+91CA}放。{U+4E3A}了在{U+7ED3}構{U+8F83}複{U+6742}的情景中{U+6267}行上述工作，{U+6807}准{U+5E93}提供 weak_ptr、bad_weak_ptr 和 enable_shared_from_this 等{U+8F85}助{U+7C7B}。
* Class unique_ptr {U+5B9E}{U+73B0}{U+72EC}占式{U+62E5}有（exclusive ownership）或{U+4E25}格{U+62E5}有（strict ownership）概念，保{U+8BC1}同一{U+65F6}{U+95F4}{U+5185}只有一{U+4E2A}智能指{U+9488}可以指向{U+8BE5}{U+5BF9}象。你可以移交{U+62E5}有{U+6743}。它{U+5BF9}於避免{U+5185}存泄漏（resource leak）——如 new 後忘{U+8BB0} delete ——特{U+522B}有用。

##### shared_ptr

多{U+4E2A}智能指{U+9488}可以共享同一{U+4E2A}{U+5BF9}象，{U+5BF9}象的最末一{U+4E2A}{U+62E5}有{U+7740}有{U+8D23}任{U+9500}{U+6BC1}{U+5BF9}象，並清理與{U+8BE5}{U+5BF9}象相{U+5173}的所有{U+8D44}源。

* 支持定制型{U+5220}除器（custom deleter），可防範 Cross-DLL {U+95EE}{U+9898}（{U+5BF9}象在{U+52A8}{U+6001}{U+94FE}接{U+5E93}（DLL）中被 new {U+521B}建，{U+5374}在另一{U+4E2A} DLL {U+5185}被 delete {U+9500}{U+6BC1}）、自{U+52A8}解除互斥{U+9501}

##### weak_ptr

weak_ptr 允{U+8BB8}你共享但不{U+62E5}有某{U+5BF9}象，一旦最末一{U+4E2A}{U+62E5}有{U+8BE5}{U+5BF9}象的智能指{U+9488}失去了所有{U+6743}，任何 weak_ptr 都{U+4F1A}自{U+52A8}成空（empty）。因此，在 default 和 copy 構造函{U+6570}之外，weak_ptr 只提供 「接受一{U+4E2A} shared_ptr」 的構造函{U+6570}。

* 可打破{U+73AF}{U+72B6}引用（cycles of references，{U+4E24}{U+4E2A}其{U+5B9E}已{U+7ECF}{U+6CA1}有被使用的{U+5BF9}象彼此互指，使之看似{U+8FD8}在 「被使用」 的{U+72B6}{U+6001}）的{U+95EE}{U+9898}

##### unique_ptr

unique_ptr 是 C++11 才{U+5F00}始提供的{U+7C7B}型，是一種在異常{U+65F6}可以{U+5E2E}助避免{U+8D44}源泄漏的智能指{U+9488}。采用{U+72EC}占式{U+62E5}有，意味{U+7740}可以確保一{U+4E2A}{U+5BF9}象和其相{U+5E94}的{U+8D44}源同一{U+65F6}{U+95F4}只被一{U+4E2A} pointer {U+62E5}有。一旦{U+62E5}有{U+7740}被{U+9500}{U+6BC1}或{U+7F16}程 empty，或{U+5F00}始{U+62E5}有另一{U+4E2A}{U+5BF9}象，先前{U+62E5}有的那{U+4E2A}{U+5BF9}象就{U+4F1A}被{U+9500}{U+6BC1}，其任何相{U+5E94}{U+8D44}源亦{U+4F1A}被{U+91CA}放。

* unique_ptr 用於取代 auto_ptr

##### auto_ptr

被 c++11 {U+5F03}用，原因是缺乏{U+8BED}言特性如 「{U+9488}{U+5BF9}構造和{U+8D4B}值」 的 `std::move` {U+8BED}{U+4E49}，以及其他瑕疵。

##### auto_ptr 與 unique_ptr 比{U+8F83}

* auto_ptr 可以{U+8D4B}值拷{U+8D1D}，複制拷{U+8D1D}後所有{U+6743}{U+8F6C}移；unqiue_ptr {U+65E0}拷{U+8D1D}{U+8D4B}值{U+8BED}{U+4E49}，但{U+5B9E}{U+73B0}了`move` {U+8BED}{U+4E49}；
* auto_ptr {U+5BF9}象不能管理{U+6570}{U+7EC4}（析構{U+8C03}用 `delete`），unique_ptr 可以管理{U+6570}{U+7EC4}（析構{U+8C03}用 `delete[]` ）；

### {U+5F3A}制{U+7C7B}型{U+8F6C}{U+6362}{U+8FD0}算符

[MSDN . {U+5F3A}制{U+8F6C}{U+6362}{U+8FD0}算符](https://msdn.microsoft.com/zh-CN/library/5f6c9f8h.aspx)

#### static_cast

* 用於非多{U+6001}{U+7C7B}型的{U+8F6C}{U+6362}
* 不{U+6267}行{U+8FD0}行{U+65F6}{U+7C7B}型{U+68C0}查（{U+8F6C}{U+6362}安全性不如 dynamic_cast）
* 通常用於{U+8F6C}{U+6362}{U+6570}值{U+6570}據{U+7C7B}型（如 float -> int）
* 可以在整{U+4E2A}{U+7C7B}{U+5C42}次{U+7ED3}構中移{U+52A8}指{U+9488}，子{U+7C7B}{U+8F6C}化{U+4E3A}父{U+7C7B}安全（向上{U+8F6C}{U+6362}），父{U+7C7B}{U+8F6C}化{U+4E3A}子{U+7C7B}不安全（因{U+4E3A}子{U+7C7B}可能有不在父{U+7C7B}的字段或方法）

> 向上{U+8F6C}{U+6362}是一種{U+9690}式{U+8F6C}{U+6362}。

#### dynamic_cast

* 用於多{U+6001}{U+7C7B}型的{U+8F6C}{U+6362}
* {U+6267}行行{U+8FD0}行{U+65F6}{U+7C7B}型{U+68C0}查
* 只適用於指{U+9488}或引用
* {U+5BF9}不明確的指{U+9488}的{U+8F6C}{U+6362}{U+5C06}失{U+8D25}（返回 nullptr），但不引{U+53D1}異常
* 可以在整{U+4E2A}{U+7C7B}{U+5C42}次{U+7ED3}構中移{U+52A8}指{U+9488}，包括向上{U+8F6C}{U+6362}、向下{U+8F6C}{U+6362}

#### const_cast 

* 用於{U+5220}除 const、volatile 和 __unaligned 特性（如{U+5C06} const int {U+7C7B}型{U+8F6C}{U+6362}{U+4E3A} int {U+7C7B}型 ）

#### reinterpret_cast

* 用於位的{U+7B80}{U+5355}重新解{U+91CA}
* {U+6EE5}用 reinterpret_cast {U+8FD0}算符可能很容易{U+5E26}{U+6765}{U+98CE}{U+9669}。 除非所需{U+8F6C}{U+6362}本身是低{U+7EA7}{U+522B}的，否{U+5219}{U+5E94}使用其他{U+5F3A}制{U+8F6C}{U+6362}{U+8FD0}算符之一。
* 允{U+8BB8}{U+5C06}任何指{U+9488}{U+8F6C}{U+6362}{U+4E3A}任何其他指{U+9488}{U+7C7B}型（如 `char*` 到 `int*` 或 `One_class*` 到 `Unrelated_class*` 之{U+7C7B}的{U+8F6C}{U+6362}，但其本身並不安全）
* 也允{U+8BB8}{U+5C06}任何整{U+6570}{U+7C7B}型{U+8F6C}{U+6362}{U+4E3A}任何指{U+9488}{U+7C7B}型以及反向{U+8F6C}{U+6362}。
* reinterpret_cast {U+8FD0}算符不能{U+4E22}掉 const、volatile 或 __unaligned 特性。 
* reinterpret_cast 的一{U+4E2A}{U+5B9E}{U+9645}用途是在哈希函{U+6570}中，即，通{U+8FC7}{U+8BA9}{U+4E24}{U+4E2A}不同的值幾乎不以相同的索引{U+7ED3}尾的方式{U+5C06}值映射到索引。

#### bad_cast

* 由於{U+5F3A}制{U+8F6C}{U+6362}{U+4E3A}引用{U+7C7B}型失{U+8D25}，dynamic_cast {U+8FD0}算符引{U+53D1} bad_cast 異常。

<details><summary>bad_cast 使用</summary> 

```cpp
try {  
    Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);   
}  
catch (bad_cast b) {  
    cout << "Caught: " << b.what();  
} 
```

</details>

### {U+8FD0}行{U+65F6}{U+7C7B}型信息 (RTTI) 

#### dynamic_cast

* 用於多{U+6001}{U+7C7B}型的{U+8F6C}{U+6362}

#### typeid

* typeid {U+8FD0}算符允{U+8BB8}在{U+8FD0}行{U+65F6}確定{U+5BF9}象的{U+7C7B}型
* type\_id 返回一{U+4E2A} type\_info {U+5BF9}象的引用
* 如果想通{U+8FC7}基{U+7C7B}的指{U+9488}{U+83B7}得派生{U+7C7B}的{U+6570}據{U+7C7B}型，基{U+7C7B}必{U+987B}{U+5E26}有{U+865A}函{U+6570}
* 只能{U+83B7}取{U+5BF9}象的{U+5B9E}{U+9645}{U+7C7B}型

#### type_info

* type_info {U+7C7B}描述{U+7F16}{U+8BD1}器在程序中生成的{U+7C7B}型信息。 此{U+7C7B}的{U+5BF9}象可以有效存{U+50A8}指向{U+7C7B}型的名{U+79F0}的指{U+9488}。 type_info {U+7C7B}{U+8FD8}可存{U+50A8}適合比{U+8F83}{U+4E24}{U+4E2A}{U+7C7B}型是否相等或比{U+8F83}其排列{U+987A}序的{U+7F16}{U+7801}值。 {U+7C7B}型的{U+7F16}{U+7801}{U+89C4}{U+5219}和排列{U+987A}序是未指定的，並且可能因程序而異。
* {U+5934}文件：`typeinfo`

<details><summary>typeid、type_info 使用</summary>

```cpp
class Flyable                       // 能{U+98DE}的
{
public:
    virtual void takeoff() = 0;     // 起{U+98DE}
    virtual void land() = 0;        // 降落
};
class Bird : public Flyable         // {U+9E1F}
{
public:
    void foraging() {...}           // {U+89C5}食
    virtual void takeoff() {...}
    virtual void land() {...}
};
class Plane : public Flyable        // {U+98DE}機
{
public:
    void carry() {...}              // {U+8FD0}{U+8F93}
    virtual void take off() {...}
    virtual void land() {...}
};

class type_info
{
public:
    const char* name() const;
    bool operator == (const type_info & rhs) const;
    bool operator != (const type_info & rhs) const;
    int before(const type_info & rhs) const;
    virtual ~type_info();
private:
    ...
};

class doSomething(Flyable *obj)                 // 做些事情
{
    obj->takeoff();

    cout << typeid(*obj).name() << endl;        // {U+8F93}出{U+4F20}入{U+5BF9}象{U+7C7B}型（"class Bird" or "class Plane"）

    if(typeid(*obj) == typeid(Bird))            // 判{U+65AD}{U+5BF9}象{U+7C7B}型
    {
        Bird *bird = dynamic_cast<Bird *>(obj); // {U+5BF9}象{U+8F6C}化
        bird->foraging();
    }

    obj->land();
};
```

</details>

### Effective C++

1. {U+89C6} C++ {U+4E3A}一{U+4E2A}{U+8BED}言{U+8054}邦（C、Object-Oriented C++、Template C++、STL）
2. 寧可以{U+7F16}{U+8BD1}器替{U+6362}{U+9884}{U+5904}理器（{U+5C3D}量以 `const`、`enum`、`inline` 替{U+6362} `#define`）
3. {U+5C3D}可能使用 const
4. 確定{U+5BF9}象被使用前已先被初始化（構造{U+65F6}{U+8D4B}值（copy 構造函{U+6570}）比 default 構造後{U+8D4B}值（copy assignment）效率高）
5. 了解 C++ 默默{U+7F16}{U+5199}並{U+8C03}用哪些函{U+6570}（{U+7F16}{U+8BD1}器暗自{U+4E3A} class {U+521B}建 default 構造函{U+6570}、copy 構造函{U+6570}、copy assignment 操作符、析構函{U+6570}）
6. 若不想使用{U+7F16}{U+8BD1}器自{U+52A8}生成的函{U+6570}，就{U+5E94}{U+8BE5}明確拒{U+7EDD}（{U+5C06}不想使用的成{U+5458}函{U+6570}{U+58F0}明{U+4E3A} private，並且不予{U+5B9E}{U+73B0}）
7. {U+4E3A}多{U+6001}基{U+7C7B}{U+58F0}明 virtual 析構函{U+6570}（如果 class {U+5E26}有任何 virtual 函{U+6570}，它就{U+5E94}{U+8BE5}{U+62E5}有一{U+4E2A} virtual 析構函{U+6570}）
8. {U+522B}{U+8BA9}異常逃離析構函{U+6570}（析構函{U+6570}{U+5E94}{U+8BE5}吞下不{U+4F20}播異常，或者{U+7ED3}束程序，而不是吐出異常；如果要{U+5904}理異常{U+5E94}{U+8BE5}在非析構的普通函{U+6570}{U+5904}理）
9. {U+7EDD}不在構造和析構{U+8FC7}程中{U+8C03}用 virtual 函{U+6570}（因{U+4E3A}{U+8FD9}{U+7C7B}{U+8C03}用{U+4ECE}不下降至 derived class）
10. 令 `operator=` 返回一{U+4E2A} `reference to *this` （用於{U+8FDE}{U+9501}{U+8D4B}值）
11. 在 `operator=` 中{U+5904}理 「自我{U+8D4B}值」
12. {U+8D4B}值{U+5BF9}象{U+65F6}{U+5E94}確保複制 「{U+5BF9}象{U+5185}的所有成{U+5458}{U+53D8}量」 及 「所有 base class 成分」（{U+8C03}用基{U+7C7B}複制構造函{U+6570}）
13. 以{U+5BF9}象管理{U+8D44}源（{U+8D44}源在構造函{U+6570}{U+83B7}得，在析構函{U+6570}{U+91CA}放，建{U+8BAE}使用智能指{U+9488}，{U+8D44}源取得{U+65F6}機便是初始化{U+65F6}機（Resource Acquisition Is Initialization，RAII））
14. 在{U+8D44}源管理{U+7C7B}中小心 copying 行{U+4E3A}（普遍的 RAII class copying 行{U+4E3A}是：抑制 copying、引用{U+8BA1}{U+6570}、深度拷{U+8D1D}、{U+8F6C}移底部{U+8D44}源{U+62E5}有{U+6743}（{U+7C7B}似 auto_ptr））
15. 在{U+8D44}源管理{U+7C7B}中提供{U+5BF9}原始{U+8D44}源（raw resources）的{U+8BBF}{U+95EE}（{U+5BF9}原始{U+8D44}源的{U+8BBF}{U+95EE}可能{U+7ECF}{U+8FC7}{U+663E}式{U+8F6C}{U+6362}或{U+9690}式{U+8F6C}{U+6362}，一般而言{U+663E}示{U+8F6C}{U+6362}比{U+8F83}安全，{U+9690}式{U+8F6C}{U+6362}{U+5BF9}客{U+6237}比{U+8F83}方便）
16. 成{U+5BF9}使用 new 和 delete {U+65F6}要采取相同形式（`new` 中使用 `[]` {U+5219} `delete []`，`new` 中不使用 `[]` {U+5219} `delete`）
17. 以{U+72EC}立{U+8BED}句{U+5C06} newed {U+5BF9}象存{U+50A8}於（置入）智能指{U+9488}（如果不{U+8FD9}{U+6837}做，可能{U+4F1A}因{U+4E3A}{U+7F16}{U+8BD1}器優化，{U+5BFC}致{U+96BE}以察{U+89C9}的{U+8D44}源泄漏）
18. {U+8BA9}接口容易被正確使用，不易被{U+8BEF}用（促{U+8FDB}正常使用的{U+529E}法：接口的一致性、{U+5185}置{U+7C7B}型的行{U+4E3A}兼容；阻止{U+8BEF}用的{U+529E}法：建立新{U+7C7B}型，限制{U+7C7B}型上的操作，{U+7EA6}束{U+5BF9}象值、消除客{U+6237}的{U+8D44}源管理{U+8D23}任）
19. {U+8BBE}{U+8BA1} class {U+72B9}如{U+8BBE}{U+8BA1} type，需要考{U+8651}{U+5BF9}象{U+521B}建、{U+9500}{U+6BC1}、初始化、{U+8D4B}值、值{U+4F20}{U+9012}、合法值、{U+7EE7}承{U+5173}系、{U+8F6C}{U+6362}、一般化等等。
20. 寧以 pass-by-reference-to-const 替{U+6362} pass-by-value （前者通常更高效、避免切割{U+95EE}{U+9898}（slicing problem），但不適用於{U+5185}置{U+7C7B}型、STL迭代器、函{U+6570}{U+5BF9}象）
21. 必{U+987B}返回{U+5BF9}象{U+65F6}，{U+522B}妄想返回其 reference（{U+7EDD}不返回 pointer 或 reference 指向一{U+4E2A} local stack {U+5BF9}象，或返回 reference 指向一{U+4E2A} heap-allocated {U+5BF9}象，或返回 pointer 或 reference 指向一{U+4E2A} local static {U+5BF9}象而有可能同{U+65F6}需要多{U+4E2A}{U+8FD9}{U+6837}的{U+5BF9}象。）
22. {U+5C06}成{U+5458}{U+53D8}量{U+58F0}明{U+4E3A} private（{U+4E3A}了封{U+88C5}、一致性、{U+5BF9}其{U+8BFB}{U+5199}精確控制等）
23. 寧以 non-member、non-friend 替{U+6362} member 函{U+6570}（可增加封{U+88C5}性、包裹{U+5F39}性（packaging flexibility）、機能{U+6269}充性）
24. 若所有{U+53C2}{U+6570}（包括被this指{U+9488}所指的那{U+4E2A}{U+9690}喻{U+53C2}{U+6570}）皆{U+987B}要{U+7C7B}型{U+8F6C}{U+6362}，{U+8BF7}{U+4E3A}此采用 non-member 函{U+6570}
25. 考{U+8651}{U+5199}一{U+4E2A}不{U+629B}異常的 swap 函{U+6570}
26. {U+5C3D}可能延後{U+53D8}量定{U+4E49}式的出{U+73B0}{U+65F6}{U+95F4}（可增加程序清晰度並改善程序效率）
27. {U+5C3D}量少做{U+8F6C}型{U+52A8}作（{U+65E7}式：`(T)expression`、`T(expression)`；新式：`const_cast<T>(expression)`、`dynamic_cast<T>(expression)`、`reinterpret_cast<T>(expression)`、`static_cast<T>(expression)`、；{U+5C3D}量避免{U+8F6C}型、注重效率避免 dynamic_casts、{U+5C3D}量{U+8BBE}{U+8BA1}成{U+65E0}需{U+8F6C}型、可把{U+8F6C}型封{U+88C5}成函{U+6570}、寧可用新式{U+8F6C}型）
28. 避免使用 handles（包括 引用、指{U+9488}、迭代器）指向{U+5BF9}象{U+5185}部（以增加封{U+88C5}性、使 const 成{U+5458}函{U+6570}的行{U+4E3A}更像 const、降低 「{U+865A}吊{U+53F7}{U+7801}牌」（dangling handles，如{U+60AC}空指{U+9488}等）的可能性）
29. {U+4E3A} 「異常安全」 而努力是值得的（異常安全函{U+6570}（Exception-safe functions）即使{U+53D1}生異常也不{U+4F1A}泄露{U+8D44}源或允{U+8BB8}任何{U+6570}據{U+7ED3}構{U+8D25}壞，分{U+4E3A}三種可能的保{U+8BC1}：基本型、{U+5F3A}列型、不{U+629B}異常型）
30. 透{U+5F7B}了解 inlining 的裏裏外外（inlining 在大多{U+6570} C++ 程序中是{U+7F16}{U+8BD1}期的行{U+4E3A}；inline 函{U+6570}是否真正 inline，取{U+51B3}於{U+7F16}{U+8BD1}器；大部分{U+7F16}{U+8BD1}器拒{U+7EDD}太{U+8FC7}複{U+6742}（如{U+5E26}有循{U+73AF}或{U+9012}{U+5F52}）的函{U+6570} inlining，而所有{U+5BF9} virtual 函{U+6570}的{U+8C03}用（除非是最平淡{U+65E0}奇的）也都{U+4F1A}使 inlining 落空；inline 造成的代{U+7801}膨{U+80C0}可能{U+5E26}{U+6765}效率{U+635F}失；inline 函{U+6570}{U+65E0}法{U+968F}{U+7740}程序{U+5E93}的升{U+7EA7}而升{U+7EA7}）
31. {U+5C06}文件{U+95F4}的{U+7F16}{U+8BD1}依存{U+5173}系降至最低（如果使用 object references 或 object pointers 可以完成任{U+52A1}，就不要使用 objects；如果能{U+8FC7}{U+591F}，{U+5C3D}量以 class {U+58F0}明式替{U+6362} class 定{U+4E49}式；{U+4E3A}{U+58F0}明式和定{U+4E49}式提供不同的{U+5934}文件）
32. 確定你的 public {U+7EE7}承塑模出 is-a {U+5173}系（適用於 base classes 身上的每一件事情一定適用於 derived classes 身上，因{U+4E3A}每一{U+4E2A} derived class {U+5BF9}象也都是一{U+4E2A} base class {U+5BF9}象）
33. 避免遮掩{U+7EE7}承而{U+6765}的名字（可使用 using {U+58F0}明式或{U+8F6C}交函{U+6570}（forwarding functions）{U+6765}{U+8BA9}被遮掩的名字再{U+89C1}天日）
34. {U+533A}分接口{U+7EE7}承和{U+5B9E}{U+73B0}{U+7EE7}承（在 public {U+7EE7}承之下，derived classes {U+603B}是{U+7EE7}承 base class 的接口；pure virtual 函{U+6570}只具體指定接口{U+7EE7}承；非{U+7EAF} impure virtual 函{U+6570}具體指定接口{U+7EE7}承及缺省{U+5B9E}{U+73B0}{U+7EE7}承；non-virtual 函{U+6570}具體指定接口{U+7EE7}承以及{U+5F3A}制性{U+5B9E}{U+73B0}{U+7EE7}承）
35. 考{U+8651} virtual 函{U+6570}以外的其他{U+9009}{U+62E9}（如 Template Method {U+8BBE}{U+8BA1}模式的 non-virtual interface（NVI）手法，{U+5C06} virtual 函{U+6570}替{U+6362}{U+4E3A} 「函{U+6570}指{U+9488}成{U+5458}{U+53D8}量」，以 `tr1::function` 成{U+5458}{U+53D8}量替{U+6362} virtual 函{U+6570}，{U+5C06}{U+7EE7}承體系{U+5185}的 virtual 函{U+6570}替{U+6362}{U+4E3A}另一{U+4E2A}{U+7EE7}承體系{U+5185}的 virtual 函{U+6570}）
36. {U+7EDD}不重新定{U+4E49}{U+7EE7}承而{U+6765}的 non-virtual 函{U+6570}
37. {U+7EDD}不重新定{U+4E49}{U+7EE7}承而{U+6765}的缺省{U+53C2}{U+6570}值，因{U+4E3A}缺省{U+53C2}{U+6570}值是{U+9759}{U+6001}{U+7ED1}定（statically bound），而 virtual 函{U+6570}{U+5374}是{U+52A8}{U+6001}{U+7ED1}定（dynamically bound）

### Google C++ Style Guide

> 英文：[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)  
> 中文：[C++ {U+98CE}格指南](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/)
<details><summary>Google C++ Style Guide {U+56FE}</summary>

![Google C++ Style Guide](images/GoogleCppStyleGuide.png)

> {U+56FE}片{U+6765}源於：[CSDN . 一{U+5F20}{U+56FE}{U+603B}{U+7ED3}Google C++{U+7F16}程{U+89C4}範(Google C++ Style Guide)](https://blog.csdn.net/voidccc/article/details/37599203)

</details>

## STL

### 索引

[STL 方法含{U+4E49}](https://github.com/huihut/interview/tree/master/STL)

### 容器

容器 | 底{U+5C42}{U+6570}據{U+7ED3}構 | {U+65F6}{U+95F4}複{U+6742}度 | 有{U+65E0}序 | 可不可重複 | 其他
---|---|---|---|---|---
[array](https://github.com/huihut/interview/tree/master/STL#array)|{U+6570}{U+7EC4}|{U+968F}機{U+8BFB}改 O(1)|{U+65E0}序|可重複|支持快速{U+968F}機{U+8BBF}{U+95EE}
[vector](https://github.com/huihut/interview/tree/master/STL#vector)|{U+6570}{U+7EC4}|{U+968F}機{U+8BFB}改、尾部插入、尾部{U+5220}除 O(1)<br/>{U+5934}部插入、{U+5934}部{U+5220}除 O(n)|{U+65E0}序|可重複|支持快速{U+968F}機{U+8BBF}{U+95EE}
[list](https://github.com/huihut/interview/tree/master/STL#list)|{U+53CC}向{U+94FE}表|插入、{U+5220}除 O(1)<br/>{U+968F}機{U+8BFB}改 O(n)|{U+65E0}序|可重複|支持快速增{U+5220}
[deque](https://github.com/huihut/interview/tree/master/STL#deque)|{U+53CC}端{U+961F}列|{U+5934}尾插入、{U+5934}尾{U+5220}除 O(1)|{U+65E0}序|可重複|一{U+4E2A}中央控制器 + 多{U+4E2A}{U+7F13}{U+51B2}{U+533A}，支持首尾快速增{U+5220}，支持{U+968F}機{U+8BBF}{U+95EE}
[stack](https://github.com/huihut/interview/tree/master/STL#stack)|deque / list|{U+9876}部插入、{U+9876}部{U+5220}除 O(1)|{U+65E0}序|可重複|deque 或 list 封{U+95ED}{U+5934}端{U+5F00}口，不用 vector 的原因{U+5E94}{U+8BE5}是容量大小有限制，{U+6269}容耗{U+65F6}
[queue](https://github.com/huihut/interview/tree/master/STL#queue)|deque / list|尾部插入、{U+5934}部{U+5220}除 O(1)|{U+65E0}序|可重複|deque 或 list 封{U+95ED}{U+5934}端{U+5F00}口，不用 vector 的原因{U+5E94}{U+8BE5}是容量大小有限制，{U+6269}容耗{U+65F6}
[priority_queue](https://github.com/huihut/interview/tree/master/STL#priority_queue)|vector + max-heap|插入、{U+5220}除 O(log<sub>2</sub>n)|有序|可重複|vector容器+heap{U+5904}理{U+89C4}{U+5219}
[set](https://github.com/huihut/interview/tree/master/STL#set)|{U+7EA2}黑{U+6811}|插入、{U+5220}除、查找 O(log<sub>2</sub>n)|有序|不可重複|
[multiset](https://github.com/huihut/interview/tree/master/STL#multiset)|{U+7EA2}黑{U+6811}|插入、{U+5220}除、查找 O(log<sub>2</sub>n)|有序|可重複|
[map](https://github.com/huihut/interview/tree/master/STL#map)|{U+7EA2}黑{U+6811}|插入、{U+5220}除、查找 O(log<sub>2</sub>n)|有序|不可重複|
[multimap](https://github.com/huihut/interview/tree/master/STL#multimap)|{U+7EA2}黑{U+6811}|插入、{U+5220}除、查找 O(log<sub>2</sub>n)|有序|可重複|
hash_set|哈希表|插入、{U+5220}除、查找 O(1) 最差 O(n)|{U+65E0}序|不可重複|
hash_multiset|哈希表|插入、{U+5220}除、查找 O(1) 最差 O(n)|{U+65E0}序|可重複|
hash_map|哈希表|插入、{U+5220}除、查找 O(1) 最差 O(n)|{U+65E0}序|不可重複|
hash_multimap|哈希表|插入、{U+5220}除、查找 O(1) 最差 O(n)|{U+65E0}序|可重複|

### 算法

算法 | 底{U+5C42}算法 | {U+65F6}{U+95F4}複{U+6742}度 | 可不可重複
---|---|---|---
[find](http://www.cplusplus.com/reference/algorithm/find/)|{U+987A}序查找|O(n)|可重複
[sort](https://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/include/bits/stl_algo.h#L4808)|[{U+5185}省排序](https://en.wikipedia.org/wiki/Introsort)|O(n*log<sub>2</sub>n)|可重複

## {U+6570}據{U+7ED3}構

### {U+987A}序{U+7ED3}構

#### {U+987A}序{U+6808}（Sequence Stack）

[SqStack.cpp](DataStructure/SqStack.cpp)

<details><summary>{U+987A}序{U+6808}{U+6570}據{U+7ED3}構和{U+56FE}片</summary>

```cpp
typedef struct {
	ElemType *elem;
	int top;
	int size;
	int increment;
} SqSrack;
```

![](images/SqStack.png)

</details>

#### {U+961F}列（Sequence Queue）

<details><summary>{U+961F}列{U+6570}據{U+7ED3}構</summary>

```cpp
typedef struct {
	ElemType * elem;
	int front;
	int rear;
	int maxSize;
}SqQueue;
```

</details>

##### 非循{U+73AF}{U+961F}列

<details><summary>非循{U+73AF}{U+961F}列{U+56FE}片</summary>

![](images/SqQueue.png)

`SqQueue.rear++`

</details>

##### 循{U+73AF}{U+961F}列

<details><summary>循{U+73AF}{U+961F}列{U+56FE}片</summary>

![](images/SqLoopStack.png)

`SqQueue.rear = (SqQueue.rear + 1) % SqQueue.maxSize`

</details>

#### {U+987A}序表（Sequence List）

[SqList.cpp](DataStructure/SqList.cpp)

<details><summary>{U+987A}序表{U+6570}據{U+7ED3}構和{U+56FE}片</summary>

```cpp
typedef struct {
	ElemType *elem;
	int length;
	int size;
	int increment;
} SqList;
```

![](images/SqList.png)

</details>


### {U+94FE}式{U+7ED3}構

[LinkList.cpp](DataStructure/LinkList.cpp)

[LinkList_with_head.cpp](DataStructure/LinkList_with_head.cpp)

<details><summary>{U+94FE}式{U+6570}據{U+7ED3}構</summary>

```cpp
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList; 
```

</details>

#### {U+94FE}{U+961F}列（Link Queue）

<details><summary>{U+94FE}{U+961F}列{U+56FE}片</summary>

![](images/LinkQueue.png)

</details>

#### {U+7EBF}性表的{U+94FE}式表示

##### {U+5355}{U+94FE}表（Link List）

<details><summary>{U+5355}{U+94FE}表{U+56FE}片</summary>

![](images/LinkList.png)

</details>


##### {U+53CC}向{U+94FE}表（Du-Link-List）

<details><summary>{U+53CC}向{U+94FE}表{U+56FE}片</summary>

![](images/DuLinkList.png)

</details>

##### 循{U+73AF}{U+94FE}表（Cir-Link-List）

<details><summary>循{U+73AF}{U+94FE}表{U+56FE}片</summary>

![](images/CirLinkList.png)

</details>

### 哈希表

[HashTable.cpp](DataStructure/HashTable.cpp)

#### 概念

哈希函{U+6570}：`H(key): K -> D , key {U+2208} K`

#### 構造方法

* 直接定址法
* 除留餘{U+6570}法
* {U+6570}字分析法
* 折{U+53E0}法
* 平方取中法

#### {U+51B2}突{U+5904}理方法

* {U+94FE}地址法：key 相同的用{U+5355}{U+94FE}表{U+94FE}接
* {U+5F00}放定址法
    * {U+7EBF}性探{U+6D4B}法：key 相同 -> 放到 key 的下一{U+4E2A}位置，`Hi = (H(key) + i) % m`
    * 二次探{U+6D4B}法：key 相同 -> 放到 `Di = 1^2, -1^2, ..., ±（k)^2,(k<=m/2）`
    * {U+968F}機探{U+6D4B}法：`H = (H(key) + {U+4F2A}{U+968F}機{U+6570}) % m`

#### {U+7EBF}性探{U+6D4B}的哈希表{U+6570}據{U+7ED3}構

<details><summary>{U+7EBF}性探{U+6D4B}的哈希表{U+6570}據{U+7ED3}構和{U+56FE}片</summary>

```cpp
typedef char KeyType;

typedef struct {
	KeyType key;
}RcdType;

typedef struct {
	RcdType *rcd;
	int size;
	int count;
	bool *tag;
}HashTable;
```

![](images/HashTable.png)

</details>


### {U+9012}{U+5F52}

#### 概念

函{U+6570}直接或{U+95F4}接地{U+8C03}用自身

#### {U+9012}{U+5F52}與分治

* 分治法
    * {U+95EE}{U+9898}的分解
    * {U+95EE}{U+9898}{U+89C4}模的分解
* 折半查找（{U+9012}{U+5F52}）
* {U+5F52}並查找（{U+9012}{U+5F52}）
* 快速排序（{U+9012}{U+5F52}）

#### {U+9012}{U+5F52}與迭代

* 迭代：反複利用{U+53D8}量{U+65E7}值推出新值
* 折半查找（迭代）
* {U+5F52}並查找（迭代）

#### {U+5E7F}{U+4E49}表

##### {U+5934}尾{U+94FE}表存{U+50A8}表示

<details><summary>{U+5E7F}{U+4E49}表的{U+5934}尾{U+94FE}表存{U+50A8}表示和{U+56FE}片</summary>

```cpp
// {U+5E7F}{U+4E49}表的{U+5934}尾{U+94FE}表存{U+50A8}表示
typedef enum {ATOM, LIST} ElemTag;
// ATOM==0：原子，LIST==1：子表
typedef struct GLNode {
    ElemTag tag;
    // 公共部分，用於{U+533A}分原子{U+7ED3}{U+70B9}和表{U+7ED3}{U+70B9}
    union {
        // 原子{U+7ED3}{U+70B9}和表{U+7ED3}{U+70B9}的{U+8054}合部分
        AtomType atom;
        // atom 是原子{U+7ED3}{U+70B9}的值域，AtomType 由用{U+6237}定{U+4E49}
        struct {
            struct GLNode *hp, *tp;
        } ptr;
        // ptr 是表{U+7ED3}{U+70B9}的指{U+9488}域，prt.hp 和 ptr.tp 分{U+522B}指向表{U+5934}和表尾
    } a;
} *GList, GLNode;
```

![](images/GeneralizedList1.png)

</details>

##### {U+6269}展{U+7EBF}性{U+94FE}表存{U+50A8}表示

<details><summary>{U+6269}展{U+7EBF}性{U+94FE}表存{U+50A8}表示和{U+56FE}片</summary>

```cpp
// {U+5E7F}{U+4E49}表的{U+6269}展{U+7EBF}性{U+94FE}表存{U+50A8}表示
typedef enum {ATOM, LIST} ElemTag;
// ATOM==0：原子，LIST==1：子表
typedef struct GLNode1 {
    ElemTag tag;
    // 公共部分，用於{U+533A}分原子{U+7ED3}{U+70B9}和表{U+7ED3}{U+70B9}
    union {
        // 原子{U+7ED3}{U+70B9}和表{U+7ED3}{U+70B9}的{U+8054}合部分
        AtomType atom; // 原子{U+7ED3}{U+70B9}的值域
        struct GLNode1 *hp; // 表{U+7ED3}{U+70B9}的表{U+5934}指{U+9488}
    } a;
    struct GLNode1 *tp;
    // 相{U+5F53}於{U+7EBF}性{U+94FE}表的 next，指向下一{U+4E2A}元素{U+7ED3}{U+70B9}
} *GList1, GLNode1;
```

![](images/GeneralizedList2.png)

</details>

### 二叉{U+6811}

[BinaryTree.cpp](DataStructure/BinaryTree.cpp)

#### 性{U+8D28}

1. 非空二叉{U+6811}第 i {U+5C42}最多 2<sup>(i-1)</sup> {U+4E2A}{U+7ED3}{U+70B9} （i >= 1）
2. 深度{U+4E3A} k 的二叉{U+6811}最多 2<sup>k</sup> - 1 {U+4E2A}{U+7ED3}{U+70B9} （k >= 1）
3. 度{U+4E3A} 0 的{U+7ED3}{U+70B9}{U+6570}{U+4E3A} n<sub>0</sub>，度{U+4E3A} 2 的{U+7ED3}{U+70B9}{U+6570}{U+4E3A} n<sub>2</sub>，{U+5219} n<sub>0</sub> = n<sub>2</sub> + 1
4. 有 n {U+4E2A}{U+7ED3}{U+70B9}的完全二叉{U+6811}深度 k = {U+230A} log<sub>2</sub>(n) {U+230B} + 1 
5. {U+5BF9}於含 n {U+4E2A}{U+7ED3}{U+70B9}的完全二叉{U+6811}中{U+7F16}{U+53F7}{U+4E3A} i （1 <= i <= n） 的{U+7ED3}{U+70B9}
    1. 若 i = 1，{U+4E3A}根，否{U+5219}{U+53CC}{U+4EB2}{U+4E3A} {U+230A} i / 2 {U+230B}
    2. 若 2i > n，{U+5219} i {U+7ED3}{U+70B9}{U+6CA1}有左孩子，否{U+5219}孩子{U+7F16}{U+53F7}{U+4E3A} 2i
    3. 若 2i + 1 > n，{U+5219} i {U+7ED3}{U+70B9}{U+6CA1}有右孩子，否{U+5219}孩子{U+7F16}{U+53F7}{U+4E3A} 2i + 1

#### 存{U+50A8}{U+7ED3}構

<details><summary>二叉{U+6811}{U+6570}據{U+7ED3}構</summary>

```cpp
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
```

</details>


##### {U+987A}序存{U+50A8}

<details><summary>二叉{U+6811}{U+987A}序存{U+50A8}{U+56FE}片</summary>

![](images/SqBinaryTree.png)

</details>

##### {U+94FE}式存{U+50A8}

<details><summary>二叉{U+6811}{U+94FE}式存{U+50A8}{U+56FE}片</summary>

![](images/LinkBinaryTree.png)

</details>

#### 遍{U+5386}方式

* 先序遍{U+5386}
* 中序遍{U+5386}
* 後{U+7EED}遍{U+5386}
* {U+5C42}次遍{U+5386}

#### 分{U+7C7B}

* {U+6EE1}二叉{U+6811}
* 完全二叉{U+6811}（堆）
    * 大{U+9876}堆：根 >= 左 && 根 >= 右
    * 小{U+9876}堆：根 <= 左 && 根 <= 右
* 二叉查找{U+6811}（二叉排序{U+6811}）：左 < 根 < 右
* 平衡二叉{U+6811}（AVL{U+6811}）：| 左子{U+6811}{U+6811}高 - 右子{U+6811}{U+6811}高 | <= 1
* 最小失衡{U+6811}：平衡二叉{U+6811}插入新{U+7ED3}{U+70B9}{U+5BFC}致失衡的子{U+6811}：{U+8C03}整：
    * LL型：根的左孩子右旋
    * RR型：根的右孩子左旋
    * LR型：根的左孩子左旋，再右旋
    * RL型：右孩子的左子{U+6811}，先右旋，再左旋

### 其他{U+6811}及森林

#### {U+6811}的存{U+50A8}{U+7ED3}構

* {U+53CC}{U+4EB2}表示法
* {U+53CC}{U+4EB2}孩子表示法
* 孩子兄弟表示法

#### 並查集

一種不相交的子集所構成的集合 S = {S1, S2, ..., Sn}

#### 平衡二叉{U+6811}（AVL{U+6811}）

##### 性{U+8D28}

* | 左子{U+6811}{U+6811}高 - 右子{U+6811}{U+6811}高 | <= 1
* 平衡二叉{U+6811}必定是二叉搜索{U+6811}，反之{U+5219}不一定
* 最小二叉平衡{U+6811}的{U+8282}{U+70B9}的公式：`F(n)=F(n-1)+F(n-2)+1` （1 是根{U+8282}{U+70B9}，F(n-1) 是左子{U+6811}的{U+8282}{U+70B9}{U+6570}量，F(n-2) 是右子{U+6811}的{U+8282}{U+70B9}{U+6570}量）

<details><summary>平衡二叉{U+6811}{U+56FE}片</summary>

![](images/Self-balancingBinarySearchTree.png)

</details>

##### 最小失衡{U+6811}

平衡二叉{U+6811}插入新{U+7ED3}{U+70B9}{U+5BFC}致失衡的子{U+6811}

{U+8C03}整：

* LL 型：根的左孩子右旋
* RR 型：根的右孩子左旋
* LR 型：根的左孩子左旋，再右旋
* RL 型：右孩子的左子{U+6811}，先右旋，再左旋

#### {U+7EA2}黑{U+6811}

##### {U+7EA2}黑{U+6811}的特征是什麼？

1. {U+8282}{U+70B9}是{U+7EA2}色或黑色。
2. 根是黑色。
3. 所有{U+53F6}子都是黑色（{U+53F6}子是 NIL {U+8282}{U+70B9}）。
4. 每{U+4E2A}{U+7EA2}色{U+8282}{U+70B9}必{U+987B}有{U+4E24}{U+4E2A}黑色的子{U+8282}{U+70B9}。（{U+4ECE}每{U+4E2A}{U+53F6}子到根的所有路{U+5F84}上不能有{U+4E24}{U+4E2A}{U+8FDE}{U+7EED}的{U+7EA2}色{U+8282}{U+70B9}。）（新增{U+8282}{U+70B9}的父{U+8282}{U+70B9}必{U+987B}相同）
5. {U+4ECE}任一{U+8282}{U+70B9}到其每{U+4E2A}{U+53F6}子的所有{U+7B80}{U+5355}路{U+5F84}都包含相同{U+6570}目的黑色{U+8282}{U+70B9}。（新增{U+8282}{U+70B9}必{U+987B}{U+4E3A}{U+7EA2}）

##### {U+8C03}整

1. {U+53D8}色
2. 左旋
3. 右旋

##### {U+5E94}用

* {U+5173}{U+8054}{U+6570}{U+7EC4}：如 STL 中的 map、set

##### {U+7EA2}黑{U+6811}、B {U+6811}、B+ {U+6811}的{U+533A}{U+522B}？

* {U+7EA2}黑{U+6811}的深度比{U+8F83}大，而 B {U+6811}和 B+ {U+6811}的深度{U+5219}相{U+5BF9}要小一些
* B+ {U+6811}{U+5219}{U+5C06}{U+6570}據都保存在{U+53F6}子{U+8282}{U+70B9}，同{U+65F6}通{U+8FC7}{U+94FE}表的形式{U+5C06}他{U+4EEC}{U+8FDE}接在一起。

#### B {U+6811}（B-tree）、B+ {U+6811}（B+-tree）

<details><summary>B {U+6811}、B+ {U+6811}{U+56FE}片</summary>

![B {U+6811}（B-tree）、B+ {U+6811}（B+-tree）](https://i.stack.imgur.com/l6UyF.png)

</details>

##### 特{U+70B9}

* 一般化的二叉查找{U+6811}（binary search tree）
* 「矮胖」，{U+5185}部（非{U+53F6}子）{U+8282}{U+70B9}可以{U+62E5}有可{U+53D8}{U+6570}量的子{U+8282}{U+70B9}（{U+6570}量範{U+56F4}{U+9884}先定{U+4E49}好）

##### {U+5E94}用

* 大部分文件系{U+7EDF}、{U+6570}據{U+5E93}系{U+7EDF}都采用B{U+6811}、B+{U+6811}作{U+4E3A}索引{U+7ED3}構

##### {U+533A}{U+522B}

* B+{U+6811}中只有{U+53F6}子{U+8282}{U+70B9}{U+4F1A}{U+5E26}有指向{U+8BB0}{U+5F55}的指{U+9488}（ROWID），而B{U+6811}{U+5219}所有{U+8282}{U+70B9}都{U+5E26}有，在{U+5185}部{U+8282}{U+70B9}出{U+73B0}的索引{U+9879}不{U+4F1A}再出{U+73B0}在{U+53F6}子{U+8282}{U+70B9}中。
* B+{U+6811}中所有{U+53F6}子{U+8282}{U+70B9}都是通{U+8FC7}指{U+9488}{U+8FDE}接在一起，而B{U+6811}不{U+4F1A}。

##### B{U+6811}的優{U+70B9}

{U+5BF9}於在{U+5185}部{U+8282}{U+70B9}的{U+6570}據，可直接得到，不必根據{U+53F6}子{U+8282}{U+70B9}{U+6765}定位。

##### B+{U+6811}的優{U+70B9}

* 非{U+53F6}子{U+8282}{U+70B9}不{U+4F1A}{U+5E26}上 ROWID，{U+8FD9}{U+6837}，一{U+4E2A}{U+5757}中可以容{U+7EB3}更多的索引{U+9879}，一是可以降低{U+6811}的高度。二是一{U+4E2A}{U+5185}部{U+8282}{U+70B9}可以定位更多的{U+53F6}子{U+8282}{U+70B9}。
* {U+53F6}子{U+8282}{U+70B9}之{U+95F4}通{U+8FC7}指{U+9488}{U+6765}{U+8FDE}接，範{U+56F4}{U+626B}描{U+5C06}十分{U+7B80}{U+5355}，而{U+5BF9}於B{U+6811}{U+6765}{U+8BF4}，{U+5219}需要在{U+53F6}子{U+8282}{U+70B9}和{U+5185}部{U+8282}{U+70B9}不停的往返移{U+52A8}。

> B {U+6811}、B+ {U+6811}{U+533A}{U+522B}{U+6765}自：[differences-between-b-trees-and-b-trees](https://stackoverflow.com/questions/870218/differences-between-b-trees-and-b-trees)、[B{U+6811}和B+{U+6811}的{U+533A}{U+522B}](https://www.cnblogs.com/ivictor/p/5849061.html)

#### 八叉{U+6811}

<details><summary>八叉{U+6811}{U+56FE}片</summary>

![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/35/Octree2.png/400px-Octree2.png)

</details>

八叉{U+6811}（octree），或{U+79F0}八元{U+6811}，是一種用於描述三{U+7EF4}空{U+95F4}（劃分空{U+95F4}）的{U+6811}{U+72B6}{U+6570}據{U+7ED3}構。八叉{U+6811}的每{U+4E2A}{U+8282}{U+70B9}表示一{U+4E2A}正方體的體{U+79EF}元素，每{U+4E2A}{U+8282}{U+70B9}有八{U+4E2A}子{U+8282}{U+70B9}，{U+8FD9}八{U+4E2A}子{U+8282}{U+70B9}所表示的體{U+79EF}元素加在一起就等於父{U+8282}{U+70B9}的體{U+79EF}。一般中心{U+70B9}作{U+4E3A}{U+8282}{U+70B9}的分叉中心。

##### 用途

* 三{U+7EF4}{U+8BA1}算機{U+56FE}形
* 最{U+90BB}近搜索

## 算法

### 排序

排序算法 | 平均{U+65F6}{U+95F4}複{U+6742}度 | 最差{U+65F6}{U+95F4}複{U+6742}度 | 空{U+95F4}複{U+6742}度 | {U+6570}據{U+5BF9}象{U+7A33}定性
---|---|---|---|---
[冒泡排序](Algorithm/BubbleSort.h) | O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(1)|{U+7A33}定
[{U+9009}{U+62E9}排序](Algorithm/SelectionSort.h) | O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(1)|{U+6570}{U+7EC4}不{U+7A33}定、{U+94FE}表{U+7A33}定
[插入排序](Algorithm/InsertSort.h) | O(n<sup>2</sup>)|O(n<sup>2</sup>)|O(1)|{U+7A33}定
[快速排序](Algorithm/QuickSort.h) | O(n*log<sub>2</sub>n) |  O(n<sup>2</sup>) | O(log<sub>2</sub>n) | 不{U+7A33}定
[堆排序](Algorithm/HeapSort.cpp) | O(n*log<sub>2</sub>n)|O(n*log<sub>2</sub>n)|O(1)|不{U+7A33}定
[{U+5F52}並排序](Algorithm/MergeSort.h) | O(n*log<sub>2</sub>n) | O(n*log<sub>2</sub>n)|O(n)|{U+7A33}定
[希{U+5C14}排序](Algorithm/ShellSort.h) | O(n*log<sup>2</sup>n)|O(n<sup>2</sup>)|O(1)|不{U+7A33}定
[{U+8BA1}{U+6570}排序](Algorithm/CountSort.cpp) | O(n+m)|O(n+m)|O(n+m)|{U+7A33}定
[桶排序](Algorithm/BucketSort.cpp) | O(n)|O(n)|O(m)|{U+7A33}定
[基{U+6570}排序](Algorithm/RadixSort.h) | O(k*n)|O(n<sup>2</sup>)| |{U+7A33}定

> * 均按{U+4ECE}小到大排列
> * k：代表{U+6570}值中的 「{U+6570}位」 {U+4E2A}{U+6570}
> * n：代表{U+6570}據{U+89C4}模
> * m：代表{U+6570}據的最大值{U+51CF}最小值
> * {U+6765}自：[wikipedia . 排序算法](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)

### 查找

查找算法 | 平均{U+65F6}{U+95F4}複{U+6742}度 | 空{U+95F4}複{U+6742}度 | 查找{U+6761}件
---|---|---|---
[{U+987A}序查找](Algorithm/SequentialSearch.h) | O(n) | O(1) | {U+65E0}序或有序
[二分查找（折半查找）](Algorithm/BinarySearch.h) | O(log<sub>2</sub>n)| O(1) | 有序
[插值查找](Algorithm/InsertionSearch.h) | O(log<sub>2</sub>(log<sub>2</sub>n)) | O(1) | 有序
[斐波那契查找](Algorithm/FibonacciSearch.cpp) | O(log<sub>2</sub>n) | O(1) | 有序
[哈希查找](DataStructure/HashTable.cpp) | O(1) | O(n) | {U+65E0}序或有序
[二叉查找{U+6811}（二叉搜索{U+6811}查找）](Algorithm/BSTSearch.h) |O(log<sub>2</sub>n) |   | 
[{U+7EA2}黑{U+6811}](DataStructure/RedBlackTree.cpp) |O(log<sub>2</sub>n) | |
2-3{U+6811} | O(log<sub>2</sub>n - log<sub>3</sub>n) |   | 
B{U+6811}/B+{U+6811} |O(log<sub>2</sub>n) |   | 

### {U+56FE}搜索算法

{U+56FE}搜索算法 |{U+6570}據{U+7ED3}構| 遍{U+5386}{U+65F6}{U+95F4}複{U+6742}度 | 空{U+95F4}複{U+6742}度
---|---|---|---
[BFS{U+5E7F}度優先搜索](https://zh.wikipedia.org/wiki/%E5%B9%BF%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2)|{U+90BB}接矩{U+9635}<br/>{U+90BB}接{U+94FE}表|O(\|v\|<sup>2</sup>)<br/>O(\|v\|+\|E\|)|O(\|v\|<sup>2</sup>)<br/>O(\|v\|+\|E\|)
[DFS深度優先搜索](https://zh.wikipedia.org/wiki/%E6%B7%B1%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2)|{U+90BB}接矩{U+9635}<br/>{U+90BB}接{U+94FE}表|O(\|v\|<sup>2</sup>)<br/>O(\|v\|+\|E\|)|O(\|v\|<sup>2</sup>)<br/>O(\|v\|+\|E\|)

### 其他算法

算法 |思想| {U+5E94}用
---|---|---
[分治法](https://zh.wikipedia.org/wiki/%E5%88%86%E6%B2%BB%E6%B3%95)|把一{U+4E2A}複{U+6742}的{U+95EE}{U+9898}分成{U+4E24}{U+4E2A}或更多的相同或相似的子{U+95EE}{U+9898}，直到最後子{U+95EE}{U+9898}可以{U+7B80}{U+5355}的直接求解，原{U+95EE}{U+9898}的解即子{U+95EE}{U+9898}的解的合並|[循{U+73AF}{U+8D5B}日程安排{U+95EE}{U+9898}](https://github.com/huihut/interview/tree/master/Problems/RoundRobinProblem)、排序算法（快速排序、{U+5F52}並排序）
[{U+52A8}{U+6001}{U+89C4}劃](https://zh.wikipedia.org/wiki/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)|通{U+8FC7}把原{U+95EE}{U+9898}分解{U+4E3A}相{U+5BF9}{U+7B80}{U+5355}的子{U+95EE}{U+9898}的方式求解複{U+6742}{U+95EE}{U+9898}的方法，適用於有重{U+53E0}子{U+95EE}{U+9898}和最優子{U+7ED3}構性{U+8D28}的{U+95EE}{U+9898}|[背包{U+95EE}{U+9898}](https://github.com/huihut/interview/tree/master/Problems/KnapsackProblem)、斐波那契{U+6570}列
[{U+8D2A}心法](https://zh.wikipedia.org/wiki/%E8%B4%AA%E5%BF%83%E6%B3%95)|一種在每一步{U+9009}{U+62E9}中都采取在{U+5F53}前{U+72B6}{U+6001}下最好或最優（即最有利）的{U+9009}{U+62E9}，{U+4ECE}而希望{U+5BFC}致{U+7ED3}果是最好或最優的算法|旅行推{U+9500}{U+5458}{U+95EE}{U+9898}（最短路{U+5F84}{U+95EE}{U+9898}）、最小生成{U+6811}、哈夫曼{U+7F16}{U+7801}

## Problems

### Single Problem

* [Chessboard Coverage Problem（棋{U+76D8}覆{U+76D6}{U+95EE}{U+9898}）](Problems/ChessboardCoverageProblem)
* [Knapsack Problem（背包{U+95EE}{U+9898}）](Problems/KnapsackProblem)
* [Neumann Neighbor Problem（{U+51AF}{U+8BFA}依曼{U+90BB}居{U+95EE}{U+9898}）](Problems/NeumannNeighborProblem)
* [Round Robin Problem（循{U+73AF}{U+8D5B}日程安排{U+95EE}{U+9898}）](Problems/RoundRobinProblem)
* [Tubing Problem（{U+8F93}油管道{U+95EE}{U+9898}）](Problems/TubingProblem)

### Leetcode Problems

* [Github . haoel/leetcode](https://github.com/haoel/leetcode)
* [Github . pezy/LeetCode](https://github.com/pezy/LeetCode)

### {U+5251}指 Offer

* [Github . zhedahht/CodingInterviewChinese2](https://github.com/zhedahht/CodingInterviewChinese2)
* [Github . gatieme/CodingInterviews](https://github.com/gatieme/CodingInterviews)

### Cracking the Coding Interview 程序{U+5458}面{U+8BD5}金典

* [Github . careercup/ctci](https://github.com/careercup/ctci)
* [牛客網 . 程序{U+5458}面{U+8BD5}金典](https://www.nowcoder.com/ta/cracking-the-coding-interview)

### 牛客網

* [牛客網 . 在{U+7EBF}{U+7F16}程{U+4E13}{U+9898}](https://www.nowcoder.com/activity/oj)

## 操作系{U+7EDF}

### {U+8FDB}程與{U+7EBF}程

{U+5BF9}於有{U+7EBF}程系{U+7EDF}：
* {U+8FDB}程是{U+8D44}源分配的{U+72EC}立{U+5355}位
* {U+7EBF}程是{U+8D44}源{U+8C03}度的{U+72EC}立{U+5355}位

{U+5BF9}於{U+65E0}{U+7EBF}程系{U+7EDF}：
* {U+8FDB}程是{U+8D44}源{U+8C03}度、分配的{U+72EC}立{U+5355}位

#### {U+8FDB}程之{U+95F4}的通信方式以及優缺{U+70B9}

* 管道（PIPE）
    * 有名管道：一種半{U+53CC}工的通信方式，它允{U+8BB8}{U+65E0}{U+4EB2}{U+7F18}{U+5173}系{U+8FDB}程{U+95F4}的通信
        * 優{U+70B9}：可以{U+5B9E}{U+73B0}任意{U+5173}系的{U+8FDB}程{U+95F4}的通信
        * 缺{U+70B9}：
            1. {U+957F}期存於系{U+7EDF}中，使用不{U+5F53}容易出{U+9519}
            2. {U+7F13}{U+51B2}{U+533A}有限
    * {U+65E0}名管道：一種半{U+53CC}工的通信方式，只能在具有{U+4EB2}{U+7F18}{U+5173}系的{U+8FDB}程{U+95F4}使用（父子{U+8FDB}程）
        * 優{U+70B9}：{U+7B80}{U+5355}方便
        * 缺{U+70B9}：
            1. 局限於{U+5355}向通信 
            2. 只能{U+521B}建在它的{U+8FDB}程以及其有{U+4EB2}{U+7F18}{U+5173}系的{U+8FDB}程之{U+95F4}
            3. {U+7F13}{U+51B2}{U+533A}有限
* 信{U+53F7}量（Semaphore）：一{U+4E2A}{U+8BA1}{U+6570}器，可以用{U+6765}控制多{U+4E2A}{U+7EBF}程{U+5BF9}共享{U+8D44}源的{U+8BBF}{U+95EE}
    * 優{U+70B9}：可以同步{U+8FDB}程
    * 缺{U+70B9}：信{U+53F7}量有限
* 信{U+53F7}（Signal）：一種比{U+8F83}複{U+6742}的通信方式，用於通知接收{U+8FDB}程某{U+4E2A}事件已{U+7ECF}{U+53D1}生
* 消息{U+961F}列（Message Queue）：是消息的{U+94FE}表，存放在{U+5185}核中並由消息{U+961F}列{U+6807}{U+8BC6}符{U+6807}{U+8BC6}
    * 優{U+70B9}：可以{U+5B9E}{U+73B0}任意{U+8FDB}程{U+95F4}的通信，並通{U+8FC7}系{U+7EDF}{U+8C03}用函{U+6570}{U+6765}{U+5B9E}{U+73B0}消息{U+53D1}送和接收之{U+95F4}的同步，{U+65E0}需考{U+8651}同步{U+95EE}{U+9898}，方便
    * 缺{U+70B9}：信息的複制需要{U+989D}外消耗 CPU 的{U+65F6}{U+95F4}，不適宜於信息量大或操作{U+9891}繁的{U+573A}合
* 共享{U+5185}存（Shared Memory）：映射一段能被其他{U+8FDB}程所{U+8BBF}{U+95EE}的{U+5185}存，{U+8FD9}段共享{U+5185}存由一{U+4E2A}{U+8FDB}程{U+521B}建，但多{U+4E2A}{U+8FDB}程都可以{U+8BBF}{U+95EE}
    * 優{U+70B9}：{U+65E0}{U+987B}複制，快捷，信息量大
    * 缺{U+70B9}：
        1. 通信是通{U+8FC7}{U+5C06}共享空{U+95F4}{U+7F13}{U+51B2}{U+533A}直接附加到{U+8FDB}程的{U+865A}{U+62DF}地址空{U+95F4}中{U+6765}{U+5B9E}{U+73B0}的，因此{U+8FDB}程{U+95F4}的{U+8BFB}{U+5199}操作的同步{U+95EE}{U+9898}
        2. 利用{U+5185}存{U+7F13}{U+51B2}{U+533A}直接交{U+6362}信息，{U+5185}存的{U+5B9E}體存在於{U+8BA1}算機中，只能同一{U+4E2A}{U+8BA1}算機系{U+7EDF}中的{U+8BF8}多{U+8FDB}程共享，不方便網{U+7EDC}通信
* 套接字（Socket）：可用於不同及其{U+95F4}的{U+8FDB}程通信
    * 優{U+70B9}：
        1. {U+4F20}{U+8F93}{U+6570}據{U+4E3A}字{U+8282}{U+7EA7}，{U+4F20}{U+8F93}{U+6570}據可自定{U+4E49}，{U+6570}據量小效率高
        2. {U+4F20}{U+8F93}{U+6570}據{U+65F6}{U+95F4}短，性能高
        3. 適合於客{U+6237}端和服{U+52A1}器端之{U+95F4}信息{U+5B9E}{U+65F6}交互
        4. 可以加密,{U+6570}據安全性{U+5F3A}
    * 缺{U+70B9}：需{U+5BF9}{U+4F20}{U+8F93}的{U+6570}據{U+8FDB}行解析，{U+8F6C}化成{U+5E94}用{U+7EA7}的{U+6570}據。

#### {U+7EBF}程之{U+95F4}的通信方式

* {U+9501}機制：包括互斥{U+9501}/量（mutex）、{U+8BFB}{U+5199}{U+9501}（reader-writer lock）、自旋{U+9501}（spin lock）、{U+6761}件{U+53D8}量（condition）
    * 互斥{U+9501}/量（mutex）：提供了以排他方式防止{U+6570}據{U+7ED3}構被並{U+53D1}修改的方法。
    * {U+8BFB}{U+5199}{U+9501}（reader-writer lock）：允{U+8BB8}多{U+4E2A}{U+7EBF}程同{U+65F6}{U+8BFB}共享{U+6570}據，而{U+5BF9}{U+5199}操作是互斥的。
    * 自旋{U+9501}（spin lock）與互斥{U+9501}{U+7C7B}似，都是{U+4E3A}了保{U+62A4}共享{U+8D44}源。互斥{U+9501}是{U+5F53}{U+8D44}源被占用，申{U+8BF7}者{U+8FDB}入睡眠{U+72B6}{U+6001}；而自旋{U+9501}{U+5219}循{U+73AF}{U+68C0}{U+6D4B}保持{U+7740}是否已{U+7ECF}{U+91CA}放{U+9501}。
    * {U+6761}件{U+53D8}量（condition）：可以以原子的方式阻塞{U+8FDB}程，直到某{U+4E2A}特定{U+6761}件{U+4E3A}真{U+4E3A}止。{U+5BF9}{U+6761}件的{U+6D4B}{U+8BD5}是在互斥{U+9501}的保{U+62A4}下{U+8FDB}行的。{U+6761}件{U+53D8}量始{U+7EC8}與互斥{U+9501}一起使用。
* 信{U+53F7}量機制(Semaphore)
    * {U+65E0}名{U+7EBF}程信{U+53F7}量
    * 命名{U+7EBF}程信{U+53F7}量
* 信{U+53F7}機制(Signal)：{U+7C7B}似{U+8FDB}程{U+95F4}的信{U+53F7}{U+5904}理
* 屏障（barrier）：屏障允{U+8BB8}每{U+4E2A}{U+7EBF}程等待，直到所有的合作{U+7EBF}程都{U+8FBE}到某一{U+70B9}，然後{U+4ECE}{U+8BE5}{U+70B9}{U+7EE7}{U+7EED}{U+6267}行。

{U+7EBF}程{U+95F4}的通信目的主要是用於{U+7EBF}程同步，所以{U+7EBF}程{U+6CA1}有像{U+8FDB}程通信中的用於{U+6570}據交{U+6362}的通信機制  

> {U+8FDB}程之{U+95F4}的通信方式以及優缺{U+70B9}{U+6765}源於：[{U+8FDB}程{U+7EBF}程面{U+8BD5}{U+9898}{U+603B}{U+7ED3}](http://blog.csdn.net/wujiafei_njgcxy/article/details/77098977)

#### {U+8FDB}程之{U+95F4}私有和共享的{U+8D44}源

* 私有：地址空{U+95F4}、堆、全局{U+53D8}量、{U+6808}、寄存器
* 共享：代{U+7801}段，公共{U+6570}據，{U+8FDB}程目{U+5F55}，{U+8FDB}程 ID

#### {U+7EBF}程之{U+95F4}私有和共享的{U+8D44}源

* 私有：{U+7EBF}程{U+6808}，寄存器，程序寄存器
* 共享：堆，地址空{U+95F4}，全局{U+53D8}量，{U+9759}{U+6001}{U+53D8}量

#### 多{U+8FDB}程與多{U+7EBF}程{U+95F4}的{U+5BF9}比、優劣與{U+9009}{U+62E9}

##### {U+5BF9}比

{U+5BF9}比{U+7EF4}度 | 多{U+8FDB}程 | 多{U+7EBF}程 | {U+603B}{U+7ED3}
---|---|---|---
{U+6570}據共享、同步|{U+6570}據共享複{U+6742}，需要用 IPC；{U+6570}據是分{U+5F00}的，同步{U+7B80}{U+5355}|因{U+4E3A}共享{U+8FDB}程{U+6570}據，{U+6570}據共享{U+7B80}{U+5355}，但也是因{U+4E3A}{U+8FD9}{U+4E2A}原因{U+5BFC}致同步複{U+6742}|各有優{U+52BF}
{U+5185}存、CPU|占用{U+5185}存多，切{U+6362}複{U+6742}，CPU 利用率低|占用{U+5185}存少，切{U+6362}{U+7B80}{U+5355}，CPU 利用率高|{U+7EBF}程占優
{U+521B}建{U+9500}{U+6BC1}、切{U+6362}|{U+521B}建{U+9500}{U+6BC1}、切{U+6362}複{U+6742}，速度慢|{U+521B}建{U+9500}{U+6BC1}、切{U+6362}{U+7B80}{U+5355}，速度很快|{U+7EBF}程占優
{U+7F16}程、{U+8C03}{U+8BD5}|{U+7F16}程{U+7B80}{U+5355}，{U+8C03}{U+8BD5}{U+7B80}{U+5355}|{U+7F16}程複{U+6742}，{U+8C03}{U+8BD5}複{U+6742}|{U+8FDB}程占優
可靠性|{U+8FDB}程{U+95F4}不{U+4F1A}互相影{U+54CD}|一{U+4E2A}{U+7EBF}程掛掉{U+5C06}{U+5BFC}致整{U+4E2A}{U+8FDB}程掛掉|{U+8FDB}程占優
分布式|適{U+5E94}於多核、多機分布式；如果一台機器不{U+591F}，{U+6269}展到多台機器比{U+8F83}{U+7B80}{U+5355}|適{U+5E94}於多核分布式|{U+8FDB}程占優

##### 優劣

優劣|多{U+8FDB}程|多{U+7EBF}程
---|---|---
優{U+70B9}|{U+7F16}程、{U+8C03}{U+8BD5}{U+7B80}{U+5355}，可靠性{U+8F83}高|{U+521B}建、{U+9500}{U+6BC1}、切{U+6362}速度快，{U+5185}存、{U+8D44}源占用小
缺{U+70B9}|{U+521B}建、{U+9500}{U+6BC1}、切{U+6362}速度慢，{U+5185}存、{U+8D44}源占用大|{U+7F16}程、{U+8C03}{U+8BD5}複{U+6742}，可靠性{U+8F83}差

##### {U+9009}{U+62E9}

* 需要{U+9891}繁{U+521B}建{U+9500}{U+6BC1}的優先用{U+7EBF}程
* 需要{U+8FDB}行大量{U+8BA1}算的優先使用{U+7EBF}程
* {U+5F3A}相{U+5173}的{U+5904}理用{U+7EBF}程，弱相{U+5173}的{U+5904}理用{U+8FDB}程
* 可能要{U+6269}展到多機分布的用{U+8FDB}程，多核分布的用{U+7EBF}程
* 都{U+6EE1}足需求的情{U+51B5}下，用你最熟悉、最拿手的方式

> 多{U+8FDB}程與多{U+7EBF}程{U+95F4}的{U+5BF9}比、優劣與{U+9009}{U+62E9}{U+6765}自：[多{U+7EBF}程{U+8FD8}是多{U+8FDB}程的{U+9009}{U+62E9}及{U+533A}{U+522B}](https://blog.csdn.net/lishenglong666/article/details/8557215)

### Linux {U+5185}核的同步方式

#### 原因

在{U+73B0}代操作系{U+7EDF}裏，同一{U+65F6}{U+95F4}可能有多{U+4E2A}{U+5185}核{U+6267}行流在{U+6267}行，因此{U+5185}核其{U+5B9E}象多{U+8FDB}程多{U+7EBF}程{U+7F16}程一{U+6837}也需要一些同步機制{U+6765}同步各{U+6267}行{U+5355}元{U+5BF9}共享{U+6570}據的{U+8BBF}{U+95EE}。尤其是在多{U+5904}理器系{U+7EDF}上，更需要一些同步機制{U+6765}同步不同{U+5904}理器上的{U+6267}行{U+5355}元{U+5BF9}共享的{U+6570}據的{U+8BBF}{U+95EE}。

#### 同步方式

* 原子操作
* 信{U+53F7}量（semaphore）
* {U+8BFB}{U+5199}信{U+53F7}量（rw_semaphore）
* 自旋{U+9501}（spinlock）
* 大{U+5185}核{U+9501}（BKL，Big Kernel Lock）
* {U+8BFB}{U+5199}{U+9501}（rwlock）
* 大{U+8BFB}者{U+9501}（brlock-Big Reader Lock）
* {U+8BFB}-拷{U+8D1D}修改(RCU，Read-Copy Update)
* {U+987A}序{U+9501}（seqlock）

> {U+6765}自：[Linux {U+5185}核的同步機制，第 1 部分](https://www.ibm.com/developerworks/cn/linux/l-synch/part1/)、[Linux {U+5185}核的同步機制，第 2 部分](https://www.ibm.com/developerworks/cn/linux/l-synch/part2/)

### 死{U+9501}

#### 原因

* 系{U+7EDF}{U+8D44}源不足
* {U+8D44}源分配不{U+5F53}
* {U+8FDB}程{U+8FD0}行推{U+8FDB}{U+987A}序不合適

#### {U+4EA7}生{U+6761}件

* 互斥
* {U+8BF7}求和保持
* 不{U+5265}{U+593A}
* {U+73AF}路

#### {U+9884}防

* 打破互斥{U+6761}件：改造{U+72EC}占性{U+8D44}源{U+4E3A}{U+865A}{U+62DF}{U+8D44}源，大部分{U+8D44}源已{U+65E0}法改造。
* 打破不可{U+62A2}占{U+6761}件：{U+5F53}一{U+8FDB}程占有一{U+72EC}占性{U+8D44}源後又申{U+8BF7}一{U+72EC}占性{U+8D44}源而{U+65E0}法{U+6EE1}足，{U+5219}退出原占有的{U+8D44}源。
* 打破占有且申{U+8BF7}{U+6761}件：采用{U+8D44}源{U+9884}先分配策略，即{U+8FDB}程{U+8FD0}行前申{U+8BF7}全部{U+8D44}源，{U+6EE1}足{U+5219}{U+8FD0}行，不然就等待，{U+8FD9}{U+6837}就不{U+4F1A}占有且申{U+8BF7}。
* 打破循{U+73AF}等待{U+6761}件：{U+5B9E}{U+73B0}{U+8D44}源有序分配策略，{U+5BF9}所有{U+8BBE}{U+5907}{U+5B9E}{U+73B0}分{U+7C7B}{U+7F16}{U+53F7}，所有{U+8FDB}程只能采用按序{U+53F7}{U+9012}增的形式申{U+8BF7}{U+8D44}源。
* 有序{U+8D44}源分配法
* {U+94F6}行家算法

### 文件系{U+7EDF}

* Windows：FCB 表 + FAT + 位{U+56FE}
* Unix：inode + 混合索引 + 成{U+7EC4}{U+94FE}接

### 主機字{U+8282}序與網{U+7EDC}字{U+8282}序

#### 主機字{U+8282}序（CPU 字{U+8282}序）

##### 概念

主機字{U+8282}序又叫 CPU 字{U+8282}序，其不是由操作系{U+7EDF}{U+51B3}定的，而是由 CPU 指令集架構{U+51B3}定的。主機字{U+8282}序分{U+4E3A}{U+4E24}種：

* 大端字{U+8282}序（Big Endian）：高序字{U+8282}存{U+50A8}在低位地址，低序字{U+8282}存{U+50A8}在高位地址
* 小端字{U+8282}序（Little Endian）：高序字{U+8282}存{U+50A8}在高位地址，低序字{U+8282}存{U+50A8}在低位地址

##### 存{U+50A8}方式

32 位整{U+6570} `0x12345678` 是{U+4ECE}起始位置{U+4E3A} `0x00` 的地址{U+5F00}始存放，{U+5219}：

{U+5185}存地址 | 0x00 | 0x01 | 0x02 | 0x03
---|---|---|---|---
大端|12|34|56|78
小端|78|56|34|12


<details><summary>大端小端{U+56FE}片</summary>

![大端序](images/CPU-Big-Endian.svg.png)
![小端序](images/CPU-Little-Endian.svg.png)

</details>

##### 判{U+65AD}大端小端

<details><summary>判{U+65AD}大端小端</summary>

可以{U+8FD9}{U+6837}判{U+65AD}自己 CPU 字{U+8282}序是大端{U+8FD8}是小端：

```cpp
#include <iostream>
using namespace std;

int main()
{
	int i = 0x12345678;

	if (*((char*)&i) == 0x12)
		cout << "大端" << endl;
	else	
		cout << "小端" << endl;

	return 0;
}
```

</details>

##### 各架構{U+5904}理器的字{U+8282}序

* x86（Intel、AMD）、MOS Technology 6502、Z80、VAX、PDP-11 等{U+5904}理器{U+4E3A}小端序；
* Motorola 6800、Motorola 68000、PowerPC 970、System/370、SPARC（除 V9 外）等{U+5904}理器{U+4E3A}大端序；
* ARM（默{U+8BA4}小端序）、PowerPC（除 PowerPC 970 外）、DEC Alpha、SPARC V9、MIPS、PA-RISC 及 IA64 的字{U+8282}序是可配置的。

#### 網{U+7EDC}字{U+8282}序

網{U+7EDC}字{U+8282}{U+987A}序是 TCP/IP 中{U+89C4}定好的一種{U+6570}據表示格式，它與具體的 CPU {U+7C7B}型、操作系{U+7EDF}等{U+65E0}{U+5173}，{U+4ECE}而可以保重{U+6570}據在不同主機之{U+95F4}{U+4F20}{U+8F93}{U+65F6}能{U+591F}被正確解{U+91CA}。

網{U+7EDC}字{U+8282}{U+987A}序采用：大端（Big Endian）排列方式。

### {U+9875}面置{U+6362}算法

在地址映射{U+8FC7}程中，若在{U+9875}面中{U+53D1}{U+73B0}所要{U+8BBF}{U+95EE}的{U+9875}面不在{U+5185}存中，{U+5219}{U+4EA7}生缺{U+9875}中{U+65AD}。{U+5F53}{U+53D1}生缺{U+9875}中{U+65AD}{U+65F6}，如果操作系{U+7EDF}{U+5185}存中{U+6CA1}有空{U+95F2}{U+9875}面，{U+5219}操作系{U+7EDF}必{U+987B}在{U+5185}存{U+9009}{U+62E9}一{U+4E2A}{U+9875}面{U+5C06}其移出{U+5185}存，以便{U+4E3A}即{U+5C06}{U+8C03}入的{U+9875}面{U+8BA9}出空{U+95F4}。而用{U+6765}{U+9009}{U+62E9}淘汰哪一{U+9875}的{U+89C4}{U+5219}叫做{U+9875}面置{U+6362}算法。

#### 分{U+7C7B}

* 全局置{U+6362}：在整{U+4E2A}{U+5185}存空{U+95F4}置{U+6362}
* 局部置{U+6362}：在本{U+8FDB}程中{U+8FDB}行置{U+6362}

#### 算法

全局：
* 工作集算法
* 缺{U+9875}率置{U+6362}算法

局部：
* 最佳置{U+6362}算法（OPT）
* 先{U+8FDB}先出置{U+6362}算法（FIFO）
* 最近最久未使用（LRU）算法
* {U+65F6}{U+949F}（Clock）置{U+6362}算法

## {U+8BA1}算機網{U+7EDC}

{U+8BA1}算機{U+7ECF}網{U+7EDC}體系{U+7ED3}構：

![{U+8BA1}算機{U+7ECF}網{U+7EDC}體系{U+7ED3}構](images/{U+8BA1}算機{U+7ECF}網{U+7EDC}體系{U+7ED3}構.png)

### 各{U+5C42}作用及{U+534F}{U+8BAE}

分{U+5C42} | 作用 | {U+534F}{U+8BAE}
---|---|---
物理{U+5C42} | 通{U+8FC7}媒介{U+4F20}{U+8F93}比特，確定機械及{U+7535}氣{U+89C4}範（比特 Bit） | RJ45、CLOCK、IEEE802.3（中{U+7EE7}器，集{U+7EBF}器）
{U+6570}據{U+94FE}路{U+5C42}|{U+5C06}比特{U+7EC4}{U+88C5}成{U+5E27}和{U+70B9}到{U+70B9}的{U+4F20}{U+9012}（{U+5E27} Frame）| PPP、FR、HDLC、VLAN、MAC（網{U+6865}，交{U+6362}機）
網{U+7EDC}{U+5C42}|{U+8D1F}{U+8D23}{U+6570}據包{U+4ECE}源到宿的{U+4F20}{U+9012}和網{U+9645}互{U+8FDE}（包 Packet）|IP、ICMP、ARP、RARP、OSPF、IPX、RIP、IGRP（路由器）
{U+8FD0}{U+8F93}{U+5C42}|提供端到端的可靠{U+62A5}文{U+4F20}{U+9012}和{U+9519}{U+8BEF}恢複（ 段Segment）|TCP、UDP、SPX
{U+4F1A}{U+8BDD}{U+5C42}|建立、管理和{U+7EC8}止{U+4F1A}{U+8BDD}（{U+4F1A}{U+8BDD}{U+534F}{U+8BAE}{U+6570}據{U+5355}元 SPDU）|NFS、SQL、NETBIOS、RPC
表示{U+5C42}|{U+5BF9}{U+6570}據{U+8FDB}行翻{U+8BD1}、加密和{U+538B}{U+7F29}（表示{U+534F}{U+8BAE}{U+6570}據{U+5355}元 PPDU）|JPEG、MPEG、ASII
{U+5E94}用{U+5C42}|允{U+8BB8}{U+8BBF}{U+95EE}OSI{U+73AF}境的手段（{U+5E94}用{U+534F}{U+8BAE}{U+6570}據{U+5355}元 APDU）|FTP、DNS、Telnet、SMTP、HTTP、WWW、NFS


### 物理{U+5C42}

* {U+4F20}{U+8F93}{U+6570}據的{U+5355}位 ———— 比特
* {U+6570}據{U+4F20}{U+8F93}系{U+7EDF}：源系{U+7EDF}（源{U+70B9}、{U+53D1}送器） --> {U+4F20}{U+8F93}系{U+7EDF} --> 目的系{U+7EDF}（接收器、{U+7EC8}{U+70B9}）

通道：
* {U+5355}向通道（{U+5355}工通道）：只有一{U+4E2A}方向通信，{U+6CA1}有反方向交互，如{U+5E7F}播
* {U+53CC}向交替通行（半{U+53CC}工通信）：通信{U+53CC}方都可{U+53D1}消息，但不能同{U+65F6}{U+53D1}送或接收
* {U+53CC}向同{U+65F6}通信（全{U+53CC}工通信）：通信{U+53CC}方可以同{U+65F6}{U+53D1}送和接收信息

通道複用技{U+672F}：
* {U+9891}分複用（FDM，Frequency Division Multiplexing）：不同用{U+6237}在不同{U+9891}{U+5E26}，所用用{U+6237}在同{U+6837}{U+65F6}{U+95F4}占用不同{U+5E26}{U+5BBD}{U+8D44}源
* {U+65F6}分複用（TDM，Time Division Multiplexing）：不同用{U+6237}在同一{U+65F6}{U+95F4}段的不同{U+65F6}{U+95F4}片，所有用{U+6237}在不同{U+65F6}{U+95F4}占用同{U+6837}的{U+9891}{U+5E26}{U+5BBD}度
* 波分複用（WDM，Wavelength Division Multiplexing）：光的{U+9891}分複用
* {U+7801}分複用（CDM，Code Division Multiplexing）：不同用{U+6237}使用不同的{U+7801}，可以在同{U+6837}{U+65F6}{U+95F4}使用同{U+6837}{U+9891}{U+5E26}通信

### {U+6570}據{U+94FE}路{U+5C42}

主要信道：
* {U+70B9}{U+5BF9}{U+70B9}信道
* {U+5E7F}播信道

#### {U+70B9}{U+5BF9}{U+70B9}信道

* {U+6570}據{U+5355}元 ———— {U+5E27}

三{U+4E2A}基本{U+95EE}{U+9898}：
* 封{U+88C5}成{U+5E27}：把網{U+7EDC}{U+5C42}的 IP {U+6570}據{U+62A5}封{U+88C5}成{U+5E27}，`SOH - {U+6570}據部分 - EOT`
* 透明{U+4F20}{U+8F93}：不管{U+6570}據部分什麼字符，都能{U+4F20}{U+8F93}出去；可以通{U+8FC7}字{U+8282}填充方法解{U+51B3}（{U+51B2}突字符前加{U+8F6C}{U+4E49}字符）
* 差{U+9519}{U+68C0}{U+6D4B}：降低{U+8BEF}{U+7801}率（BER，Bit Error Rate），{U+5E7F}泛使用循{U+73AF}冗餘{U+68C0}{U+6D4B}（CRC，Cyclic Redundancy Check）

{U+70B9}{U+5BF9}{U+70B9}{U+534F}{U+8BAE}（Point-to-Point Protocol）：
* {U+70B9}{U+5BF9}{U+70B9}{U+534F}{U+8BAE}（Point-to-Point Protocol）：用{U+6237}{U+8BA1}算機和 ISP 通信{U+65F6}所使用的{U+534F}{U+8BAE}

#### {U+5E7F}播信道

{U+5E7F}播通信：
* 硬件地址（物理地址、MAC 地址）
* {U+5355}播（unicast）{U+5E27}（一{U+5BF9}一）：收到的{U+5E27}的 MAC 地址與本站的硬件地址相同
* {U+5E7F}播（broadcast）{U+5E27}（一{U+5BF9}全體）：{U+53D1}送{U+7ED9}本局域網上所有站{U+70B9}的{U+5E27}
* 多播（multicast）{U+5E27}（一{U+5BF9}多）：{U+53D1}送{U+7ED9}本局域網上一部分站{U+70B9}的{U+5E27}

### 網{U+7EDC}{U+5C42}

* IP（Internet Protocol，網{U+9645}{U+534F}{U+8BAE}）是{U+4E3A}{U+8BA1}算機網{U+7EDC}相互{U+8FDE}接{U+8FDB}行通信而{U+8BBE}{U+8BA1}的{U+534F}{U+8BAE}。
* ARP（Address Resolution Protocol，地址解析{U+534F}{U+8BAE}）
* ICMP（Internet Control Message Protocol，網{U+9645}控制{U+62A5}文{U+534F}{U+8BAE}）
* IGMP（Internet Group Management Protocol，網{U+9645}{U+7EC4}管理{U+534F}{U+8BAE}）

#### IP 網{U+9645}{U+534F}{U+8BAE}

IP 地址分{U+7C7B}：
* `IP 地址 ::= {<網{U+7EDC}{U+53F7}>,<主機{U+53F7}>}`

IP 地址{U+7C7B}{U+522B} | 網{U+7EDC}{U+53F7} | 網{U+7EDC}範{U+56F4} | 主機{U+53F7} | IP 地址範{U+56F4}
---|---|---|---|---
A {U+7C7B} | 8bit，第一位固定{U+4E3A} 0 | 0 —— 127 | 24bit | 1.0.0.0 —— 127.255.255.255
B {U+7C7B} | 16bit，前{U+4E24}位固定{U+4E3A}  10 | 128.0 —— 191.255 | 16bit | 128.0.0.0 —— 191.255.255.255
C  {U+7C7B} | 24bit，前三位固定{U+4E3A}  110 | 192.0.0 —— 223.255.255 | 8bit | 192.0.0.0 —— 223.255.255.255
D  {U+7C7B} | 前四位固定{U+4E3A} 1110，後面{U+4E3A}多播地址
E  {U+7C7B} | 前五位固定{U+4E3A} 11110，後面保留{U+4E3A}今後所用

IP {U+6570}據{U+62A5}格式：

![IP {U+6570}據{U+62A5}格式](images/IP{U+6570}據{U+62A5}格式.png)

#### ICMP 網{U+9645}控制{U+62A5}文{U+534F}{U+8BAE}

ICMP {U+62A5}文格式：

![ICMP {U+62A5}文格式](images/ICMP{U+62A5}文格式.png)

{U+5E94}用：
* PING（Packet InterNet Groper，分{U+7EC4}網{U+95F4}探{U+6D4B}）{U+6D4B}{U+8BD5}{U+4E24}{U+4E2A}主機之{U+95F4}的{U+8FDE}通性
    * TTL（Time To Live，生存{U+65F6}{U+95F4}）{U+8BE5}字段指定 IP 包被路由器{U+4E22}{U+5F03}之前允{U+8BB8}通{U+8FC7}的最大網段{U+6570}量

#### {U+5185}部網{U+5173}{U+534F}{U+8BAE}

* RIP（Routing Information Protocol，路由信息{U+534F}{U+8BAE}）
* OSPF（Open Sortest Path First，{U+5F00}放最短路{U+5F84}優先）

#### 外部網{U+5173}{U+534F}{U+8BAE}

* BGP（Border Gateway Protocol，{U+8FB9}界網{U+5173}{U+534F}{U+8BAE}）

#### IP多播

* IGMP（Internet Group Management Protocol，網{U+9645}{U+7EC4}管理{U+534F}{U+8BAE}）
* 多播路由{U+9009}{U+62E9}{U+534F}{U+8BAE}

#### VPN 和 NAT

* VPN（Virtual Private Network，{U+865A}{U+62DF}{U+4E13}用網）
* NAT（Network Address Translation，網{U+7EDC}地址{U+8F6C}{U+6362}）

#### 路由表包含什麼？

1. 網{U+7EDC} ID（Network ID, Network number）：就是目{U+6807}地址的網{U+7EDC} ID。
2. 子網掩{U+7801}（subnet mask）：用{U+6765}判{U+65AD} IP 所{U+5C5E}網{U+7EDC}
3. 下一跳地址/接口（Next hop / interface）：就是{U+6570}據在{U+53D1}送到目{U+6807}地址的旅途中下一站的地址。其中 interface 指向 next hop（即{U+4E3A}下一{U+4E2A} route）。一{U+4E2A}自治系{U+7EDF}（AS, Autonomous system）中的 route {U+5E94}{U+8BE5}包含{U+533A}域{U+5185}所有的子網{U+7EDC}，而默{U+8BA4}網{U+5173}（Network id: `0.0.0.0`, Netmask: `0.0.0.0`）指向自治系{U+7EDF}的出口。

根據{U+5E94}用和{U+6267}行的不同，路由表可能含有如下附加信息：

1. 花{U+8D39}（Cost）：就是{U+6570}據{U+53D1}送{U+8FC7}程中通{U+8FC7}路{U+5F84}所需要的花{U+8D39}。
2. 路由的服{U+52A1}{U+8D28}量
3. 路由中需要{U+8FC7}{U+6EE4}的出/入{U+8FDE}接列表

### {U+8FD0}{U+8F93}{U+5C42}

{U+534F}{U+8BAE}：

* TCP（Transmission Control Protocol，{U+4F20}{U+8F93}控制{U+534F}{U+8BAE}）
* UDP（User Datagram Protocol，用{U+6237}{U+6570}據{U+62A5}{U+534F}{U+8BAE}）

端口：

{U+5E94}用程序 | FTP | TELNET | SMTP | DNS | TFTP | HTTP | HTTPS | SNMP  
--- | --- | --- |--- |--- |--- |--- |--- |---   
端口{U+53F7} | 21 | 23 | 25 | 53 | 69 | 80 | 443 | 161  

#### TCP

* TCP（Transmission Control Protocol，{U+4F20}{U+8F93}控制{U+534F}{U+8BAE}）是一種面向{U+8FDE}接的、可靠的、基於字{U+8282}流的{U+4F20}{U+8F93}{U+5C42}通信{U+534F}{U+8BAE}，其{U+4F20}{U+8F93}的{U+5355}位是{U+62A5}文段。

特征：
* 面向{U+8FDE}接
* 只能{U+70B9}{U+5BF9}{U+70B9}（一{U+5BF9}一）通信
* 可靠交互
* 全{U+53CC}工通信
* 面向字{U+8282}流

TCP 如何保{U+8BC1}可靠{U+4F20}{U+8F93}：
* 確{U+8BA4}和超{U+65F6}重{U+4F20}
* {U+6570}據合理分片和排序
* 流量控制
* {U+62E5}塞控制
* {U+6570}據校{U+9A8C}

TCP {U+62A5}文{U+7ED3}構

![TCP {U+62A5}文](images/TCP{U+62A5}文.png)

TCP 首部

![TCP 首部](images/TCP首部.png)

TCP：{U+72B6}{U+6001}控制{U+7801}（Code，Control Flag），占 6 比特，含{U+4E49}如下：
* URG：{U+7D27}急比特（urgent），{U+5F53} `URG＝1` {U+65F6}，表明{U+7D27}急指{U+9488}字段有效，代表{U+8BE5}封包{U+4E3A}{U+7D27}急封包。它告{U+8BC9}系{U+7EDF}此{U+62A5}文段中有{U+7D27}急{U+6570}據，{U+5E94}{U+5C3D}快{U+4F20}送(相{U+5F53}於高優先{U+7EA7}的{U+6570}據)， 且上{U+56FE}中的 Urgent Pointer 字段也{U+4F1A}被{U+542F}用。
* ACK：確{U+8BA4}比特（Acknowledge）。只有{U+5F53} `ACK＝1` {U+65F6}確{U+8BA4}{U+53F7}字段才有效，代表{U+8FD9}{U+4E2A}封包{U+4E3A}確{U+8BA4}封包。{U+5F53} `ACK＝0` {U+65F6}，確{U+8BA4}{U+53F7}{U+65E0}效。
* PSH：（Push function）若{U+4E3A} 1 {U+65F6}，代表要求{U+5BF9}方立即{U+4F20}送{U+7F13}{U+51B2}{U+533A}{U+5185}的其他{U+5BF9}{U+5E94}封包，而{U+65E0}需等{U+7F13}{U+51B2}{U+6EE1}了才送。
* RST：複位比特(Reset)，{U+5F53} `RST＝1` {U+65F6}，表明 TCP {U+8FDE}接中出{U+73B0}{U+4E25}重差{U+9519}（如由於主機崩{U+6E83}或其他原因），必{U+987B}{U+91CA}放{U+8FDE}接，然後再重新建立{U+8FD0}{U+8F93}{U+8FDE}接。
* SYN：同步比特(Synchronous)，SYN 置{U+4E3A} 1，就表示{U+8FD9}是一{U+4E2A}{U+8FDE}接{U+8BF7}求或{U+8FDE}接接受{U+62A5}文，通常{U+5E26}有 SYN {U+6807}志的封包表示『主{U+52A8}』要{U+8FDE}接到{U+5BF9}方的意思。
* FIN：{U+7EC8}止比特(Final)，用{U+6765}{U+91CA}放一{U+4E2A}{U+8FDE}接。{U+5F53} `FIN＝1` {U+65F6}，表明此{U+62A5}文段的{U+53D1}送端的{U+6570}據已{U+53D1}送完{U+6BD5}，並要求{U+91CA}放{U+8FD0}{U+8F93}{U+8FDE}接。

#### UDP

* UDP（User Datagram Protocol，用{U+6237}{U+6570}據{U+62A5}{U+534F}{U+8BAE}）是 OSI（Open System Interconnection {U+5F00}放式系{U+7EDF}互{U+8054}） {U+53C2}考模型中一種{U+65E0}{U+8FDE}接的{U+4F20}{U+8F93}{U+5C42}{U+534F}{U+8BAE}，提供面向事{U+52A1}的{U+7B80}{U+5355}不可靠信息{U+4F20}送服{U+52A1}，其{U+4F20}{U+8F93}的{U+5355}位是用{U+6237}{U+6570}據{U+62A5}。

特征：
* {U+65E0}{U+8FDE}接
* {U+5C3D}最大努力交付
* 面向{U+62A5}文
* {U+6CA1}有{U+62E5}塞控制
* 支持一{U+5BF9}一、一{U+5BF9}多、多{U+5BF9}一、多{U+5BF9}多的交互通信
* 首部{U+5F00}{U+9500}小

UDP {U+62A5}文{U+7ED3}構

![UDP {U+62A5}文](images/UDP{U+62A5}文.png)

UDP 首部

![UDP 首部](images/UDP首部.png)

> TCP/UDP {U+56FE}片{U+6765}源於：<https://github.com/JerryC8080/understand-tcp-udp>

#### TCP 與 UDP 的{U+533A}{U+522B}

1. TCP 面向{U+8FDE}接，UDP 是{U+65E0}{U+8FDE}接的；
2. TCP 提供可靠的服{U+52A1}，也就是{U+8BF4}，通{U+8FC7} TCP {U+8FDE}接{U+4F20}送的{U+6570}據，{U+65E0}差{U+9519}，不{U+4E22}失，不重複，且按序到{U+8FBE}；UDP {U+5C3D}最大努力交付，即不保{U+8BC1}可靠交付
3. TCP 的{U+903B}{U+8F91}通信信道是全{U+53CC}工的可靠信道；UDP {U+5219}是不可靠信道
5. 每一{U+6761} TCP {U+8FDE}接只能是{U+70B9}到{U+70B9}的；UDP 支持一{U+5BF9}一，一{U+5BF9}多，多{U+5BF9}一和多{U+5BF9}多的交互通信
6. TCP 面向字{U+8282}流（可能出{U+73B0}黏包{U+95EE}{U+9898}），{U+5B9E}{U+9645}上是 TCP 把{U+6570}據看成一{U+8FDE}串{U+65E0}{U+7ED3}構的字{U+8282}流；UDP 是面向{U+62A5}文的（不{U+4F1A}出{U+73B0}黏包{U+95EE}{U+9898}）
7. UDP {U+6CA1}有{U+62E5}塞控制，因此網{U+7EDC}出{U+73B0}{U+62E5}塞不{U+4F1A}使源主機的{U+53D1}送速率降低（{U+5BF9}{U+5B9E}{U+65F6}{U+5E94}用很有用，如 IP {U+7535}{U+8BDD}，{U+5B9E}{U+65F6}{U+89C6}{U+9891}{U+4F1A}{U+8BAE}等）
8. TCP 首部{U+5F00}{U+9500}20字{U+8282}；UDP 的首部{U+5F00}{U+9500}小，只有 8 {U+4E2A}字{U+8282}

#### TCP 黏包{U+95EE}{U+9898}

##### 原因

TCP 是一{U+4E2A}基於字{U+8282}流的{U+4F20}{U+8F93}服{U+52A1}（UDP 基於{U+62A5}文的），「流」 意味{U+7740} TCP 所{U+4F20}{U+8F93}的{U+6570}據是{U+6CA1}有{U+8FB9}界的。所以可能{U+4F1A}出{U+73B0}{U+4E24}{U+4E2A}{U+6570}據包黏在一起的情{U+51B5}。

##### 解{U+51B3}

* {U+53D1}送定{U+957F}包。如果每{U+4E2A}消息的大小都是一{U+6837}的，那麼在接收{U+5BF9}等方只要累{U+8BA1}接收{U+6570}據，直到{U+6570}據等於一{U+4E2A}定{U+957F}的{U+6570}值就{U+5C06}它作{U+4E3A}一{U+4E2A}消息。
* 包{U+5934}加上包體{U+957F}度。包{U+5934}是定{U+957F}的 4 {U+4E2A}字{U+8282}，{U+8BF4}明了包體的{U+957F}度。接收{U+5BF9}等方先接收包{U+5934}{U+957F}度，依據包{U+5934}{U+957F}度{U+6765}接收包體。
* 在{U+6570}據包之{U+95F4}{U+8BBE}置{U+8FB9}界，如添加特殊符{U+53F7} `\r\n` {U+6807}{U+8BB0}。FTP {U+534F}{U+8BAE}正是{U+8FD9}麼做的。但{U+95EE}{U+9898}在於如果{U+6570}據正文中也含有 `\r\n`，{U+5219}{U+4F1A}{U+8BEF}判{U+4E3A}消息的{U+8FB9}界。
* 使用更加複{U+6742}的{U+5E94}用{U+5C42}{U+534F}{U+8BAE}。

#### TCP 流量控制

##### 概念

流量控制（flow control）就是{U+8BA9}{U+53D1}送方的{U+53D1}送速率不要太快，要{U+8BA9}接收方{U+6765}得及接收。

##### 方法

<details><summary>利用可{U+53D8}窗口{U+8FDB}行流量控制</summary>

![](images/利用可{U+53D8}窗口{U+8FDB}行流量控制{U+4E3E}例.png)

</details>

#### TCP {U+62E5}塞控制

##### 概念

{U+62E5}塞控制就是防止{U+8FC7}多的{U+6570}據注入到網{U+7EDC}中，{U+8FD9}{U+6837}可以使網{U+7EDC}中的路由器或{U+94FE}路不致{U+8FC7}{U+8F7D}。

##### 方法

* 慢{U+5F00}始( slow-start )
* {U+62E5}塞避免( congestion avoidance )
* 快重{U+4F20}( fast retransmit )
* 快恢複( fast recovery )

<details><summary>TCP的{U+62E5}塞控制{U+56FE}</summary>

![](images/TCP{U+62E5}塞窗口cwnd在{U+62E5}塞控制{U+65F6}的{U+53D8}化情{U+51B5}.png)
![](images/快重{U+4F20}示意{U+56FE}.png)
![](images/TCP的{U+62E5}塞控制流程{U+56FE}.png)

</details>

#### TCP {U+4F20}{U+8F93}{U+8FDE}接管理

> 因{U+4E3A} TCP 三次握手建立{U+8FDE}接、四次{U+6325}手{U+91CA}放{U+8FDE}接很重要，所以附上《{U+8BA1}算機網{U+7EDC}（第 7 版）-{U+8C22}希仁》{U+4E66}中{U+5BF9}此章的{U+8BE6}{U+7EC6}描述：<https://github.com/huihut/interview/blob/master/images/TCP-transport-connection-management.png>

##### TCP 三次握手建立{U+8FDE}接

![UDP {U+62A5}文](images/TCP三次握手建立{U+8FDE}接.png)

【TCP 建立{U+8FDE}接全{U+8FC7}程解{U+91CA}】

1. 客{U+6237}端{U+53D1}送 SYN {U+7ED9}服{U+52A1}器，{U+8BF4}明客{U+6237}端{U+8BF7}求建立{U+8FDE}接；
2. 服{U+52A1}端收到客{U+6237}端{U+53D1}的 SYN，並回複 SYN+ACK {U+7ED9}客{U+6237}端（同意建立{U+8FDE}接）；
3. 客{U+6237}端收到服{U+52A1}端的 SYN+ACK 後，回複 ACK {U+7ED9}服{U+52A1}端（表示客{U+6237}端收到了服{U+52A1}端{U+53D1}的同意{U+62A5}文）；
4. 服{U+52A1}端收到客{U+6237}端的 ACK，{U+8FDE}接已建立，可以{U+6570}據{U+4F20}{U+8F93}。

##### TCP {U+4E3A}什麼要{U+8FDB}行三次握手？

【答案一】因{U+4E3A}信道不可靠，而 TCP 想在不可靠信道上建立可靠地{U+4F20}{U+8F93}，那麼三次通信是理{U+8BBA}上的最小值。（而 UDP {U+5219}不需建立可靠{U+4F20}{U+8F93}，因此 UDP 不需要三次握手。）

> [Google Groups . TCP 建立{U+8FDE}接{U+4E3A}什麼是三次握手？{技{U+672F}}{網{U+7EDC}通信}](https://groups.google.com/forum/#!msg/pongba/kF6O7-MFxM0/5S7zIJ4yqKUJ)

【答案二】因{U+4E3A}{U+53CC}方都需要確{U+8BA4}{U+5BF9}方收到了自己{U+53D1}送的序列{U+53F7}，確{U+8BA4}{U+8FC7}程最少要{U+8FDB}行三次通信。

> [知乎 . TCP {U+4E3A}什麼是三次握手，而不是{U+4E24}次或四次？](https://www.zhihu.com/question/24853633/answer/115173386)

【答案三】{U+4E3A}了防止已失效的{U+8FDE}接{U+8BF7}求{U+62A5}文段突然又{U+4F20}送到了服{U+52A1}端，因而{U+4EA7}生{U+9519}{U+8BEF}。

> [《{U+8BA1}算機網{U+7EDC}（第 7 版）-{U+8C22}希仁》](https://github.com/huihut/interview/blob/master/images/TCP-transport-connection-management.png)

##### TCP 四次{U+6325}手{U+91CA}放{U+8FDE}接

![UDP {U+62A5}文](images/TCP四次{U+6325}手{U+91CA}放{U+8FDE}接.png)

【TCP {U+91CA}放{U+8FDE}接全{U+8FC7}程解{U+91CA}】

1. 客{U+6237}端{U+53D1}送 FIN {U+7ED9}服{U+52A1}器，{U+8BF4}明客{U+6237}端不必{U+53D1}送{U+6570}據{U+7ED9}服{U+52A1}器了（{U+8BF7}求{U+91CA}放{U+4ECE}客{U+6237}端到服{U+52A1}器的{U+8FDE}接）；
2. 服{U+52A1}器接收到客{U+6237}端{U+53D1}的 FIN，並回複 ACK {U+7ED9}客{U+6237}端（同意{U+91CA}放{U+4ECE}客{U+6237}端到服{U+52A1}器的{U+8FDE}接）；
3. 客{U+6237}端收到服{U+52A1}端回複的 ACK，此{U+65F6}{U+4ECE}客{U+6237}端到服{U+52A1}器的{U+8FDE}接已{U+91CA}放（但服{U+52A1}端到客{U+6237}端的{U+8FDE}接{U+8FD8}未{U+91CA}放，並且客{U+6237}端{U+8FD8}可以接收{U+6570}據）；
4. 服{U+52A1}端{U+7EE7}{U+7EED}{U+53D1}送之前{U+6CA1}{U+53D1}完的{U+6570}據{U+7ED9}客{U+6237}端；
5. 服{U+52A1}端{U+53D1}送 FIN+ACK {U+7ED9}客{U+6237}端，{U+8BF4}明服{U+52A1}端{U+53D1}送完了{U+6570}據（{U+8BF7}求{U+91CA}放{U+4ECE}服{U+52A1}端到客{U+6237}端的{U+8FDE}接，就算{U+6CA1}收到客{U+6237}端的回複，{U+8FC7}段{U+65F6}{U+95F4}也{U+4F1A}自{U+52A8}{U+91CA}放）；
6. 客{U+6237}端收到服{U+52A1}端的 FIN+ACK，並回複 ACK {U+7ED9}客{U+6237}端（同意{U+91CA}放{U+4ECE}服{U+52A1}端到客{U+6237}端的{U+8FDE}接）；
7. 服{U+52A1}端收到客{U+6237}端的 ACK 後，{U+91CA}放{U+4ECE}服{U+52A1}端到客{U+6237}端的{U+8FDE}接。

##### TCP {U+4E3A}什麼要{U+8FDB}行四次{U+6325}手？

【{U+95EE}{U+9898}一】TCP {U+4E3A}什麼要{U+8FDB}行四次{U+6325}手？ / {U+4E3A}什麼 TCP 建立{U+8FDE}接需要三次，而{U+91CA}放{U+8FDE}接{U+5219}需要四次？

【答案一】因{U+4E3A} TCP 是全{U+53CC}工模式，客{U+6237}端{U+8BF7}求{U+5173}{U+95ED}{U+8FDE}接後，客{U+6237}端向服{U+52A1}端的{U+8FDE}接{U+5173}{U+95ED}（一二次{U+6325}手），服{U+52A1}端{U+7EE7}{U+7EED}{U+4F20}{U+8F93}之前{U+6CA1}{U+4F20}完的{U+6570}據{U+7ED9}客{U+6237}端（{U+6570}據{U+4F20}{U+8F93}），服{U+52A1}端向客{U+6237}端的{U+8FDE}接{U+5173}{U+95ED}（三四次{U+6325}手）。所以 TCP {U+91CA}放{U+8FDE}接{U+65F6}服{U+52A1}器的 ACK 和 FIN 是分{U+5F00}{U+53D1}送的（中{U+95F4}隔{U+7740}{U+6570}據{U+4F20}{U+8F93}），而 TCP 建立{U+8FDE}接{U+65F6}服{U+52A1}器的 ACK 和 SYN 是一起{U+53D1}送的（第二次握手），所以 TCP 建立{U+8FDE}接需要三次，而{U+91CA}放{U+8FDE}接{U+5219}需要四次。

【{U+95EE}{U+9898}二】{U+4E3A}什麼 TCP {U+8FDE}接{U+65F6}可以 ACK 和 SYN 一起{U+53D1}送，而{U+91CA}放{U+65F6}{U+5219} ACK 和 FIN 分{U+5F00}{U+53D1}送呢？（ACK 和 FIN 分{U+5F00}是指第二次和第三次{U+6325}手）

【答案二】因{U+4E3A}客{U+6237}端{U+8BF7}求{U+91CA}放{U+65F6}，服{U+52A1}器可能{U+8FD8}有{U+6570}據需要{U+4F20}{U+8F93}{U+7ED9}客{U+6237}端，因此服{U+52A1}端要先{U+54CD}{U+5E94}客{U+6237}端 FIN {U+8BF7}求（服{U+52A1}端{U+53D1}送 ACK），然後{U+6570}據{U+4F20}{U+8F93}，{U+4F20}{U+8F93}完成後，服{U+52A1}端再提出 FIN {U+8BF7}求（服{U+52A1}端{U+53D1}送 FIN）；而{U+8FDE}接{U+65F6}{U+5219}{U+6CA1}有中{U+95F4}的{U+6570}據{U+4F20}{U+8F93}，因此{U+8FDE}接{U+65F6}可以 ACK 和 SYN 一起{U+53D1}送。

【{U+95EE}{U+9898}三】{U+4E3A}什麼客{U+6237}端{U+91CA}放最後需要 TIME-WAIT 等待 2MSL 呢？

【答案三】

1. {U+4E3A}了保{U+8BC1}客{U+6237}端{U+53D1}送的最後一{U+4E2A} ACK {U+62A5}文能{U+591F}到{U+8FBE}服{U+52A1}端。若未成功到{U+8FBE}，{U+5219}服{U+52A1}端超{U+65F6}重{U+4F20} FIN+ACK {U+62A5}文段，客{U+6237}端再重{U+4F20} ACK，並重新{U+8BA1}{U+65F6}。
2. 防止已失效的{U+8FDE}接{U+8BF7}求{U+62A5}文段出{U+73B0}在本{U+8FDE}接中。TIME-WAIT 持{U+7EED} 2MSL 可使本{U+8FDE}接持{U+7EED}的{U+65F6}{U+95F4}{U+5185}所{U+4EA7}生的所有{U+62A5}文段都{U+4ECE}網{U+7EDC}中消失，{U+8FD9}{U+6837}可使下次{U+8FDE}接中不{U+4F1A}出{U+73B0}{U+65E7}的{U+8FDE}接{U+62A5}文段。

#### TCP 有限{U+72B6}{U+6001}機

<details><summary>TCP 有限{U+72B6}{U+6001}機{U+56FE}片</summary>

![TCP 的有限{U+72B6}{U+6001}機](images/TCP的有限{U+72B6}{U+6001}機.png)

</details>

### {U+5E94}用{U+5C42}

#### DNS

* DNS（Domain Name System，域名系{U+7EDF}）是互{U+8054}網的一{U+9879}服{U+52A1}。它作{U+4E3A}{U+5C06}域名和 IP 地址相互映射的一{U+4E2A}分布式{U+6570}據{U+5E93}，能{U+591F}使人更方便地{U+8BBF}{U+95EE}互{U+8054}網。DNS 使用 TCP 和 UDP 端口 53。{U+5F53}前，{U+5BF9}於每一{U+7EA7}域名{U+957F}度的限制是 63 {U+4E2A}字符，域名{U+603B}{U+957F}度{U+5219}不能超{U+8FC7} 253 {U+4E2A}字符。

域名：
* `域名 ::= {<三{U+7EA7}域名>.<二{U+7EA7}域名>.<{U+9876}{U+7EA7}域名>}`，如：`blog.huihut.com`

#### FTP

* FTP（File Transfer Protocol，文件{U+4F20}{U+8F93}{U+534F}{U+8BAE}）是用於在網{U+7EDC}上{U+8FDB}行文件{U+4F20}{U+8F93}的一套{U+6807}准{U+534F}{U+8BAE}，使用客{U+6237}/服{U+52A1}器模式，使用 TCP {U+6570}據{U+62A5}，提供交互式{U+8BBF}{U+95EE}，{U+53CC}向{U+4F20}{U+8F93}。
* TFTP（Trivial File Transfer Protocol，{U+7B80}{U+5355}文件{U+4F20}{U+8F93}{U+534F}{U+8BAE}）一{U+4E2A}小且易{U+5B9E}{U+73B0}的文件{U+4F20}{U+8F93}{U+534F}{U+8BAE}，也使用客{U+6237}-服{U+52A1}器方式，使用UDP{U+6570}據{U+62A5}，只支持文件{U+4F20}{U+8F93}而不支持交互，{U+6CA1}有列目{U+5F55}，不能{U+5BF9}用{U+6237}{U+8FDB}行身份{U+9274}定

#### TELNET

* TELNET {U+534F}{U+8BAE}是 TCP/IP {U+534F}{U+8BAE}族中的一{U+5458}，是 Internet {U+8FDC}程登{U+9646}服{U+52A1}的{U+6807}准{U+534F}{U+8BAE}和主要方式。它{U+4E3A}用{U+6237}提供了在本地{U+8BA1}算機上完成{U+8FDC}程主機工作的能力。

* HTTP（HyperText Transfer Protocol，超文本{U+4F20}{U+8F93}{U+534F}{U+8BAE}）是用於{U+4ECE} WWW（World Wide Web，萬{U+7EF4}網）服{U+52A1}器{U+4F20}{U+8F93}超文本到本地{U+6D4F}{U+89C8}器的{U+4F20}送{U+534F}{U+8BAE}。

* SMTP（Simple Mail Transfer Protocol，{U+7B80}{U+5355}{U+90AE}件{U+4F20}{U+8F93}{U+534F}{U+8BAE}）是一{U+7EC4}用於由源地址到目的地址{U+4F20}送{U+90AE}件的{U+89C4}{U+5219}，由它{U+6765}控制信件的中{U+8F6C}方式。SMTP {U+534F}{U+8BAE}{U+5C5E}於 TCP/IP {U+534F}{U+8BAE}簇，它{U+5E2E}助每台{U+8BA1}算機在{U+53D1}送或中{U+8F6C}信件{U+65F6}找到下一{U+4E2A}目的地。
* Socket 建立網{U+7EDC}通信{U+8FDE}接至少要一{U+5BF9}端口{U+53F7}（Socket）。Socket 本{U+8D28}是{U+7F16}程接口（API），{U+5BF9} TCP/IP 的封{U+88C5}，TCP/IP 也要提供可供程序{U+5458}做網{U+7EDC}{U+5F00}{U+53D1}所用的接口，{U+8FD9}就是 Socket {U+7F16}程接口。

#### WWW

* WWW（World Wide Web，{U+73AF}球信息網，萬{U+7EF4}網）是一{U+4E2A}由{U+8BB8}多互相{U+94FE}接的超文本{U+7EC4}成的系{U+7EDF}，通{U+8FC7}互{U+8054}網{U+8BBF}{U+95EE}

##### URL

* URL（Uniform Resource Locator，{U+7EDF}一{U+8D44}源定位符）是因特網上{U+6807}准的{U+8D44}源的地址（Address）

{U+6807}准格式：

* `{U+534F}{U+8BAE}{U+7C7B}型:[//服{U+52A1}器地址[:端口{U+53F7}]][/{U+8D44}源{U+5C42}{U+7EA7}UNIX文件路{U+5F84}]文件名[?查{U+8BE2}][#片段ID]`
    
完整格式：

* `{U+534F}{U+8BAE}{U+7C7B}型:[//[{U+8BBF}{U+95EE}{U+8D44}源需要的{U+51ED}{U+8BC1}信息@]服{U+52A1}器地址[:端口{U+53F7}]][/{U+8D44}源{U+5C42}{U+7EA7}UNIX文件路{U+5F84}]文件名[?查{U+8BE2}][#片段ID]`

> 其中【{U+8BBF}{U+95EE}{U+51ED}{U+8BC1}信息@；:端口{U+53F7}；?查{U+8BE2}；#片段ID】都{U+5C5E}於{U+9009}填{U+9879}  
> 如：`https://github.com/huihut/interview#cc`

##### HTTP

HTTP（HyperText Transfer Protocol，超文本{U+4F20}{U+8F93}{U+534F}{U+8BAE}）是一種用於分布式、{U+534F}作式和超媒體信息系{U+7EDF}的{U+5E94}用{U+5C42}{U+534F}{U+8BAE}。HTTP 是萬{U+7EF4}網的{U+6570}據通信的基{U+7840}。

{U+8BF7}求方法

方法 | 意{U+4E49}
--- | ---
OPTIONS | {U+8BF7}求一些{U+9009}{U+9879}信息，允{U+8BB8}客{U+6237}端查看服{U+52A1}器的性能
GET | {U+8BF7}求指定的{U+9875}面信息，並返回{U+5B9E}體主體
HEAD | {U+7C7B}似於 get {U+8BF7}求，只不{U+8FC7}返回的{U+54CD}{U+5E94}中{U+6CA1}有具體的{U+5185}容，用於{U+83B7}取{U+62A5}{U+5934}
POST | 向指定{U+8D44}源提交{U+6570}據{U+8FDB}行{U+5904}理{U+8BF7}求（例如提交表{U+5355}或者上{U+4F20}文件）。{U+6570}據被包含在{U+8BF7}求體中。POST{U+8BF7}求可能{U+4F1A}{U+5BFC}致新的{U+8D44}源的建立和/或已有{U+8D44}源的修改
PUT | {U+4ECE}客{U+6237}端向服{U+52A1}器{U+4F20}送的{U+6570}據取代指定的文{U+6863}的{U+5185}容
DELETE | {U+8BF7}求服{U+52A1}器{U+5220}除指定的{U+9875}面
TRACE | 回{U+663E}服{U+52A1}器收到的{U+8BF7}求，主要用於{U+6D4B}{U+8BD5}或{U+8BCA}{U+65AD}

{U+72B6}{U+6001}{U+7801}（Status-Code）

* 1xx：表示通知信息，如{U+8BF7}求收到了或正在{U+8FDB}行{U+5904}理
    * 100 Continue：{U+7EE7}{U+7EED}，客{U+6237}端{U+5E94}{U+7EE7}{U+7EED}其{U+8BF7}求
    * 101 Switching Protocols 切{U+6362}{U+534F}{U+8BAE}。服{U+52A1}器根據客{U+6237}端的{U+8BF7}求切{U+6362}{U+534F}{U+8BAE}。只能切{U+6362}到更高{U+7EA7}的{U+534F}{U+8BAE}，例如，切{U+6362}到 HTTP 的新版本{U+534F}{U+8BAE}
* 2xx：表示成功，如接收或知道了
    * 200 OK: {U+8BF7}求成功
* 3xx：表示重定向，如要完成{U+8BF7}求{U+8FD8}必{U+987B}采取{U+8FDB}一步的行{U+52A8}
    * 301 Moved Permanently: 永久移{U+52A8}。{U+8BF7}求的{U+8D44}源已被永久的移{U+52A8}到新 URL，返回信息{U+4F1A}包括新的 URL，{U+6D4F}{U+89C8}器{U+4F1A}自{U+52A8}定向到新 URL。今後任何新的{U+8BF7}求都{U+5E94}使用新的 URL 代替
* 4xx：表示客{U+6237}的差{U+9519}，如{U+8BF7}求中有{U+9519}{U+8BEF}的{U+8BED}法或不能完成
    * 400 Bad Request: 客{U+6237}端{U+8BF7}求的{U+8BED}法{U+9519}{U+8BEF}，服{U+52A1}器{U+65E0}法理解
    * 401 Unauthorized: {U+8BF7}求要求用{U+6237}的身份{U+8BA4}{U+8BC1}
    * 403 Forbidden: 服{U+52A1}器理解{U+8BF7}求客{U+6237}端的{U+8BF7}求，但是拒{U+7EDD}{U+6267}行此{U+8BF7}求（{U+6743}限不{U+591F}）
    * 404 Not Found: 服{U+52A1}器{U+65E0}法根據客{U+6237}端的{U+8BF7}求找到{U+8D44}源（網{U+9875}）。通{U+8FC7}此代{U+7801}，網站{U+8BBE}{U+8BA1}人{U+5458}可{U+8BBE}置 「您所{U+8BF7}求的{U+8D44}源{U+65E0}法找到」 的{U+4E2A}性{U+9875}面
    * 408 Request Timeout: 服{U+52A1}器等待客{U+6237}端{U+53D1}送的{U+8BF7}求{U+65F6}{U+95F4}{U+8FC7}{U+957F}，超{U+65F6}
* 5xx：表示服{U+52A1}器的差{U+9519}，如服{U+52A1}器失效{U+65E0}法完成{U+8BF7}求
    * 500 Internal Server Error: 服{U+52A1}器{U+5185}部{U+9519}{U+8BEF}，{U+65E0}法完成{U+8BF7}求
    * 503 Service Unavailable: 由於超{U+8F7D}或系{U+7EDF}{U+7EF4}{U+62A4}，服{U+52A1}器{U+6682}{U+65F6}的{U+65E0}法{U+5904}理客{U+6237}端的{U+8BF7}求。延{U+65F6}的{U+957F}度可包含在服{U+52A1}器的 Retry-After {U+5934}信息中
    * 504 Gateway Timeout: 充{U+5F53}網{U+5173}或代理的服{U+52A1}器，未及{U+65F6}{U+4ECE}{U+8FDC}端服{U+52A1}器{U+83B7}取{U+8BF7}求

> 更多{U+72B6}{U+6001}{U+7801}：[菜{U+9E1F}教程 . HTTP{U+72B6}{U+6001}{U+7801}](http://www.runoob.com/http/http-status-codes.html)

##### 其他{U+534F}{U+8BAE}

* SMTP（Simple Main Transfer Protocol，{U+7B80}{U+5355}{U+90AE}件{U+4F20}{U+8F93}{U+534F}{U+8BAE}）是在 Internet {U+4F20}{U+8F93} Email 的{U+6807}准，是一{U+4E2A}相{U+5BF9}{U+7B80}{U+5355}的基於文本的{U+534F}{U+8BAE}。在其之上指定了一{U+6761}消息的一{U+4E2A}或多{U+4E2A}接收者（在大多{U+6570}情{U+51B5}下被確{U+8BA4}是存在的），然後消息文本{U+4F1A}被{U+4F20}{U+8F93}。可以很{U+7B80}{U+5355}地通{U+8FC7} Telnet 程序{U+6765}{U+6D4B}{U+8BD5}一{U+4E2A} SMTP 服{U+52A1}器。SMTP 使用 TCP 端口 25。
* DHCP（Dynamic Host Configuration Protocol，{U+52A8}{U+6001}主機{U+8BBE}置{U+534F}{U+8BAE}）是一{U+4E2A}局域網的網{U+7EDC}{U+534F}{U+8BAE}，使用 UDP {U+534F}{U+8BAE}工作，主要有{U+4E24}{U+4E2A}用途：
    * 用於{U+5185}部網{U+7EDC}或網{U+7EDC}服{U+52A1}供{U+5E94}商自{U+52A8}分配 IP 地址{U+7ED9}用{U+6237}
    * 用於{U+5185}部網{U+7EDC}管理{U+5458}作{U+4E3A}{U+5BF9}所有{U+7535}{U+8111}作中央管理的手段
* SNMP（Simple Network Management Protocol，{U+7B80}{U+5355}網{U+7EDC}管理{U+534F}{U+8BAE}）構成了互{U+8054}網工程工作小{U+7EC4}（IETF，Internet Engineering Task Force）定{U+4E49}的 Internet {U+534F}{U+8BAE}族的一部分。{U+8BE5}{U+534F}{U+8BAE}能{U+591F}支持網{U+7EDC}管理系{U+7EDF}，用以{U+76D1}{U+6D4B}{U+8FDE}接到網{U+7EDC}上的{U+8BBE}{U+5907}是否有任何引起管理上{U+5173}注的情{U+51B5}。

## 網{U+7EDC}{U+7F16}程

### Socket

[Linux Socket {U+7F16}程（不限 Linux）](https://www.cnblogs.com/skynet/archive/2010/12/12/1903949.html)

![Socket 客{U+6237}端服{U+52A1}器通{U+8BAF}](images/socket客{U+6237}端服{U+52A1}器通{U+8BAF}.jpg)


#### Socket 中的 read()、write() 函{U+6570}

```cpp
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
```

##### read()

* read 函{U+6570}是{U+8D1F}{U+8D23}{U+4ECE} fd 中{U+8BFB}取{U+5185}容。
* {U+5F53}{U+8BFB}成功{U+65F6}，read 返回{U+5B9E}{U+9645}所{U+8BFB}的字{U+8282}{U+6570}。
* 如果返回的值是 0 表示已{U+7ECF}{U+8BFB}到文件的{U+7ED3}束了，小於 0 表示出{U+73B0}了{U+9519}{U+8BEF}。
* 如果{U+9519}{U+8BEF}{U+4E3A} EINTR {U+8BF4}明{U+8BFB}是由中{U+65AD}引起的；如果是 ECONNREST 表示網{U+7EDC}{U+8FDE}接出了{U+95EE}{U+9898}。

##### write()

* write 函{U+6570}{U+5C06} buf 中的 nbytes 字{U+8282}{U+5185}容{U+5199}入文件描述符 fd。
* 成功{U+65F6}返回{U+5199}的字{U+8282}{U+6570}。失{U+8D25}{U+65F6}返回 -1，並{U+8BBE}置 errno {U+53D8}量。
* 在網{U+7EDC}程序中，{U+5F53}我{U+4EEC}向套接字文件描述符{U+5199}{U+65F6}有{U+4FE9}種可能。
* （1）write 的返回值大於 0，表示{U+5199}了部分或者是全部的{U+6570}據。
* （2）返回的值小於 0，此{U+65F6}出{U+73B0}了{U+9519}{U+8BEF}。
* 如果{U+9519}{U+8BEF}{U+4E3A} EINTR 表示在{U+5199}的{U+65F6}候出{U+73B0}了中{U+65AD}{U+9519}{U+8BEF}；如果{U+4E3A} EPIPE 表示網{U+7EDC}{U+8FDE}接出{U+73B0}了{U+95EE}{U+9898}（{U+5BF9}方已{U+7ECF}{U+5173}{U+95ED}了{U+8FDE}接）。

#### Socket 中 TCP 的三次握手建立{U+8FDE}接

我{U+4EEC}知道 TCP 建立{U+8FDE}接要{U+8FDB}行 「三次握手」，即交{U+6362}三{U+4E2A}分{U+7EC4}。大致流程如下：

1. 客{U+6237}端向服{U+52A1}器{U+53D1}送一{U+4E2A} SYN J
2. 服{U+52A1}器向客{U+6237}端{U+54CD}{U+5E94}一{U+4E2A} SYN K，並{U+5BF9} SYN J {U+8FDB}行確{U+8BA4} ACK J+1
3. 客{U+6237}端再想服{U+52A1}器{U+53D1}一{U+4E2A}確{U+8BA4} ACK K+1

只有就完了三次握手，但是{U+8FD9}{U+4E2A}三次握手{U+53D1}生在 Socket 的那幾{U+4E2A}函{U+6570}中呢？{U+8BF7}看下{U+56FE}：

![socket 中{U+53D1}送的 TCP 三次握手](http://images.cnblogs.com/cnblogs_com/skynet/201012/201012122157467258.png)

{U+4ECE}{U+56FE}中可以看出：
1. {U+5F53}客{U+6237}端{U+8C03}用 connect {U+65F6}，觸{U+53D1}了{U+8FDE}接{U+8BF7}求，向服{U+52A1}器{U+53D1}送了 SYN J 包，{U+8FD9}{U+65F6} connect {U+8FDB}入阻塞{U+72B6}{U+6001}；  
2. 服{U+52A1}器{U+76D1}聽到{U+8FDE}接{U+8BF7}求，即收到 SYN J 包，{U+8C03}用 accept 函{U+6570}接收{U+8BF7}求向客{U+6237}端{U+53D1}送 SYN K ，ACK J+1，{U+8FD9}{U+65F6} accept {U+8FDB}入阻塞{U+72B6}{U+6001}；  
3. 客{U+6237}端收到服{U+52A1}器的 SYN K ，ACK J+1 之後，{U+8FD9}{U+65F6} connect 返回，並{U+5BF9} SYN K {U+8FDB}行確{U+8BA4}；  
4. 服{U+52A1}器收到 ACK K+1 {U+65F6}，accept 返回，至此三次握手完{U+6BD5}，{U+8FDE}接建立。

#### Socket 中 TCP 的四次握手{U+91CA}放{U+8FDE}接

上面介{U+7ECD}了 socket 中 TCP 的三次握手建立{U+8FC7}程，及其涉及的 socket 函{U+6570}。{U+73B0}在我{U+4EEC}介{U+7ECD} socket 中的四次握手{U+91CA}放{U+8FDE}接的{U+8FC7}程，{U+8BF7}看下{U+56FE}：

![socket 中{U+53D1}送的 TCP 四次握手](http://images.cnblogs.com/cnblogs_com/skynet/201012/201012122157487616.png)

{U+56FE}示{U+8FC7}程如下：

1. 某{U+4E2A}{U+5E94}用{U+8FDB}程首先{U+8C03}用 close 主{U+52A8}{U+5173}{U+95ED}{U+8FDE}接，{U+8FD9}{U+65F6} TCP {U+53D1}送一{U+4E2A} FIN M；
2. 另一端接收到 FIN M 之後，{U+6267}行被{U+52A8}{U+5173}{U+95ED}，{U+5BF9}{U+8FD9}{U+4E2A} FIN {U+8FDB}行確{U+8BA4}。它的接收也作{U+4E3A}文件{U+7ED3}束符{U+4F20}{U+9012}{U+7ED9}{U+5E94}用{U+8FDB}程，因{U+4E3A} FIN 的接收意味{U+7740}{U+5E94}用{U+8FDB}程在相{U+5E94}的{U+8FDE}接上再也接收不到{U+989D}外{U+6570}據；
3. 一段{U+65F6}{U+95F4}之後，接收到文件{U+7ED3}束符的{U+5E94}用{U+8FDB}程{U+8C03}用 close {U+5173}{U+95ED}它的 socket。{U+8FD9}{U+5BFC}致它的 TCP 也{U+53D1}送一{U+4E2A} FIN N；
4. 接收到{U+8FD9}{U+4E2A} FIN 的源{U+53D1}送端 TCP {U+5BF9}它{U+8FDB}行確{U+8BA4}。

{U+8FD9}{U+6837}每{U+4E2A}方向上都有一{U+4E2A} FIN 和 ACK。

## {U+6570}據{U+5E93}

* {U+6570}據{U+5E93}事{U+52A1}四大特性：原子性、一致性、分離性、持久性
* {U+6570}據{U+5E93}索引：{U+987A}序索引、B+ {U+6811}索引、hash 索引
[MySQL 索引背後的{U+6570}據{U+7ED3}構及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)
* [SQL {U+7EA6}束 (Constraints)](http://www.w3school.com.cn/sql/sql_constraints.asp)

### 範式

* 第一範式（1NF）：{U+5C5E}性（字段）是最小{U+5355}位不可再分
* 第二範式（2NF）：{U+6EE1}足 1NF，每{U+4E2A}非主{U+5C5E}性完全依{U+8D56}於主{U+952E}（消除 1NF 非主{U+5C5E}性{U+5BF9}{U+7801}的部分函{U+6570}依{U+8D56}）
* 第三範式（3NF）：{U+6EE1}足 2NF，任何非主{U+5C5E}性不依{U+8D56}於其他非主{U+5C5E}性（消除 2NF 主{U+5C5E}性{U+5BF9}{U+7801}的{U+4F20}{U+9012}函{U+6570}依{U+8D56}）
* {U+9C8D}依斯-科得範式（BCNF）：{U+6EE1}足 3NF，任何非主{U+5C5E}性不能{U+5BF9}主{U+952E}子集依{U+8D56}（消除 3NF 主{U+5C5E}性{U+5BF9}{U+7801}的部分和{U+4F20}{U+9012}函{U+6570}依{U+8D56}）
* 第四範式（4NF）：{U+6EE1}足 3NF，{U+5C5E}性之{U+95F4}不能有非平凡且非函{U+6570}依{U+8D56}的多值依{U+8D56}（消除 3NF 非平凡且非函{U+6570}依{U+8D56}的多值依{U+8D56}）

## {U+8BBE}{U+8BA1}模式

> 各大{U+8BBE}{U+8BA1}模式例子{U+53C2}考：[CSDN{U+4E13}{U+680F} . C++ {U+8BBE}{U+8BA1}模式](https://blog.csdn.net/column/details/15392.html) 系列博文

[{U+8BBE}{U+8BA1}模式工程目{U+5F55}](DesignPattern)

### {U+5355}例模式

[{U+5355}例模式例子](DesignPattern/SingletonPattern)

### 抽象工廠模式

[抽象工廠模式例子](DesignPattern/AbstractFactoryPattern)

### 適配器模式

[適配器模式例子](DesignPattern/AdapterPattern)

### {U+6865}接模式

[{U+6865}接模式例子](DesignPattern/BridgePattern)

### {U+89C2}察者模式

[{U+89C2}察者模式例子](DesignPattern/ObserverPattern)

### {U+8BBE}{U+8BA1}模式的六大原{U+5219}

* {U+5355}一{U+804C}{U+8D23}原{U+5219}（SRP，Single Responsibility Principle）
* 裏氏替{U+6362}原{U+5219}（LSP，Liskov Substitution Principle）
* 依{U+8D56}倒置原{U+5219}（DIP，Dependence Inversion Principle）
* 接口隔離原{U+5219}（ISP，Interface Segregation Principle）
* 迪米特法{U+5219}（LoD，Law of Demeter）
* {U+5F00}放封{U+95ED}原{U+5219}（OCP，Open Close Principle）

## {U+94FE}接{U+88C5}{U+8F7D}{U+5E93}

### {U+5185}存、{U+6808}、堆

一般{U+5E94}用程序{U+5185}存空{U+95F4}有如下{U+533A}域：

* {U+6808}：由操作系{U+7EDF}自{U+52A8}分配{U+91CA}放，存放函{U+6570}的{U+53C2}{U+6570}值、局部{U+53D8}量等的值，用於{U+7EF4}{U+62A4}函{U+6570}{U+8C03}用的上下文
* 堆：一般由程序{U+5458}分配{U+91CA}放，若程序{U+5458}不{U+91CA}放，程序{U+7ED3}束{U+65F6}可能由操作系{U+7EDF}回收，用{U+6765}容{U+7EB3}{U+5E94}用程序{U+52A8}{U+6001}分配的{U+5185}存{U+533A}域
* 可{U+6267}行文件映像：存{U+50A8}{U+7740}可{U+6267}行文件在{U+5185}存中的映像，由{U+88C5}{U+8F7D}器{U+88C5}{U+8F7D}是{U+5C06}可{U+6267}行文件的{U+5185}存{U+8BFB}取或映射到{U+8FD9}裏
* 保留{U+533A}：保留{U+533A}並不是一{U+4E2A}{U+5355}一的{U+5185}存{U+533A}域，而是{U+5BF9}{U+5185}存中受到保{U+62A4}而禁止{U+8BBF}{U+95EE}的{U+5185}存{U+533A}域的{U+603B}{U+79F0}，如通常 C {U+8BED}言{U+8BB2}{U+65E0}效指{U+9488}{U+8D4B}值{U+4E3A} 0（NULL），因此 0 地址正常情{U+51B5}下不可能有效的{U+8BBF}{U+95EE}{U+6570}據

#### {U+6808}

{U+6808}保存了一{U+4E2A}函{U+6570}{U+8C03}用所需要的{U+7EF4}{U+62A4}信息，常被{U+79F0}{U+4E3A}堆{U+6808}{U+5E27}（Stack Frame）或活{U+52A8}{U+8BB0}{U+5F55}（Activate Record），一般包含以下幾方面：

* 函{U+6570}的返回地址和{U+53C2}{U+6570}
* {U+4E34}{U+65F6}{U+53D8}量：包括函{U+6570}的非{U+9759}{U+6001}局部{U+53D8}量以及{U+7F16}{U+8BD1}器自{U+52A8}生成的其他{U+4E34}{U+65F6}{U+53D8}量
* 保存上下文：包括函{U+6570}{U+8C03}用前後需要保持不{U+53D8}的寄存器

#### 堆

堆分配算法：

* 空{U+95F2}{U+94FE}表（Free List）
* 位{U+56FE}（Bitmap）
* {U+5BF9}象池

#### 「段{U+9519}{U+8BEF}（segment fault）」 或 「非法操作，{U+8BE5}{U+5185}存地址不能 read/write」

典型的非法指{U+9488}解引用造成的{U+9519}{U+8BEF}。{U+5F53}指{U+9488}指向一{U+4E2A}不允{U+8BB8}{U+8BFB}{U+5199}的{U+5185}存地址，而程序{U+5374}{U+8BD5}{U+56FE}利用指{U+9488}{U+6765}{U+8BFB}或{U+5199}{U+8BE5}地址{U+65F6}，{U+4F1A}出{U+73B0}{U+8FD9}{U+4E2A}{U+9519}{U+8BEF}。

普遍原因：

* {U+5C06}指{U+9488}初始化{U+4E3A} NULL，之後{U+6CA1}有{U+7ED9}它一{U+4E2A}合理的值就{U+5F00}始使用指{U+9488}
* {U+6CA1}用初始化{U+6808}中的指{U+9488}，指{U+9488}的值一般{U+4F1A}是{U+968F}機{U+6570}，之後就直接{U+5F00}始使用指{U+9488}

### {U+7F16}{U+8BD1}{U+94FE}接

#### 各平台文件格式

平台 | 可{U+6267}行文件 | 目{U+6807}文件 | {U+52A8}{U+6001}{U+5E93}/共享{U+5BF9}象 | {U+9759}{U+6001}{U+5E93}
---|---|---|---|---
Windows|exe|obj|dll|lib
Unix/Linux|ELF、out|o|so|a
Mac|Mach-O|o|dylib、tbd、framework|a、framework

#### {U+7F16}{U+8BD1}{U+94FE}接{U+8FC7}程

1. {U+9884}{U+7F16}{U+8BD1}（{U+9884}{U+7F16}{U+8BD1}器{U+5904}理如 `#include`、`#define` 等{U+9884}{U+7F16}{U+8BD1}指令，生成 `.i` 或 `.ii` 文件）
2. {U+7F16}{U+8BD1}（{U+7F16}{U+8BD1}器{U+8FDB}行{U+8BCD}法分析、{U+8BED}法分析、{U+8BED}{U+4E49}分析、中{U+95F4}代{U+7801}生成、目{U+6807}代{U+7801}生成、優化，生成 `.s` 文件）
3. {U+6C47}{U+7F16}（{U+6C47}{U+7F16}器把{U+6C47}{U+7F16}{U+7801}翻{U+8BD1}成機器{U+7801}，生成 `.o` 文件）
4. {U+94FE}接（{U+8FDE}接器{U+8FDB}行地址和空{U+95F4}分配、符{U+53F7}{U+51B3}{U+8BAE}、重定位，生成 `.out` 文件）

> {U+73B0}在版本 GCC 把{U+9884}{U+7F16}{U+8BD1}和{U+7F16}{U+8BD1}合成一步，{U+9884}{U+7F16}{U+8BD1}{U+7F16}{U+8BD1}程序 cc1、{U+6C47}{U+7F16}器 as、{U+8FDE}接器 ld

> MSVC {U+7F16}{U+8BD1}{U+73AF}境，{U+7F16}{U+8BD1}器 cl、{U+8FDE}接器 link、可{U+6267}行文件查看器 dumpbin

#### 目{U+6807}文件

{U+7F16}{U+8BD1}器{U+7F16}{U+8BD1}源代{U+7801}後生成的文件叫做目{U+6807}文件。目{U+6807}文件{U+4ECE}{U+7ED3}構上{U+8BB2}，它是已{U+7ECF}{U+7F16}{U+8BD1}後的可{U+6267}行文件格式，只是{U+8FD8}{U+6CA1}有{U+7ECF}{U+8FC7}{U+94FE}接的{U+8FC7}程，其中可能有些符{U+53F7}或有些地址{U+8FD8}{U+6CA1}有被{U+8C03}整。

> 可{U+6267}行文件（Windows 的 `.exe` 和 Linux 的 `ELF`）、{U+52A8}{U+6001}{U+94FE}接{U+5E93}（Windows 的 `.dll` 和 Linux 的 `.so`）、{U+9759}{U+6001}{U+94FE}接{U+5E93}（Windows 的 `.lib` 和 Linux 的 `.a`）都是按照可{U+6267}行文件格式存{U+50A8}（Windows 按照 PE-COFF，Linux 按照 ELF）

##### 目{U+6807}文件格式

* Windows 的 PE（Portable Executable），或{U+79F0}{U+4E3A} PE-COFF，`.obj` 格式
* Linux 的 ELF（Executable Linkable Format），`.o` 格式
* Intel/Microsoft 的 OMF（Object Module Format）
* Unix 的 `a.out` 格式
* MS-DOS 的 `.COM` 格式

> PE 和 ELF 都是 COFF（Common File Format）的{U+53D8}種

##### 目{U+6807}文件存{U+50A8}{U+7ED3}構

段 | 功能
--- | ---
File Header | 文件{U+5934}，描述整{U+4E2A}文件的文件{U+5C5E}性（包括文件是否可{U+6267}行、是{U+9759}{U+6001}{U+94FE}接或{U+52A8}{U+6001}{U+8FDE}接及入口地址、目{U+6807}硬件、目{U+6807}操作系{U+7EDF}等）
.text section | 代{U+7801}段，{U+6267}行{U+8BED}句{U+7F16}{U+8BD1}成的機器代{U+7801} 
.data section | {U+6570}據段，已初始化的全局{U+53D8}量和局部{U+9759}{U+6001}{U+53D8}量
.bss section | BSS 段（Block Started by Symbol），未初始化的全局{U+53D8}量和局部{U+9759}{U+6001}{U+53D8}量（因{U+4E3A}默{U+8BA4}值{U+4E3A} 0，所以只是在此{U+9884}留位置，不占空{U+95F4}）
.rodata section | 只{U+8BFB}{U+6570}據段，存放只{U+8BFB}{U+6570}據，一般是程序裏面的只{U+8BFB}{U+53D8}量（如 const 修{U+9970}的{U+53D8}量）和字符串常量
.comment section | 注{U+91CA}信息段，存放{U+7F16}{U+8BD1}器版本信息
.note.GNU-stack section | 堆{U+6808}提示段 

> 其他段略

#### {U+94FE}接的接口————符{U+53F7}

在{U+94FE}接中，目{U+6807}文件之{U+95F4}相互拼合{U+5B9E}{U+9645}上是目{U+6807}文件之{U+95F4}{U+5BF9}地址的引用，即{U+5BF9}函{U+6570}和{U+53D8}量的地址的引用。我{U+4EEC}{U+5C06}函{U+6570}和{U+53D8}量{U+7EDF}{U+79F0}{U+4E3A}符{U+53F7}（Symbol），函{U+6570}名或{U+53D8}量名就是符{U+53F7}名（Symbol Name）。

如下符{U+53F7}表（Symbol Table）：

Symbol（符{U+53F7}名） | Symbol Value （地址）
--- | ---
main| 0x100
Add | 0x123
... | ...

### Linux 的共享{U+5E93}（Shared Library）

Linux 下的共享{U+5E93}就是普通的 ELF 共享{U+5BF9}象。

共享{U+5E93}版本更新{U+5E94}{U+8BE5}保{U+8BC1}二{U+8FDB}制接口 ABI（Application Binary Interface）的兼容

#### 命名

`libname.so.x.y.z`

* x：主版本{U+53F7}，不同主版本{U+53F7}的{U+5E93}之{U+95F4}不兼容，需要重新{U+7F16}{U+8BD1}
* y：次版本{U+53F7}，高版本{U+53F7}向後兼容低版本{U+53F7}
* z：{U+53D1}布版本{U+53F7}，不{U+5BF9}接口{U+8FDB}行更改，完全兼容

#### 路{U+5F84}

大部分包括 Linux 在{U+5185}的{U+5F00}源系{U+7EDF}遵循 FHS（File Hierarchy Standard）的{U+6807}准，{U+8FD9}{U+6807}准{U+89C4}定了系{U+7EDF}文件如何存放，包括各{U+4E2A}目{U+5F55}{U+7ED3}構、{U+7EC4}{U+7EC7}和作用。

* `/lib`：存放系{U+7EDF}最{U+5173}{U+952E}和最基{U+7840}的共享{U+5E93}，如{U+52A8}{U+6001}{U+94FE}接器、C {U+8BED}言{U+8FD0}行{U+5E93}、{U+6570}{U+5B66}{U+5E93}等
* `/usr/lib`：存放非系{U+7EDF}{U+8FD0}行{U+65F6}所需要的{U+5173}{U+952E}性的{U+5E93}，主要是{U+5F00}{U+53D1}{U+5E93}
* `/usr/local/lib`：存放跟操作系{U+7EDF}本身並不十分相{U+5173}的{U+5E93}，主要是一些第三方{U+5E94}用程序的{U+5E93}

> {U+52A8}{U+6001}{U+94FE}接器{U+4F1A}在 `/lib`、`/usr/lib` 和由 `/etc/ld.so.conf` 配置文件指定的，目{U+5F55}中查找共享{U+5E93}

#### {U+73AF}境{U+53D8}量

* `LD_LIBRARY_PATH`：{U+4E34}{U+65F6}改{U+53D8}某{U+4E2A}{U+5E94}用程序的共享{U+5E93}查找路{U+5F84}，而不{U+4F1A}影{U+54CD}其他{U+5E94}用程序
* `LD_PRELOAD`：指定{U+9884}先{U+88C5}{U+8F7D}的一些共享{U+5E93}甚至是目{U+6807}文件
* `LD_DEBUG`：打{U+5F00}{U+52A8}{U+6001}{U+94FE}接器的{U+8C03}{U+8BD5}功能

#### so 共享{U+5E93}的{U+7F16}{U+5199}

<details><summary>使用 CLion {U+7F16}{U+5199}共享{U+5E93}</summary>

{U+521B}建一{U+4E2A}名{U+4E3A} MySharedLib 的共享{U+5E93}

CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)
project(MySharedLib)

set(CMAKE_CXX_STANDARD 11)

add_library(MySharedLib SHARED library.cpp library.h)
```

library.h

```cpp
#ifndef MYSHAREDLIB_LIBRARY_H
#define MYSHAREDLIB_LIBRARY_H

// 打印 Hello World!
void hello();

// 使用可{U+53D8}模版{U+53C2}{U+6570}求和
template <typename T>
T sum(T t)
{
    return t;
}
template <typename T, typename ...Types>
T sum(T first, Types ... rest)
{
    return first + sum<T>(rest...);
}

#endif
```

library.cpp

```cpp
#include <iostream>
#include "library.h"

void hello() {
    std::cout << "Hello, World!" << std::endl;
}
```

</details>

#### so 共享{U+5E93}的使用（被可{U+6267}行{U+9879}目{U+8C03}用）

<details><summary>使用 CLion {U+8C03}用共享{U+5E93}</summary>

{U+521B}建一{U+4E2A}名{U+4E3A} TestSharedLib 的可{U+6267}行{U+9879}目

CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)
project(TestSharedLib)

# C++11 {U+7F16}{U+8BD1}
set(CMAKE_CXX_STANDARD 11)

# {U+5934}文件路{U+5F84}
set(INC_DIR /home/xx/code/clion/MySharedLib)
# {U+5E93}文件路{U+5F84}
set(LIB_DIR /home/xx/code/clion/MySharedLib/cmake-build-debug)

include_directories(${INC_DIR})
link_directories(${LIB_DIR})
link_libraries(MySharedLib)

add_executable(TestSharedLib main.cpp)

# {U+94FE}接 MySharedLib {U+5E93}
target_link_libraries(TestSharedLib MySharedLib)
```

main.cpp

```cpp
#include <iostream>
#include "library.h"
using std::cout;
using std::endl;

int main() {

    hello();
    cout << "1 + 2 = " << sum(1,2) << endl;
    cout << "1 + 2 + 3 = " << sum(1,2,3) << endl;

    return 0;
}
```

{U+6267}行{U+7ED3}果

```
Hello, World!
1 + 2 = 3
1 + 2 + 3 = 6
```

</details>

### Windows {U+5E94}用程序入口函{U+6570}

* GUI（Graphical User Interface）{U+5E94}用，{U+94FE}接器{U+9009}{U+9879}：`/SUBSYSTEM:WINDOWS`
* CUI（Console User Interface）{U+5E94}用，{U+94FE}接器{U+9009}{U+9879}：`/SUBSYSTEM:CONSOLE`

<details><summary>_tWinMain 與 _tmain 函{U+6570}{U+58F0}明</summary>

```cpp
Int WINAPI _tWinMain(
    HINSTANCE hInstanceExe,
    HINSTANCE,
    PTSTR pszCmdLine,
    int nCmdShow);

int _tmain(
    int argc,
    TCHAR *argv[],
    TCHAR *envp[]);
```

</details>

{U+5E94}用程序{U+7C7B}型|入口{U+70B9}函{U+6570}|嵌入可{U+6267}行文件的{U+542F}{U+52A8}函{U+6570}
---|---|---
{U+5904}理ANSI字符（串）的GUI{U+5E94}用程序|_tWinMain(WinMain)|WinMainCRTSartup
{U+5904}理Unicode字符（串）的GUI{U+5E94}用程序|_tWinMain(wWinMain)|wWinMainCRTSartup
{U+5904}理ANSI字符（串）的CUI{U+5E94}用程序|_tmain(Main)|mainCRTSartup
{U+5904}理Unicode字符（串）的CUI{U+5E94}用程序|_tmain(wMain)|wmainCRTSartup
{U+52A8}{U+6001}{U+94FE}接{U+5E93}（Dynamic-Link Library）|DllMain|_DllMainCRTStartup 

### Windows 的{U+52A8}{U+6001}{U+94FE}接{U+5E93}（Dynamic-Link Library）

> 知{U+8BC6}{U+70B9}{U+6765}自《Windows核心{U+7F16}程（第五版）》

#### 用{U+5904}

* {U+6269}展了{U+5E94}用程序的特性
* {U+7B80}化了{U+9879}目管理
* 有助於{U+8282}省{U+5185}存
* 促{U+8FDB}了{U+8D44}源的共享
* 促{U+8FDB}了本地化
* 有助於解{U+51B3}平台{U+95F4}的差異
* 可以用於特殊目的

#### 注意

* {U+521B}建 DLL，事{U+5B9E}上是在{U+521B}建可供一{U+4E2A}可{U+6267}行模{U+5757}{U+8C03}用的函{U+6570}
* {U+5F53}一{U+4E2A}模{U+5757}提供一{U+4E2A}{U+5185}存分配函{U+6570}（malloc、new）的{U+65F6}候，它必{U+987B}同{U+65F6}提供另一{U+4E2A}{U+5185}存{U+91CA}放函{U+6570}（free、delete）
* 在使用 C 和 C++ 混{U+7F16}的{U+65F6}候，要使用 extern "C" 修{U+9970}符
* 一{U+4E2A} DLL 可以{U+5BFC}出函{U+6570}、{U+53D8}量（避免{U+5BFC}出）、C++ {U+7C7B}（{U+5BFC}出{U+5BFC}入需要同{U+7F16}{U+8BD1}器，否{U+5219}避免{U+5BFC}出）
* DLL 模{U+5757}：cpp 文件中的 __declspec(dllexport) {U+5199}在 include {U+5934}文件之前
* {U+8C03}用 DLL 的可{U+6267}行模{U+5757}：cpp 文件的 __declspec(dllimport) 之前不{U+5E94}{U+8BE5}定{U+4E49} MYLIBAPI

#### 加{U+8F7D} Windows 程序的搜索{U+987A}序

1. 包含可{U+6267}行文件的目{U+5F55}
2. Windows 的系{U+7EDF}目{U+5F55}，可以通{U+8FC7} GetSystemDirectory 得到
3. 16 位的系{U+7EDF}目{U+5F55}，即 Windows 目{U+5F55}中的 System 子目{U+5F55}
4. Windows 目{U+5F55}，可以通{U+8FC7} GetWindowsDirectory 得到
5. {U+8FDB}程的{U+5F53}前目{U+5F55}
6. PATH {U+73AF}境{U+53D8}量中所列出的目{U+5F55}

#### DLL 入口函{U+6570}

<details><summary>DllMain 函{U+6570}</summary>

```cpp
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch(fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // 第一次{U+5C06}一{U+4E2A}DLL映射到{U+8FDB}程地址空{U+95F4}{U+65F6}{U+8C03}用
        // The DLL is being mapped into the process' address space.
        break;
    case DLL_THREAD_ATTACH:
        // {U+5F53}{U+8FDB}程{U+521B}建一{U+4E2A}{U+7EBF}程的{U+65F6}候，用於告{U+8BC9}DLL{U+6267}行與{U+7EBF}程相{U+5173}的初始化（非主{U+7EBF}程{U+6267}行）
        // A thread is bing created.
        break;
    case DLL_THREAD_DETACH:
        // 系{U+7EDF}{U+8C03}用 ExitThread {U+7EBF}程退出前，即{U+5C06}{U+7EC8}止的{U+7EBF}程通{U+8FC7}告{U+8BC9}DLL{U+6267}行與{U+7EBF}程相{U+5173}的清理
        // A thread is exiting cleanly.
        break;
    case DLL_PROCESS_DETACH:
        // {U+5C06}一{U+4E2A}DLL{U+4ECE}{U+8FDB}程的地址空{U+95F4}{U+65F6}{U+8C03}用
        // The DLL is being unmapped from the process' address space.
        break;
    }
    return (TRUE); // Used only for DLL_PROCESS_ATTACH
}
```

</details>

#### {U+8F7D}入卸{U+8F7D}{U+5E93}

<details><summary>LoadLibrary、LoadLibraryExA、LoadPackagedLibrary、FreeLibrary、FreeLibraryAndExitThread 函{U+6570}{U+58F0}明</summary>

```cpp
// {U+8F7D}入{U+5E93}
HMODULE WINAPI LoadLibrary(
  _In_ LPCTSTR lpFileName
);
HMODULE LoadLibraryExA(
  LPCSTR lpLibFileName,
  HANDLE hFile,
  DWORD  dwFlags
);
// 若要在通用 Windows 平台（UWP）{U+5E94}用中加{U+8F7D} Win32 DLL，需要{U+8C03}用 LoadPackagedLibrary，而不是 LoadLibrary 或 LoadLibraryEx
HMODULE LoadPackagedLibrary(
  LPCWSTR lpwLibFileName,
  DWORD   Reserved
);

// 卸{U+8F7D}{U+5E93}
BOOL WINAPI FreeLibrary(
  _In_ HMODULE hModule
);
// 卸{U+8F7D}{U+5E93}和退出{U+7EBF}程
VOID WINAPI FreeLibraryAndExitThread(
  _In_ HMODULE hModule,
  _In_ DWORD   dwExitCode
);
```

</details>

#### {U+663E}示地{U+94FE}接到{U+5BFC}出符{U+53F7}

<details><summary>GetProcAddress 函{U+6570}{U+58F0}明</summary>

```cpp
FARPROC GetProcAddress(
  HMODULE hInstDll,
  PCSTR pszSymbolName  // 只能接受 ANSI 字符串，不能是 Unicode
);
```

</details>

#### DumpBin.exe 查看 DLL 信息

在 `VS 的{U+5F00}{U+53D1}人{U+5458}命令提示符` 使用 `DumpBin.exe` 可查看 DLL {U+5E93}的{U+5BFC}出段（{U+5BFC}出的{U+53D8}量、函{U+6570}、{U+7C7B}名的符{U+53F7}）、相{U+5BF9}{U+865A}{U+62DF}地址（RVA，relative virtual address）。如：
```
DUMPBIN -exports D:\mydll.dll
```

#### LoadLibrary 與 FreeLibrary 流程{U+56FE}

<details><summary>LoadLibrary 與 FreeLibrary 流程{U+56FE}</summary>

##### LoadLibrary

![WindowsLoadLibrary](http://ojlsgreog.bkt.clouddn.com/WindowsLoadLibrary.png)

##### FreeLibrary

![WindowsFreeLibrary](http://ojlsgreog.bkt.clouddn.com/WindowsFreeLibrary.png)

</details>

#### DLL {U+5E93}的{U+7F16}{U+5199}（{U+5BFC}出一{U+4E2A} DLL 模{U+5757}）

<details><summary>DLL {U+5E93}的{U+7F16}{U+5199}（{U+5BFC}出一{U+4E2A} DLL 模{U+5757}）</summary>
DLL {U+5934}文件

```cpp
// MyLib.h

#ifdef MYLIBAPI

// MYLIBAPI {U+5E94}{U+8BE5}在全部 DLL 源文件的 include "Mylib.h" 之前被定{U+4E49}
// 全部函{U+6570}/{U+53D8}量正在被{U+5BFC}出

#else

// {U+8FD9}{U+4E2A}{U+5934}文件被一{U+4E2A}exe源代{U+7801}模{U+5757}包含，意味{U+7740}全部函{U+6570}/{U+53D8}量被{U+5BFC}入
#define MYLIBAPI extern "C" __declspec(dllimport)

#endif

// {U+8FD9}裏定{U+4E49}任何的{U+6570}據{U+7ED3}構和符{U+53F7}

// 定{U+4E49}{U+5BFC}出的{U+53D8}量（避免{U+5BFC}出{U+53D8}量）
MYLIBAPI int g_nResult;

// 定{U+4E49}{U+5BFC}出函{U+6570}原型
MYLIBAPI int Add(int nLeft, int nRight);
```

DLL 源文件

```cpp
// MyLibFile1.cpp

// 包含{U+6807}准Windows和C{U+8FD0}行{U+65F6}{U+5934}文件
#include <windows.h>

// DLL源{U+7801}文件{U+5BFC}出的函{U+6570}和{U+53D8}量
#define MYLIBAPI extern "C" __declspec(dllexport)

// 包含{U+5BFC}出的{U+6570}據{U+7ED3}構、符{U+53F7}、函{U+6570}、{U+53D8}量
#include "MyLib.h"

// {U+5C06}此DLL源代{U+7801}文件的代{U+7801}放在此{U+5904}
int g_nResult;

int Add(int nLeft, int nRight)
{
    g_nResult = nLeft + nRight;
    return g_nResult;
}
```

</details>

#### DLL {U+5E93}的使用（{U+8FD0}行{U+65F6}{U+52A8}{U+6001}{U+94FE}接 DLL）

<details><summary>DLL {U+5E93}的使用（{U+8FD0}行{U+65F6}{U+52A8}{U+6001}{U+94FE}接 DLL）</summary>

```cpp
// A simple program that uses LoadLibrary and 
// GetProcAddress to access myPuts from Myputs.dll. 
 
#include <windows.h> 
#include <stdio.h> 
 
typedef int (__cdecl *MYPROC)(LPWSTR); 
 
int main( void ) 
{ 
    HINSTANCE hinstLib; 
    MYPROC ProcAdd; 
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE; 
 
    // Get a handle to the DLL module.
 
    hinstLib = LoadLibrary(TEXT("MyPuts.dll")); 
 
    // If the handle is valid, try to get the function address.
 
    if (hinstLib != NULL) 
    { 
        ProcAdd = (MYPROC) GetProcAddress(hinstLib, "myPuts"); 
 
        // If the function address is valid, call the function.
 
        if (NULL != ProcAdd) 
        {
            fRunTimeLinkSuccess = TRUE;
            (ProcAdd) (L"Message sent to the DLL function\n"); 
        }
        // Free the DLL module.
 
        fFreeResult = FreeLibrary(hinstLib); 
    } 

    // If unable to call the DLL function, use an alternative.
    if (! fRunTimeLinkSuccess) 
        printf("Message printed from executable\n"); 

    return 0;
}
```

</details>

### {U+8FD0}行{U+5E93}（Runtime Library）

#### 典型程序{U+8FD0}行步{U+9AA4}

1. 操作系{U+7EDF}{U+521B}建{U+8FDB}程，把控制{U+6743}交{U+7ED9}程序的入口（往往是{U+8FD0}行{U+5E93}中的某{U+4E2A}入口函{U+6570}）
2. 入口函{U+6570}{U+5BF9}{U+8FD0}行{U+5E93}和程序{U+8FD0}行{U+73AF}境{U+8FDB}行初始化（包括堆、I/O、{U+7EBF}程、全局{U+53D8}量構造等等）。
3. 入口函{U+6570}初始化後，{U+8C03}用 main 函{U+6570}，正式{U+5F00}始{U+6267}行程序主體部分。
4. main 函{U+6570}{U+6267}行完{U+6BD5}後，返回到入口函{U+6570}{U+8FDB}行清理工作（包括全局{U+53D8}量析構、堆{U+9500}{U+6BC1}、{U+5173}{U+95ED}I/O等），然後{U+8FDB}行系{U+7EDF}{U+8C03}用{U+7ED3}束{U+8FDB}程。

> 一{U+4E2A}程序的 I/O 指代程序與外界的交互，包括文件、管程、網{U+7EDC}、命令行、信{U+53F7}等。更{U+5E7F}{U+4E49}地{U+8BB2}，I/O 指代操作系{U+7EDF}理解{U+4E3A} 「文件」 的事物。

#### glibc 入口

`_start -> __libc_start_main -> exit -> _exit`

其中 `main(argc, argv, __environ)` 函{U+6570}在 `__libc_start_main` 裏{U+6267}行。

#### MSVC CRT 入口

`int mainCRTStartup(void)`

{U+6267}行如下操作：

1. 初始化和 OS 版本有{U+5173}的全局{U+53D8}量。
2. 初始化堆。
3. 初始化 I/O。
4. {U+83B7}取命令行{U+53C2}{U+6570}和{U+73AF}境{U+53D8}量。
5. 初始化 C {U+5E93}的一些{U+6570}據。
6. {U+8C03}用 main 並{U+8BB0}{U+5F55}返回值。
7. {U+68C0}查{U+9519}{U+8BEF}並{U+5C06} main 的返回值返回。

#### C {U+8BED}言{U+8FD0}行{U+5E93}（CRT）

大致包含如下功能：

* {U+542F}{U+52A8}與退出：包括入口函{U+6570}及入口函{U+6570}所依{U+8D56}的其他函{U+6570}等。
* {U+6807}准函{U+6570}：有 C {U+8BED}言{U+6807}准{U+89C4}定的C{U+8BED}言{U+6807}准{U+5E93}所{U+62E5}有的函{U+6570}{U+5B9E}{U+73B0}。
* I/O：I/O 功能的封{U+88C5}和{U+5B9E}{U+73B0}。
* 堆：堆的封{U+88C5}和{U+5B9E}{U+73B0}。
* {U+8BED}言{U+5B9E}{U+73B0}：{U+8BED}言中一些特殊功能的{U+5B9E}{U+73B0}。
* {U+8C03}{U+8BD5}：{U+5B9E}{U+73B0}{U+8C03}{U+8BD5}功能的代{U+7801}。

#### C{U+8BED}言{U+6807}准{U+5E93}（ANSI C）

包含：

* {U+6807}准{U+8F93}入{U+8F93}出（stdio.h）
* 文件操作（stdio.h）
* 字符操作（ctype.h）
* 字符串操作（string.h）
* {U+6570}{U+5B66}函{U+6570}（math.h）
* {U+8D44}源管理（stdlib.h）
* 格式{U+8F6C}{U+6362}（stdlib.h）
* {U+65F6}{U+95F4}/日期（time.h）
* {U+65AD}言（assert.h）
* 各種{U+7C7B}型上的常{U+6570}（limits.h & float.h）
* {U+53D8}{U+957F}{U+53C2}{U+6570}（stdarg.h）
* 非局部跳{U+8F6C}（setjmp.h）

## 海量{U+6570}據{U+5904}理

* [ 海量{U+6570}據{U+5904}理面{U+8BD5}{U+9898}集{U+9526}](http://blog.csdn.net/v_july_v/article/details/6685962)
* [十道海量{U+6570}據{U+5904}理面{U+8BD5}{U+9898}與十{U+4E2A}方法大{U+603B}{U+7ED3}](http://blog.csdn.net/v_JULY_v/article/details/6279498)

## 音{U+89C6}{U+9891}

* [最全{U+5B9E}{U+65F6}音{U+89C6}{U+9891}{U+5F00}{U+53D1}要用到的{U+5F00}源工程{U+6C47}{U+603B}](http://www.yunliaoim.com/im/1869.html)
* [18{U+4E2A}{U+5B9E}{U+65F6}音{U+89C6}{U+9891}{U+5F00}{U+53D1}中{U+4F1A}用到{U+5F00}源{U+9879}目](http://webrtc.org.cn/18%E4%B8%AA%E5%AE%9E%E6%97%B6%E9%9F%B3%E8%A7%86%E9%A2%91%E5%BC%80%E5%8F%91%E4%B8%AD%E4%BC%9A%E7%94%A8%E5%88%B0%E5%BC%80%E6%BA%90%E9%A1%B9%E7%9B%AE/)

## 其他

* [Bjarne Stroustrup 的常{U+89C1}{U+95EE}{U+9898}](http://www.stroustrup.com/bs_faq.html)
* [Bjarne Stroustrup 的 C++ {U+98CE}格和技巧常{U+89C1}{U+95EE}{U+9898}](http://www.stroustrup.com/bs_faq2.html)

## {U+4E66}籍

### {U+8BED}言

* 《C++ Primer》
* 《Effective C++》
* 《More Effective C++》
* 《深度探索 C++ {U+5BF9}象模型》
* 《深入理解 C++11》
* 《STL 源{U+7801}剖析》

### 算法

* 《{U+5251}指 Offer》
* 《{U+7F16}程珠{U+7391}》
* 《程序{U+5458}面{U+8BD5}{U+5B9D}典》

### 系{U+7EDF}

* 《深入理解{U+8BA1}算機系{U+7EDF}》
* 《Windows 核心{U+7F16}程》
* 《Unix {U+73AF}境高{U+7EA7}{U+7F16}程》

### 網{U+7EDC}

* 《Unix 網{U+7EDC}{U+7F16}程》
* 《TCP/IP {U+8BE6}解》

### 其他

* 《程序{U+5458}的自我修{U+517B}》

## 複{U+4E60}刷{U+9898}網站

* [leetcode](https://leetcode.com/)
* [牛客網](https://www.nowcoder.net/)
* [慕{U+8BFE}網](https://www.imooc.com/)
* [菜{U+9E1F}教程](http://www.runoob.com/)

## 招聘{U+65F6}{U+95F4}{U+5C97}位

* [牛客網 . 2019 IT名企校招指南](https://www.nowcoder.com/activity/campus2019)

## 面{U+8BD5}{U+9898}目{U+7ECF}{U+9A8C}

### 牛客網

* [牛客網 . 2017秋季校{U+56ED}招聘{U+7B14}{U+7ECF}面{U+7ECF}{U+4E13}{U+9898}{U+6C47}{U+603B}](https://www.nowcoder.com/discuss/12805)
* [牛客網 . 史上最全2017春招面{U+7ECF}大合集！！](https://www.nowcoder.com/discuss/25268)
* [牛客網 . 面{U+8BD5}{U+9898}幹{U+8D27}在此](https://www.nowcoder.com/discuss/57978)

### 知乎

* [知乎 . 互{U+8054}網求{U+804C}路上，你{U+89C1}{U+8FC7}哪些{U+5199}得很好、很用心的面{U+7ECF}？最好能分享自己的面{U+7ECF}、心路{U+5386}程。](https://www.zhihu.com/question/29693016)
* [知乎 . 互{U+8054}網公司最常{U+89C1}的面{U+8BD5}算法{U+9898}有哪些？](https://www.zhihu.com/question/24964987)
* [知乎 . 面{U+8BD5} C++ 程序{U+5458}，什麼{U+6837}的{U+95EE}{U+9898}是好{U+95EE}{U+9898}？](https://www.zhihu.com/question/20184857)

### CSDN

* [CSDN . 全面整理的C++面{U+8BD5}{U+9898}](http://blog.csdn.net/ljzcome/article/details/574158)
* [CSDN . 百度研{U+53D1}{U+7C7B}面{U+8BD5}{U+9898}（C++方向）](http://blog.csdn.net/Xiongchao99/article/details/74524807?locationNum=6&fps=1)
* [CSDN . c++常{U+89C1}面{U+8BD5}{U+9898}30道](http://blog.csdn.net/fakine/article/details/51321544)
* [CSDN . {U+817E}{U+8BAF}2016{U+5B9E}{U+4E60}生面{U+8BD5}{U+7ECF}{U+9A8C}（已{U+7ECF}拿到offer)](http://blog.csdn.net/onever_say_love/article/details/51223886)

### cnblogs

* [cnblogs . C++面{U+8BD5}集{U+9526}( 面{U+8BD5}被{U+95EE}到的{U+95EE}{U+9898} )](https://www.cnblogs.com/Y1Focus/p/6707121.html)
* [cnblogs . C/C++ {U+7B14}{U+8BD5}、面{U+8BD5}{U+9898}目大{U+6C47}{U+603B}](https://www.cnblogs.com/fangyukuan/archive/2010/09/18/1829871.html)
* [cnblogs . 常{U+89C1}C++面{U+8BD5}{U+9898}及基本知{U+8BC6}{U+70B9}{U+603B}{U+7ED3}（一）](https://www.cnblogs.com/LUO77/p/5771237.html)

### Segmentfault

* [segmentfault . C++常{U+89C1}面{U+8BD5}{U+95EE}{U+9898}{U+603B}{U+7ED3}](https://segmentfault.com/a/1190000003745529)
