#include "liblinkshared.h"
#include "libdistribution.hpp"

static std::random_device device;
static std::mt19937 generator(device());

static Distribution<DistributionBase::Uniform> uniform(&generator, -100, 100);
static Distribution<DistributionBase::Poisson> poisson(&generator, -100, 100);
static Distribution<DistributionBase::Normal>   normal(&generator, -100, 100);

uint64_t uniform_next()
{
    return uniform.next();
}

uint64_t poisson_next()
{
    return poisson.next();
}   

uint64_t normal_next()
{
    return normal.next();
}