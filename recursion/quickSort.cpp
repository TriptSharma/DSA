#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void quickSort(int *arr, int s, int e){
    if(s>=e) return;
    int pivot = e;    //Denotes the element  that divides the arr into two subarrays;1 greater than pivot elem and other < pvot elem
    int i=s-1;  //Denotes the array containing elements < pivot
    int j=s; //Denotes the index from which we traverse (till pivot elem) to divide array

    //While current index< pivot
    while(j<pivot){
        if(arr[j]<=arr[pivot]){
            //if the current value is < pivot val then swap it with the leftmost val > pivot
            //Thus, divide the list into two subarrays as discussed
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    //bring thepivot element to its sorted position
    swap(arr[i+1],arr[pivot]);

    //recusive call
    quickSort(arr, s, i-1);
    quickSort(arr, i+1, e);
}
void shuffle(int *arr, int s, int e){
    //Worst case of QuickSort is when the array is sorted -> O(n^2)
    //Avg Time complexity: O(nlog(n))
    //Therefore, we randomize every array to bring time complexity to avg case
    srand(time(NULL));
    for(int i=e;i>=s;i--){
        int x = rand()%(i+1);
        swap(arr[i], arr[x]);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];    
    }
    shuffle(arr, 0, n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}