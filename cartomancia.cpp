// Código do competidor Carlos Cabral
#include <bits/stdc++.h>
using namespace std;
 
#define N 200010
#define M 1000010
#define INF 1000000020
#define INFLL 1000000000000000020
#define fi first
#define se second
#define pb push_back
#define LOG 20
#define SQRT 100
#define mod 1000000007
//#define ordered_set tree<pair<int,int>,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll; 
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef vector< ll > vl;
typedef vector< pll > vll;
typedef tuple< int, int, int> tiii;
typedef tuple< ll, ll, ll> tlll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,la,lb,ra,rb,i,t=1;
    string a,b,g;
    bool emp;

    //cin >> t;
    while(t)
    {
        t--;
        la=ra=lb=rb=0;
        emp=true;
        cin >> n;
        cin >> a >> b >> g;
        for(i=0;i<n;i++)
        {
            if(a[i]==b[i] && a[i]!='?')
                continue;
            if(g[i]=='?')
            {
                emp=false;
                ra++;
                rb++;
                continue;
            }
            if(a[i]=='?')
            {
                emp=false;
                ra++;
            }else
            {
                la+=(bool)(a[i]==g[i]);
                ra+=(bool)(a[i]==g[i]);
            }
            if(b[i]=='?')
            {
                emp=false;
                rb++;
            }else
            {
                lb+=(bool)(b[i]==g[i]);
                rb+=(bool)(b[i]==g[i]);
            }
        }
        if(la>rb)
        {
            cout << "Enzo" << endl;
        }else if(lb>ra)
        {
            cout << "Lobo" << endl;
        }else
        {
            cout << ((emp) ? "Empate" : "Indefinido") << endl;
        }
    }

    return 0;
}
