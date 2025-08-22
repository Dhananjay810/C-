#include<iostream>
#include<cmath>
using namespace std;
bool isPerfectSqure(int n){
    int root=sqrt(n);
    if(root*root==n) return true;
    else return false;
}
int main(){
    int n;
    cin>>n;
    int x=0;
    int y=n;
    bool u=false;
    while(x<=y){
        if(isPerfectSqure(x) && isPerfectSqure(y)){
            cout<<"true";
            u=true;
            break;
        }
        else if(!isPerfectSqure(y)){
            y=(int)sqrt(y)*(int)sqrt(y);
            x=n-y;
        }
        else{
            x=(int)(sqrt(x)+1)*(sqrt(x)+1);
            y=n-x;
        }
    }
    if(u==false){
        cout<<"false";
    }
}