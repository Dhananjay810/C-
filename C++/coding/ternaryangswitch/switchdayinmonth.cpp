//switch (integer expression){
//case constant 1:
//      do this;
//case constant 3:
//   do this;
// defalt :
// do this;
//   }
#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"enter the no. of month :";
    cin>>x;
    cout<<"no. of days in this month is :";
    switch(x){
        case 1:
        cout<<"31";break;
        case 2:
        cout<<"28";break;
        case 3:
        cout<<"31";break;
        case 4:
        cout<<"30";break;
        case 5:
        cout<<"31";break;
        case 6:
        cout<<"30";break;
        case 7:
        cout<<"31";break;
        case 8:
        cout<<"31";break;
        case 9:
        cout<<"30";break;
        case 10:
        cout<<"31";break;
        case 11:
        cout<<"30";break;
        case 12:
        cout<<"31";break;
    }
}