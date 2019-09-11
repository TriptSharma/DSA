//WAP to multily 2 INTEGERS recursively without * operator and convert string to int
#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
int mul(int x, int y){
    if(x<y)
        return mul(y,x);
    //base case
    if(x==0||y==0) 
        return 0;
    //if one is -ve
    if(y<0)     //The condition also handles x<0, y<0 as in the next recursive call x<y -> in next recursive call the negative x would be taken care of
        return -mul(x,-y);
    return x+mul(x,y-1);
}
int str2int(string str,int n){
    if(n==0) return 0;
    string sub=str.substr(1);
    return (str[0]-'0')*pow(10,n-1)+str2int(sub,n-1);
}
int main(){
    int a,b;
    cin>>a>>b;
    //string str="20489";
    cout<<mul(a,b);
}