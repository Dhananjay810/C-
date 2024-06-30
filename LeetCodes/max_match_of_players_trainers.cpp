#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> p={4,7,9};
    vector<int> t={8,2,5,8};
    sort(p.begin(),p.end());
    sort(t.begin(),t.end());
    int sum=0;
    for(int i=0; i<p.size(); i++){
        for(int j=0; j<t.size(); j++){
            if(p[i]>t[t.size()-1]) break;
            else if(p[i]<=t[j]){
                sum++;
                t[j]=-1;
                break;
            }
        }
    }
    cout<<sum;
}