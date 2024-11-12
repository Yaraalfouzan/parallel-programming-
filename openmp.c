#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// Function to generate random vector
void generate_vector(double *vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 100; // Random values between 0 and 99
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <vector_size>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double *a = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    generate_vector(a, n);
    generate_vector(b, n);

    double start_time, end_time;
    double euclidean_distance = 0.0;

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:euclidean_distance)
    for (int i = 0; i < n; i++) {
        double diff = a[i] - b[i];
        euclidean_distance += diff * diff;
    }

    euclidean_distance = sqrt(euclidean_distance);

    end_time = omp_get_wtime();

    printf("Euclidean Distance: %f\n", euclidean_distance);
    printf("Time taken: %f seconds\n", end_time - start_time);

    free(a);
    free(b);

    return 0;
}
