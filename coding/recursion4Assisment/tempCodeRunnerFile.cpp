for(int i=0; i<f.size(); i++){
        int g=f[i];
        vector<int> x;
        for(int j=0; j<f.size(); j++){
            if(j!=i) x.push_back(f[j]);
        }
        ans.push_back(g);
        sum(x,ans,tar-g,idx+1);
    }