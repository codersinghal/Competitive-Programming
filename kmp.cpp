KMP algo worstcase-O(n)
void kmp(string text,string pat)
{   int cnt=0;
    int n=text.length();
    int m=pat.length();
    int lps[m];
    computeLPS(pat,m,lps);
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cnt++;
            j=lps[j-1];
            
        }
        else
        if(i<n&&text[i]!=pat[j])
        {
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i++; 
        }
    }
    
}
void computeLPS(string pat,int m,int *lps)
{
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            if (len != 0) { 
                len = lps[len - 1]; 
  
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
