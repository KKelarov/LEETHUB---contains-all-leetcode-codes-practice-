class Solution {
public:
    int solve(string s,string t,int i,int j,vector<vector<int>>&v)
    {
        
        if(i==s.length() || j==t.length())
            return 0;
        else if(v[i][j]!=-1)
            return v[i][j];
        else if(s[i]==t[j])
            return v[i][j]=1+solve(s,t,i+1,j+1,v);
        else
            return v[i][j]=solve(s,t,i,j+1,v);
    }
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;
        vector<vector<int>>v(s.length()+1,vector<int>(t.length()+1,-1));
        for(int i=s.length();i>=0;i--)
        {
            for(int j=t.length();j>=0;j--)
            {
                if(i==s.length()||j==t.length())
                    v[i][j]=0;
            }
        }
        for(int i=s.length()-1;i>=0;i--)
        {
            for(int j=t.length()-1;j>=0;j--)
            {
                if(s[i]==t[j])
                {
                    cout<<"HI";
                    v[i][j]=1+v[i+1][j+1];
                }
                else
                    v[i][j]=v[i][j+1];
            }
            cout<<endl;
        }

         if(v[0][0]==s.length())
             return true;
        else
            return false;
    }
};