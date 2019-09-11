//WAP to print the digits of an int in words using RECURSION (concept)
#include<iostream>
#include<vector>
using namespace std;
void printWord(int n, vector<string> v){
    if(n==0) return;
    printWord(n/10, v);
    cout<<v[n%10]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<string> num {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    printWord(n, num);
    return 0;
}