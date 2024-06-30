#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string n;
    cout<<"enter string : ";
    getline(cin,n);
    stringstream nn(n);
    string s;
    vector<string> v;
    vector<string> j;
    
    while(nn>>s){
        v.push_back(s);
        cout<<s[1];
    }
    cout<<v[0];
    //vector print
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<endl;
    // }
    // cout<<endl;
    // sort(v.begin(),v.end());
    // // for(int i=0; i<v.size(); i++){
    // //     cout<<v[i]<<endl;
    // // }
    // int count = 1, maxcount = 1;
    // for(int i=1; i<v.size(); i++){
    //     if(v[i]==v[i-1]){ count++;}
    //     else count = 1;
    //     maxcount = max(maxcount,count);
        
    // }
    
    // count =1;
    // for(int i=1; i<v.size(); i++){
    //     if(v[i]==v[i-1]){ count++;}
    //     else count = 1;
    //     if(count==maxcount){
    //         cout<<v[i]<<" "<<maxcount<<endl;
    //     }
        
    // }
}