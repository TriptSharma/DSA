#include<iostream>
using namespace std;

template <typename T>
class Queue{
    T *arr;
    int front;
    int rear;
    int maxSize;
    int curSize;
public:
    Queue(int defaultSize=4){
        maxSize=defaultSize;
        front=0;
        rear=0;
        arr = new T[maxSize];
        curSize=0;
    }
    //Push: Enqueue operation
    void push(int data){
        if(!isFulL()){
            rear=(rear+1)%maxSize;
            arr[rear]=data;
            curSize++;
        }
        else
            cout<<"Queue full"<<endl;
    }
    bool isFull(){
        return (curSize==maxSize)
    }
    bool isEmpty(){
        return curSize==0;
    }
    //Pop: Dequeue operation
    void pop(){
        if(!isEmpty()){
            front=(front+1)%maxSize;
            curSize--;
        }
    }
    T getFront(){
        return arr[front];
    }
};

int main(){
    Queue<int> q;
    
    for(int i=1;i<=6;i++)
        q.push(i);
    
    q.pop();
    q.push(8);

    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }
    return 0;
}