#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v={1,2,3,3};
    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
            for(int k=i; k<=j; k++){
                cout<<v[k]<<" ";
            }
            cout<<endl;
        }
    }
}