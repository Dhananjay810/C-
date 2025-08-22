#include<iostream>
using namespace std;
int main(){
    // int n;
    // cout<<"enter till what you want to print : ";
    // cin>>n;
    // int x= -1;
    // int y = 0;
    // int o=1;
    // while(n>0){
    //     x = x*(-1);
    //     y = y + (x*o);
    //     o++;
    //     n--;

    // }
    // cout<<y<<endl;
//     int n;
//     cout<<"enter no. : ";
//     cin>>n;
//     int y = 0;
//     for(int i=1; i<=n; i++){
//         if(i%2!=0){
//             y = y+i;
//         }
//         else{
//             y = y-i;
//         }
        
//     }
//    cout<<y<<endl;

int n;
cout<<"enter no. : ";
cin>>n;
if(n%2==0){
    cout<<(-1)*(n/2);

}
else{
    cout<<(-1)*(n/2)+n;
}


    
}