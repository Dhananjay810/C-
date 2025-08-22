#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v={2,-3,4,4,-7,-1,4,-2,6};
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    int k=4;
    vector<int> ans(v.size()-k+1);
    int p=-1;
    for(int i=0; i<k; i++){
        if(v[i]<0){
            p=i;
            break;
        }
    }
    if(p==-1) ans[0]=1;
    else ans[0]=v[p];
    int i=1,j=k;
    while(j<v.size()){
        if(p>=i){
           ans[i]=v[p];
        }
        else{
            p=-1;
            for(int m=i; m<i+k; m++){
                if(v[m]<0){
                    p=m;
                    break;
                }
            }
            if(p==-1) ans[i]=1;
            else ans[i]=v[p];
        }
        i++;
        j++;
    }
    for(int i=0; i<v.size()-k+1; i++) cout<<ans[i]<<" ";
}