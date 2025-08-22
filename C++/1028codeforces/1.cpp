#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==c && b==d) cout<<"Gellyfish"<<endl;
        int e=min(a,b);
        int f=min(c,d);
        if(e==f){
            if(e==a) e=b;
            else e=a;
            if(f==c) f=d;
            else f=c;
        }
        // int i=1;
        // while(e>0 && f>0){
        //     if(i%2!=0){
        //         f--;
        //     }
        //     else e--;
        //     i++;
        // }
        int ans=e-f;
        // cout<<ans<<endl;
        if(ans>0) cout<<"Gellyfish"<<endl;
        else cout<<"Flower"<<endl;
        // if(e==0) cout<<"Flower"<<endl;
        // else cout<<"Gellyfish"<<endl;
    }
}