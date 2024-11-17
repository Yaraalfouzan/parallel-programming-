#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 150000; //vector size

    double total_execution_time = 0.0;
    double total_distance = 0.0;

    for (int run = 1; run <= 10; run++) {
        double *vector1 = NULL, *vector2 = NULL;
        double start_time, end_time;

        if (rank == 0) {
            //memory allocation & generating random vectors on root process
            vector1 = (double*) malloc(n * sizeof(double));
            vector2 = (double*) malloc(n * sizeof(double));

            srand(time(NULL) + run); //change seed for each run
            for (int i = 0; i < n; i++) {
                vector1[i] = rand() % 1000;
                vector2[i] = rand() % 1000;
            }
        }

        //broadcast vectors to all processes
        double* local_vector1 = (double*) malloc((n / size) * sizeof(double));
        double* local_vector2 = (double*) malloc((n / size) * sizeof(double));

        MPI_Scatter(vector1, n / size, MPI_DOUBLE, local_vector1, n / size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        MPI_Scatter(vector2, n / size, MPI_DOUBLE, local_vector2, n / size, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        //start time
        MPI_Barrier(MPI_COMM_WORLD);
        start_time = MPI_Wtime();

        //local sum of squared differences
        double local_sum = 0.0;
        int local_size = n / size;

        for (int i = 0; i < local_size; i++) {
            double diff = local_vector1[i] - local_vector2[i];
            local_sum += diff * diff;
        }

        // all local sums and final result
        double global_sum = 0.0;
        MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        //stop time
        MPI_Barrier(MPI_COMM_WORLD);
        end_time = MPI_Wtime();

        if (rank == 0) {
            double execution_time = end_time - start_time;
            double distance = sqrt(global_sum);

            printf("Run %d: Execution Time = %f sec, Distance = %.2f\n", run, execution_time, distance);

            //totals
            total_execution_time += execution_time;
            total_distance += distance;
        }

        free(local_vector1);
        free(local_vector2);
        if (rank == 0) {
            free(vector1);
            free(vector2);
        }
    }

    if (rank == 0) {
        double average_execution_time = total_execution_time / 10;
        double average_distance = total_distance / 10;
        printf("\nAverage Execution Time = %f seconds\n", average_execution_time);
        printf("Average Distance = %.3f\n", average_distance);
    }

    MPI_Finalize();
    return 0;
}
