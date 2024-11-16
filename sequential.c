#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calculate_euclidean_distance(int *a, int *b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

int main(int argc, char *argv[]) {
    //when user doesnt enter exactly one vector length
    if (argc != 2) {
        printf("%s enter exactly one vector length \n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    //when n isnt positive
    if (n <= 0) {
        printf("Vector length should be a positive integer.\n");
        return 1;
    }
    
     // Allocate memory for the vectors
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (a == NULL || b == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Seed for random number generation
    srand(time(0));

    
    // Generate random values for both vectors
    for (int i = 0; i < n; i++) {
        a[i] = rand() %1000;
        b[i] = rand() %1000;
    }

    int num_runs=10;
     for (int i = 0; i < num_runs; i++) {
    // Start timer for sequential 
    clock_t start = clock();
    
    // Calculate Euclidean distance
    double distance = calculate_euclidean_distance(a, b, n);

    // End timer for sequential
    clock_t end = clock();

    // Calculate the time in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
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
