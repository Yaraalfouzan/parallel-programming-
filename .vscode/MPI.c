#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate_euclidean_distance(int n, int rank, int size) {
    double *a = NULL, *b = NULL; // Full vectors (only in root process)
    double local_sum = 0.0, global_sum = 0.0; // Partial and total sums
    int local_n = n / size; // Number of elements per process

    // Allocate memory for local chunks
    double *a_local = malloc(local_n * sizeof(double));
    double *b_local = malloc(local_n * sizeof(double));

    // Root process generates random vectors and scatters them
    if (rank == 0) {
        a = malloc(n * sizeof(double));
        b = malloc(n * sizeof(double));

        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100;
            b[i] = rand() % 100;
        }
    }

    // Scatter the vectors to all processes
    MPI_Scatter(a, local_n, MPI_DOUBLE, a_local, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(b, local_n, MPI_DOUBLE, b_local, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Compute local sum of squared differences
    for (int i = 0; i < local_n; i++) {
        local_sum += pow(a_local[i] - b_local[i], 2);
    }

    // Reduce local sums to calculate the global sum at root process
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Root process calculates and prints the Euclidean distance
    if (rank == 0) {
        double euclidean_distance = sqrt(global_sum);
        printf("Final result: %f\n", euclidean_distance);

        // Free the full vectors
        free(a);
        free(b);
    }

    // Free local memory
    free(a_local);
    free(b_local);
}

int main(int argc, char **argv) {
    int rank, size, n = 1500000; // Vector size
    double total_time = 0.0; // Total execution time for all runs
    int num_runs = 10;       // Number of iterations

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get total number of processes

    for (int i = 0; i < num_runs; i++) {
        // Start timing
        double start_time = MPI_Wtime();

        // Perform Euclidean distance calculation
        calculate_euclidean_distance(n, rank, size);

        // End timing
        double end_time = MPI_Wtime();

        // Accumulate elapsed time for this run (only on the root process)
        if (rank == 0) {
            total_time += (end_time - start_time);
        }
    }

    // Compute and print the average execution time on the root process
    if (rank == 0) {
        double average_execution_time = total_time / num_runs;
        printf("Average Execution Time over %d runs: %f seconds\n", num_runs, average_execution_time);
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
