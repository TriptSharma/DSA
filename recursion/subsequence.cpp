#include<iostream>
using namespace std;
void printSubSeq(string s, int n, string out){
    //base case
    if(s[n]=='\0'){
        out+="\0";
        cout<<out<<endl;
        return;
    }
    //break the problem into subparts: At any given index we can either consider the array element or not
    printSubSeq(s, n+1, out+s[n]);
    printSubSeq(s, n+1, out+"");

}
int main(){
    string str;
    cin>>str;
    printSubSeq(str)
}