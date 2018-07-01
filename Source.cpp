#include <iostream>
using namespace std;

int c;

int endian1() {
	int one = 1;
	char *ptr;
	ptr = (char *)&one;
	return (*ptr);
}
int main()
{
	int size;
	cin >> size;
	//int arr[size];
	//cout << sizeof(arr) << endl;
	int arr[]{ 1,2,3 };
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
	system("pause");
	return 0;
}