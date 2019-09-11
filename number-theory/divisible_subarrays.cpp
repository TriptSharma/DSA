//Find the no. of sub-arrays whose sum is divisible by the size of the array
#include<iostream>
using namespace std;
int getCount(int arr[], int n){
    //uses pigeon hole principle -> TIME COMPLEXITY: O(n)
    //csum=cumulative sum array; cnt=frequency array keeping count of %n

    //NOTE: this can also be done in O(n*n) using cumulative sum only and traversing through the csum array to see of sub-array sum%n==0
    int cnt[n]={0};
    int csum[n], sum=0;
    //cnt[0]=1 init. because the cumulative sum starts from 0 (not included in csum array, therefore manually added in the start)
    cnt[0]++;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        csum[i]=sum;
        cnt[csum[i]%n]++;
    }
    int count=0;
    //Subarray divisible by n IF: (b-a)%n==0 -> b%n=a%n -> Thus, we create a freq. array
    for(int i=0;i<n;i++){
        count+=cnt[i]*(cnt[i]-1)/2;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<getCount(arr,n);
}