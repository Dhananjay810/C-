#include<iostream>
using namespace std;
int main(){
    int array[5]={2,3,5,2,6};
    int y=1;
    for(int i=0; i<=4; i++){
        y=y*array[i];


    }
    cout<<y;
}