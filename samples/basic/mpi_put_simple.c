#include <mpi.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define COUNT 2
#define MEM_RANK 1
enum {disp_guard = 0, disp_payload = 1};
int main(int argc, char** argv)
{
  int myrank/*, nprocs*/;
  MPI_Win win;
  int *baseptr;
  MPI_Aint local_size;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  
  local_size = (myrank == MEM_RANK) ? COUNT : 0;

  MPI_Win_allocate(local_size * sizeof(int), sizeof(int), MPI_INFO_NULL, MPI_COMM_WORLD, &baseptr, &win);

  MPI_Win_lock_all(0, win);

  if (myrank == 0) {
    int payload = 42;
    int flag = 1;

    MPI_Put( &payload, 1, MPI_INT, MEM_RANK, disp_payload, 1, MPI_INT, win);
    MPI_Put( &flag, 1, MPI_INT, MEM_RANK, disp_guard, 1, MPI_INT, win);

  } 

  MPI_Win_unlock_all(win);

  MPI_Barrier(MPI_COMM_WORLD);

  if (myrank == MEM_RANK) {
    assert(baseptr[disp_guard] == 1);
    assert(baseptr[disp_payload] == 42);
  }

  MPI_Win_free(&win);
  MPI_Finalize();
  return EXIT_SUCCESS;
}

