#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool comparatorDesc(int a, int b){
    return a>b;
}
void stlSort(int *arr, int n, bool compareFunc=false){
    if(compareFunc)
        sort(arr, arr+n, comparatorDesc);
    else
        sort(arr, arr+n);
}
void printSorted(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void printSorted(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void printSorted(string str){
    cout<<str<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //STL sort in ascending order
    stlSort(arr,n);
    cout<<"STL Sort array in ascending order\n";
    printSorted(arr, n);

    //STL sort in descending order
    stlSort(arr,n,true);
    cout<<"STL Sort array in descending order\n";
    printSorted(arr, n);

    //STL sort a vector
        //init vector from the arr;
    vector<int> vec(arr, arr+n);
    sort(vec.begin(), vec.end());
    cout<<"STL Sort vector in ascending order\n";
    printSorted(vec);
    
    //STL sort a string
    string str="yughgads";
    sort(str.begin(), str.end());
    cout<<"STL Sort string in ascending order\n";
    printSorted(str);
    
}