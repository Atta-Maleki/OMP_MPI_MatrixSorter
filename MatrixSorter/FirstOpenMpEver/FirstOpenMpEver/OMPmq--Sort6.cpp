//#include <iostream>
//#include <omp.h>
//#include <vector>
//
//#define SIZE 256
//#define SIZE2 SIZE*SIZE
//#define RANDRANGE 512
//#define THNUM 8
//using namespace std;
//
//// Quicksort function
//void quicksort(vector<int>& arr, int left, int right) {
//	int tid = omp_get_thread_num();
//	//cout <<"doing quick sort by"<< tid << endl;
//	if (left < right) {
//		int pivot = arr[right];
//		int i = left - 1;
//
//		for (int j = left; j <= right - 1; ++j) {
//			if (arr[j] <= pivot) {
//				++i;
//				swap(arr[i], arr[j]);
//			}
//		}
//
//		swap(arr[i + 1], arr[right]);
//
//		int partitionIndex = i + 1;
//
//		quicksort(arr, left, partitionIndex - 1);
//		quicksort(arr, partitionIndex + 1, right);
//	}
//}
//
////Merge function from original merge sort algorithm.
//vector<int> mergeSortedVectors(const vector<int>& vec1, const vector<int>& vec2) {
//	vector<int> merged(vec1.size() + vec2.size());
//	int i = 0, j = 0, k = 0;
//	int tid = omp_get_thread_num();
//	//cout << "merge sort by " << tid << endl;
//
//
//		while (i < vec1.size() && j < vec2.size()) {
//			//cout << "comparing " << i << " with " << j <<" by thread : "<<tid<< endl;
//			if (vec1[i] <= vec2[j]) {
//
//				
//					merged[k] = vec1[i];
//					++i;
//				}
//			
//			else {
//
//					merged[k] = vec2[j];
//					++j;
//				}
//			
//			++k;
//		}
//
//			while (i < vec1.size()) {
//
//					merged[k] = vec1[i];
//					++i;
//					++k;
//				}
//			
//
//			while (j < vec2.size()) {
//
//					merged[k] = vec2[j];
//					++j;
//					++k;
//				}
//			
//		
//
//	return merged;
//}
////merge sort (modified) for sum  vectors instead of elements of an array or sth.
//vector<int> mergeAllVectors(const vector<vector<int>>& vectors) {
//	if (vectors.empty())
//		return vector<int>();
//
//	
//		vector<int> merged = vectors[0];
//	
//#pragma omp parallel for shared(merged)
//		for (int i = 1; i < vectors.size(); ++i) 
//		{
//			cout << "size of vector " << i << " = " << vectors[i].size() << "and size of merged  = " << merged.size() << endl;
//			merged = mergeSortedVectors(merged, vectors[i]);
//		}
//	return merged;
//}
//
//int main() {
//	const int arraySize = SIZE2;
//
//
//	vector<int> mainArray(arraySize);
//	mainArray.reserve(arraySize);
//	for (int i = 0; i < arraySize; ++i) {
//		mainArray[i] = rand() % RANDRANGE;
//	}
//
//
//
//
//	vector<vector<int>> subArrays(THNUM);
//	for (int i = 0; i < THNUM; ++i) {
//		int startIndex = i * (arraySize / THNUM);
//		int endIndex = (i + 1) * (arraySize / THNUM);
//		subArrays[i].assign(mainArray.begin() + startIndex, mainArray.begin() + endIndex);
//	}
//
//
//
//
//#pragma omp parallel num_threads(THNUM)
//	{
//		int threadID = omp_get_thread_num();
//		quicksort(subArrays[threadID], 0, subArrays[threadID].size() - 1);
//	}
//
//
//
//
////printing separate sorted subarrays
//	//for (int i = 0; i < THNUM; ++i) 
//	//{
//	//	cout << "\n\nThread " << i << ": \n\n";
//	//	for (int j = 0; j < subArrays[i].size(); ++j) {
//	//		cout << subArrays[i][j] << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//
//	vector<int> merged = mergeAllVectors(subArrays);
//
////print sorted final array
//	for (int i = 0; i < merged.size(); ++i) 
//	{
//		cout << merged[i] << " ";
//	}
//	cout << std::endl;
//
//	//cout << "Original array:" << endl;
//	//for (int i = 0; i < arraySize; i++) {
//	//cout << arr[i] << " ";
//	//}
//	//cout << endl;
//	//#pragma omp parallel num_threads(8)
//	//	{
//	//		mergeSort(arr, arraySize);
//	//	}
//	//cout << "Sorted array:" << endl;
//	//for (int i = 0; i < 5500; i++) {
//	//	cout << arr[i] << "--";
//	//	cout << arr[SIZE2 - i - 1] << " ";
//	//}
//	//cout << endl;
//	//for (int i = 0; i < arraySize; i++) {
//	//cout << arr[i] << " ";
//	//}
//	//cout << endl;
//
//	system("pause");
//	return 0;
//}
