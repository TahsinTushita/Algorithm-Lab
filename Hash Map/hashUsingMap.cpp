#include<bits/stdc++.h>
using namespace std;

map<string,int> m;

int main(){

    string s;
    while(cin>>s){
        if(s[0]=='T')
            m[s]++;

        cout<<"\n";

    for(auto it:m){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    cout<<"\n";

    }

    return 0;
}
