#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <iomanip>
#include<algorithm>
using namespace std;

void f(int idx,int a, int &ans,int ff,int ans1,int ans2){
    if(idx==ff){
        if((ans2+a)==ans1) ans++;
        // cout<<a<<endl;
        return;
    }
    int u=a+1;
    int v=a-1;
    // cout<<u<<" "<<v<<endl;
    f(idx+1,u,ans,ff,ans1,ans2);
    f(idx+1,v,ans,ff,ans1,ans2);

}

int main(){
    string corr;
    cin>>corr;
    string wron;
    cin>>wron;
    int n=corr.size();
    int m=wron.size();
    if(n!=m){
        cout<<0<<endl;
        return 0;
    }
    int ans1=0;
    for(int i=0; i<n; i++){
        if(corr[i]=='+') ans1++;
        else ans1--;
    }
    // cout<<ans1<<endl;
    int ans2=0;
    int ff=0;
    for(int i=0; i<n; i++){
        if(wron[i]!='?'){
            if(wron[i]=='+') ans2++;
            else ans2--;
        }
        else ff++;
    }
    // cout<<ff<<endl;
    // cout<<ans2<<endl;
    int ans=0;
    f(0,0,ans,ff,ans1,ans2);
    int uu=pow(2,ff);
    cout << fixed << setprecision(9) << (ans+0.0)/uu << endl;
    // cout<<(ans+0.0)/uu;
}