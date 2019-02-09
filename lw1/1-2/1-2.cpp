#include "pch.h"

using namespace std;

int main()
{
	const int n = 10;
	const int borderCount = 2;

	vector<size_t> pi(n + borderCount);
	vector<size_t> p(n + borderCount);
	iota(pi.begin() + 1, pi.end() - 1, 1);
	p = pi;

	vector<int> d(n + borderCount);
	fill(d.begin() + 1, d.end() - 1, -1);

	int m = n + 1;

	pi[0] = m;
	pi[n + borderCount - 1] = m;
	d[1] = 0;

	boost::timer t;
	t.restart();

	while (m != 1)
	{
		m = n;
		while (pi[p[m] + d[m]] > m)
		{
			d[m] = -d[m];
			--m;
		}
		swap(pi[p[m]], pi[p[m] + d[m]]);
		swap(p[pi[p[m]]], p[m]);
	}

	cout << t.elapsed() << endl;

	return 0;
}
