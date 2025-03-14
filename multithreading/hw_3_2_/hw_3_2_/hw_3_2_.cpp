#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <future>
#include <thread>

using namespace std;
typedef unsigned int ui;

int increment_vector(int value) {
	return value + 1;
}

template<typename Iterator, typename T>
void paralel_for_each(Iterator first, Iterator last, T f) {
	const ui length = distance(first, last);
	if (!length)
		return;
	const ui min_per_thread = 10;
	if (length < (2 * min_per_thread)) {
		for_each(first, last, f);
	}
	else {
		Iterator const mid_point = first + length / 2;
		future<void> first_half = async(&paralel_for_each<Iterator, T>, first, mid_point, f);
		future<void> last_half = async(&paralel_for_each<Iterator, T>, mid_point, last, f);
		first_half.get();
		last_half.get();
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
	int kol = 10;
	vector<int> v;
	for (int i = 0; i < kol; i++)
	{
		v.push_back(rand() % 100);
	}
	print_spisok(v);
	paralel_for_each(v.begin(), v.end(), [](int value) {std::cout << increment_vector(value) << " "; });
}