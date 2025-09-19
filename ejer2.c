#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    // fase 1 atnes de la barrera
    printf("Proceso %d: INICIANDO primera etapa\n", rank);
    
    // tarea con sleep
    sleep(rank + 1);
    printf("Proceso %d: TERMINO primera etapa (trabajo de %d segundos)\n", rank, rank + 1);
    
    // barrera
    MPI_Barrier(MPI_COMM_WORLD);
    
    // segundafase 2, luego de la barrera
    printf("Proceso %d: INICIANDO segunda etapa - TODOS sincronizados\n", rank);
    
    // Trabajo después de la barrera
    sleep(1);
    printf("Proceso %d: COMPLETO todo el trabajo\n", rank);
    
    MPI_Finalize();
    return 0;
}