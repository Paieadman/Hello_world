#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int distance(int x1, int y1, int x2, int y2);
int iter(vector<vector<int>> &A, int NofV, vector<int> &path, vector<vector<int>> &ans);
int search_min(vector<int> S);
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
		cout << "input " << i << " coords" << endl;
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
	cout << endl;
	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j <NofV; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	vector<vector<int>> ans(NofV);
	ans = A;
	vector<int> path;// (NofV);
	path.push_back(300);
	path.push_back(300);
	vector<int> hello;
	iter(A, NofV, path, ans);
	cout << "right path is ";
	for (int i = 2; i < path.size(); i++)
	{
		cout << path[i] << " ";
	}
	cout << endl;
	for (int i = 2; i < path.size(); i = i +2)
	{
		w = w + ans[path[i]][path[i + 1]];
	}
	cout << "the best weight is ";
	cout << w << endl;
	system("pause");
	return 0;
}

int distance(int x1, int y1, int x2, int y2)
{
	double a = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	a = sqrt(a);
	(int)a;
	return a;
}


int iter(vector<vector<int>> &A, int NofV, vector<int> &path, vector<vector<int>> &ans)
{
	int a = 0;
	while (a < NofV)
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
			for (int j = 0; j < NofV; j++)
			{
				if (A[i][j] < di[i] && nechet(path, i) && chet(path, j))
				{
					di[i] = A[i][j];
				}
			}
		}
		for (int i = 0; i < NofV; i++)
		{
			for (int j = 0; j < NofV; j++)
			{
				if (i != j && nechet(path, i) && chet(path, j))
				{
					A[i][j] = A[i][j] - di[i];
				}
			}
		}
		for (int i = 0; i < NofV; i++)
		{
			for (int j = 0; j < NofV; j++)
			{
				if (A[j][i] < dj[i] && nechet(path, i) && chet(path, j))
				{
					dj[i] = A[j][i];
				}
			}
		}
		
		for (int i = 0; i < NofV; i++)
		{
			for (int j = 0; j < NofV; j++)
			{
				if (i != j && nechet(path, i) && chet(path, j))
				{
					A[j][i] = A[j][i] - dj[i];
				}
				
			}
			
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////
		
		for (int i = 0; i < NofV; i++)
		{
			di[i] = 300;
		}
		
		for (int i = 0; i < NofV; i++)
		{
			dj[i] = 300;
		}
		
		vector<vector<int>> r(NofV);
		for (int i = 0; i < NofV; i++)
		{
			r[i].resize(NofV);
		}

		for (int i = 0; i < NofV; i++)
		{
			for (int j = 0; j < NofV; j++)
			{
				if (A[i][j] == 0 && nechet(path, i) && chet(path, j))
				{
					vector <int> v;
					for (int h = 0; h < NofV; h++)
					{
						if (nechet(path, h) && h != i)
						{
							v.push_back(A[h][j]);
						}
					}
					vector <int> vi;
					for (int h = 0; h < NofV; h++)
					{
						if (chet(path, h) && h != j)
						{
							vi.push_back(A[i][h]);
						}
					}
					r[i][j] = search_min(vi) + search_min(v);
				}
			}
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
		
		path.push_back(x);
		path.push_back(y);
		A[y][x] = 300;
		a++;
	}
		return 0;
	
}
int search_min(vector<int> S)
{
	int min = 300;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i]<min)
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