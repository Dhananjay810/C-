#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1) cout<<"1";
    else if(n==2) cout<<"11";
    string v;
    v.push_back('1');
    v.push_back('1');
    string c;
    int count=0;
    for(int i=0; i<n-2; i++){
        c.clear();
        int j=0;
        do{
            char x=v[j];
            if(v[j]==v[j+1] && j<v.size()-1){
                count++;
            }
            else{
                string ff=to_string(count+1);
                    c.push_back(ff[0]);
                    c.push_back(x);
                    count=0;
            }
            j++;
        }while(j<v.size());
        v.clear();
        for(int b=0; b<c.size(); b++){
            v.push_back(c[b]);
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
}