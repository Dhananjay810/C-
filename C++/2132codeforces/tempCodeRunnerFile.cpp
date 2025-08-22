    ans++;
                int f=y/i;
                string cc="";
                for(int j=1; j<=f; j++){
                    for(int u=0; u<i; u++){
                        if(j%2!=0) cc=cc+to_string(a);
                        else cc=cc+"0";
                    }
                }
                ss.push_back(cc);