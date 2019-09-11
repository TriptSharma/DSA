//Binary Search via Recursion
#include<iostream>
using namespace std;
int binSearch(int *arr, int s, int e, int k){
    int mid=(s+e)/2;
    if(arr[mid]==k) return mid;
    else if (arr[mid]<k)
        return binSearch(arr, mid+1, e, k);
    else
        return binSearch(arr, s, mid-1, k);
}
int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<binSearch(arr, 0, n-1, k);
}