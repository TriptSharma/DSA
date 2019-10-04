//implement deep and shallow copy constructors
#include <iostream>
#include<cstring>
using namespace std;

class Toy{
private:
    int price;
public:
    int model_no;
    char *name;
    
    //Constructor 
    Toy(){
        //Override the default Constructor
        name = NULL;
        cout<<"Making a toy.."<<endl;
    }
    // Constructor with parameters - Parametrised Constructor 
    Toy(int p,int mn,char *n){
        price = p;
        model_no = mn;
        int l  = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        
    }
   
   //Deep Copy Constructor 
   Toy(Toy &X){
        price = X.price;
        model_no = X.model_no;
        int l = strlen(X.name);
        name = new char[l+1];
        strcpy(name,X.name);
    }
    
    void setName(char *n){
        if(name==NULL){
            name = new char[strlen(n)+1];
            strcpy(name,n);
        }
        else{
            //Delete the oldname array and allocate a new one.
            char* oldname = name;
            name = new char[strlen(n)+1];
            strcpy(name,n);
            delete [] name;
        }
    }
    
    void start(){
        cout<<"Making toy "<<name<<endl;
    }
    void setPrice(int p){
        if(p>1000){
            price  = p;
        }
        else{
            price = 1000;
        }
    }
    int getPrice(){
        return price;
    }
    void print(){
        cout<<name<<endl;
        cout<<model_no<<endl;
        cout<<price<<endl;
        cout<<endl;
    }
    
};

int main() {
    
    Toy C;
    //Initialisation
    //C.price =-500;
    C.setPrice(1500);
    C.setName("Nano");
    C.model_no = 1001;
    //C.start();
    C.print();
    
    Toy D(100,200,"BMW");
    
    Toy E(D); //Default Copy Constructor
    E.name[0] ='G';
    
    D.print();
    E.print();
}