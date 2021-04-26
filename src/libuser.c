#include "liblinkshared.h"

int main(int argc, char** argv)
{
    printf("uniform: %ld\n", uniform_next());
    printf("normal: %ld\n",  normal_next());
}