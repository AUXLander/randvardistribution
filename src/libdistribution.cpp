#include "liblinkshared.h"
#include "libdistribution.hpp"

static std::random_device device;
static std::mt19937 generator(device());

static Distribution<DistributionBase::Uniform> uniform(&generator, -50, 50);
static Distribution<DistributionBase::Normal>   normal(&generator, 0, 10);

int64_t uniform_next()
{
    return uniform.next();
}

int64_t normal_next()
{
    return normal.next();
}