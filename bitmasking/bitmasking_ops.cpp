#include<iostream>
using namespace std;

//Find number of set bits (number of 1s in a binary number)
int getSetBits(int n){
    //Time Complexity: O(no. of bits)
    int count=0;
    while(n>0){
        count+=n&1;
        n=n>>1;
    }
    return count;
}
int getSetBitsFast(int n){
    //Time Complexity: O(no. of set bits)
    //count no. of iiterations for 'AND' of n, n-1
    int count=0;
    while(n>0){
        n=n&(n-1);
        count++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<getSetBits(n)<<" "<<getSetBitsFast(n);
    return 0;
}