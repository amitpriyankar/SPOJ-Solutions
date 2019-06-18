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
 int T;
 cin>>T;
 
 while(T--)
 {
  int n;
  cin>>n;
  pair<int,int> pp[n];
  int a,b;
  for(int i=0; i<n; i++)
    cin>>pp[i].first>>pp[i].second;
  int l,p;
  cin>>l>>p;
  for(int i=0; i<n ;i++)
  {
    if(pp[i].first<l)
      pp[i].first=l-pp[i].first;
  }
  sort(pp,pp+n);
  priority_queue<int> pq;
  int i=0;
  int ans=0;
  while(p<l&&i<n)
  {
    while(pp[i].first<=p)
    {
      pq.push(pp[i].second);
      i++;
    }
    ans++;
    if(pq.empty())break;
    p+=pq.top();
    pq.pop();
  }
  if(p>=l)cout<<ans<<'\n';
  else cout<<"-1\n";

 }

  #ifndef ONLINE_JUDGE 
  clock_t end = clock();
  cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif 
  return 0;
}