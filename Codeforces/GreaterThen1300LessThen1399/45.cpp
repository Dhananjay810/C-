#include<iostream>
using namespace std;
int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2 || y1==y2){
        int dist=abs(y2-y1)+abs(x2-x1);
        if(x1==x2){
            cout<<x1+dist<<" "<<y1<<" "<<x1+dist<<" "<<y2;
        }
        else{
            cout<<x1<<" "<<y1+dist<<" "<<x2<<" "<<y1+dist;
        }
    }
    else if(abs(x1-x2)==abs(y1-y2)){
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
    }
    else cout<<-1;
}