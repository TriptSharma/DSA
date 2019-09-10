#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool isPrime(int n){
    //Time Complexity: O(sqrt(n))
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
vector<int> isPrimeFast(int n){
    //Implement Sieve of Eratosthenes ->TIME COMPLEXITY: O(nlog(logn))
    int arr[n+1]={0};   //Keeps count of visited nodes
    vector<int> v;      //stores prime nos
    if(n<2) return v;
    v.push_back(2);
    //All even nos are composite (except 2); so put them as visited node
    for(int i=2;i<=n;i+=2) arr[i]=1;
    //Translate over odd nos
    for(int i=3;i<=n;i++){
        if(!arr[i]){
            //If the current no. is not visited earlier, then it must be prime
            v.push_back(i);
            for(int j=i*i;(j*i)<=n;j+=2){
                //Multiples of the current prime no should be marked visited
                //NOTE: we optimize our solution by starting from i*i as all the previous multiples must be visited
                arr[i*j]=1;
            }
        }
    }
    return v;
}
int main(){
    int n;
    cin>>n;
    cout<<isPrime(n)<<endl;
    vector<int> prime=isPrimeFast(n);
    for(int i=0;i<prime.size();i++) cout<<prime[i]<<" ";
}