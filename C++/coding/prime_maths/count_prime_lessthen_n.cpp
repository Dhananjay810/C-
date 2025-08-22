#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

void fill(vector<bool>& flag){
    int n=flag.size()-1;
    for(int i=2; i<=sqrt(n); i++){
        for(int j=i*2; j<=n; j += i){
            flag[j]=0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    if(n<=2) return 0;
        n=n-1;
        int count=0;
        vector<bool> flag(n+1,1);
        fill(flag);
        flag[0]=0;
        flag[1]=0;
        for(int i=2; i<=n; i++){
            if(flag[i]==1) count++;
        }
        cout<<count;
}