//COINT CHANGE no. of ways to get sum
//https://practice.geeksforgeeks.org/problems/coin-change2448/1

class Solution
{
  public:
    long long int count( int coin[], int n, int sum )
    {
       long long int i,j,k,t[n+1][sum+1];
       
       t[0][0]=0;
       
       for(i=0;i<n+1;++i)
        for(j=0;j<sum+1;++j)
        {
            if(i==0)
                t[i][j]=0;
        }
        
        for(i=0;i<n+1;++i)
            for(j=0;j<sum+1;++j)
            {
                if(j==0)
                    t[i][j]=1;
            }
        
         t[0][0]=0;
        
        for(i=1;i<n+1;++i)
        {
            for(j=1;j<sum+1;++j)
            {
                if(coin[i-1]<=j)
                    t[i][j] = t[i-1][j] + t[i][j - coin[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][sum];
       
    }
};