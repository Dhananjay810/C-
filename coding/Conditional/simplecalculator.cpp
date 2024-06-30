#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter a :";
    cin>>a;
    char ch ;
    cout<<"enter operation that you want";
    cin>>ch;
    cout<<"enter b (b can't be 0 if operator is /) :";
    cin>>b;
    int v=(int)ch;
    switch (v){
        case 43:
        float x;
        x=a+b;
        cout<<x<<endl;break;
         case 45:
        float y;
        y=a-b;
        cout<<y<<endl;break;
         case 42:
        float h;
        h=a*b;
        cout<<h<<endl;break;
         case 47:
        float j;
        j=a/b;
        cout<<j<<endl;break;
    }
    return 0;
}