#include "pch.h"

using namespace std;

vector<size_t> GetRandomPermutation(const int maxValueNumber)
{
	vector<size_t> permutation(maxValueNumber);
	iota(permutation.begin(), permutation.end(), 1);
	
	default_random_engine randomGenerator;
	uniform_int_distribution<size_t> range(0, maxValueNumber - 1);

	for (int i = 0; i < permutation.size(); i++)
	{
		size_t randomValue = range(randomGenerator);
		swap(permutation[i], permutation[randomValue]);
	}

	return permutation;
}

int main(const int argc, const char* argv[])
{
	const int maxPosition = 10;

	vector<size_t> permutation = GetRandomPermutation(maxPosition);

	copy(permutation.begin(), permutation.end(), std::ostream_iterator<size_t>(std::cout, " "));
	cout << endl;

	return 0;
}
