#include<bits/stdc++.h>
using namespace std;
struct mon{
    int pos;
    int hp;
    bool operator<(const mon &x) const{
        return pos < x.pos;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,w;
    cin>>n>>m>>k>>w; 
    vector<int> tpos;
    int p[m+1];
    int h[m+1];
    int totalHp = 0;
    for(int i = 1;i<=m;i++) cin>>p[i];
    for(int i = 1;i<=m;i++) {cin>>h[i]; totalHp += h[i]; }
    for(int i = 1;i<=k;i++) {
        int p; cin>>p;
        tpos.push_back(p);
    }
    sort(tpos.begin(),tpos.end());
    vector<mon> enemy;
    for(int i = 1;i<=m;i++){
        enemy.push_back({p[i],h[i]});
    }
    sort(enemy.begin(),enemy.end());
    int atk = 0;
    int mon_idx=0;
    for(int i = 0;i<tpos.size();i++){
        int l = tpos[i] - w;
        int r = tpos[i] + w;
        while(enemy[mon_idx].pos<l && mon_idx<m) mon_idx++;
        if(mon_idx>=m) break;
        if(enemy[mon_idx].pos<r){
            atk++;
            enemy[mon_idx].hp--;
        }
        if(enemy[mon_idx].hp==0) mon_idx++;
        if(enemy[mon_idx].pos>r) continue;
    }
    cout<<totalHp - atk;
}