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
    int a[n], b[n];

    // Seed for random number generation
    srand(time(0));

    // Start timer for sequential 
    clock_t start = clock();
    
    // Generate random values for both vectors
    for (int i = 0; i < n; i++) {
        a[i] = rand() %1000;
        b[i] = rand() %1000;
    }

    // Calculate Euclidean distance
    double distance = calculate_euclidean_distance(a, b, n);

    // End timer for sequential
    clock_t end = clock();

    // Calculate the time in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print vectors and distance
    printf("Vector a: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Vector b: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("Euclidean Distance: %.2f\n", distance);
    printf("Time taken: %.5f seconds\n", time_taken);



    return 0;
}