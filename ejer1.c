#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);

    int size, rank;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0){
        printf("Rank %d comunicador\n", rank);
    } else {
        printf("Rank %d con size %d\n", rank, size);
    }
    MPI_Finalize();

    return 0;
}