#include<iostream>
#include<vector>
#include<string>

using namespace std;

int solve_tab(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
    for(int i = 1;i <= s1.length();i++){
        for (int j = 1; j <= s2.length(); j++)
        {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s1.length()][s2.length()];
}
int main(){
    string s;
    string t;
    cin>>s;
    cin>>t;
    vector<vector<int>> dp_t(s.length() + 1,vector<int>(t.length() + 1,0));
    cout<<"The solution using tabulation :"<<solve_tab(s,t,0,0,dp_t);
    return 0;
}