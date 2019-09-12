//Sorting via recursion
#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    if(n==1) return;
    for(int i=0;i<n-1;i++)
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    bubbleSort(arr, n-1);
}
void bubbleSort2D(int *arr, int j, int n){
    //nested loop also handled by recursion
    if(n==1) return;
    if(j==n-1)
        return bubbleSort2D(arr,0, n-1);    //NOTE: return here acts as break, DON'T FORGET WRITING return
    if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);
    bubbleSort2D(arr, j+1, n);
}

void merge(int *arr, int s, int e){
    int pivot=(s+e)/2;

    //temp variables to traverse the two subarrays
    int i=s;    //start of subarray 1
    int j=pivot+1;    //start of subarray 2
    int k=s;    //start of temp arr
    int temp[100];

    while(i<=pivot && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else
            temp[k++]=arr[j++];
    }
    while(i<=pivot)
        temp[k++]=arr[i++];
    while(j<=e)
        temp[k++]=arr[j++];
    
    //Finally, copy the sorted array back to arr
    for(int i=s;i<=e;i++)
        arr[i]=temp[i];
}
void mergeSort(int *arr, int s, int e){
    if(s>=e) return;
    
    //Find pivot to divide the array into two parts
    int pivot=(s+e)/2;

    //Recursive call on divided arrays
    mergeSort(arr, s, pivot);
    mergeSort(arr, pivot+1, e);

    //merge the the two subarrays
    merge(arr, s, e);
}

int main(){
    int  n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    //bubbleSort(arr, n);

    //bubblwSort2D(arr,0,n)
    
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}