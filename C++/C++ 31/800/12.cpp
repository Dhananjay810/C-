#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            if(i==0){
                v.push_back(num);
                continue;
            }
            if(v[v.size()-1]>num){
                v.push_back(num);
            }
            v.push_back(num);
        }
        cout<<v.size()<<endl;
        for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        cout<<endl;
    }
}