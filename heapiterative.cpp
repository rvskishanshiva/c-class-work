#include<iostream>
using namespace std;

void maxheap(int arr[],int n){
    for(int i=1;i<n;i++){
        int item=arr[i];
        int key=i;
        int parent=(i-1)/2;
        while(key>0 && item>arr[parent]){
            arr[key]=arr[parent];
            key=parent;
            parent=i/2-1;
        }
        arr[key]=item;
    }

}
void heapsort(int arr[], int n){
    maxheap(arr,n);
    int i=n-1;
    while(i>=0){
        swap(arr[0],arr[i]);
        i--;
        maxheap(arr,i+1);
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    heapsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}