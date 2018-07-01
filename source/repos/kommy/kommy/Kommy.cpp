#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int distance(int x1, int y1, int x2, int y2);
int iter(vector<vector<int>> &A, int NofV, vector<int> &path, vector<vector<int>> &ans);
int search_min(vector<int> S, int pos);
int w = 0;
bool nechet(vector<int> path, int what);
bool chet(vector<int> path, int what);

int main()
{
	int NofV;
	cout << "input NofV" << endl;
	cin >> NofV;
	vector<vector<int>> B(NofV);
	for (int i = 0; i < NofV; i++)
	{
		B[i].resize(2);
	}
	for (int i = 0; i < NofV; i++)
	{
		cout << "input " << i << " coords"<<endl;
		cin >> B[i][0] >> B[i][1];
	}

	vector<vector<int>> A(NofV);
	for (int i = 0; i < NofV; i++)
	{
		A[i].resize(NofV);
	}

	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			A[i][j] = distance(B[i][1], B[i][0], B[j][1], B[j][0]);
			A[j][i] = A[i][j];
		}
	}
	for (int i = 0; i < NofV; i++)
	{
		A[i][i] = 300;
	}
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j <NofV; j++)
		{
			cout << A[i][j]<< " ";
		}
		cout << endl;
	}
	vector<vector<int>> ans(NofV);
	ans = A;
	vector<int> path;// (NofV);
	path.push_back(300);
	path.push_back(300);
	vector<int> hello;
	//int p = 0;
	iter(A, NofV, path, ans);
	cout << "returnned";
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i] << " ";
	}
	system("pause");
	return 0;
}

int distance(int x1, int y1, int x2, int y2)
{
	double a = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	//cout << a << " pr";
	a = sqrt(a);
	//cout << a << " qrt";
	(int)a;
	return a;
}


int iter(vector<vector<int>> &A, int NofV, vector<int> &path, vector<vector<int>> &ans)
{
	vector<int> di(NofV);
	for (int i = 0; i < NofV; i++)
	{
		di[i] = 300;
	}
	vector<int> dj(NofV);
	for (int i = 0; i < NofV; i++)
	{
		di[i] = 300;
	}
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j<NofV; j++)
		{
			if (A[i][j] < di[i])
			{
				di[i] = A[i][j];
			}
		}
	}
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j<NofV; j++)
		{
			if (i != j)
			{
				A[i][j] = A[i][j] - di[i];
			}
		}
	}
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j<NofV; j++)
		{
			if (A[j][i] < dj[i])
			{
				dj[i] = A[j][i];
			}
		}
	}
	cout << endl;
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j<NofV; j++)
		{
			if (i != j)
			{
				A[j][i] = A[j][i] - dj[i];
			}
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//vector<int> di(NofV);
	for (int i = 0; i < NofV; i++)
	{
		di[i] = 300;
	}
	//vector<int> dj(NofV);
	for (int i = 0; i < NofV; i++)
	{
		dj[i] = 300;
	}
	/*for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j<NofV; j++)
		{
			if (A[i][j] < di[i] && A[i][j] != 0)//search min not !=0
			{
				di[i] = A[i][j];
			}
		}
		cout << di[i]<< " ";
	}
	*/
	cout << endl;
	/*
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j < NofV; j++)
		{
			if (A[j][i] < dj[i] && A[j][i] !=0)
			{
				dj[i] = A[j][i];
			}
		}
		cout << dj[i] << " ";
	}
	*/
	cout << endl;
	/*
	for (int j = 0; j < NofV; j++)
	{
		if (dj[j]==300)
		{
			dj[j] = 0;
		}
	}
	for (int j = 0; j < NofV; j++)
	{
		if (di[j] == 300)
		{
			di[j] = 0;
		}
	}
	*/
	vector<vector<int>> r(NofV);
	for (int i = 0; i < NofV; i++)
	{
		r[i].resize(NofV);
	}

	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j < NofV; j++)
		{
			if (A[i][j] == 0)
			{
				vector <int> v(NofV);
				for (int h = 0; h < NofV; h++)
					v[h] = A[i][h];
				r[i][j] = search_min(A[i], j)+ search_min(v, i);
				cout << r[i][j] << " ";
			}
		}
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j < NofV; j++)
		{
			cout << r[i][j] << " ";
		}
		cout << endl;
	}

	int max = 0;
	int x = 0, y = 0;
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j < NofV; j++)
		{
			if (r[i][j] > max)
			{
				max = r[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << max << " " << x << " " << y << "  f" << endl;
	A[y][x] = 300;
	vector<vector<int>> Second(NofV-1);
		
		/*for (int j = 0; j < NofV-1; j++)
		{
			Second[j].resize(NofV - 1);
		}*/
		int ic = 0, jc= 0;
		int i = 0;
		/*bool flag;
		while(i<NofV)
		{
			flag = true;
			jc = 0;

			for (int j = 0; j < NofV; j++)
			{
				if (flag)
				{
					if (i != x || j != y)
					{
						Second[i - ic][j - jc] = A[i][j];
					}
					else
					{
						if (x == i) { ic++; flag = false; }
						else
						{
							if (y == j) jc++;
						}

					}
				}
				
			}
			i++;
		}
		for (int i = 0; i < NofV-1; i++)
		{
			for (int j = 0; j < NofV-1; j++)
			{
				cout << Second[i][j]<<" ";
			}
			cout << endl;
		}
		*/
		//vector<int> v2(NofV);
		int a = 0;
		for (int i = 0; i < NofV; i++)
		{
			//vector<int> v1(NofV);
			if (x != i)
			{
				for (int j = 0; j < NofV; j++)
				{
					if (y != j)
					{
						Second[a].push_back(A[i][j]);
						//v1.push_back(A[i][j]);
						cout << A[i][j] << " ";
					}
				}
				a++;
			}
			//if(i!=x)a++;
			//Second.push_back(v1);
			cout<<endl;
			/*for (int h = 0; h < NofV-1; h++)
				cout << v1[h] << " ";*/
		}
		cout << endl;
		cout <<"second"<< endl;
		for (int i = 0; i < NofV - 1; i++)
		{
			for (int j = 0; j < NofV - 1; j++)
			{
				cout << Second[i][j] << " ";
			}
			cout << endl;
		}
		int it1 = 0; int it2 = 0;
		int c = 0;
		int b = 0;
		int tr1 = 0;
		int tr2 = 0;
		while (it1 < NofV)
		{
			if (nechet(path, it1))
			{
				while (it2 < NofV)
				{
					if (chet(path, it2))
					{
						if (c == x && b == y)
						{
							w += ans[it1][it2];
							tr1 = it1;
							tr2 = it2;
						}
						b++;
					}
					it2++;
				}
				c++;
			}
			it1++;
			b = 0;
		}
		path.push_back(tr1);
		cout << "tr1 " << tr1 << " tr2 " << tr2 << endl;
		path.push_back(tr2);
		cout << " here";
		//w = w + ans[x][y];
		int m = 300;
		if (NofV == 3)
		{
			for (int i = 0; i < Second.size(); i++)
			{
				for (int j = 0; j < Second.size(); j++)
				{
					if (Second[i][j] < m)
					{
						m = Second[i][j];
						x = i;
						y = j;
					}
				}
			}
			cout << "here i go";
			path.push_back(x);
			path.push_back(y);
			cout << "pushed";
			vector<int> yeah;
			yeah = path;
			cout << "made";
			return 0;
		}
		else
		{
			iter(Second, NofV - 1, path, ans);
		}
}
int search_min(vector<int> S, int pos)
{
	int min = 300;
	for (int i = 0; i < S.size(); i++)
	{
		if (i != pos && S[i]<min)
		{
			min = S[i];
		}
	}
	return min;
}
bool chet(vector<int> path, int what)
{
	int i = 1;
	while (i < path.size())
	{
		if (what == path[i])
		{
			return false;
		}
		i++;
		i++;
	}
	return true;
}
bool nechet(vector<int> path, int what)
{
	int i = 0;
	while (i < path.size())
	{
		if (what == path[i])
		{
			return false;
		}
		i++;
		i++;
	}
	return true;
}