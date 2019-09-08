#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr){
    //divide the array into two parts where the lhs is sorted and rhs is unsorted
    //traverse the array and put the ith element at the apt position in the sorted 
    //part by shifting all the greater elements to right side
    for(int i=1;i<arr.size();i++){
        //store the current elem
        int temp=arr[i], j=i-1;
        while(j>=0 && arr[j]>temp){
            //shift all elements greater than temp to right side
            arr[j+1]=arr[j];
            j--;
        }
        //j=j+1 becoz the while loop ends with j--; so if if j=0 ->j=-1(not possible) ->++j
        arr[++j]=temp;
    }
}
void printSorted(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0); 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    insertionSort(arr);
    printSorted(arr);
}