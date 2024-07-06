#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int n=enemyEnergies.size();
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(currentEnergy<enemyEnergies[0]) return 0;
        int i=0;
        int j=n-1;
        long long point=0;
        while(i<=j){
            if(currentEnergy>=enemyEnergies[i]){
                currentEnergy -=enemyEnergies[i];
                point++;
            }
            else{
                currentEnergy += enemyEnergies[j];
                j--;
            }
        }
        return point;
    }

int main(){
    vector<int> enemyEnergies={3,2,2};
    int currentEnergy=2;
    cout<<maximumPoints(enemyEnergies,currentEnergy);
}