#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
    vector<int> dp(3, 0);
    if (n == 1)
    {
        return 1;
    }

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[2] = dp[1] + dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<climbStairs(n)<<"\n";
    }
    return 0;
}

//! testcase 
// 4
// 2
// 3
// 44
// 1
//? expected output
// 2
// 3
// 1134903170
// 1