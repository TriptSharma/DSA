#include<iostream>
using namespace std;
float findSqrt(int n, int p){
    //n=no; p=decimal place for precision
    int mid, s=0, e=n-1;
    float ans=0;
    while(s<=e){
        mid=(s+e)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        else if(mid*mid>n) e=mid-1;
        else{
            ans=mid;
            s=mid+1;
        }
    }
    float precision=0.1;
    while(p--){
        float i;
        for(i=precision; i<precision*10; i+=precision){
            if((ans+i)*(ans+i)>n) 
                break;
        }
        ans+=(i-precision);
        precision/=10;
    }
    return ans;
}
int main(){
    int n, p; float sqrt;
    cin>>n>>p;
    sqrt = findSqrt(n, p);
    cout<<sqrt;
    return 0;
}