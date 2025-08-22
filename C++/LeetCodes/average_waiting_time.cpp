#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>> customers={
        {5,2},
        {5,4},
        {10,3},
        {20,1}
    };
    int n=customers.size();
        double t=0;
        int s;
        int f=customers[0][0];
        for(int i=0; i<n; i++){
            if(f>=customers[i][0])s=f;
            else s=customers[i][0];
            f=s+customers[i][1];
            int timeTaken=f-customers[i][0];
            t=t+timeTaken;
            cout<<t<<" ";
        }

}