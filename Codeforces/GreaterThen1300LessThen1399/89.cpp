#include<iostream>
using namespace std;
int main(){
    long long int a,b,c;
    cin>>a>>b>>c;
        int l=a%3;
        int m=b%3;
        int n=c%3;
        if(a==0 || b==0 || c==0){
            cout<<a/3+b/3+c/3;
            return 0;
        }
        if(l!=m && m!=n && l!=n){
            long long int y=min(a,b);
            long long int z=min(y,c);
            // cout<<z<<" ";
            a=a-z;
            b=b-z;
            c=c-z;
            // cout<<endl<<a<<" "<<b<<" "<<c<<endl;
            // cout<<a/3<<" "<<b/3<<" "<<c/3<<endl;
            z=z+a/3;
            z=z+b/3;
            z=z+c/3;
            cout<<z;
            return 0;
        }
        int g=0;
        if(a%3==0) g++;
        if(b%3==0) g++;
        if(c%3==0) g++;
        long long int t=0;
            while(g<2){
                g=0;
                a--;
                b--;
                c--;
                t++;
                if(a%3==0) g++;
                if(b%3==0) g++;
                if(c%3==0) g++;
            }
            t=t+a/3;
            t=t+b/3;
            t=t+c/3;
            cout<<t;
    
}