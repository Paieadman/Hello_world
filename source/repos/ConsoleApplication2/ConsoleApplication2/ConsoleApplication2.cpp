// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;
int main()
{
	/*ifstream file;
	file.open("20x20.txt");
	char buff[1000];
	int A[50];
	file.getline(A, 7);
		cout << A << endl;
		int i = 0;
		int count = 0;
		int temp;
		while (!file.eof()) 
		{
			file >> buff[count];
			count++;
		}
		for (int i = 0; i < count; i++)
			cout << buff[i] << " ";*/
	//file.getline(buff, 50); // считали строку из файла
	//file.close(); // закрываем файл
	//cout << buff << endl; // напечатали эту строку
	ifstream in("20x20.txt");
	int a, b;
	in >> a;
	in >> b;
	cout << a << " " << b << endl;
	int **x = nullptr;
	x = new int*[a];
	for (int y = 0; y < a; y++) 
		x[y] = new int[b];
	int i = -1;
	int j = 0;
	int c[40];
	int ci = 0;
	char symbol;
	while (true)
	{
		i++;
		if (!in.eof())
		{
			in >> symbol;
			if (symbol == '/n')
			{
				j++;
				c[ci] = i - 1;
				i = -1;
			}
			else {
				//if (symbol != ' ')
				//{
				cout << symbol << " ";
				x[j][i] = symbol;
				//}
				//else
				//{
				//continue;
				//}
			}
		}
		else 
		{
			break;
		}

	}
	


		
	
	/*if (in.is_open())
	{
		//Если открытие файла прошло успешно

		//Вначале посчитаем сколько чисел в файле
		int count = 0;// число чисел в файле
		int temp;//Временная переменная

		while (!in.eof())// пробегаем пока не встретим конец файла eof
		{
			in >> temp;//в пустоту считываем из файла числа
			count++;// увеличиваем счетчик числа чисел
		}

		//Число чисел посчитано, теперь нам нужно понять сколько
		//чисел в одной строке
		//Для этого посчитаем число пробелов до знака перевода на новую строку 

		//Вначале переведем каретку в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Число пробелов в первой строчке вначале равно 0
		int count_space = 0;
		char symbol;
		while (!in.eof())//на всякий случай цикл ограничиваем концом файла
		{
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			in.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}
		//cout << count_space << endl;

		//Опять переходим в потоке в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Теперь мы знаем сколько чисел в файле и сколько пробелов в первой строке.
		//Теперь можем считать матрицу.

		int n = count / (count_space + 1);//число строк
		int m = count_space + 1;//число столбцов на единицу больше числа пробелов
		int **x;
		x = new int*[n];
		for (int i = 0; i<n; i++) x[i] = new int[m];

		//Считаем матрицу из файла
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> x[i][j];

		//Выведем матрицу
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << x[i][j] << "\t";
			cout << "\n";
		}

		for (int i = 0; i<n; i++) delete[] x[i];
		delete[] x;

		in.close();//под конец закроем файла
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не найден.";
	}*/
	system("pause");
	return 0;
}

