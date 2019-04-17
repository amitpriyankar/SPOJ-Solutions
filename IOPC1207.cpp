#include <bits/stdc++.h>
using namespace std;
#define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
int const N=100009;


void update(int tree[],int lazy[],int id,int l,int r,int tl,int tr)
{
  if(lazy[id]!=0)
  {
    tree[id]=r-l+1-tree[id];
    if(l!=r)
    {
      lazy[2*id]=!(lazy[2*id]);
      lazy[2*id+1]=!(lazy[2*id+1]);
    }
    lazy[id]=0;
  }
  if(l>r||l>tr||tl>r)return;
  if(l>=tl&&r<=tr)
  {
    tree[id]=r-l+1-tree[id];
    if(l!=r)
    {
      lazy[2*id]=!(lazy[2*id]);
      lazy[2*id+1]=!(lazy[2*id+1]); 
    }
    return;
  }
  int mid=(l+r)/2;
  update(tree,lazy,2*id,l,mid,tl,tr);
  update(tree,lazy,2*id+1,mid+1,r,tl,tr);
  tree[id]=tree[2*id]+tree[2*id+1];

}


int querry(int tree[],int lazy[],int id,int l,int r,int tl,int tr)
{
  if(l>r||l>tr||tl>r)return 0;
  if(lazy[id]!=0)
  {
    tree[id]=r-l+1-tree[id];
    if(l!=r)
    {
      lazy[2*id]=!(lazy[2*id]);
      lazy[2*id+1]=!(lazy[2*id+1]);
    }
    lazy[id]=0;
  }
  if(l>=tl&&r<=tr)return tree[id];
  int mid=(l+r)/2;
  return querry(tree,lazy,2*id,l,mid,tl,tr)+querry(tree,lazy,2*id+1,mid+1,r,tl,tr);
}
 
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
int q;
int nx,ny,nz;
cin>>nx>>ny>>nz;
cin>>q;
int treex[4*nx]={0},lazyx[4*nx]={0},treey[4*ny]={0},lazyy[4*ny]={0},treez[4*nz]={0},lazyz[4*nz]={0};
 
 
 int t;
 while(q--)
 {
  cin>>t;
  int i,j;
  if(t==0)
  {
    cin>>i>>j;
    update(treex,lazyx,1,0,nx-1,i,j);
  }
  if(t==1)
  {
    cin>>i>>j;
    update(treey,lazyy,1,0,ny-1,i,j);
  }
  if(t==2)
  {
    cin>>i>>j;
    update(treez,lazyz,1,0,nz-1,i,j);
  }
  if(t==3)
  {
    int x1,y1,z1,x2,y2,z2;
    cin>>x1>>y1>>z1>>x2>>y2>>z2;
    long long xx=(long long )querry(treex,lazyx,1,0,nx-1,x1,x2);
    long long yy=(long long )querry(treey,lazyy,1,0,ny-1,y1,y2);
    long long zz=(long long )querry(treez,lazyz,1,0,nz-1,z1,z2);
    long long fx=(long long )(x2-x1+1);
    long long fy=(long long )(y2-y1+1);
    long long fz=(long long )(z2-z1+1);

    // cout<<xx<<" "<<yy<<" "<<zz<<endl;
    // cout<<fx<<" "<<fy<<" "<<fz<<endl;
    cout<<xx*(fy-yy)*(fz-zz)+(fx-xx)*yy*(fz-zz)+(fx-xx)*(fy-yy)*zz+xx*yy*zz<<endl;
  }

 }
}

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
return 0;
}
