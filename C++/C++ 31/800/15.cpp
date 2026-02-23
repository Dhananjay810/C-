#include<iostream>
#include<vector>
using namespace std;
bool f(int sum1, int sum2, vector<int> v, int idx){
    if(idx>=v.size()){
        if(sum1%2==sum2%2) return true;
        return false;
    }
    if(sum1%2==sum2%2) return true;
    return f(sum1+v[idx],sum2-v[idx],v,idx+1) & (sum1,sum2,v,idx+1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int odd=0;
        int even=0;
        int sum=0;
        for(int i=0; i<n; i++) {
            int num;
            cin>>num;
            sum+=num;
        }
        bool g=f(0,sum,v,0);
        if(g==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}