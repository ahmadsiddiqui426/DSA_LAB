// C++ program for implement deletion in Heaps
#include <iostream>
using namespace std;

class minHeap{
	int *arr;
	int size;
	int capacity;
	public:
		minHeap(int cap){
			arr = new int[cap];
			capacity = cap;
			size = 0;
		}
		int left(int *arr, int i){
			return arr[2*i + 1];
		}
		int right(int *arr, int i){
			return arr[2*i + 2];
		}
		int parent(int *arr, int i){
			return arr[(i-1) / 2];
		}
		bool isEmpty(){
			if(size == 0)	return 1;
			return 0;
		}
		bool isFull(){
			if(size == capacity)	return 1;
			return 0;
		}
		void heapify(int arr[], int n, int i){
		 int largest = i; 
		 int l = 2 * i + 1; 
		 int r = 2 * i + 2; 
			if (l<n && arr[l] > arr[largest])
				largest = l;
		 	if (r<n && arr[r] > arr[largest])
		  		largest = r;
		 	if (largest != i){
		  		swap(arr[i], arr[largest]);
			heapify(arr, n, largest);
		 	}
		}
		void deleteRoot(int arr[], int& n){
		 	int lastElement = arr[n - 1];
		 	arr[0] = lastElement;
		 	n = n - 1;
		 	heapify(arr, n, 0);
		}
		void heapifyTopDown(int arr[], int n, int i){
		 	int parent = (i - 1) / 2;
		 	if (arr[parent] > 0) {
		 	if (arr[i] > arr[parent]){
		   		swap(arr[i], arr[parent]);
		   		heapifyTopDown(arr, n, parent);
		 	 }
		 	}
		}
		void insertNode(int arr[], int& n, int Key){
			if(size <= capacity){
				n = n + 1;
			 	arr[n - 1] = Key;
			 	heapifyTopDown(arr, n, n - 1);
			 	size++;
			}
		 	else cout<<"Cannot insert\n";
		}
		void printArray(int arr[], int n){
		 	for (int i=0;i<n;i++)
		  		cout << arr[i] << " ";
		 	cout << "\n";
		}
};
//void heapify(int arr[], int n, int i){
// int largest = i; // Initialize largest as root
// int l = 2 * i + 1; // left = 2*i + 1
// int r = 2 * i + 2; // right = 2*i + 2
//	if (l<n && arr[l] > arr[largest])
//		largest = l;
// 	if (r<n && arr[r] > arr[largest])
//  		largest = r;
// 	if (largest != i){
//  		swap(arr[i], arr[largest]);
//	heapify(arr, n, largest);
// 	}
//}
//// Function to delete the root from Heap
//void deleteRoot(int arr[], int& n){
// // Get the last element
// 	int lastElement = arr[n - 1];
// // Replace root with last element
// 	arr[0] = lastElement;
// // Decrease size of heap by 1
// 	n = n - 1;
// // heapify the root node
// 	heapify(arr, n, 0);
//}
//void heapifyTopDown(int arr[], int n, int i){
// // Find parent
// 	int parent = (i - 1) / 2;
// 	if (arr[parent] > 0) {
//  // For Max-Heap
//  // If current node is greater than its parent
//  // Swap both of them and call heapify again
//  // for the parent
// 	if (arr[i] > arr[parent]){
//   		swap(arr[i], arr[parent]);
//   // Recursively heapify the parent node
//   		heapifyTopDown(arr, n, parent);
// 	 }
// 	}
//}
//// Function to insert a new node to the Heap
//void insertNode(int arr[], int& n, int Key){
// // Increase the size of Heap by 1
// 	n = n + 1;
// // Insert the element at end of Heap
// 	arr[n - 1] = Key;
// // Heapify the new node following a
// // Bottom-up approach
// 	heapifyTopDown(arr, n, n - 1);
//}
///* A utility function to print array of size n */
//void printArray(int arr[], int n){
// 	for (int i=0;i<n;i++)
//  		cout << arr[i] << " ";
// 	cout << "\n";
//}
int main(){
 // Array representation of Max-Heap
 //  10
 // / \
 // 5 3
 // / \
 // 2 4
 //int arr[] = {10,5,3,2,4};
	int arr[];
 int n = sizeof(arr) / sizeof(arr[0]);
 	minHeap m(4,7);
 	m.insertNode(arr,n,8);
 	m.deleteRoot(arr, n);
 	m.printArray(arr, n);
 	return 0;
}

