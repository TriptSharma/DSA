#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};
Node* insertAtBack(int data, Node* &head){
    if(head==NULL){
        head=new Node(data);
        return head;
    }
    Node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = new Node(data);
    return head;
}
istream& operator>> (istream &is, Node* &head){
    int data;
    is>>data;
    while(data!=-1){
        insertAtBack(data, head);
        is>>data;
    }
}
ostream& operator<<(ostream &os, Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return os;
}

void reverseCopy(Node *head, Node*& rev){
    //Creates another linked list; copying takes time -- Not feasible...
    Node *temp = head;
    head=head->next;
    temp->next =rev;
    rev=temp;
}
void reverse(Node *&head){
    Node*prev=NULL;
    Node*current=head;
    Node*nxt;
    while(current!=NULL){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
    }
    head=prev;
}
void reverseRecursive(Node*&head, Node*C, Node*P, Node*N){
    //C=current, P=prev, N=next
    if(N==NULL){
        C->next=P;
        head=C;
        return;
    }
    C->next=P;
    P=C;
    C=N;
    N=N->next;
    reverseRecursive(head, C, P, N);
}
Node* reverseRecursiveEfficient(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* revhead = reverseRecursiveEfficient(head->next);
    head->next->next=head;
    head->next=NULL;
    return revhead;
}
int main(){
    Node *rev=NULL, *head = NULL;
    cin>>head;
    cout<<head;

    // reverseCopy(head, rev);
    // cout<<rev;

    // reverse(head);
    
    // reverseRecursive(head, head, NULL, head->next);
    
    head = reverseRecursiveEfficient(head);
    cout<<head;
}