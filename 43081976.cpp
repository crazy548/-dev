#include<bits/stdc++.h>
using namespace std;

//#include<ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = (int)1e7+9;
#define REP0(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<=n;i++)
#define F first
#define S second
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define inf (int)(1e18)
#define prec(x) fixed<<setprecision(x)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

void fileio(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool check(ll mid,ll n,vector<ll>&candy,vector<ll>&balloons,ll m){
    ll add = 0;
    for(int i=0;i<n;i++){
        // balloons[i] = no of balloons  needed on a particular day
        // mid/candy[i] represents the no of candies that I can compensate for the balloons
        ll now = balloons[i] - (mid/candy[i]);
        add += max(now,0LL);
        if(add > m){
            return false;
        }
    }
    return true;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    // m => ballons that we have
    vector<ll> balloons(n),candy(n);    
    for(auto &x : balloons) cin>>x;
    for(auto &x : candy) cin>>x;

    ll low = 0;
    ll high = 1e18;

    while(low < high){
        ll mid = low + (high-low)/2;
        if(check(mid,n,candy,balloons,m)){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    cout<<low<<endl;
}


int main(){
    fastio;
    fileio();
    int tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
