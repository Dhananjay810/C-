 else{
            if(ch!=s[i-1]){
                string l=s.substr(0,i);
                string r=s.substr(i+1);
                per(ans+ch,l+r);
            }
        }