class Solution {
public:

bool is_pal(string &s, int l, int r)
{
    while(l < r)
    {
        if(s[l] != s[r])
        {
            return false;
        }
        else
        {
            l++;
            r--;
        }
    }
    
    return true;
}
int minCut(string s) {
    
    int i, j, n = s.size();
    
    vector<int> dp(n, INT_MAX);
    
    for(i=0; i<n; i++)
    {
        if(is_pal(s,0, i))
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i-1]+1;
        }
        
        for(j=i; j> 0; j--)
        {
            if(dp[i] == 1)
            {
                break;
            }
            if(is_pal(s,j,i))
            {
                dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
    }
    
    return dp[n-1];
    
}
};