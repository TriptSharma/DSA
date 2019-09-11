//Print all nos nos <=n in asc and desc orders
#include<iostream>
using namespace std;
//Find the no. of sub-arrays whose sum is divisible by the size of the array
bool isSorted(int *arr, int n){
    //using Recursion
    //base case
    if(n==1) return true;
    //work toward base case and recusive call
    if(arr[0]<arr[1])
        isSorted(arr+1,n-1);
    else
        return false;
}
void printAscNoob(int n, int i){
    if(i>n) return;
    cout<<i<<" ";
    printAscNoob(n,i+1);
}
void printAsc(int n){
    if(n==0) return;
    printAsc(n-1);
    cout<<n<<" ";
}
void printDesc(int n){
    if(n==0) return;
    cout<<n<<" ";
    printDesc(n-1);
}
int linearSearch(int *arr, int i, int n, int k){
    //print index of key if found else -1;
    if(n==0) return -1;
    if(arr[0]==k) return i;
    return linearSearch(arr+1, i+1, n-1, k);
}
int main(){
    int n1, n2;
    cin>>n1>>n2;
    int arr[n1];
    for(int i=0;i<n1;i++) cin>>arr[i];
    
    cout<<linearSearch(arr, 0, n1, n2);     //let n1=size of arr, n2=key
    
    // cout<<isSorted(arr,n1);
    
    // printAsc(n2);
    // cout<<endl;
    // printDesc(n2);
}
