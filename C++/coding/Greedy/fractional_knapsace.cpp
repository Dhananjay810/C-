#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
double frac(vector<int> &profit, vector<int> &weight, int n, int w){
    vector<pair<int,pair<int,int>>> arr;
    for(int i=0; i<n; i++){
        double s=(profit[i]*1.0)/(weight[i]*1.0);
        arr.push_back({s,{profit[i],weight[i]}});
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    double x=0;
    for(int i=0; i<n; i++){
        if(arr[i].second.second <= w){
            x=x+arr[i].second.first;
            w-=arr[i].second.second;
        }
        else{
            x += (arr[i].first*1.0)*w;
            w=0;
            break;
        }
    }
    return x;
}
int main(){
    vector<int> profit={60,100,120};
    vector<int> weight={10,20,30};
    int w=50;
    int n=3;
    cout<<frac(profit,weight,n,w);
}