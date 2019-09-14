//print count of possible n-Queens config (OPTIMIZED SOLN)
#include<iostream>
#include<bitset>
using namespace std;

bitset<30> col, dia1, dia2;  //bitsets containing 30 bits (init val = 000...0) (indexing starts from rhs) 

bool isPossible(int n, int i, int j){
    //Implement function in O(1) rather than O(n) (used in backtracking soln)
    //We create bitsets which is 1 if that element's col/dia1/dia2 is filled

    //dia1 values vary from -3 to 3 for n=4 -> we shift the values of array by adding (n-1) to each val
    if(!col[j] && !dia1[i-j+(n-1)] && !dia2[i+j])
        return true;
    return false;
}

void nQueens(int n, int i, int &count){
    //base case
    if(i==n){
        count++;
        return;
    }
    for(int k=0;k<n;k++){
        if(isPossible(n,i,k)){
            col[k]=dia1[i-k+(n-1)]=dia2[i+k]=1;
            nQueens(n,i+1,count);
            
            //backtrack; as all possible combinations from the current element have been accounted in the recursive calls of the child
            col[k]=dia1[i-k+(n-1)]=dia2[i+k]=0;  //Backtracking
        }

    }
    return;
}
int main(){
    int n;
    cin>>n;
    int board[10][10]={0};
    int count=0;
    nQueens(n,0,count);
    cout<<count;
}