#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int k=0;
    int y=s.length();
    sort(s.begin(),s.end());
    // cout<<y<<endl;
    // cout<<s<<endl;
    // vector<int> v[y];
    for(int i=0; i<y; i++){
        int u=0;
        for(int j=i; j<y; j++){
            if(s[i]==s[j+1]){
                u++;
               
            }    
            
        }
        k=k+u;
       // cout<<u<<" ";
        i=i+u;
        // if(u!=0){
        //      i=i+u;
        // }
       
    //    if(u!=0){
    //     k=k+1;
    //    }
        
    }
    //cout<<k<<endl;
    if((y-k)%2==0){
        cout<<"CHAT WITH HER!";
    }
    else cout<<"IGNORE HIM!";
    
}