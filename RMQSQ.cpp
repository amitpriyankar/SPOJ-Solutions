#include <bits/stdc++.h>
using namespace std;
#define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define M_PI 3.14159265358979323846
int const N = 100009;
int tree[4*N],arr[N];

void build(int l, int r, int node)
{
  if(l == r)
    {
      tree[node] = arr[l];
      return;
    }

  int mid = (l + r)/2;
  build(l, mid, 2*node);
  build(mid+1, r, 2*node + 1);
  tree[node] = min(tree[2*node], tree[2*node+1]);
}

int querry(int l, int r, int node, int tl, int tr)
{
  if(l>tr || r<tl)
    return INT_MAX;
  else if(l>=tl && r<=tr)
    return tree[node];
  else
  {
    int mid = (l + r)/2;
    return min(querry(l, mid, 2*node, tl ,tr), querry(mid+1, r, 2*node+1, tl, tr));
  }

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
for(int i = 1; i <= n; i++)
  cin>>arr[i];
build(1, n, 1);

int q,l,r;
cin>>q;
while(q--)
{
  cin>>l>>r;
  l++; r++;
  cout<<querry(1, n, 1, l, r)<<endl;
}

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
return 0;
}
