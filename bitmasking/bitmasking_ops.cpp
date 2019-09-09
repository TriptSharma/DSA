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
int getIthBit(int n, int i){
    //1 0 1 get bit at index 2 (from rhs)
    //NOTE: (n&(1<<i))==1 wont work bcoz the int value will oly be equal if (0th bit of n)==1 {as the returned value is translated to int}
    return (n&(1<<i))!=0 ? 1:0;
}
int setIthBit(int n, int i){
    //set ith bit to 1
    return n|(1<<i);
}
int setIthBit0(int n, int i){
    int mask=1<<i;
    mask=~mask;
    return n&mask;
}
bool isEven(int n){
    return (n&1)==1?0:1; //if 0th bit is a setbit then no is odd else even
}
void XORswap(int a, int b){
    //NOTE: This is a call by value function. For call by reference we need to allocate the const values a variable [to refer it via pointers]
    a=a^b;
    b=b^a;  //Same as a^b : XOR holds commutative property (as well as associative property)
    a=a^b;
    cout<<a<<" "<<b;
}
int main(){
    int n, i;
    cin>>n>>i;
    //cout<<getSetBits(n)<<" "<<getSetBitsFast(n);
    cout<<setIthBit0(n, i)<<endl;
    XORswap(n, n+1);
    return 0;
}