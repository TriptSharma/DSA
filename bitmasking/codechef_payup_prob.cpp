#include<iostream>
#include<vector>
using namespace std;
static int count=0;
void printSeq(vector<int> arr, int n, int k){
    //n=no of subsequence, k=sum required
    vector<int> seq;
    int sum=0, index=0;
    while(n>0 && index<arr.size()){
        if((n&1)==1){
            sum+=arr[index];
            seq.push_back(arr[index]);
        }
        n=n>>1;     //NOTE: Right shift returns a number it doesn't update the value
        index++;
    }
    if(sum==k){
        for(int i=0;i<seq.size();i++) cout<<seq[i]<<" ";
        cout<<endl;
    }
}
void getSeq(vector<int> arr, int k){
    int n=(1<<arr.size())-1;
    for(int i=0;i<=n;i++){
        printSeq(arr, i, k);
    }
}
int main(){
    int n,k;
    cin>>n>>k;  //n=size of arr; k=denomination sum (sum of subsequences)
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    getSeq(arr,k);
    return 0;
}