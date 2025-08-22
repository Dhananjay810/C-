#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        long long a,b;
        cin>>a>>b;
        int x=a;
        vector<int> v(b-a+1);
        for(int j=0; j<=(b-a); j++){
            v[j]=x;
            x++;
        }
        int count=0;
        while(v[v.size()-1]!=0){
            int g=0;
            while(v[g]!=0) g++;
            if(g==v.size()-1){
                v[g]=v[g]/3;
            }
            else{
            v[g]=3*(v[g]);
            v[g+1]=((v[g+1])/3);
            }
            count++;
            sort(v.begin(),v.end());
        }
        cout<<count<<endl;
    }
}