//print all possible n-Queens solutions
#include<iostream>
using namespace std;
bool isPossible(int board[][10], int n, int i, int j){
    //NOTE: No need to check for row as we are traversing row-wise adding only one queen in a row (DUH..)
    
    int ii=i, jj=j;     //copies of i, j
    //check column
    for(int k=0;k<i;k++)
        if(board[k][j]==1) return false;
    
    //check in diagonal 1
    while(ii>=0 && jj>=0){
        if(board[ii][jj]==1)
            return false;
        ii--;
        jj--;
    }
    ii=i;
    jj=j;   //reason for copies....
    //check against diagonal 2
    while(i>=0 && j<n){
        if(board[i][j]==1)
            return false;
        i--;
        j++;
    }
    //if all satisfy return true
    return true;
}
bool nQueens(int board[][10], int n, int i){
    //base case
    if(i==n){
        //print board
        for(int p=0;p<n;p++){
            for(int q=0;q<n;q++){
                if(board[p][q]==1) cout<<"Q ";
                else cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl;
        //if we want to print only one soln. Uncomment below and comment return false
        //return ture;

        //This is a hack as it tells the caller that we haven't found the answer. Thus, it continue to search for answer and prints all the possible solns
        return false;
    }
    for(int k=0;k<n;k++){
        if(isPossible(board,n,i,k)){
            board[i][k]=1;
            bool queenPlaced=nQueens(board,n,i+1);
            //if it is not possible to place a queen with the present config; our assumption is wrong
            //Hence backtrack
            if(!queenPlaced){
                board[i][k]=0;  //Backtracking
            }
            //else the cofig is true up till now and return true as we have found the ans
            else
                return true;
        }

    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int board[10][10]={0};

    nQueens(board,n,0);
}