#include<bits/stdc++.h>
using namespace std;

int main()
    {
        string s="aabbaabaaab";
        string p="aab";

        for(int i=0;i<=s.length();i++){
            if(s[i]==p[0]){
                int c=1;
                for(int j=i+1,k=1;j<=s.length();j++,k++){
                    if(c==p.length()){
                        printf("founded\n");
                        break;
                    }
                    else if(p[k]==s[j])
                        c++;
                    else break;

                }
            }
        }

        return 0;
    }
