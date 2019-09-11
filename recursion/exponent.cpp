//exponent via recursion
#include<iostream>
using namespace std;
int power(int n,  int p){
    if(p==0)
        return 1;
    return n*power(n,p-1);
}
int fastPower(int n, int p){
    //Time Complexity: O(log(n))
    if(p==0) return 1;
    int ans = fastPower(n,p/2);
    if(n&1)
        return ans*ans*n;
    else
        return ans*ans;
}
int main(){
    int n, pow;
    cin>>n>>pow;
    cout<<power(n,pow)<<endl<<fastPower(n,pow);
    return 0;
}