//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

int cutRod(int price[], int n) {
    
    int t[n+1][n+1],i,j,k;
    
    for(i=0;i<n+1;++i)
        for(j=0;j<n+1;++j)
            if(i==0 || j==0)
                t[i][j]=0;
    
    for(i=1;i<n+1;++i)
    {
        for(j=1;j<n+1;++j)
        {
            if(i<=j)
            {
                t[i][j] = max(price[i-1] + t[i][j-i] , t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    
    return t[n][n];
}