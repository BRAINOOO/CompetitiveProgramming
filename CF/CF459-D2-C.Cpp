#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int n,k,d,N,arr[1009][1009],id;
void bk(vector<int>  v)
{

    if(N==0)
        return ;
    if(sz(v)==d)
    {
        for(int i=0;i<sz(v);i++)
            arr[i][id]=v[i];
        id++;
        N--;
        return ;
    }
    for(int i=1;i<=k;i++)
    {
        v.pb(i);
        bk(v);
        v.pop_back();
    }
}
int main()
{
      cin>>n>>k>>d;
      N=n;
      if(k>=n)
    {
        for(int i=0;i<d;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<j<<" ";
            cout<<endl;
        }
        return 0;
    }
      ll s=1;
      int fl=0;
      for(int i=0;i<d;i++)
      {
          s*=k;
          if(s>=n)
          {
              fl=1;
              break;
          }
      }
      if(!fl)
      {
          cout<<"-1\n";
          return 0;
      }
      vector<int> v;
      bk(v);
      for(int i=0;i<d;i++)
      {
          for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
          cout<<endl;
      }
}
