#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;
    pair<string,int> v;
    v={"Dhananjay", 17};
    m.insert(v);
    pair<string,int> w;
    w={"Abhinav", 1};
    m.insert(w);
    pair<string,int> x;
    x={"Chirag", 14};
    m.insert(x);
    pair<string,int> y;
    y={"Chirag", 14};
    m.insert(y);
    for(pair<string,int> e : m){
        cout<<e.first<<" "<<e.second<<endl;
    }
    cout<<m.size()<<endl;
    for(auto e : m) cout<<e.first<<" "<<e.second<<endl;
    cout<<m.size()<<endl;
    m.erase("Chirag");
    for(auto e : m) cout<<e.first<<" "<<e.second<<endl;
    cout<<m.size()<<endl;
    if(m.find("Abhinav")!=m.end()) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    cout<<m["Dhananjay"]<<endl;
}