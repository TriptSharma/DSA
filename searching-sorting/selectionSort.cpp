#include<iostream>
using namespace std;
int *selectionSort(int arr[], int n){
    //tranverse the list -> find the min ->swap it ith element in ith position
    for(int i=0;i<n-1;i++){
        int min=arr[i], minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
    return arr;
}
void printSorted(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n; //input no. of elements
    int arr[n], *sorted;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sorted = selectionSort(arr,n);
    printSorted(sorted,n);
    return 0;
}