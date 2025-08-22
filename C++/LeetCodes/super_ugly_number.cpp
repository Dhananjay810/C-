#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;
unordered_map<int,vector<int>> m;

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            // fac=i;
            return false;
        }
    } 
    return true;
}

int isprim(int n){
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return i;
            // return false;
        }
    }
    // return true;
}

bool ispre(vector<int>& v, unordered_set<int>& set){
    for(int i=0; i<v.size(); i++){
        if(set.find(v[i])==set.end()) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int mm;
    cin>>mm;
    unordered_set<int> set;
    for(int i=0; i<mm; i++){
        int num;
        cin>>num;
        set.insert(num);
    }
    int z=1;
    int h=2;
    m[1].push_back(1);
    if(n==1){
        cout<<1;
        return 0;
    }
    while(true){
        vector<int> f;
        if(isPrime(h)==true){
            f.push_back(h);
            m[h].push_back(h);
            // m[h]=f;
            bool flag=ispre(f,set);
            if(flag==true) z++;
            
            if(z==n){
                cout<<h;
                break;
            }
            else{
                h++;
                continue;
            }
        }
        int fac=isprim(h);
        // f.push_back(fac);
        // copy(m[fac].begin(), m[fac].end(), back_inserter(f));
        f=m[h/fac];
        f.push_back(fac);
        m[h]=f;
        
        bool flag=ispre(f,set);
        if(flag==true) z++;
        
        if(z==n){
            cout<<h;
            break;
        }
        h++;
    }
}