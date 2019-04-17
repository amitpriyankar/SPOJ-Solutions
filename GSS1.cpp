                #include <bits/stdc++.h>
                using namespace std;
                #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
                typedef long long ll;
                int const N=500009;

                struct data
                {
                  ll sum,prev,suff,ans;
                };

                data tree[4*N];
                ll arr[N];

                data combine(data l,data r)
                {
                    data temp;
                    temp.sum=l.sum+r.sum;
                    temp.prev=max(l.prev,l.sum+r.prev);
                    temp.suff=max(r.suff,l.suff+r.sum);
                    temp.ans=max(l.suff+r.prev,max(l.ans,r.ans)); 
                    return temp;
                }

                data make_data(ll val)
                {
                  data temp;
                  temp.sum=val;
                  temp.prev=val;
                  temp.suff=val;
                  temp.ans=val;
                  return temp;
                }


    
                void build(int id,int l,int r)
                {
                  if(l==r)tree[id]=make_data(arr[l]);
                  else
                  {
                    int mid=(l+r)/2;
                    build(2*id,l,mid);
                    build(2*id+1,mid+1,r);
                    tree[id]=combine(tree[2*id],tree[2*id+1]);
                  }

                }


                data querry(int id,int l,int r,int tl,int tr)
                {
                  if(tl>r||tr<l)return make_data(-1e14);
                  if(tl<=l&&r<=tr)return tree[id];

                  int mid=(l+r)/2;
                  return combine(querry(2*id,l,mid,tl,tr),querry(2*id+1,mid+1,r,tl,tr));
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
                  for(int i=1; i<=n; i++)cin>>arr[i];
                  build(1,1,n);
                  int q;
                  cin>>q;
                  int aa,bb;
                  while(q--)
                  {
                      cin>>aa>>bb;
                    
                      cout<<querry(1,1,n,aa,bb).ans<<endl;
                  }
                 
                
             
          
                #ifndef ONLINE_JUDGE 
             clock_t end = clock();
             cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
             #endif 
                return 0;
                }
                

            