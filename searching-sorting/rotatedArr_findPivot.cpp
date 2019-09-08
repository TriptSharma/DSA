#include<iostream>
using namespace std;
int findPivot(int arr[], int n){
    int mid, index, s=0, e=n-1;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]>arr[mid+1]) return mid;
        else if (arr[mid]<arr[mid-1]) return mid-1;
        if (arr[mid]<=arr[s]){
            //lhs:unsorted; rhs:sorted
            e=mid-1;
        }
        else s=mid+1;
    }
    return -1;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int index=findPivot(arr,n);
    index==-1?cout<<"Array not rotated":cout<<"Found Pivot at index: "<<index;
    return 0;
}