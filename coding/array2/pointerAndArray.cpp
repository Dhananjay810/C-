#include<iostream>
using namespace std;
int main(){
    int array[]={2,4,9};
    int* ptr=array;// prnt address.
    cout<<ptr<<endl<<&array<<endl;

    ptr[1] = 78;
    for(int i=0; i<3; i++){
        cout<<ptr[i]<<" "; // i[ptr],i[array]
    } // pointer also chanfe the element of array;

    cout<<endl;


    *ptr = 5; // ptr[0] = 5
    ptr++; //ptr is pointing to 2nd element
    *ptr = 9; //ptr[1] =9
    ptr--;

    for(int i=0; i<3; i++){
        cout<<ptr[i]<<" "; // i[ptr],i[array]
    }

}