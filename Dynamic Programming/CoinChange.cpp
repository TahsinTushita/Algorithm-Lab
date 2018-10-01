#include<bits/stdc++.h>
using namespace std;



int mincoins(int coins[],int m,int v)
    {
        int table[v+1];
        memset(table,999999,sizeof(table));
        table[0] = 0;

        for(int i=1;i<=v;i++){
            for(int j=0;j<m;j++){
                if(coins[j]<=i){
                    int sub_res = table[i-coins[j]];
                    if(sub_res!=999999 && sub_res+1<table[i])
                        table[i] = sub_res+1;
                }
            }
        }
        return table[v];
    }

int main()
    {
        int coins[] = {1,2};
        int m = sizeof(coins)/sizeof(coins[0]);
        int v = 3;
        cout<<"Minimum number of coins: "<<mincoins(coins,m,v);
        return 0;
    }
