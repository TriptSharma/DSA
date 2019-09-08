#include<iostream>
using namespace std;


int main(){
    int a[]={10,20,30,40};
    int students;
    cin>>students;
    int n = sizeof(a)/sizeof(a[0]);
    int mid, s=INT_MIN, e=0;
    for (int i=0; i<n; i++){
        e+=a[i];
        if(a[i]<s) s=a[i];
    }
    int flag=1;
    int finalans=0;
    while(s<=e){
        mid=(s+e)/2;
        int sum=0, k=1;
        for(int i=0; i<n; i++){
            sum+=a[i];
            if(sum>mid && k<students){
                sum=a[i];
                k++;
            }
            else if(sum>mid && k>=students){
                flag=0;
                sum=0;
                break;
            }
        }
        if(flag==0)
            e=mid-1;
        else{
            s=mid+1;
            finalans=mid;
        }
    }
    return mid;
}