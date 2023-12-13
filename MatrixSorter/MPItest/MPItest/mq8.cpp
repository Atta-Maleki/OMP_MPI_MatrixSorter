//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <mpi.h>
//using namespace std;
///*****************************------------Swap func for quick sort---------------*******************************/
//void swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
///*****************************------------Partition func for quick sort---------------**************************/
//int partition(int* arr, int low, int high) {
//	int pivot = arr[high];
//	int i = (low - 1);
//
//	for (int j = low; j <= high - 1; j++) {
//		if (arr[j] < pivot) {
//			i++;
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}
//
///*****************************--------------------------QUICK SORT  ---------------------*********************/
//void quickSort(int* arr, int low, int high) {
//	if (low < high) {
//		int pivot = partition(arr, low, high);
//		quickSort(arr, low, pivot - 1);
//		quickSort(arr, pivot + 1, high);
//	}
//}
//
///*****************************------------MAIN FUNCTION---------------*******************************/
//int main(int argc, char** argv) {
//	int size, rank;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	const int SIZE = 252;
//	const int SIZE2 = SIZE * SIZE;
//	const int RANDRANGE = 1000;
//	const int THNUM = 8;
//	const int SUBSIZE = SIZE2 / THNUM;
//
//	int* mainArray = new int[SIZE2];
//
//
//	if (rank == 0) {
//		srand(static_cast<unsigned int>(time(nullptr)));
//		for (int i = 0; i < SIZE2; i++) {
//			mainArray[i] = rand() % RANDRANGE;
//		}
//		cout << endl;
//	}
//	int *subArray0 = NULL;
//	int *subArray1 = NULL;
//	int *subArray2 = NULL;
//	int *subArray3 = NULL;
//	int *subArray4 = NULL;
//	int *subArray5 = NULL;
//	int *subArray6 = NULL;
//	int *subArray7 = NULL;
//	int *subArray01 = NULL;
//	int *subArray23 = NULL;
//	int *subArray45 = NULL;
//	int *subArray67 = NULL;
//	int *subArray4567 = NULL;
//	int *subArray0123 = NULL;
//	if (rank == 0)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray0);
//		MPI_Alloc_mem(SUBSIZE * 2 * sizeof(int), MPI_INFO_NULL, &subArray01);
//		MPI_Alloc_mem(SUBSIZE* 4 * sizeof(int), MPI_INFO_NULL, &subArray0123);
//		//int* subArray0 = new int[SUBSIZE];
//		for (int i = 1; i < 8; i++)
//		{
//			MPI_Send(&mainArray[i*SUBSIZE], SUBSIZE, MPI_INT, i, 0, MPI_COMM_WORLD);
//		}
//		
//	}//end of if rank ==0 #1
//	MPI_Barrier(MPI_COMM_WORLD);
//	cout << "Barrier number 1 passed" << endl;
//
//	/*
//	**********************************************************************************************
//	**********************************************************************************************
//	**********************************      BARRIER   1     **************************************
//	**********************************************************************************************
//	************************************************************************************************/
//	if (rank == 0) {
//		//int* subArray01 = new int[SUBSIZE * 2];
//		for (int i = 0; i < SUBSIZE;i++)
//		{
//			subArray0[i] = mainArray[i];
//		}
//		quickSort(subArray0, 0, SUBSIZE - 1);
//		cout << "rank " << rank << "done after barrier1" << endl;
//	}//end of if rank ==0
//	if (rank == 1)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray1);
//		//int* subArray1 = new int[SUBSIZE];
//		MPI_Recv(subArray1, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray1, 0, SUBSIZE - 1);
//		MPI_Send(subArray1, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
//		cout << "rank " << rank << "done after barrier1" << endl;
//	}
//	if (rank == 2)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray2);
//		MPI_Alloc_mem(SUBSIZE * 2 * sizeof(int), MPI_INFO_NULL, &subArray23);
//		//int* subArray2 = new int[SUBSIZE];
//		MPI_Recv(subArray2, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray2, 0, SUBSIZE - 1);
//		cout << "rank " << rank << "done after barrier1" << endl;
//	}//end of if rank ==2
//	
//	if (rank == 3)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray3);
//		//int* subArray3 = new int[SUBSIZE];
//		MPI_Recv(subArray3, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray3, 0, SUBSIZE - 1);
//		MPI_Send(subArray3, SUBSIZE, MPI_INT, 2, 0, MPI_COMM_WORLD);
//		cout << "rank " << rank << "done after barrier1" << endl;
//	}
//	if (rank == 4)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray4);
//		MPI_Alloc_mem(SUBSIZE * 2 * sizeof(int), MPI_INFO_NULL, &subArray45);
//		MPI_Alloc_mem(SUBSIZE * 4 * sizeof(int), MPI_INFO_NULL, &subArray4567);
//		//int* subArray4 = new int[SUBSIZE];
//		MPI_Recv(subArray4, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray4, 0, SUBSIZE - 1);
//		cout << "rank " << rank << "done after barrier1" << endl;
//		//int* subArray45 = new int[SUBSIZE * 2];
//	}//end of if rank ==4
//	
//	if (rank == 5)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray5);
//		//int* subArray5 = new int[SUBSIZE];
//		MPI_Recv(subArray5, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray5, 0, SUBSIZE - 1);
//		MPI_Send(subArray5, SUBSIZE, MPI_INT, 4, 0, MPI_COMM_WORLD);
//		cout << "rank " << rank << "done after barrier1" << endl;
//	}
//	if (rank == 6)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray6);
//		MPI_Alloc_mem(SUBSIZE * 2 * sizeof(int), MPI_INFO_NULL, &subArray67);
//		//int* subArray6 = new int[SUBSIZE];
//		MPI_Recv(subArray6, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray6, 0, SUBSIZE - 1);
//		cout << "rank " << rank << "done after barrier1" << endl;
//		//int* subArray67 = new int[SUBSIZE * 2];
//	}//end of if rank ==6
//
//	if (rank == 7)
//	{
//		MPI_Alloc_mem(SUBSIZE * sizeof(int), MPI_INFO_NULL, &subArray7);
//		//int* subArray7 = new int[SUBSIZE];
//		MPI_Recv(subArray7, SUBSIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray7, 0, SUBSIZE - 1);
//		MPI_Send(subArray7, SUBSIZE, MPI_INT, 6, 0, MPI_COMM_WORLD);
//		cout << "rank " << rank << "done after barrier1" << endl;
//	}
//	MPI_Barrier(MPI_COMM_WORLD);
//	cout << "Barrier number 2 passed" << endl;
//
//	/*
//	**********************************************************************************************
//	**********************************************************************************************
//	**********************************      BARRIER   2     **************************************
//	**********************************************************************************************
//	************************************************************************************************/
//
//
//	if (rank == 0)
//	{
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray01[i] = subArray0[i];
//		}
//		MPI_Recv(&subArray01[SUBSIZE], SUBSIZE, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray01, 0, (SUBSIZE * 2) - 1);
//		cout << "rank " << rank << "done after barrier2" << endl;
//	}//end of if rank==0
//	
//	if (rank == 2)
//	{
//		//int* subArray23 = new int[SUBSIZE * 2];
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray23[i] = subArray2[i];
//		}
//		MPI_Recv(&subArray23[SUBSIZE], SUBSIZE, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray23, 0, (SUBSIZE * 2) - 1);
//		MPI_Send(subArray23, SUBSIZE * 2, MPI_INT, 0, 0, MPI_COMM_WORLD);
//		cout << "rank " << rank << "done after barrier2" << endl;
//	}
//	if (rank == 4)
//	{
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray45[i] = subArray4[i];
//		}
//		MPI_Recv(&subArray45[SUBSIZE], SUBSIZE, MPI_INT, 5, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray45, 0, (SUBSIZE * 2) - 1);
//		cout << "rank " << rank << "done after barrier2" << endl;
//		//int* subArray4567 = new int[SUBSIZE * 4];
//	}//end of if rank ==4
//	
//	if (rank == 6)
//	{
//		for (int i = 0; i < SUBSIZE; i++)
//		{
//			subArray67[i] = subArray6[i];
//		}
//		cout << "transfer from 6 to 67 done" << endl;
//		MPI_Recv(&subArray67[SUBSIZE], SUBSIZE, MPI_INT, 7, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		cout << "recieve from 7 to 67 done" << endl;
//		quickSort(subArray67, 0, (SUBSIZE * 2) - 1);
//		cout << "sorting of 67 done" << endl;
//		MPI_Send(subArray67, SUBSIZE * 2, MPI_INT, 4, 0, MPI_COMM_WORLD);
//		cout << "sending of 67 done" << endl;
//		cout << "rank " << rank << "done after barrier2" << endl;
//	}
//	MPI_Barrier(MPI_COMM_WORLD);
//	cout << "Barrier number 3 passed" << endl;
//
//
//	/*
//	**********************************************************************************************
//	**********************************************************************************************
//	**********************************      BARRIER   3     **************************************
//	**********************************************************************************************
//	************************************************************************************************/
//
//
//	if (rank == 0)
//	{
//		//int* subArray0123 = new int[SUBSIZE * 4];
//		for (int i = 0; i < SUBSIZE * 2;i++)
//		{
//			subArray0123[i] = subArray01[i];
//		}
//		MPI_Recv(&subArray0123[SUBSIZE * 2], SUBSIZE * 2, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		quickSort(subArray0123, 0, (SUBSIZE * 4) - 1);
//		cout << "rank " << rank << "done  after barrier3" << endl;
//	}//end of if rank ==0
//
//	if (rank == 4)
//	{
//		for (int i = 0; i < SUBSIZE * 2;i++)
//		{
//			subArray4567[i] = subArray45[i];
//		}
//		cout << "45 to 4567 done" << endl;
//		MPI_Recv(&subArray4567[SUBSIZE * 2], SUBSIZE * 2, MPI_INT, 6, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		cout << "rcv from 6 done" << endl;
//		quickSort(subArray4567, 0, (SUBSIZE * 4) - 1);
//		cout << "qsort done" << endl;
//		
//		MPI_Send(subArray4567, SUBSIZE * 4, MPI_INT, 0, 0, MPI_COMM_WORLD);
//		
//		cout << "send 4567 to 0 done" << endl;
//		cout << "rank " << rank << "done  after barrier3" << endl;
//	}
//	MPI_Barrier(MPI_COMM_WORLD);
//	cout << "Barrier number 4 passed" << endl;
//
//
//	/*
//	**********************************************************************************************
//	**********************************************************************************************
//	**********************************      BARRIER   4     **************************************
//	**********************************************************************************************
//	************************************************************************************************/
//
//
//	if (rank == 0)
//	{
//		cout << "we're inside the rank 0" << endl;
//		for (int i = 0; i < SIZE2 / 2; i++)
//		{
//			mainArray[i] = subArray0123[i];
//		}
//		cout << "from 0123 to main done" << endl;
//		MPI_Recv(&mainArray[SUBSIZE * 4], SUBSIZE * 4, MPI_INT, 4, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		cout << "recieve from rank 4 (4567) to mainArray to rank 0 is done" << endl;
//		quickSort(mainArray, 0, SIZE2);
//		cout << "sorting of main array done " << endl;
//		cout << "rank " << rank << "done  after barrier4" << endl;
//	}
//	MPI_Barrier(MPI_COMM_WORLD);
//	cout << "Barrier number 5 passed" << endl;
//
//	/*
//	**********************************************************************************************
//	**********************************************************************************************
//	**********************************      BARRIER   5     **************************************
//	**********************************************************************************************
//	************************************************************************************************/
//
//
//	MPI_Free_mem(subArray0);
//	MPI_Free_mem(subArray1);
//	MPI_Free_mem(subArray2);
//	MPI_Free_mem(subArray3);
//	MPI_Free_mem(subArray4);
//	MPI_Free_mem(subArray5);
//	MPI_Free_mem(subArray6);
//	MPI_Free_mem(subArray7);
//	MPI_Free_mem(subArray01);
//	MPI_Free_mem(subArray23);
//	MPI_Free_mem(subArray45);
//	MPI_Free_mem(subArray67);
//	MPI_Free_mem(subArray0123);
//	MPI_Free_mem(subArray4567);
//	///////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////
//	///////////////////////////////////////////////////////////////////////////////////
//	//cout << "everything is ok.";
//	if (rank == 0) {
//		for (int i = 0; i < SIZE2;i++)
//		{
//			cout << mainArray[i] << " ";
//		}
//	}
//	
//	MPI_Finalize();
//	return 0;
//}