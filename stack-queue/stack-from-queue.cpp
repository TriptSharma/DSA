#include<iostream>
#include<queue>
using namespace std;

class stackViaQueue{
    queue<int> *q1, *q2;
public:
    stackViaQueue(){
        q1 = new queue<int>();
        q2 = new queue<int>();
    }
    void push(int data){
        q1->push(data);
    }
    void pop(){
        int n = q1->size();
        for(int i=0;i<n-1;i++){
            q2->push(q1->front());
            q1->pop();
        }
        if(q1->empty()==false)
            q1->pop();
        swap(q1,q2);
    }
    int top(){
        int n=q1->size();
        for(int i=0;i<n-1;i++){
            q2->push(q1->front());
            q1->pop();
        }
        int topElement=q1->front();
        q2->push(q1->front());
        q1->pop();
        swap(q1,q2);

        return topElement;
    }
};
int main(){
    stackViaQueue s;
    s.push(1); s.push(2); s.push(3);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}