#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(int argc, char* argv[]) 
{
	if (argc < 3)
		exit(1);

	double tstart = 0.0, tend = 0.0, ttaken;

	/* Parse arguments */
	int N = strtol(argv[1], NULL, 10);
	int t = strtol(argv[2], NULL, 10);

	if (!(N > 2 && N <= 1000000) || !(t > 0 && t <= 100))
		exit(1);

	int stop = (N+1) / 2;
	int* primes = (int *)calloc(N, sizeof(int));

	tstart = omp_get_wtime();

	/* Generate prime numbers */
	int i, j;

	for (i = 2; i <= stop; i++) {
		if (primes[i-1] == 0) {
			for (j = 2; j <= N / i; j++)
				primes[i * j] = 1;
		}
	}

	ttaken = omp_get_wtime() - t_start;
	printf("Time take for the main part: %f\n", ttaken);

	/* Write output file and exit */
	FILE *output = fopen("%d.txt", N, "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	j = 1;
	int prev = 2;
	for (i = 2; i <= N; i++) {
		if (primes[i-1] == 0) {
			fprintf(output, "%d, %d, %d\n", j, i, i-prev);
			j++;
			prev = i;
		}
	}

	fclose(f);

	free(primes);

	exit(0);
}
