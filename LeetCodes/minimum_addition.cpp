#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v={24,5,64,53,26,38};
    int k=54;
    while(k>0){
        sort(v.begin(),v.end());
        if(k>=(v[1]+1)-v[0]){
            k=k-((v[1]+1)-v[0]);
            v[0]=v[1]+1;
        }
        else{
            v[0]=v[0]+k;
            k=0;
        }
    }
    long long c=1;
    for(int i=0; i<v.size(); i++){
        c=c*v[i];
    }
    cout<<c;
}