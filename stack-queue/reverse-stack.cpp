#include<iostream>
#include<vector>
using namespace std;
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
//reverse using 2 stacks
template<typename T>
void transfer(stack<T> &s1, stack<T> &s2){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
}
template<typename T>
void reverse2stack(stack<T> &s) {
    //pop all elements to 1st stack (all elemts are in reverse order) -> now transfer all elements to 2nd stack (elements in original order) -> finally transfer all elemts to the original array (elem in reverse order)
    stack <T> s1, s2;
    transfer(s,s1);
    transfer(s1,s2);
    transfer(s2,s);
}

//reverse using 1 stack
template <typename T>
void transfer(stack<T> &s1, stack<T> &s2, int size){
    for(int i=0;i<size;i++){
        s2.push(s1.top());
        s1.pop();
    }
}

template <typename T>
void reverse1stack(stack<T> &s){
    //Take the top element out and transfer other elements till n-i-1 (bcoz for ith iteration i elements have been reversed and '-1' for the current element being reversed) to temp stack where there order is opposite. Add the saved top element to the main stack (this puts it to its right location in the reverse stack). Now transfer from temp stack. Repeat the process till last element.Stack is reversed!
    stack<T> temp;
    int n=s.size();
    for(int i=0;i<s.size();i++){
        T cur_top = s.top();
        s.pop();
        transfer(s,temp,n-i-1);
        s.push(cur_top);
        transfer(temp,s,n-i-1);
    }
}
int main(){
    stack<int> s;
    s.push(1); s.push(2); s.push(3);
    reverse2stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    s.push(1); s.push(2); s.push(3);
    reverse1stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}