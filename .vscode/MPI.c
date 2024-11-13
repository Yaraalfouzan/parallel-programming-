#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    int rank, size, n = 1000; // Default vector size (can be changed)
    double *a = NULL, *b = NULL; // Full vectors (only in root process)
    double local_sum = 0.0, global_sum = 0.0; // Partial and total sums

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get total number of processes

    int local_n = n / size; // Number of elements per process

    // Allocate memory for local chunks
    double *a_local = malloc(local_n * sizeof(double));
    double *b_local = malloc(local_n * sizeof(double));

    // Root process generates random vectors and scatters them
    if (rank == 0) {
        // Allocate full vectors in the root process
        a = malloc(n * sizeof(double));
        b = malloc(n * sizeof(double));

        // Generate random values for vectors a and b
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100; // Random values between 0 and 99
            b[i] = rand() % 100;
        }
    }

    // Scatter the vectors to all processes
    MPI_Scatter(a, local_n, MPI_DOUBLE, a_local, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(b, local_n, MPI_DOUBLE, b_local, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Compute local sum of squared differences
    for (int i = 0; i < local_n; i++) {
        double diff = a_local[i] - b_local[i];
        local_sum += diff * diff;
    }

    // Reduce local sums to calculate the global sum at root process
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Root process calculates the Euclidean distance
    if (rank == 0) {
        double euclidean_distance = sqrt(global_sum);
        printf("Euclidean Distance: %f\n", euclidean_distance);

        // Free memory for full vectors
        free(a);
        free(b);
    }

    // Free local memory
    free(a_local);
    free(b_local);

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
