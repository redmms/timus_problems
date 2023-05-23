#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
//#include "my_code.h"
using namespace std;
vector <string> changes;
unordered_map <int, list <int>> sets;
vector <int> leaders;
void unite(int big, int ltl) { // big и ltl - вершины большего и меньшего множеств
	big = leaders[big], ltl = leaders[ltl];
	int bigSize = sets[big].size(), ltlSize = sets[ltl].size();
	if (bigSize < ltlSize)
		swap(big, ltl);
	for (auto child : sets[ltl])
		leaders[child] = big;
	sets[big].splice(sets[big].end(), sets[ltl]);
	sets.erase(ltl);
}
int main()
{
	// ввод первой строки:
	int n, d, a;
	cin >> n >> d >> a;

	// ввод матрицы и обработка данных:
	string s(n, '0');
	changes.resize(n, s);
	leaders.resize(n);
	for (int i = 0; i < n; i++)
	{
		sets[i].push_back(i);
		leaders[i] = i; // изначально у каждой вершины родитель - она сама
	}
	long long totalCost = 0;
	string line;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = i; j < n; j++)
		{
			if (line[j] == '1')
				if (leaders[i] == leaders[j])
				{
					changes[i][j] = 'd';  // найдем лидеров, а заодно и удалим лишние ребра
					changes[j][i] = 'd';  // если вершина уже добавлена в компонент связности, значит ребро лишнее и образует цикл, поэтому удаляем его
					totalCost += d;
				}
				else
					unite(i, j);
		}
	}
	if (sets.size() > 1)
		for (auto leader = next(sets.begin()); leader != sets.end(); leader++)
		{
			int prev = next(leader, -1)->first, cur = leader->first;
			changes[cur][prev] = 'a';  // объединим непересекающиеся множества сразу в матрице вывода:
			changes[prev][cur] = 'a';
			totalCost += a;
		}

	// вывод:
	cout << totalCost << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << changes[i] << '\n';
	}
	return 0;
}