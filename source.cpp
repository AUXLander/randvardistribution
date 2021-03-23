#include <iostream>
#include <cstdlib>
#include <map>

#include "src/distribution.hpp"

void makeHistogramm(DistributionBase& distribution, std::map<uint64_t, uint64_t>& histogramm, const unsigned int N = 10000)
{
	histogramm.clear();

	for (int n = 0; n < N; ++n)
	{
		++histogramm[distribution.next()];
	}
}

int main()
{
	std::random_device device;
	std::mt19937 generator(device());

	Distribution<DistributionBase::Uniform> uniform(&generator, 0, 100);
	//Distribution<DistributionBase::Poisson> poisson(&generator, 0, 100);
	Distribution<DistributionBase::Normal>  normal (&generator, 0, 100);

	std::map<uint64_t, uint64_t> histogramm;

	makeHistogramm(uniform, histogramm);
	//makeHistogramm(poisson, histogramm);

	makeHistogramm(normal, histogramm);

	return 0;
}