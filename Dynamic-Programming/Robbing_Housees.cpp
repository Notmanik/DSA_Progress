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
int max_house(vector<int> &house,int n,vector<int> & dp){
    if(n == 0) return 0;
    if(n == 1) return house[0];
    
    dp[0] = house[0];
    dp[1] = max(house[0],house[1]);
    for(int i = 2;i<n;i++){
        dp[i] = max(dp[i-1] , dp[i-2] + house[i]);
    }
    return dp[n-1];
}
//? if the houses are in circle
int robLinear(vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0;
    for (int i = start; i <= end; i++) {
        int take = nums[i] + prev2;
        int notTake = prev1;
        int cur = max(take, notTake);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
// Main function
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    vector<int> nums(n);
    vector<int> dp(n);
    for(auto & x: nums) cin>>x;
    // cout<<"The maximum ammount the robber can steal is :"<<max_house(nums,n,dp)<<endl;
    // print_vec(dp);
    cout<<"The solution for the problem 2 is :"<<max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    return 0;
}
