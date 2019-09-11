//IMPORTANT (CONCEPTUAL) Tower of Hanoi
#include<iostream>
using namespace std;
void towerOfHanoi(int n, char src, char dst, char helper){
    //base case
    if(n==0)
        return;
    //recursive call (It shifs n-1 disk to helper; stacks up all n-1 disks to helper)
    towerOfHanoi(n-1, src, helper, dst);

    //move current disk to destination
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dst<<endl;

    //put n-1 disk to destination
    towerOfHanoi(n-1, helper, dst, src);
}
int main(){
    int n;  //no of disks
    cin>>n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}