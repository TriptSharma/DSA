#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    //compare adjacent elements and bubble out the larger one
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
void printSorted(int *arr, int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
int main(){
    int n; //no. of elements in the array
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    bubbleSort(arr,n);
    printSorted(arr,n);
    return 0;
}