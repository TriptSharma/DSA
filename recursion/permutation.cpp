#include<iostream>
using namespace std;
void permutation(string s, string out, int i){
    //base case
    if(s[i]=='\0'){
        out+='\0';
        cout<<out;
        return;
    }
    //recursive call in loop because at each index there are be 3 possible permutations
    for(int j=i;j<s.size();j++){
        //i represents the current index of permutation
        //swap ith element to bring the jth candidate element for the permutation
        swap(s[i],s[j]);
        permutation(s,out+s[i],i+1);
    }
}
int main(){
    string s;
    cin>>s;
    permutation(s, "", 0);
}