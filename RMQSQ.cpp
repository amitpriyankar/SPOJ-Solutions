#include <bits/stdc++.h>
using namespace std;
#define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define M_PI 3.14159265358979323846
int const N = 100009;
int const K = 17;
int logs[N+1],st[N][K+1];
int arr[N];
void preprocess(int n)
{
  logs[1] = 0;
  for(int i = 2; i <= N; i++)
    logs[i] = logs[i/2] + 1;

  for(int i = 0; i < n; i++)
    st[i][0] = arr[i];

  for(int j = 1; j <= K; j++)
  {
    for(int i = 0; i + (1<<j) <= n; i++)
      st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
  }
}

int querry(int l, int r)
{
  int j = logs[r - l + 1];
  return min(st[l][j], st[r - (1 << j) + 1][j]);
}
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
for(int i = 0; i < n; i++)
  cin>>arr[i];
preprocess(n);

int q,l,r;
cin>>q;
while(q--)
{
  cin>>l>>r;
  cout<<querry(l,r)<<'\n';
}

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
return 0;
}
