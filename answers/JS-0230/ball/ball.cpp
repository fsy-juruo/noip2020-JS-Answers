#include<bits/stdc++.h>
#include<stdint.h>
#define FILEIO(x) do{freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);}while(0)
using namespace std;
template<typename T>
void ri(T&x)
{
	x=0;
	int neg=1;
	char c=getchar();
	for (;!(isdigit(c)||c=='-');c=getchar());
	if (c=='-') neg=-1,c=getchar();
	for (;isdigit(c);c=getchar()) x=x*10+c-48;
	x*=neg;
}
#ifdef MYDBG
#define DEBUG(x) cerr<<#x<<":"<<x<<" "
#define DEBUGL(x) cerr<<#x<<":"<<x<<endl
#else
#define DEBUG(x)
#define DEBUGL(x)
#endif
const int MAXN=55;
const int MAXM=405;
int ball[MAXN][MAXM];
int cnt[MAXN],top[MAXN];
int n,m;
vector<pair<int,int> > ans;
void moveBall(int y,int x)
{
    ball[x][top[x]++]=ball[y][--top[y]];
    ans.push_back(make_pair(y,x));
}
void moveBalls(int x,int y,int k)
{
    while(k--) moveBall(x,y);
}
int trans(int k,int c,int x)
{
    int pos=m-1;
    while(pos>=0&&ball[k][pos]!=c) pos--;
    if (pos<0) return 0;
    moveBalls(k,n,m-pos-1);
    //cerr<<"!"<<endl;
    int pos2=0;
    while(ball[x][pos2]==x&&pos2<m) pos2++;
    if (m-top[n]>=m-pos2){
        moveBalls(x,n,m-pos2);
        moveBall(k,x);
        //cerr<<"@"<<endl;
    }
    else {
            //cerr<<n<<" "<<m<<" "<<top[k]<<" "<<k<<" "<<top[x]<<" "<<x<<endl;
        int t=m-top[n]-1;
        moveBalls(x,n,m-top[n]-1);
        moveBall(k,n);
    //cerr<<n<<" "<<m<<" "<<top[k]<<" "<<k<<" "<<top[x]<<" "<<x<<endl;
        moveBalls(x,k,m-pos2-t);
        moveBall(n,x);
        //cerr<<"*"<<endl;
    }
    //cerr<<n<<" "<<m<<" "<<top[k]<<" "<<k<<" "<<top[x]<<" "<<x<<endl;
    moveBalls(n,k,m-top[k]);
    moveBalls(n,x,m-top[x]);
    return 1;
}
void solve(int k)
{
    int x=ball[k][0];
    for (int i=k+1;i<n;i++)
    {
        while(trans(i,x,k));
    }
    cerr<<k<<endl;
}
int main()
{
	FILEIO("ball");
	ri(n),ri(m);
	for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            ri(ball[i][j]);
    for (int i=0;i<n;i++)
        top[i]=m;
    for (int i=0;i<n-1;i++)
        solve(i);
    printf("%d\n",int(ans.size()));
    for (int i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    }
	return 0;
}
