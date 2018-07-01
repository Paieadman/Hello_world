
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;
vector <vector<int>> crossing(vector<vector<int>> cromo2);
int max_w = 0;
int maxc = 0;
int nachalo = 0;
const int NofV(30);
bool flag = true;
const int NofP(8);
int max_v = 10;
int B[NofV];
int max_ = 0;
int Bi = 1;
int pr_w = 0;
vector<int> mutation(vector <int> chromo);
vector<vector<int>> tournament(vector <vector<int>> &popul, vector <vector<int>> &past);
int search_w(vector<int> chromo);
vector<int> answer(NofV);
int weight = 0;
int A[NofV][NofV];
int find_num(vector<int> chromo, int what);
int end_c = 0;
int main()
{
	
	

	srand(time(NULL));

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
	popul[0][0] = 1;
	for (j = 0; j < NofV; j++)
	{
		popul[0][j] = j+1;
	}
	for (j = 0; j < NofP; j++)
	{
		popul[j] = popul[0];
	}
	vector <vector<int>> cros_v(2);
	cros_v[0].resize(NofV);
	cros_v[1].resize(NofV);
	clock_t algoTIMEbegin = clock();
	int g = 0;
	while (flag)
	{
		g++;
		past = popul;
		for (int ji = 0; ji < NofP; ji++)
		{
			int a = rand() % 10;
			if (a >= 3)
				popul[ji] = mutation(popul[ji]);
		}
		int cros_counter1;
		int cros_counter2;
		for (int it = 0; it < NofP; it++)
		{
			cros_counter1 = rand() % NofP;
			cros_counter2 = rand() % NofP;
			cros_v[0] = popul[cros_counter1];
			cros_v[1] = popul[cros_counter2];
			cros_v = crossing(cros_v);
			popul[cros_counter1] = cros_v[0];
			popul[cros_counter2] = cros_v[1];
		}
		popul = tournament(popul, past);		
	}
	clock_t algoTIMEend = clock();
	cout << " algo is " << algoTIMEend - algoTIMEbegin<<endl;
	cout<< max_<<" for GA"<<endl;
	for (int i = 0; i < NofV; i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

	vector<int> mutation(vector <int> chromo)
	{
		int a = 1 + rand() % (NofV - 2);
		int b = 1 + rand() % (NofV - 2);
		int c = 1 + rand() % (NofV - 2);
		

		int t = chromo[a];
		chromo[a] = chromo[b];
		chromo[b] = chromo[c];
		chromo[c] = t;
		return chromo;
	}
	
	
	
	
	
	
	
	vector<vector<int>> tournament(vector <vector<int>> &popul, vector <vector<int>> &past)
	{
		vector <int> cur_w(NofP);
		for (int i = 0; i < NofP; i++)
		{
			vector <int> alpha = popul[i];
			cur_w[i] = search_w(alpha);
			if (cur_w[i] > max_) {
				max_ = cur_w[i];
				maxc =0;
				answer = alpha;
			}//main expression
			else
				if (cur_w[i] == max_) { maxc++; if (maxc >= 50) flag = false; }
		}
		
		vector <int> cur_wp(NofP);
		for (int i = 0; i < NofP; i++)
		{
			vector <int> alpha = past[i];
			cur_wp[i] = search_w(alpha);
		}
		vector<int> maxi(4);
		int max_zn = 0;
		int a =0;
		while (a != 4)
		{
			for (int i = 0; i < NofP; i++)
			{
				if (cur_w[max_zn] < cur_w[i])
				{
					max_zn = i;
				}
			}
			maxi[a] = max_zn;
			cur_w[max_zn] = 0;
			a++;
		}

		vector<int> maxip(4);
		max_zn = 0;
		a = 0;
		while (a != 4)
		{
			for (int i = 0; i < NofP; i++)
			{
				if (cur_wp[max_zn] < cur_wp[i])
				{
					max_zn = i;
				}
			}
			maxip[a] = max_zn;
			cur_w[max_zn] = 0;
			a++;
		}
		
		vector<vector<int>> hop = popul;
		for (int i = 0; i < NofP/2; i++)
		{
			hop[i] = popul[maxi[i]];
		}
		for (int i = 0; i < 2; i++)
		{
			hop[i+(NofP / 2)] = past[maxip[i]];
		}
		
			for (int j = 0; j < NofV; j++)
			{
				hop[7][j] = j + 1;
			}
			hop[6] = hop[7];
		
		return hop;
	}

	int search_w(vector<int> chromo)
	{
		pr_w = 0;
		for (int i = 0; i < NofV-1; i++)
		{
			pr_w += A[chromo[i]-1][chromo[i + 1]-1];
		}
		return pr_w;
	}

	vector <vector<int>> crossing(vector<vector<int>> chromo2)
	{
		vector<int> p1(NofV);
		vector<int> p2(NofV);
		p1[0] = 1;
		p1[NofV - 1] = NofV;
		p2 = p1;
		int elem_c;
		bool f = true;
		int x;
		while (f)
		{		
			 x = elem_c = find_num(p1, 0);
			 if (elem_c == NofV + 2)
				 break;
				while (true)
				{
					p1[elem_c] = chromo2[0][elem_c];
					elem_c = find_num(chromo2[1], chromo2[0][elem_c]);
					if (elem_c == x || elem_c == (NofV+2))
						break;
				}
				x = elem_c = find_num(p1, 0);
				if (elem_c == NofV + 2)
					break;
				while (true)
				{
					p1[elem_c] = chromo2[1][elem_c];
					elem_c = find_num(chromo2[0], chromo2[1][elem_c]);
					if (elem_c == x || elem_c == (NofV + 2))
						break;
				}
				f = false;
				for (int i = 0; i < NofV; i++)
				{
					if (p1[i] == 0)
						f = true;
				}
				
		}

		f = true;
		while (f)
		{
			x = elem_c = find_num(p2, 0);
			if (elem_c == NofV + 2)
				break;
			while (true)
			{
				p2[elem_c] = chromo2[1][elem_c];
				elem_c = find_num(chromo2[0], chromo2[1][elem_c]);
				if (elem_c == x || elem_c == (NofV + 2))
					break;
			}
			x = elem_c = find_num(p2, 0);
			if (elem_c == NofV + 2)
				break;
			while (true)
			{
				p2[elem_c] = chromo2[0][elem_c];
				elem_c = find_num(chromo2[1], chromo2[0][elem_c]);
				if (elem_c == x || elem_c == (NofV + 2))
					break;
			}
			f = false;
			for (int i = 0; i < NofV; i++)
			{
				if (p2[i] == 0)
					f = true;
			}
		}
		chromo2[0] = p1;
		chromo2[1] = p2;
		return chromo2;
	}

	int find_num(vector<int> chromo, int what)
	{
		for (int i = 0; i < NofV; i++)
		{
			if (chromo[i] == what)
				return i;
		}
		return NofV+2;
	}

	