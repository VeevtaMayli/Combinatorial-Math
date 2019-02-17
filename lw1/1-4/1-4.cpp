#include "pch.h"

using namespace std;

int main()
{
	const int N = 100;
	const int k = 5;

	if (k > N)
	{
		cout << "Program error" << endl;
		return 1;
	}

	char m = 1;
	vector<int> c(k + 1);
	c[0] = -1;
	iota(c.begin() + 1, c.end(), 1);

	boost::timer timer;
	timer.restart();

	while (m != 0)
	{
		//copy(c.begin() + 1, c.end(), std::ostream_iterator<size_t>(cout, " "));
		//cout << endl;
		m = k;
		while (c[m] == N - k + m)
		{
			m--;
		}
		c[m]++;
		for (size_t i = m + 1; i <= k; i++)
		{
			c[i] = c[i - 1] + 1;
		}
	}

	cout << timer.elapsed() << endl;

	return 0;
}
