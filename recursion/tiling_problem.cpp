// WAP to find the no. of ways in which a wall of dimension 4xN can be tiled using bricks of size 4x1. Tiles can be placed in either horizontal or vertical fashion
#include<iostream>
using namespace std;
int getWays(int n){
    //Wall dimension: 4xN
    if(n==4)
        return 2; //1 horizontal, 1 vertical
    else if (n<4) 
        return 1;
    return getWays(n-1)+getWays(n-4);
}
int main(){
    int n;
    cin>>n;
    cout<<getWays(n);
}