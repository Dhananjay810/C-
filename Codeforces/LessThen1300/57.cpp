#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(m);
    for(int i=0; i<m; i++){
        cin>>v[i];
    }
    int min=INT_MAX;
    for(int i=0; i<=m-n; i++){
        vector<int> s(n);
        int g=i;
        for(int j=0; j<n; j++){
            s[j]=v[g];
            g++;
        }
        
        
         sort(s.begin(),s.end());
         for(int k=0; k<n; k++){
            cout<<s[k]<<" ";
        }
        // if(min>abs(s[0]-s[n-1])){
        //     min=abs(s[0]-s[n-1]);
        // }
        cout<<endl;
    }
   // cout<<min;
}