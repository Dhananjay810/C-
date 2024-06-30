#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int y;
    cin>>y;
    sort(v.begin(),v.end());
    int low=0;
    int high=n-1;
    bool flag=false;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(v[mid]==y){
            cout<<"true";
            flag=true;
            break;
        }
        else if(v[mid]<y) low=mid+1;
        else high=mid-1;
    }
    if(flag==false) cout<<"false";
}