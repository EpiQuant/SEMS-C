#include <stdio.h>
#include "args.h"
#include "omp.h"
#include "mpi.h"

int main(int argc, char *argv[])
{
	getArgs(argc, argv);
	return 0;
}
