// is it possible to make the subset which sum is equal to the given sum

// recursive code-

#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;


bool rec(vector<int> arr,int n, int sum){/* n is size of the array*/
    //high value to the lower value -- n-1 to 0 and sum to 0
    if (sum==0)return true; 
    else if (arr[n-1]==0)return false ;
    // choice 
    if (arr[n-1]<=sum){ // can take or not take 
        //return the or of take and not take ( if anyway we are getting true then true)
        
        return rec(arr,n-1, sum-arr[n-1]) || rec(arr, n-1, sum); 
    }
    else {// arr element is greater than the given sum then not able to take 
        return rec(arr,n-1, sum); 
    }
}
//dp  --  optimization  --
//1  --  memoization code  --

int dp[25][325]; //initiaisez with -1 

int memo(vector<int> arr, int n, int sum){// same as recursion but store the previous calculations 
    if (sum==0){
        return dp[n][sum]=1;
    }
    else if (n==0){
        return dp[n][sum]=0;
    }
    if (dp[n][sum]!=-1)return dp[n][sum];
    
    if (arr[n-1]<=sum){
        return dp[n][sum]= (int)(memo(arr,n-1,sum-arr[n-1])|| memo (arr,n-1,sum)); 
    }
    else {
        return dp[n][sum]= int (memo (arr, n-1 , sum));
    }
    // return dp[n][sum];
}
// tabulation -- top down approach

int tab(vector<int> arr,int n, int sum){
    int dp[n+1][sum+1]={};

     // Initialize base case: sum 0 is always possible
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;  // true (int 1)
    }

    // Fill the table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}




int main() {
    vector<int> arr={2,3,5,8,12};
    int sum=11;
    memset(dp,-1,sizeof(dp));

    rec(arr,arr.size(),sum)==1?cout<<"yes we can make! \n":cout<<" can't make !\n";
    memo(arr,arr.size(),sum)==1? cout<<"yes we can make! \n":cout<<" can't make !\n";
    tab(arr,arr.size(),sum)==1? cout<<"yes we can make! \n":cout<<" can't make !\n";
    cout<<" code execution successfull";
    return 0;
}