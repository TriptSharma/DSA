#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Stack Implementation using Vectors
class Stack{
    vector<int> v;
public:
    void push(int data){
        v.push_back(data);
    }
    void pop(){
        if(!isempty())
            v.pop_back();
    }
    int top(){
        return v[v.size()-1];
    }
    bool isempty(){
        return (v.size()==0);
    }
};
//Stack Implementation using Templates and Vectors
template <typename T>
//template <typename T, typename U>     //if 2 typenames are required...
class stack{
    vector<T> v1;
    //If we want two different data types like in pairs then:
    //vector<U> v2;
public:
    void push(T data){
            v1.push_back(data);
    }
    void pop(){
        if(!isempty())
            v1.pop_back();
    }
    T top(){
        return v1[v1.size()-1];
    }
    bool isempty(){
        return (v1.size()==0);
    }
};
int main(){
    stack<int> s;
    s.push(5); s.push(4); s.push(2);
    while(!s.isempty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    stack<char> v;
    for(int i=65;i<70; i++){
        v.push(i);
    }
    while(!v.isempty()){
        cout<<v.top()<<" ";
        v.pop();
    }
}