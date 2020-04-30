//code for matrix exponentiation
//only matrix mat and temp will be changed and dimensions will be changed
ll mat[4][4]={{2,3,1,0},{1,0,0,0},{0,0,7,7},{0,0,0,7}};
ll res[4][4]{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
ll temp[4][4]={{2,3,1,0},{1,0,0,0},{0,0,7,7},{0,0,0,7}};
ll iden[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
void mul(ll result[4][4],ll a[4][4],ll b[4][4] )
{   
    ll re[4][4]={0};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            re[i][j]=(re[i][j]+a[i][k]*b[k][j]%mod)%mod;
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        result[i][j]=re[i][j];
    }
}
void  power(ll n)
{
    while(n>0)
    {
        if(n&1)
        mul(res,res,mat);
        mul(mat,mat,mat);
        n=n/2;
    }
}
int main()
 {
    ll t;
    cin >> t;
    ll c=t;
    while(t--)
    {    
          for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        res[i][j]=iden[i][j];
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        mat[i][j]=temp[i][j];
    }
    
    power(n);
 }
