#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int opt;

	double *x = NULL;
	double *y = NULL;

	int size = 0;

	while ((opt = getopt(argc, argv, "ht:i")) != -1)
	{
		switch (opt)
		{
		case 't':
			FILE *fptr;
			if ((fptr = fopen(optarg, "r")) == NULL)
			{
				// TODO: file input
				printf("Read from file not implemented yet. File: %s\n", optarg);
			}
			break;
		case 'i':
			// inputsize is size of manual input
			// size should be total size of data set
			// this allows user to input data as well as text
			int inputsize;

			printf("Size of data set: ");
			scanf("%d", &inputsize);
			printf("Input %d data pairs (x, y): \n", inputsize);

			if (x == NULL)
				x = malloc(inputsize * sizeof(double));
			else
				x = realloc(x, (size + inputsize) * sizeof(double));

			if (y == NULL)
				y = malloc(inputsize * sizeof(double));
			else
				y = realloc(y, (size + inputsize) * sizeof(double));

			for (int i = size; i < size + inputsize; i++)
			{
				scanf("%lf %lf", &x[i], &y[i]);
			}
			size += inputsize;
			break;
		case 'h':
		default:
			printf("-h : Print help instructions.\n");
			printf("-t : Read data from a text file.\n");
			printf("-i : Read data from a manual input.\n");
			exit(EXIT_SUCCESS);
		}
	}

	return 0;
}