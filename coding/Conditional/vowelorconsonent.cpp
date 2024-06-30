#include<iostream>
using namespace std;
int main(){
    char x;
    cout<<"enter alphabet";
    cin>>x;
    int y= (int)x;
    if(y == (97 || 101 || 105 || 111 || 118) || y == (65 || 69 || 73 || 79 || 85)){
        cout<<"Given alphabet is Vowel";
    }
    else{
        cout<<"Given alphabet is consonent";
    }
}