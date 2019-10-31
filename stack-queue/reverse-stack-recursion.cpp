#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class stack{
    vector<T> v1;
public:
    void push(T data){
            v1.push_back(data);
    }
    void pop(){
        if(!empty())
            v1.pop_back();
    }
    T top(){
        return v1[v1.size()-1];
    }
    bool empty(){
        return (v1.size()==0);
    }
    int size(){
        return v1.size();
    }
    void print(){
        if(!empty())
        for(int i=v1.size()-1;i>=0;i--)
            cout<<v1[i]<<" ";
        cout<<endl;
    }
};

template<typename T>
void pushAtBottom(stack<T> &s, T data){
    if(s.empty()){
        s.push(data);
        return;
    }
    T x = s.top();
    s.pop();
    pushAtBottom(s,data);
    s.push(x);
}
template <typename T>
void reverseRecursion(stack<T> &s){
    if(s.empty())
        return;
    T cur_top = s.top();
    s.pop();
    reverseRecursion(s);
    pushAtBottom(s,cur_top);
}

int main(){
    stack<int> s;
    s.push(1); s.push(2); s.push(3);
    reverseRecursion(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}