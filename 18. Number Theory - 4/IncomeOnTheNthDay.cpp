#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

ll fib(ll n)
{
    if (n == 0 || n == 1 || n == 5)
        return n;
    if (n == 2)
        return 1;
    n--;
    
    ll a[2][2] = {1, 1,
                  1, 0};
    ll ans[2][2] = {
        1, 0,
        0, 1};
    ll temp[2][2];
    ll m = mod - 1, i, j, k;
    while (n)
    {
        if (n & 1)
        {
            //ans=ans*a
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                {
                    temp[i][j] = 0;
                    for (k = 0; k < 2; k++)
                    {
                        temp[i][j] += a[i][k] * ans[k][j];
                        temp[i][j] %= m;
                    }
                }
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    ans[i][j] = temp[i][j];
        }
        //a=a*a
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                temp[i][j] = 0;
                for (k = 0; k < 2; k++)
                {
                    temp[i][j] += a[i][k] * a[k][j];
                    temp[i][j] %= m;
                }
            }
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                a[i][j] = temp[i][j];
        n >>= 1;
    }
    return ans[0][0];
}
ll mpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int t;
    ll a, b, c, n, i, x, y;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        if (n == 0)
            cout << a << endl;
        else if (n == 1)
            cout << b << endl;
        else
        {
            x = fib(n - 1);
            y = fib(n);
            //cout<<x<<" "<<y<<endl;
            c = mpow(a + 1, x) * mpow(b + 1, y);
            c--;
            c = c % mod;
            if (c < 0)
                c += mod;
            cout << c << endl;
        }
    }
    return 0;
}