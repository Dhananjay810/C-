#include<iostream>
using namespace std;
int maze(int m, int n){
    if(m==1 || n==1) return 1;
    return maze(m-1,n)+maze(m,n-1);
}

void printpath(int sr, int sc, int n, int m, string s){
    if(sr>n || sc>m) return;
    if(sr==n && sc==m){
        cout<<s<<endl;
        return;
    }
    printpath(sr+1,sc,n,m,s+'D');
    printpath(sr,sc+1,n,m,s+'R');
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<maze(m,n)<<endl;

   // printpath(1,1,n,m,"");
}