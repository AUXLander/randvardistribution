#include "libdistribution.hpp"

static std::random_device device;
static std::mt19937 generator(device());

static Distribution<DistributionBase::Uniform> uniform(&generator, 0, 100);

uint64_t uniform_next()
{
    return uniform.next();
}

#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc > 0)
    {
        printf("%s\n", argv[1]);
        printf("%s\n", add(argv[1]));
        printf("%d\n", uniform_next());
    }
}
