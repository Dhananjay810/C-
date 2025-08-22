#include<iostream>
using namespace std;
int fl(int* q){
    int y,t,l;
    y= (*q)%10;
    (*q)=(*q)/10;
    cout<<y<<endl;
    if(y!=0){
        for(int j=1; j<=*q; j++){
            t=(*q)%10;
            (*q)=(*q)/10;
            if(*q!=0)continue;
            else{
                cout<<t;
                

            }break;
        } 
        
        
    }
    
}
int main(){
    int n;
    cout<<"enter a no. : ";
    cin>>n;
    // int y,t;
    // for(int i=1; i<=n; i++){
    //     y=n%10;
    //     n=n/10;

    //     cout<<y<<endl;
    //     if(y!=0){
    //         for(int j=1; j<=n; j++){
    //             t=n%10;
    //             n=n/10;
    //             if(n!=0) continue;
    //             else{
    //                 cout<<t;
    //             } break;

    //         }

    //     }
    //     break;

    // } 


    int u=fl(&n);

}