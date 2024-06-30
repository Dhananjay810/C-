#include<iostream>
using namespace std;
int main(){
    int x = 10;
    int y = 3;
    cout<<x%y<<endl; // it happen when only (x>y).
    // But lets check what happen when (x<y).
    // If a>b then a%b give us remainder
    // when   a<b then remainder that given by system is a.
    int a = 20;
    
    int b = 70;
    cout<<a%b<<endl; 
    cout<<10%-3<<endl;
    
    cout<<-10%3<<endl;
    cout<<-10%-3<<endl; 
}
