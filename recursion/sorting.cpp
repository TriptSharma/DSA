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
int main(){
    int  n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    //bubbleSort(arr, n);
    bubbleSort2D(arr,0,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
