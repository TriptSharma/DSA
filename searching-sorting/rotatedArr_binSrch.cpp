#include<iostream>
using namespace std;
int searchRotatedArr(int arr[],int n,int k){
    int mid, s=0, e=n-1;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==k) return mid;
        if(arr[mid]<arr[s]){
            //right side sorted
            if(k<arr[e]) s=mid+1;
            else e=mid-1;
        }
        else{
            //left side sorted
            if(k<arr[mid]) e=mid-1;
            else s=mid+1;
        }
    }
    return -1;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=searchRotatedArr(arr,n,k);
    ans==-1?cout<<"Not found"\n:cout<<"Found at index: "<<ans<<endl;
    return 0;
}