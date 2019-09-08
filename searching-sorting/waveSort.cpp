#include<bits/stdc++.h>
using namespace std;
void waveSort(vector<int> &arr){
    //sort the arr in wave like fashion -> increase and descreasing in alternate fashion
    //check for alternate elements
    for(int i=0;i<arr.size();i+=2){
        //NOTE: we can also replace the '>' with '<'... 
        //check if previous elem is smaller (provided i>0)
        if(i>0 && arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        //check if next elem is smaller (provided i<n-1)
        if(i<arr.size()-1 && arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
}
void printSorted(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int> arr; 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    waveSort(arr);
    printSorted(arr);
}