#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <future>

using namespace std;

void min_el(int begin, vector<int>& v, promise<int> prom)
{
	int min1 = begin;
	for (int j = begin; j < v.size(); j++)
	{
		if (v.at(j) < v.at(min1))
		{
			min1 = j;
		}
	}
	prom.set_value(min1);
}

void sort_spisok(vector<int>& v)
{
	int a, b;
	for (int i = 0; i < v.size(); i++)
	{
		promise<int> prom;
		future<int> fut = prom.get_future();
		future<void> res = async(launch::async, min_el, i, ref(v), move(prom));
		res.wait();
		b = fut.get();
		a = v.at(b);
		v.at(b) = v.at(i);
		v.at(i) = a;
	}
}

void print_spisok(vector<int>& v)
{
	cout << "Список: ";
	for (const auto& k : v)
	{
		cout << k << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	int kol = 20;
	vector<int> v;
	for (int i = 0; i < kol; i++)
	{
		v.push_back(rand() % 100);
	}
	print_spisok(v);
	sort_spisok(v);
	print_spisok(v);
}