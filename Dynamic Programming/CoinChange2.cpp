#include<bits/stdc++.h>

using namespace std;

int findCoinNum(int coins[],int numOfCoins,int money)
    {
        int values[money+1];
        memset(values,0,sizeof(values));
        values[0]=1;
        for(int i=0;i<numOfCoins;i++){
            for(int j=coins[i];j<=money;j++){
                values[j]+=values[j-coins[i]];
            }
        }
        return values[money];
    }

int main()
{
    int coins[]={1,2};
    int money=6;
    int numOfCoins=2;
    printf("%d\n",findCoinNum(coins,numOfCoins,money));
    return 0;
}
