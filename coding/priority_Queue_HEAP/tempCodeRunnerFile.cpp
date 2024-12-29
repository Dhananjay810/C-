#include<iostream>
#include<queue>
using namespace std;
int main(){
    vector<int> v={10,20,-4,6,18,24,105,118};
    int k=4;
    int hig=v.size()-k;
    priority_queue<int> pq;
    for(int i=0; i<v.size(); i++) pq.push(v[i]);
    for(int i=0; i<k; i++); pq.pop();
    cout<<pq.top();
}