#include<iostream>
#include<vector>
#include<string>

using namespace std;

// ? by using top down method (maemoization)
int solve_memo(string &s1,string &s2,int i,int j,vector<vector<int>> &  dp){
    if(i == s1.length() || j == s2.length()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    else{
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve_memo(s1,s2,i+1,j+1,dp);
        }
        else{
            return dp[i][j] = max(solve_memo(s1,s2,i,j+1,dp),solve_memo(s1,s2,i+1,j,dp));
        }
    }
}

int main(){
    string s;
    string t;
    cin>>s;
    cin>>t;
    vector<vector<int>> dp_m(s.length(),vector<int>(t.length(),-1));
    
    cout<<"The solution using memo :";
    cout<<solve_memo(s,t,0,0,dp_m)<<endl;
    
}