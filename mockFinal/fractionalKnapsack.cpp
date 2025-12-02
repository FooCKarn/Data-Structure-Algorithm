#include<bits/stdc++.h>
using namespace std;
struct item{
    double val;
    double w;
    double ratio;
    bool operator<(const item &x) const{
        return ratio > x.ratio;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    double w; int n;
    cin>>w>>n;
    vector<item> v(n);
    for(int i = 0;i<n;i++) cin>>v[i].val;
    for(int i = 0;i<n;i++){
        cin>>v[i].w;
        v[i].ratio = v[i].val/v[i].w;
    }
    sort(v.begin(),v.end());
    double curw = 0.0;
    double curv = 0.0;
    for(int i = 0;i<n;i++){
        if(curw + v[i].w<=w){
            curw+=v[i].w;
            curv+=v[i].val;
        }
        else{
            double remain = w - curw;
            double tmp = remain / v[i].w;
            curv += (v[i].val * tmp);
            break;
        }
    }
    cout<<fixed<<setprecision(4)<<curv;
}