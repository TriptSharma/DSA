#include<iostream>
#include<limits>
int count[INT_MAX] = {0};

void countSort(int arr[]){
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++) count[i]++;
}

void printSorted(){
    for(int i=0; i<INT_MAX; i++){
        while(count[i]--)
            std::cout<<i<<" ";
    }
}

int main(){
    int n;
    std::cin>>n;
    int arr[5];
    for(int i=0; i<5; i++) std::cin>>arr[i];
    return 0;
}