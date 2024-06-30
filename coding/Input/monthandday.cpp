#include<iostream>
using namespace std;
int main(){
    int days;
    cout<<"enter the no. of days";
    cin>>days;
    int month;
    month = days%30;
    int remaining Days = days - month*30
    cout<<"amswer";
    cout<<month<<"  "<<remaining Days;
    return 0;
}