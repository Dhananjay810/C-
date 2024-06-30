#include<iostream>
#include<cmath> // header file for mathamatics
using namespace std;
int sum(int x, int y){ // argument
    return x+y;

}

int mini(int x, int y){
    int a;
    if(x<y) a=x;
    else a=y;
    return a;

}

int sq(int h){
    int j;
    j=h*h;
    return j;
}
int main(){
    //cout<<sum(400,5654); // value of argument  x-->400,y-->5654


    // int x,y;
    // cin>>x>>y;
    // cout<<mini(x,y);


    // int h; 
    // cin>>h;
    // cout<<sq(h);

    cout<<sqrt(100);

    
}


// some inbult library fumction

// min(x,y)
// max(x,r)
// sqrt(x)