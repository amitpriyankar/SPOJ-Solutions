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
  priority_queue<int> maxx; // for first half of the sorted array
  priority_queue<int,vector<int>,greater<int>> minn; // for second half of the sorted array
  while(1)
  {
    
    int n;
    cin>>n;
    if(n==0)break;
    else if(n==-1)
    {
      cout<<maxx.top()<<'\n';
      maxx.pop();
      if(maxx.size()!=minn.size())
      {
        if(maxx.size()>minn.size()+1)
        {
          minn.push(maxx.top());
          maxx.pop();
        }
        if(minn.size()>maxx.size())
        {
          maxx.push(minn.top());
          minn.pop();
        }
      }
    }
    else
    {
      if(maxx.empty())
      {
        maxx.push(n);
        continue;
      }
      if(n<=maxx.top())
        maxx.push(n);
      else 
        minn.push(n);
      if(maxx.size()!=minn.size())
      {
        if(maxx.size()>minn.size()+1)
        {
          minn.push(maxx.top());
          maxx.pop();
        }
        if(minn.size()>maxx.size())
        {
          maxx.push(minn.top());
          minn.pop();
        }
      }
    }
  }
 }

  #ifndef ONLINE_JUDGE 
  clock_t end = clock();
  cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif 
  return 0;
}