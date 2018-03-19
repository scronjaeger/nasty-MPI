#include <nasty_mpi.h>
#include <stdbool.h>


#define _map_put_get_attrs(x) \
  (x).origin_addr = origin_addr; \
  (x).origin_count  = origin_count; \
  (x).origin_datatype = origin_datatype; \
  (x).target_disp = target_disp; \
  (x).target_count = target_count; \
  (x).target_datatype = target_datatype;

int MPI_Init(int *argc, char ***argv)
{
  int result = PMPI_Init(argc, argv);

  if (result == MPI_SUCCESS) {
    //nasty_mpi_init(argc, argv);
    //TODO create shared memory with getpid() offset
  }

  return result;
}

int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                     MPI_Comm comm, void *baseptr, MPI_Win *win)
{
  int result = PMPI_Win_allocate(size, disp_unit, info, comm, baseptr, win);

  if (result == MPI_SUCCESS)
  {
    //nasty_win_init(*win, comm, disp_unit);
    //TODO Check if problem, or if it can be left out
  }

  return result;
}

int MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                   MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
  int result = PMPI_Win_create(base, size, disp_unit, info, comm, win);

  if (result == MPI_SUCCESS)
  {
    //nasty_win_init(*win, comm, disp_unit);
    //TODO Check if problem, or if it can be left out
  }

  return result;

}

int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
  int result = PMPI_Win_create_dynamic(info, comm, win);

  if (result == MPI_SUCCESS)
  {
    //nasty_win_init(*win, comm, sizeof(char));
    //TODO Check if problem, or if it can be left out
  }

  return result;
}

int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                                 void *baseptr, MPI_Win *win)
{
  int result = PMPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win);

  if (result == MPI_SUCCESS)
  {
    //nasty_win_init(*win, comm, disp_unit);
    //TODO Check if problem, or if it can be left out
  }

  return result;
}

int MPI_Win_lock_all(int assert, MPI_Win win)
{
  int rc = PMPI_Win_lock_all(assert, win);

  if (rc == MPI_SUCCESS) //nasty_win_lock(win);
{
	//TODO there shouldn't be anything to be done here, everything should be done in unlock
}
  

  return rc;
}

int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win)
{
  int rc = PMPI_Win_lock(lock_type, rank, assert, win);

  if (rc == MPI_SUCCESS) //nasty_win_lock(win);
{
	//TODO there shouldn't be anything to be done here, everything should be done in unlock
{
  return rc;
}

int MPI_Put(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
            int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype,
            MPI_Win win)
{
	//TODO push PUT, origin_addr, origin_count and datatype in shared memory dArray
    return PMPI_Put(origin_addr, origin_count, origin_datatype,
                    target_rank, target_disp, target_count, target_datatype,
                    win);
}

int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
            int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype,
            MPI_Win win)
{
	//TODO push GET, origin_addr, origin_count and datatype in shared memory dArray
    return PMPI_Get(origin_addr, origin_count, origin_datatype,
                    target_rank, target_disp, target_count, target_datatype,
                    win);


}

int MPI_Win_flush(int rank, MPI_Win win)
{
	//TODO Do the same as in unlock
  return PMPI_Win_flush(rank, win);
}

int MPI_Win_flush_all(MPI_Win win)
{
	//TODO Do the same as in unlock
  return PMPI_Win_flush_all(win);
}

int MPI_Win_flush_local(int rank, MPI_Win win)
{
	//TODO Do the same as in unlock
  return PMPI_Win_flush_local(rank, win);
}

int MPI_Win_flush_local_all(MPI_Win win)
{
	//TODO Do the same as in unlock
  return PMPI_Win_flush_local_all(win);
}

int MPI_Win_unlock_all(MPI_Win win)
{
	//TODO Do the same as in unlock
  return PMPI_Win_unlock_all(win);
}

int MPI_Win_unlock(int rank, MPI_Win win)
{
	//TODO Perform collision tests between gets and puts, then native ops and gets and puts
	//Free all dArrays
  //do real unock
  return PMPI_Win_unlock(rank, win);
}

int MPI_Finalize(void)
{
  //TODO Free/detach all shared memories
  return PMPI_Finalize();
}
