#include<iostream>
using namespace std;
//QUESTIONS from HACKERBLOCKS
void uniqueNo_I(int arr[], int n){
    //all nos present twice except one, find the no.
    //Method: Simply take XOR of all elements; nos occuring twice will cancel out in XOR leaving the unique no.
    int xors=0;
    for(int i=0;i<n;i++)
        xors^=arr[i];
    cout<<xors<<endl;
}
int getFirstSetBitMask(int n){
    int index=0;
    while(n>0){
        if(n&1) break;
        index++;
        n=n>>1;
    }
    return (1<<index);
}
void uniqueNo_II(int arr[], int n){
    //all nos present twice except two, print the numbers in ascending order
    //METHOD: Take XOR of all elements; Create a bitmask for the first setbit in XOR (it is the bit where the two nos differ -> use it to separate the two nos); Take XOR of any one list ->get first no.
    int xors=0;
    for(int i=0;i<n;i++)
        xors=xors^arr[i];
    //find the first setbit and create mask
    int temp=xors, index=0;
    while(temp>0){
        if(temp&1) break;
        index++;
        temp=temp>>1;
    }
    int firstAns=0, mask=1<<index;
    for(int i=0;i<n;i++){
        //NOTE: HERE PRECEDENCE OF ! IS GREATER THAN &. THUS, arr[i]&mask HOULD BE IN CLOSED BRACKETS
        if((arr[i]&mask)!=0) firstAns^=arr[i];
    }
    int secondAns;
    secondAns=xors^firstAns;
    cout<<firstAns<<" "<<secondAns<<endl;
}
void uniqueNo_III(int arr[], int n){
    //all nos. present thrice except one(present once). Find the unique no.
    //METHOD: create a count array of size=no.of bits -> Take %3 of all array elem ->the array is the unique no (as bits)
    int cnt[64]={0}; //64=number of bits
    for(int i=0;i<n;i++){
        int bit=0, temp=arr[i];
        while(temp>0){
            if(temp&1) cnt[bit]++;
            bit++;
            temp=temp>>1;
        }
    }
    int ans=0, p=1;
    for(int i=0;i<64;i++){
        cnt[i]=(cnt[i]%3);
        ans+=cnt[i]*p;
        p=p<<1;
    }
    cout<<ans<<endl;
}
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int arr1[n1], arr2[n2], arr3[n3];
    for(int i=0;i<n1;i++) cin>>arr1[i];
    for(int i=0;i<n2;i++) cin>>arr2[i];
    for(int i=0;i<n3;i++) cin>>arr3[i];
    uniqueNo_I(arr1, n1);
    uniqueNo_II(arr2,n2);
    uniqueNo_III(arr3,n3);
    return 0;
}