#include <iostream> 
using namespace std; 

void buildMaxHeap(int arr[], int n) { 
	for (int i = 1; i < n; i++) { 
		if (arr[i] > arr[(i - 1) / 2]) { 
			int j = i; 
			while (arr[j] > arr[(j - 1) / 2]) { 
				swap(arr[j], arr[(j - 1) / 2]); 
				j = (j - 1) / 2; 
			} 
		} 
	} 
} 
void heapSort(int arr[], int n){ 
	buildMaxHeap(arr, n); 
	for (int i = n - 1; i > 0; i--){ 
		swap(arr[0], arr[i]); 
		int j = 0, index; 
		do{ 
			index = (2 * j + 1); 
			if (arr[index] < arr[index + 1] && index < (i - 1)) 
				index++; 

			if (arr[j] < arr[index] && index < i) 
				swap(arr[j], arr[index]); 
		
			j = index; 
		
		} while (index < i); 
	} 
} 
int main(){ 
	int n ;
	int arr[n];
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the elements of the array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Given array: "; 
	for (int i = 0; i < n; i++) 
		cout<<arr[i]<<" "; 	
	cout<<endl;
	heapSort(arr, n); 
	cout<<"Sorted array: "; 
	for (int i = 0; i < n; i++) 
		cout<< arr[i]<<" "; 

	return 0; 
} 
