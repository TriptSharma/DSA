#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int k){
    int mid, s=0, e=n-1;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]<k)
            s=mid+1;
        else
            e=mid-1;
    }
    return -1;
}
int main(){
    int n, k;   //n=size of arr; k=element to be searched in the arr
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int pos = binarySearch(arr, n, k);
    (pos!=-1)?cout<<"key found at index: "<<pos:cout<<"key not found";
    return 0;
}