#include<iostream>
#include<vector>
using namespace std;
string filterSeq(string str,int n){
    string seq="";
    int index=0;
    while(n>0 && index<str.length()){
        if(n&1==1) seq+=str[index];
        n=n>>1;
        index++;
    }
    //cout<<seq<<endl;
    return seq;
}
void getSubSeq(vector<string> &subSeq, string str){
    int n=str.length();
    int totSubSeq=(1<<n)-1;
    for(int i=0;i<=totSubSeq;i++){
        string s = filterSeq(str,i);
        subSeq.push_back(s);
    }
}
int main(){
    string str;
    cin>>str;
    vector<string> subSeq;
    getSubSeq(subSeq, str);
    for(int i=0;i<subSeq.size();i++)
        cout<<subSeq[i]<<endl;
    return 0;
}