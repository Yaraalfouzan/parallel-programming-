#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// Function to generate random vector
void generate_vector(double *vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 1000; // Random values
    }
}

// Function to calculate Euclidean distance
double calculate_euclidean_distance(double *a, double *b, int n) {
    double euclidean_distance = 0.0;

    #pragma omp parallel for reduction(+:euclidean_distance)
    for (int i = 0; i < n; i++) {
        double diff = a[i] - b[i];
        euclidean_distance += diff * diff;
    }

    return sqrt(euclidean_distance);
}

int main(int argc, char **argv) {
    int n = 150000;           // Default vector size
    double total_time = 0.0;  // Total execution time for all runs
    int num_runs = 10;        // Number of iterations

    if (argc == 2) {
        n = atoi(argv[1]); // If vector size is provided via command line
    }

    double *a = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    

    for (int i = 0; i < num_runs; i++) {
        
        
        generate_vector(a, n);
        generate_vector(b, n);
        // Start timing
        double start_time = omp_get_wtime();

        // Perform Euclidean distance calculation
        double euclidean_distance = calculate_euclidean_distance(a, b, n);

        // End timing
        double end_time = omp_get_wtime();

        total_time += (end_time - start_time);

        // Output for each run (optional)
        printf("Run %d: Time = %f seconds\n", i + 1, end_time - start_time);
    }

    // Compute and print the average execution time
    double average_execution_time = total_time / num_runs;
    printf("Average Execution Time over %d runs: %f seconds\n", num_runs, average_execution_time);

    free(a);
    free(b);

    return 0;
}
