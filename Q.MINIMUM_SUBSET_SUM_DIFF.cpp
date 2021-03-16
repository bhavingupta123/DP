#include <bits/stdc++.h>
using namespace std;

bool dp[1001][1001];

vector<int> subset_sum(int arr[],int n,int sum)
{
    int i,j,k;
    vector<int> v;

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=sum;++j)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]];

            else
                dp[i][j]=dp[i-1][j];
        }
    }

    for(i=0;i<=sum/2;++i)
        if(dp[n][i]!=false)
            v.push_back(i );

        return v;
}

int main()
{
    int key,flag=0,i,s=-1,ans1=0,ele,f=-1,j,k,n,m,a,b,x,y,cnt1=0,ans3=0,ans=0,max1=0,cnt=0,sum=0;

    cin>>n;

    int arr[n];

    for(i=0;i<n;++i)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

    dp[n+1][sum+1];

     for (int i = 0; i <= n; i++)
        dp[i][0] = true;

     for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    vector<int> vv=subset_sum(arr,n,sum);

    int mn = INT_MAX;

    for(i=0;i<vv.size();++i)
        mn=min(mn,(sum-(2*vv[i])));

    cout<<mn;
    return 0;
}