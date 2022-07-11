#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int random()
{
	static bool first = true;
	if (first)
	{
		srand(time(nullptr));
		first = false;
	}
	return (rand() % 100) + 1;
}

struct higher 
{
	bool operator() (int& a, int& b) 
	{
		return a > b;
	}
};

struct lower
{
	bool operator() (int& a, int& b)
	{
		return a < b;
	}
};


void print(vector<int>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;
}

int main()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(random());
	}
	print(v);
	
	string str;
	do
	{
		cout << "Ascendant or descendant (ASC/DESC)" << endl;
		cin >> str;
	} while (!(str == "ASC" || str == "DESC"));

	/*
	if (str == "ASC")
		make_heap(v.begin(), v.end(), higher());
	else
		make_heap(v.begin(), v.end(), lower());
	
	print(v)
	*/


	if (str == "ASC")
	{
		auto pq = priority_queue<int, vector<int>, higher>();
		for (auto it = v.begin(); it != v.end(); it++)
			pq.push(*it);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}

	}
	else
	{
		auto pq = priority_queue<int, vector<int>, lower>();
		for (auto it = v.begin(); it != v.end(); it++)
			pq.push(*it);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
	}
	
	return 0;
}