#include <bits/stdc++.h>
using namespace std;
#define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
int n,q;

int f[1000009];

int answer[200009],block_size,arr[30009];

pair <pair<int,int>,int> querry[200009];

inline bool mo_cmp( const pair<pair<int,int>,int> &x,const pair<pair<int,int>,int> &y)
{
  int xx=x.first.first/block_size;
  int yy=y.first.first/block_size;
  if(xx!=yy)return (xx<yy);
  else return (x.first.second<y.first.second);
}

 
int main()
{

 clock_t begin = clock();
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif

//  tani_nachi_ke

scanf("%d",&n);
for(int i=0; i<n; i++)scanf("%d",&arr[i+1]);
block_size=(int)sqrt(n);
// cout<<block_size<<endl;
scanf("%d",&q);
int aa,bb;
for(int i=0; i<q; i++)
{
    scanf("%d%d",&aa,&bb);
  querry[i]={{aa,bb},i};
}
sort(querry,querry+q,mo_cmp);
// for(int i=0; i<q; i++)cout<<querry[i].first.first<<" "<<querry[i].first.second<<endl;
int l=1,r=1;
f[arr[l]]++;
int ans=1;
for(int i=0; i<q; i++)
{
  int left=querry[i].first.first;
  int right=querry[i].first.second;
  int id=querry[i].second;
  while(l<left)
  {
    f[arr[l]]--;
    if(f[arr[l]]==0)ans--;
    l++;
  }
  while(left<l)
  {
      l--;
    f[arr[l]]++;
    if(f[arr[l]]==1)ans++;
    
  }
  while(r<right)
  {
    r++;
    f[arr[r]]++;
    if(f[arr[r]]==1)ans++;
  }
  while(right<r)
  {
    f[arr[r]]--;
    if(f[arr[r]]==0)ans--;
    r--;
  }
  answer[id]=ans;

}

for(int i=0; i<q; i++)printf("%d\n",answer[i]);
 
#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
return 0;
}
