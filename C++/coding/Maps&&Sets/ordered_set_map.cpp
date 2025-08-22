#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
    set<int> s;
    s.insert(4);
    s.insert(2);
    s.insert(9);
    for(int ele : s) cout<<ele<<" ";
    cout<<endl;

    // map
    map<int,int> m;  
    m[1]=30;
    m[-1]=10;
    m[-1]=11;
    for(auto ele : m){
        cout<<ele.first<<" "<<ele.second<<endl;
    }

}