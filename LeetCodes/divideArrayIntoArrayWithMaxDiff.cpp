#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    bool flag=false;
    sort(nums.begin(),nums.end());
    vector<vector<int>> v(n,vector<int>(3));
    int g=0;
    int j=0;
    for(int i=0; i<n/3; i++){
        int x=nums[g];
        int h=0;
        v[i][h]=x;
        h++;
        j=g;
        g=g+3;
        for( j; j<g-1; j++){
            if(nums[j+1]-nums[j]<=k){
                flag=true;
                v[i][h]=nums[j+1];
                h++;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag=false) break;
    }
    for(int i=0; i<n/3; i++){
        for(int j=0; j<3; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}