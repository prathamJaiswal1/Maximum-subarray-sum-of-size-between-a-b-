// my cf template
#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve() {
    // Your solution code goes here
    int n,a,b;cin>>n>>a>>b;

    vector<int>ps(n+1,0);
    for(int i=1; i<=n; i++){
        int ele;cin>>ele;
        ps[i]=ps[i-1]+ele;
    }

    set<pair<int,int>>st;
    for(int i=a; i<=b; i++){
        st.insert({ps[i],i});
    }

    int ans=-1e18;

    for(int i=1; i<=(n-a+1); i++){
        ans=max(ans,st.rbegin()->first - ps[i-1]);
        st.erase({ps[i+a-1],i+a-1});
        if(i+b <= n){
            st.insert({ps[i+b],i+b});
        }
    }
    cout<<ans<<endl;
}
   int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    // int t ;cin >> t;while(t--){solve();}
  solve();
    return 0;
}