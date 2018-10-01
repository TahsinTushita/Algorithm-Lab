#include<bits/stdc++.h>
using namespace std;

int main()
    {

        int arr[]={10,20,30,1,29,40,30,5,1};
        int n=sizeof(arr)/sizeof(arr[0]);
        int lis[n+1];
        fill(lis,lis+n+1,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(lis[j]+1>lis[i]){
                        lis[i]=lis[j]+1;
                    }
                }
            }
        }
        int m=0;
        for(int i=0;i<n;i++){
            if(lis[i]>m)
                m=lis[i];
        }
        printf("%d\n",m);
        vector<int> v;

        for(int i=n-1;i>=0;i--){

                if(lis[i]==m){
                    v.push_back(arr[i]);
                    m--;
                }

        }

        for(int i=v.size()-1;i>=0;i--){
            printf("%d ",v[i]);
        }

        return 0;
    }
