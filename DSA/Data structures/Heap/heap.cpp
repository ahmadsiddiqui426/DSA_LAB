#include <iostream>
using namespace std;

//void maxheap(int *a, int size){
//	int i =n/2;
//	for(; i>=1; i++){
//		heapify(a, i, n);
//	}
//}
//void heapify(int *a , int i, int n){
//	int j = 2*i, temp = a[i];
//	while(j<=n){
//		if(j<n && a[j+1] > a[j])
//			j++;
//		if(temp > a[j])	break;
//		else{
//			a[j/2] = j;
//			j = 2*j;
//		}
//	}
//	a[j/2] = temp;
//	return;
//}
void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = *b;
}
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
			int largest = i; // Initialize largest as root
			int l = 2 * i + 1; // left = 2*i + 1
			int r = 2 * i + 2; // right = 2*i + 2
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
		 	size--;
		}
		void insertNode(int arr[], int& n, int Key){
		 	n = n + 1;
		 	arr[n - 1] = Key;
		 	heapifyTopDown(arr, n, n - 1);
		 	size++;
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
		void printArray(int arr[], int n){
		 	for (int i=0;i<n;i++)
		  		cout << arr[i] << " ";
		 	cout << "\n";
		}
};
int main(){
	int a[] = {1,2,3,4};
	minHeap m(4);
	//cout<<m.parent(a,3);
//	m.heapify(a, 4, 0);
//	for(int i=0;i<4;i++){
//		cout<<a[i]<<' ';
//	}
	int n = 5;
//	m.insertNode(a, n, 1);
//	m.insertNode(a, n, 2);
//	m.insertNode(a, n, 3);
//	m.insertNode(a, n, 4);
	m.insertNode(a, n, 8);
	m.printArray(a, 5);
}