// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream in("20x20.txt");
	if (in.is_open())
	{
		cout << "i did it " << endl;

		int **x;
		x = new int*[20];
			for (int i = 0; i < 20; i++)
			{
				x[i] = new int[20];
			}
			int stc = -1;
			int sap = 0;
			int buff;
		while (!in.eof())
		{
			stc++;
			in >> buff;
			if (buff == '\n')
			{
				stc = -1;
				sap++;
				cout << endl;
				continue;
			}
			else
			{
				**(x + 20*sap+stc) = buff;
				cout << **(x + 20 * sap + stc) << " ";
			}
		}
	}
	else
	{
		cout << " somerthitg goes wrong";
	}
	system("pause");
    return 0;
}

