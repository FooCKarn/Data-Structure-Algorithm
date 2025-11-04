#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n,m;cin>>n>>m;
    map<long long,long long> mp;
    for(long long i = 0;i<n;i++){   
        long long a,b;
        cin>>a>>b;
        mp[b] = a;
    }
    for(long long i = 0 ;i<m;i++){
        long long x,y;
        cin>>x>>y;
        long long gfX = -1;
        long long gfY = -1;
        auto itX1  = mp.find(x);
        if(itX1!=mp.end()){
            long long tmpX = mp[x];
            auto itX2 = mp.find(tmpX);
            if(itX2!=mp.end()){
                gfX = mp[tmpX];
            }
        }
        auto itY1 = mp.find(y);
        if(itY1!=mp.end()){
            long long tmpY = mp[y];
            auto itY2 = mp.find(tmpY);
            if(itY2!=mp.end()){
                gfY = mp[tmpY];
            }
        }
        if(x!=y&&gfX!=-1&&gfY!=-1&&gfX==gfY){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}