#include<iostream>  
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>b[i];
    sort(b.begin(),b.end());
    long long min=b[0],max=b[n-1];
    long long count_min=1;
    for(int i=0; i<n; i++){
        if(b[i]==b[i+1]) count_min++;
        else break;
    }
    long long count_max=1;
    for(int i=n-1; i>=0; i--){
        if(b[i]==b[i-1]) count_max++;
        else break;
    }
    if(max==min){
        long long fact;
        fact=(count_min*(count_min-1))/2;
        cout<<max-min<<" "<<fact;
        return 0;
    }
    cout<<max-min<<" "<<count_max*count_min;
}