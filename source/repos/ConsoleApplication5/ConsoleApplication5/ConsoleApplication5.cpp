// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	static int a, b; 
	int c = 3;
	int *p = new int;
	std::cout <<&a<<" "<< a << " " << sizeof(a)<<std::endl;
	std::cout << &b << " " << b << " " << sizeof(b) << std::endl;
	std::cout << &c << " " << c << " " << sizeof(c) << std::endl;
	std::cout << p << " " << *p << " " << sizeof(*p) << std::endl;
	system("pause");
    return 0;
}

