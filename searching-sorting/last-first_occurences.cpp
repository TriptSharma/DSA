#include<iostream>
#include<algorithm>
using namespace std;
int getFirstOccurence(int arr[], int n, int k){
    int mid, s=0, e=n-1, ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<k) s=mid+1;
        else e=mid-1;
    }
    return ans;
}
int getLastOccurence(int arr[], int n, int k){
    int mid, s=0, e=n-1, ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==k){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<k) s=mid+1;
        else e=mid-1;
    }
    return ans;
}
int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int firstoccur, lastoccur;
    firstoccur = getFirstOccurence(arr, n, k);
    lastoccur = getLastOccurence(arr, n, k);
    cout<<firstoccur<<" "<<lastoccur;
    return 0;
}