#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<long long> v;
    long long a,b;
    cin>>a>>b;

    v.push_back(4);
    v.push_back(7);
    long long j=0;
    while(v[v.size()-1]<10000000000){
        long long f=v.size()-j;
        for(j; j<f; j++){
            long long u=v[j];
            u=u*10;
            v.push_back(u+4);
            v.push_back(u+7);

        }
    }

    long long sum=0;
    if(a<=4){
        if(b>4){
            for(int i=a; i<=4; i++) sum=sum+4;
            a=5;
        }
        else{
            for(int i=a; i<=b; i++) sum=sum+4;
            a=b;
            cout<<sum;
            return 0;
        }
    }


    long long z=1;

    while(a<=b){
        if(a<=v[z] && a>v[z-1]){
            sum=sum+v[z];
            a++;
        }
        else{
            z++;
        }
    }

    // for(int i=0; i<v.size(); i++) cout<<v[i]<<endl;

    cout<<sum;

}