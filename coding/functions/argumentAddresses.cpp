#include<iostream>
using namespace std;
int fun(int x, int y)
{
    cout<<"add. of fun vala x "<<&x<<endl<<"add of fun vala y "<<&y<<endl;
}
int main(){
    int x=7;
    int y=3;
    cout<<"add. of main vala x "<<&x<<endl<<"add of main vala y "<<&y<<endl;
    fun(x,y);
}