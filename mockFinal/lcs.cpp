#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> dp(505,vector<int>(505,0));
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a; cin>>a;
    cin.clear();
    string b; cin>>b;
    int la = a.size();
    int lb = b.size();
   
    for(int i = 1;i<=la;i++){
        for(int j=1;j<=lb;j++){
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[la][lb];
}