#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> m={2,4,3,5,1};
    int count=0;
    for(int i=0; i<m.size()-1; i++){
        for(int j=i+1; j<m.size(); j++){
            if(m[i]>m[j]) count++;
        }
    }
    cout<<count;
}