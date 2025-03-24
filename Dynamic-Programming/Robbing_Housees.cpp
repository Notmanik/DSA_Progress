#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constants
const int INF = 1e9;
const ll LINF = 1e18;

// Debugging
#define debug(x) cout << #x << " = " << (x) << endl;
#define print_vec(v) for (auto x : v) cout << x << " "; cout << endl;
//? using tabulation
int max_house(vectpr<int> &house,int n){
    vector<int> dp(n);
    if(n == 0) return 0;
    if(n == 1) return house[0];
    dp[0] = house[0];
    dp[1] = max(dp[0],house[1]);
    for(int i = 2;i<n;i++){
        dp[i] = max(dp[i-1] , dp[i-2] + house[i]);
    }
    return dp[n-1];
}
//? using memoization

// Main function
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    vector<int> house(n);
    for(auto & x: house) cin>>x;
    cout<<"The maximum ammount the robber can steal is :"<<max_house(house,n)<<endl;
    return 0;
}
