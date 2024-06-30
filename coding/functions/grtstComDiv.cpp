#include<iostream>
using namespace std;
int HCF(int a, int b){
    int y=min(a,b);
    int z=max(a,b);
    int h=z%y;
    if(h==0){
        return y;}
    else{
    
    if(y%h==0){
        return h;
    }
    else{
        int i=y%h;
        return i;
    }
    }

}
int main(){
    int a,b;
    cout<<"enter two number : ";
    cin>>a>>b;
    cout<<"HCF IS : "<<HCF(a,b);
}