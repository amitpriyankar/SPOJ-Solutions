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
  set<int> adj[n+1];
  priority_queue<pair<int,int>> pq;
  int arr[n];
  for(int i=0; i<n; i++)
    {
      cin>>arr[i];
      pq.push({arr[i],i+1});
    }
  int a,b;
  for(int i=0; i<n-1; i++)
  {
    cin>>a>>b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  for(int i=1; i<=n; i++)
  {
    vector<pair<int,int>> bin;
    while(1)
    {
      auto u = pq.top();
      int id = u.second;
      if(adj[i].find(id)==adj[i].end()&&id!=i)break;
      else 
      {
        bin.push_back(pq.top());
        pq.pop();
      }
    }
    cout<<(pq.top()).second<<" ";
    while(!bin.empty())
    {
      pq.push(bin.back());
      bin.pop_back();
    }
  }
  cout<<endl;
 }

  #ifndef ONLINE_JUDGE 
  clock_t end = clock();
  cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif 
  return 0;
}