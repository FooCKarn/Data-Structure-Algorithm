#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a; cin>>n>>a;
    vector<ll> chef(n+1);
    for(int i = 1;i<=n;i++) cin>>chef[i];
    while(a--){
        ll k;cin>>k;
        ll l = 0;
        ll r = 1e15;
        ll ans = 0;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll sum = 0;
            for(int i = 1;i<=n;i++){
                sum += (1+ (mid/chef[i]));
                if(sum>=k) break;
            }
            if(sum>=k) {r = mid-1;ans = mid;}
            else l = mid+1;
        }
        cout<<ans<<"\n";
    }
}