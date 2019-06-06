#include <bits/stdc++.h>
using namespace std;
#define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define M_PI 3.14159265358979323846

int main()
{
clock_t begin = clock();
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
tani_nachi_ke  
int n;
cin>>n;
int arr[n];
for(int i = 0; i < n; i++)
  cin>>arr[i];
int len = (int)sqrt(n + 0.1) + 1;
int dp[len];
//initialising the array
for(int i = 0; i < len; i++)
  dp[i] = INT_MAX;

//preprocessing
for(int i = 0; i < n; i++)
  dp[i/len] = min(dp[i/len], arr[i]);

int q,l,r;
cin>>q;

//queries solving
while(q--)
{
 
  cin>>l>>r;
  int c_l = l/len;
  int c_r = r/len;
  int ans = INT_MAX;
  if( c_l == c_r)
  {
    for(int i = l; i <= r; i++)
      ans = min(ans, arr[i]);
  }
  else
  {
    for(int i = l; i < (c_l + 1)*len; i++)
      ans = min(ans, arr[i]);
    for(int i = c_r*len; i <= r; i++)
      ans = min(ans, arr[i]);
    for(int i = c_l+1; i < c_r; i++)
      ans = min(ans, dp[i]);
  }
  cout<<ans<<'\n';
}

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
return 0;
}
