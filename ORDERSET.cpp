#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds;
using namespace std;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 

#define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);



int main()
{
    clock_t begin = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    tani_nachi_ke

    new_data_set p;
    int Q;
    cin>>Q;
    while(Q--)
    {
        char c;
        cin>>c;
        int x;
        cin>>x;
        if(c=='I')
            p.insert(x);
        else if(c=='C')
            cout<<p.order_of_key(x)<<'\n';
        else if(c=='D')
            p.erase(x);
        else
        {
            if(x>p.size())
                cout<<"invalid\n";
            else
                cout<<*p.find_by_order(x-1)<<'\n';
        }
    }


    #ifndef ONLINE_JUDGE 
    clock_t end = clock();
    cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
    }