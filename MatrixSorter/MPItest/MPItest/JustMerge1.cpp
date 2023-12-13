//#include <iostream>
//#include <mpi.h>
//
//#define SIZE 4096
//#define SIZE2 SIZE * SIZE
//#define RANDRANGE 8192
//#define THNUM 8
//#define SUBSIZE SIZE2 / THNUM
//
//using namespace std;
//
//void merge(int arr[], int left[], int right[], int leftSize, int rightSize)
//{
//	int i = 0, j = 0, k = 0;
//
//	while (i < leftSize && j < rightSize)
//	{
//		if (left[i] <= right[j])
//		{
//			arr[k] = left[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = right[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i < leftSize)
//	{
//		arr[k] = left[i];
//		i++;
//		k++;
//	}
//
//	while (j < rightSize)
//	{
//		arr[k] = right[j];
//		j++;
//		k++;
//	}
//}
//
//void mergeSort(int arr[], int size)
//{
//	if (size < 2)
//	{
//		return;
//	}
//
//	int mid = size / 2;
//	int* left = new int[mid];
//	int* right = new int[size - mid];
//
//	for (int i = 0; i < mid; i++)
//	{
//		left[i] = arr[i];
//	}
//	mergeSort(left, mid);
//
//	for (int i = mid; i < size; i++)
//	{
//		right[i - mid] = arr[i];
//	}
//	mergeSort(right, size - mid);
//
//	merge(arr, left, right, mid, size - mid);
//
//	delete[] left;
//	delete[] right;
//}
//
//int main(int argc, char** argv)
//{
//	int numProcesses, rank;
//	const int arraySize = SIZE2;
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	int* arr = new int[arraySize];
//
//	// Initialize the array with random values
//	srand(rank);
//	for (int i = 0; i < arraySize; i++)
//	{
//		arr[i] = rand() % RANDRANGE;
//	}
//
//	// Calculate the size of each subarray
//	int subSize = arraySize / numProcesses;
//
//	// Scatter the subarrays to each process
//	int* subArr = new int[subSize];
//	MPI_Scatter(arr, subSize, MPI_INT, subArr, subSize, MPI_INT, 0, MPI_COMM_WORLD);
//
//	// Perform the merge sort on each subarray
//	mergeSort(subArr, subSize);
//
//	// Gather the sorted subarrays back to the root process
//	MPI_Gather(subArr, subSize, MPI_INT, arr, subSize, MPI_INT, 0, MPI_COMM_WORLD);
//
//	// Root process merges the sorted subarrays
//	if (rank == 0)
//	{
//		int* tempArr = new int[arraySize];
//		merge(tempArr, arr, arr + subSize, subSize, subSize);
//
//		for (int i = 2; i < numProcesses; i++)
//		{
//			merge(tempArr, tempArr, arr + (i * subSize), i * subSize, subSize);
//		}
//
//		// Print the sorted array
//		cout << "Sorted array:" << endl;
//		for (int i = 0; i < 5500; i++)
//		{
//			cout << tempArr[i] << "--";
//			cout << tempArr[SIZE2 - i - 1] << " ";
//		}
//		cout << endl;
//
//		delete[] tempArr;
//	}
//
//	delete[] arr;
//	delete[] subArr;
//
//	MPI_Finalize();
//
//	return 0;
//}
