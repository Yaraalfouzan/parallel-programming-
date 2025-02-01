# This project explores the effectiveness of parallelization in computing the Euclidean distance between high-dimensional vectors. Three implementations were analyzed:

Sequential Algorithm - Traditional single-threaded computation.
OpenMP Parallelization - Shared-memory parallel processing.
MPI Parallelization - Distributed-memory parallel processing.
Key Findings
Parallelization significantly reduces computation time, making it more efficient for large-scale data analysis.
MPI outperforms OpenMP in scalability, showing a more consistent decrease in execution time as the number of processors increases.
OpenMP exhibits diminishing returns with higher processor counts, likely due to parallelization overhead.
MPI is more suitable for highly parallel workloads, thanks to its efficient memory distribution and communication management.
