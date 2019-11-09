#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkParenthesis(string arr){
    stack<char> s;
    for(int i=0;i<arr.size();++i){
        if(arr[i]=='(')
            s.push(arr[i]);
        else if(arr[i]==')')
            s.pop();
    }
    if(s.empty())
        return true;
    else
        return false;
}

int main(){
    string s = "((())";
    cout<<checkParenthesis(s);
}