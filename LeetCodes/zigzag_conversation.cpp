#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="AB";
    int n=s.size();
    int o=3;
    vector<int> v;
    int h=0;
    int k=1;
    bool flag=false;
    if(o==1){
        cout<<s;
        return 0;
    }
    while(h<n){
        if(flag==false){
            v.push_back(k);
            k++;
            if(k>o){
                k=k-2;
                flag=true;
            }
        }
        else if(flag==true){
            
            v.push_back(k);
            k=k-1;
            if(k<1){
                k=k+2;
                flag=false;
            }
        }
        h++;
    }

    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    //cout<<endl;
    string x="";
    for(int i=1; i<=o; i++){
        for(int j=0; j<n; j++){
            if(v[j]==i)x=x+s[j];
        }
    }
    cout<<x;
}