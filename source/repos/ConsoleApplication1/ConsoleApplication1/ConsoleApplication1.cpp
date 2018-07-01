
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <time.h>
using namespace std;
vector <vector<int>> crossing(vector<vector<int>> cromo2);
bool sea(vector <vector<int>> popul);
int max_w = 0;
int nachalo = 0;
const int NofV(20);
const int NofP(8);
int max_v = 10;
int B[NofV];
int Bi = 1;
int s;
int path_count = 0;
//vector<int> normalisation(vector<vector<int>> &am, vector<int> &alpha, int &wei);
int pr_w= 0;
vector<int> path(NofV);
vector<int> mutation(vector <int> chromo);
vector<int> tournament(vector <vector<int>> &popul);
int search_w(vector<int> chromo, int j);
void DFS(int st);
int weight = 0;
vector<int> ab(NofV);
int A[NofV][NofV];
void pr(vector<vector<int>> &chromo);
void makeNull(vector<vector<int>> &am);
void ss(vector <int> alpha, int nachalo, vector<vector<int>>&am, int wei);
vector<vector<int>> newpop(vector<vector<int>> &vec, vector<int> &it2, vector<vector<int>> &vecm, vector<int> &it3);
int main()
{
	srand(time(NULL));
	for (int i = 0; i < NofV; i++) 
	{
		for (int j = 0; j <= i; j++)
		{
			A[j][i] = rand() % max_v;
			A[i][j] = A[j][i];
		}
	}

	for (int i = 0; i < NofV; i++)
		A[i][i] = 0;

	for (int i = 0; i < NofV; i++)
	{
		for (int j = 0; j < NofV; j++)
		{
			std::cout << A[j][i] << " ";
		}
		std::cout << std::endl;
	}
	int length = 0;
	int j = 0;
	
	for (int k = 0; k < NofV; k++)
		B[k] = 0;
	clock_t DFSTIMEbegin = clock();
	DFS(j);
	clock_t DFSTIMEend = clock();
	std::cout << max_w << std::endl;
	vector<vector<int>> popul(NofP);
	for (int it1 = 0; it1 < NofP; it1++)
	{
		popul[it1].resize(NofV);
		for (int it2 = 0; it2 < NofV; it2++)
		{
			popul[it1][it2] = 0;
		}
	}
	vector<vector<int>> past(NofP);
	for (int it1 = 0; it1 < NofP; it1++)
	{
		past[it1].resize(NofV);
		for (int it2 = 0; it2 < NofV; it2++)
		{
			past[it1][it2] = 0;
		}
	}
	for (j = 0; j < NofP; j++)
	{
		popul[j][0] = 1;
		popul[j][NofV - 1] = 1;
	}
	for (j = 0; j < 40; j++)
	{
		popul[0] = mutation(popul[0]);
	}
	for (j = 0; j < NofP; j++)
	{
		popul[j] = popul[0];
	}
		vector <vector<int>> cros_v(2);
		cros_v[0].resize(NofV);
		cros_v[1].resize(NofV);
		bool flag = true;
		j = 0;
		vector<int> pop(4);
		clock_t algoTIMEbegin = clock();
		while (flag)
		{
			past = popul;
			int cros_counter1;
			int cros_counter2;
			for (int it = 0; it < NofV; it++)
			{
				cros_counter1 = rand() % NofP;
				cros_counter2 = rand() % NofP;
				cros_v[0] = popul[cros_counter1];
				cros_v[1] = popul[cros_counter2];
				cros_v = crossing(cros_v);
				popul[cros_counter1] = cros_v[0];
				popul[cros_counter2] = cros_v[1];
			}
			j++;
			cout << "cicle number " << j << "    ";
			for (int ji = 0; ji < NofP; ji++)
			{
				int a = rand() % NofV;
				if(a >=5)
				popul[ji] = mutation(popul[ji]);
			}
			vector<int> zn(4);
			
			zn = tournament(popul);
			flag = sea(popul);
			popul = newpop(popul, zn, past, pop);
			pop = zn;
			cout << endl;
		}
		clock_t algoTIMEend = clock();
		cout << "DFS is " <<   DFSTIMEend-DFSTIMEbegin << " algo is " <<   algoTIMEend-algoTIMEbegin;
	system("pause");
    return 0;
}
vector<vector<int>> newpop(vector<vector<int>> &vec, vector<int> &it2, vector<vector<int>> &vecm, vector<int> &it3)
{
	vector<vector<int>> vecl(NofP);
	for (int it1 = 0; it1 < NofP; it1++)
	{
		vecl[it1].resize(NofV);
		for (int it2 = 0; it2 < NofV; it2++)
		{
			vecl[it1][it2] = 0;
		}
	}
	for (int it1 = 0; it1 < (NofP / 2); it1++)
	{
		vecl[it1] = vec[it2[it1]];
		vecl[it1 + (NofP / 2)] = vecm[it3[it1]];
	}
	return vecl;
}
vector<int> mutation(vector <int> chromo)
{	
	int c = 1 + rand() % (NofV - 2);
	if (chromo[c] == 1)
	{
		chromo[c] = 0;
	}
	else
	{
		chromo[c] = 1;
	}
	return chromo;
}
void pr(vector<vector<int>> &chromo)
{
	for (int it1 = 0; it1 < NofP; it1++)
	{
		for (int it2 = 0; it2 < NofV; it2++)
		{
			if (chromo[it1][it2] == 1) { cout << "1 "; }
			else { cout << "0 "; }
		}
		cout << endl;
	}
	cout << endl;
}
bool sea(vector <vector<int>> popul)
{
	vector <vector <int>> am(NofV);
		for (int j = 0; j < NofV; j++)
		{
			am[j].resize(NofV);
		}
	for (int i = 0; i < NofP; i++)
	{
		makeNull(am);
		int wei = 0;
		vector <int> alpha = popul[i];
		ss(alpha, i, am, wei);
		int wea = 0;
		for (int j = 0; j < NofV; j++)
			if (am[NofV - 1][j] > wea)
				wea = am[NofV - 1][i];

		pr_w = 0;
		if (wea == max_w-NofV) 
		{
			cout << "weight is " << wea << endl;
			return false;
		}
	}
	return true;
}
void ss(vector <int> alpha,int nachalo, vector<vector<int>>&am, int wei)
{
	for (int i = 0; i < NofV; i++)
	{
		if (alpha[i] == 1 && A[nachalo][i] > 0)
		{
			wei += A[nachalo][i];
			am[nachalo][i] = wei;
			alpha[i] = 0;
			ss(alpha, i, am, wei);
		}
		
	}
}

int normalisation(int nachalo, int wea, int ww, vector<vector<int>> &am)
{
	ab[nachalo] = 1;
	if (nachalo != NofV - 1)
	{
		for (int i = 0; i < NofV; i++)
		{
			if (am[nachalo][i] > 0 && ab[i] == 0)
			{
				ww += A[nachalo][i];
				ab[i] = 1;
				if (wea >= ww-10)
				{
					return 1;
				}
				
				normalisation(i, wea, ww, am);
				ww -= A[nachalo][i];
				ab[i] = 0;
			}
		}
	}
	else
	{
		return 1;
	}
}
	
void makeNull(vector<vector<int>> &am)
{
	for (int i = 0; i < NofV; i++)
	{
		for(int j = 0; j < NofV; j++)
		{
			am[i][j] = 0;
		}
	}
}
vector<int> tournament(vector <vector<int>> &popul)
{
	vector <int> cur_w(NofP);
	vector <vector <int>> am(NofV);
	for (int j = 0; j < NofV; j++)
	{
		am[j].resize(NofV);
	}

	for (int i = 0; i < NofP; i++)
	{
		makeNull(am);
		int wei = 0;
		vector <int> alpha = popul[i];
		ss(alpha, i, am, wei);
		int wea = 0;
		
		for (int j = 0; j < NofV; j++)
			if (am[NofV - 1][j] > wea)
			{
				wea = am[NofV - 1][i];// was i?
				wei = j;
			}
		pr_w = 0;
		cur_w[i] = wea;
		//cout << endl;
		normalisation(0, wea, 0, am);
		if(s == 1)popul[i] = ab;
		for (int j = 0; j < NofP; j++)
		{
			ab[i] = 0;
		}
	}
	vector<int> t1(int(NofP / 2));
	int a = 0;
	while (a != 4)
	{
		int max_zn = 0;
		for (int i = 0; i < NofP; i++)
		{
			if (cur_w[max_zn] < cur_w[i] && cur_w[max_zn] < NofV*max_v)
			{
				max_zn = i;
			}
		}
		t1[a] = max_zn;
		cout << cur_w[max_zn] << " ";
		cur_w[max_zn] = 0;
		a++;
	}
	return t1;
}

int search_w(vector<int> chromo,int j)
{
	int flag = 1;
	for (int i = 0; i < NofV; i++)
	{
		if (A[j][i] > 0 && chromo[i] == 1 && flag ==1)
		{
			pr_w += A[j][i];
			chromo[i] = 0;
			chromo[j] = 0;
			flag = 0;
			search_w(chromo, i);
			
		}
	}
	return pr_w;
}

vector <vector<int>> crossing(vector<vector<int>> chromo2)
{
	int a = rand() % NofV;
	int b = rand() % NofV;
	int t;
	if (a > b)
	{
		for (int i = a; i <= b; i++)
		{
			t = chromo2[0][i];
			chromo2[0][i] = chromo2[1][i];
			chromo2[1][i] = t;
		}
	}
	else
	{
		for (int i = b; i <= a; i++)
		{
			t = chromo2[0][i];
			chromo2[0][i] = chromo2[1][i];
			chromo2[1][i] = t;
		}
	}
	return chromo2;
}

void DFS(int st)
{
	
	int r;
	B[st] = Bi;
	for (r = 0; r <= NofV; r++)
	{
		if ((A[st][r] > 0) && (B[r] == 0) && st!=NofV-1)
		{
			
			Bi++;
			weight += A[st][r];
			if (weight > max_w)
				max_w = weight;
			DFS(r);
			weight -= A[st][r];
			Bi--;
		}
	
	}	
	for (int j = 0; j < NofV; j++)
		if (A[st][j] > 0 && Bi < B[j])
			B[j] = 0;
}