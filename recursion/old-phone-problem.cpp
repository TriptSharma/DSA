//Convert a string of nos. pressed on a phone to corresponding character string. Print all possible strings
#include<iostream>
using namespace std;

//2D char array containing alphabets corresponding to the respective no.
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadString(char* in, char* out, int i, int j){
    //eg. in = 666, out=container to store string and print at the end (base case)
    if(in[i]=='\0'){
        out[j]='\0';    //THIS is IMPORTANT
        cout<<out<<endl;
        return;
    }
    //ERROR HANDLING
    if((in[i]-'0')<=1)
        printKeypadString(in, out, i+1, j);
    //Recursive call for all possible alphabets corresponding to the given no.
    for(int k=0; keypad[in[i]-'0'][k]!='\0';k++){
        out[j]=keypad[in[i]-'0'][k];
        printKeypadString(in, out, i+1, j+1);
    }
}

int main(){
    char no[100], out[100];
    cin>>no;
    printKeypadString(no,out,0,0);
    return 0;
}