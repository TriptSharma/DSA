#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockSpan(int arr[], int size){
    //for each element in the array tell the no. of steps we should move back to obtain a value greater than current value. Naive sol - O(n^2) (O(n) for each element in an arrayof len n)
    stack<int> s;
    vector<int> v;
    for(int i=0;i<size;++i){
        while(!s.empty() && arr[i]>=arr[s.top()]){
            s.pop();
        }
        if(s.empty())
            v.push_back(0);
        else
            v.push_back(i-s.top());
        s.push(i);
    }
    return v;
}
int main(){
    int n=7;
    int arr[100] = {100,80,60,70,60,75,85};
    vector<int> v;
    v = stockSpan(arr, n);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}