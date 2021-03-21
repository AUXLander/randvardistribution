#include <iostream>
#include <cstdlib>
#include <map>

#include "src/distribution.hpp"

void makeHistogramm(Distribution& distribution, std::map<uint64_t, uint64_t>& histogramm, const unsigned int N = 10000)
{
	for (int n = 0; n < N; ++n)
	{
		++histogramm[distribution.next(0, 100)];
	}
}

int main()
{
	std::random_device device;
	std::mt19937 generator(device());

	UniformDistribution uniform(&generator);
	PoissonDistribution poisson(&generator);
	NormalDistribution  normal (&generator);

	std::map<uint64_t, uint64_t> histogramm;

	makeHistogramm(uniform, histogramm);
	makeHistogramm(poisson, histogramm);

	return 0;

	makeHistogramm(normal, histogramm);

	return 0;
}