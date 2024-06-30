#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> a(m);
    vector<int> k(m);
    for(int i=0; i<m; i++){
        cin>>a[i];
        k[i]=a[i];
    }
    int min=0;
    sort(a.begin(),a.end());
    int y=0;
    int t=0;
    while(t!=n){
        if(a[y]!=0){
            min=min+a[y];
            a[y]=a[y]-1;
            t++;
        }
        else{
            y++;
        }
    }
    sort(k.begin(),k.end());
    reverse(k.begin(),k.end());
    int max=0;
    int z=0;
    int u=0;
    while(u!=n){
        if(k[z]>=k[z+1]){
            max=max+k[z];
            k[z]=k[z]-1;
            u++;
         //   if(k[z]==k[z+1]) z++;
        }
        else{
            sort(k.begin(),k.end());
            reverse(k.begin(),k.end());
            z=0;
        }
    }
    cout<<max<<" "<<min;
}