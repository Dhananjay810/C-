#include<iostream>
using namespace std;
int main(){
    int array[5];    // address of 'array' is the 1st bits osf first element
    cout<<&array<<endl<<endl<<endl;  // cout<<aray;   SAME
    cout<<&array[0]<<endl;
    cout<<&array[1]<<endl;
    cout<<&array[2]<<endl;
    cout<<&array[3]<<endl;
    cout<<&array[4]<<endl;

// 0x61fefc +4
// 0x61ff00 +4
// 0x61ff04 +4              all are in pattern
// 0x61ff08 +4
// 0x61ff0c
}
