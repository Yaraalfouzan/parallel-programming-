 This project explores the effectiveness of parallelization in computing the Euclidean distance between high-dimensional vectors. 
 Three implementations were analyzed:
1-Sequential Algorithm - Traditional single-threaded computation.
2-OpenMP Parallelization - Shared-memory parallel processing.
3-MPI Parallelization - Distributed-memory parallel processing.
# Key Findings:
1-Parallelization significantly reduces computation time, making it more efficient for large-scale data analysis.
2-MPI outperforms OpenMP in scalability, showing a more consistent decrease in execution time as the number of processors increases.
3-OpenMP exhibits diminishing returns with higher processor counts, likely due to parallelization overhead.
4-MPI is more suitable for highly parallel workloads, thanks to its efficient memory distribution and communication management.
