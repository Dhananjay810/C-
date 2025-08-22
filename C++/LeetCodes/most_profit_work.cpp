#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    vector<int> d={85,47,57};
    vector<int> p={24,66,99};
    vector<int> w={40,25,25};
    int sum=0;
    for(int i=0; i<w.size(); i++){
        int u=INT_MIN;
        for(int j=0; j<d.size(); j++){
            if(w[i]>=d[j]){
                if(p[j]>u) u=p[j];
            }
        }
        if(u>0) sum=sum+u;
    }
    cout<<sum;
}