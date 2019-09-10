#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int n, m;
    cin>>n>>m;
    cout<<"HCF: "<<gcd(n,m)<<endl<<"LCM: "<<lcm(n,m);
}