#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    vector<int> customers={9,10,4,5};
    vector<int> grumpy={1,0,1,1};
    int minutes=1;
    int maxloss=0;
    int preloss=0;
    int idx=0;
    for(int i=0; i<minutes; i++){
        preloss += customers[i]*grumpy[i];
    }
    maxloss=preloss;
    int i=1;
    int j=minutes;
    while(j<customers.size()){
        preloss=preloss+(customers[j]*grumpy[j])-(customers[i-1]*grumpy[i-1]);
        if(maxloss<preloss){
            maxloss=preloss;
            idx=i;
        }
        i++;
        j++;
    }
    int set=0;
    for(int i=idx; i<idx+minutes; i++){
        grumpy[i]=0;
    }
    for(int i=0; i<customers.size(); i++){
        if(grumpy[i]==0) set=set+customers[i];
    }
    cout<<set;
}