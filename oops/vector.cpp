//Vector Implementation using Class
/*
    Implement vector functionalities using
    simple functions, parameters, data members 
    const functions, parameters, data members
    constructor
    copy constructor - shallow and deep
    copy assignment - shallow and deep
    functionalities: push_back, pop_back, operator overloading (cin>>v1, cout<<v1, v1+v2, v1[i]), print, size, destructor, reserve
*/
#include <iostream>
using namespace std;

class Vector{
    int *arr;
    int cs; //current size of the array
    int maxSize;

public:
    Vector(){
        cs=0;
        maxSize=4;
        arr = new int[maxSize];
    }
    Vector(const int size){
        //input the size of the array and returns an empty array of the given size
        //input size should be constant i.e. it should not be changed. It is a good practice to follow such safety protocols
        maxSize = size;
        cs=0;
        arr = new int [maxSize];
    }
    Vector(int size, int currentsize, int *arrptr){
        maxSize=size;
        cs=currentsize;
        arr=arrptr;
    }
    //NOTE: here we pass class by reference because call by value requires a copy of the class and copy can be created only using a copy constructor, but such a copy constructor requires a copy of class. Thus, a loop is created. Hence, to break the loop we ALWAYS pass a class by reference.
    Vector(Vector &X){
        //The default copy constructor creates a shallow copy
        //Shallow copy means that if the class contains a dynamix array then the pointer of the new object (for the corresponding array) points to the same array in heap memory and changes from one objet are refected in the other object too.
        // Therfore we create a deep copy constructor which handles such cases specifically. If all elements are in the static memory, then there is no need to create a deep copy constructor
        maxSize = X.getMaxSize();
        cs = X.size();
        arr = new int [maxSize];
        for(int i=0;i<cs;i++)
            arr[i]=X[i];
    }
    void push_back(int data){
        if(cs==maxSize){
            int *oldArr = arr;
            maxSize *=2;
            arr = new int [maxSize];
            
            for(int i=0;i<cs;i++){
                arr[i]=oldArr[i];
            }
            
            delete [] oldArr;
        }
        arr[cs]=data;
        cs++;
    }
    void pop_back(){
        cs--;
    }
    int at(int pos){
        return arr[pos];
    }
    int& operator[] (int pos){
        return arr[pos];
    }
    int size(){
        return cs;
    }
    int getMaxSize(){
        return maxSize;
    }
    void operator+(Vector &X){
        //void fuction returns none due to which we can perform v1+v2 ops but v1+v2+v3 is not possible as v1+v2 return none and v3 cannot be added to none. To perform the cascading of operator make the return type = Vector& (pass by reference) and return the current object.
        int *oldArr=arr;
        maxSize+=X.getMaxSize();
        arr = new int [maxSize];
        for(int i=0;i<cs;i++)
            arr[i]=oldArr[i];
        for(int i=0;i<X.size();i++){
            arr[i+cs]=X[i];
        }
        cs+=X.size();
        // Vector add(maxSize, cs, arr);
        // return add;
    }
    void print(){
        for(int i=0;i<cs;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~Vector(){
        delete [] arr;
    }
};

//to Overload << and >> operator for cin and cout, the forst operator is the istream/ostream class object. So, changes have to be made in the iostream header file which is dangerous. So, we create a function ouside the class which takes two inputs: an object of the istream/ostream class and another of the user-defined Vector class
istream& operator>>(istream &is, Vector &X){
    //the function retrun the ifstream object bcoz it helps in cascading of input of vectors
    int a;
    is>>a;
    X.push_back(a);
    return is;
}
ostream& operator<<(ostream &os, Vector &X){
    X.print();
    return os;
}
int main(){
    Vector X;
    X.push_back(2);
    X.push_back(1);
    X.push_back(4);
    Vector Y(X);
    Y[2]=6;
    cout<<Y;
    Y+X;
    Y.print();
    X.print();
    Vector Z;
    for(int i=0;i<5;i++)
        cin>>Z;
    cout<<Z;
}