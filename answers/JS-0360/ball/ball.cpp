#include<bits/stdc++.h>
#define MAX 500
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
int n,m,a[MAX+5][MAX+5],k,pin=1,x,y,top[MAX+5];
vector<pii>ans;
void run(int i,int j)
{
	swap(a[i][top[i]--],a[j][top[j]++]);
	ans.push_back(mp(i,j));
	k++;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    scanf("%d",&a[i][j]);
    for(int i=1; i<=n; i++) top[i]=m; top[n+1]=1;
    while(true)
    {
    	int mask=1,flag=0;
    	for(int i=1; i<=n; i++)
    	for(int j=1; j<=m; j++)
    	mask&=(a[i][j]==i);
    	if(mask) break;
    	for(int i=pin+1; i<=n; i++)
    	if(!flag)
    	for(int j=1; j<=m; j++)
    	if(a[i][j]==pin) { x=i,y=j; flag=1; break; }
        for(int i=1; i<=m-y; i++) run(x,n+1);
        int TOP=top[n+1];
    	for(int i=1; i<=m-TOP; i++) run(pin,n+1);
    	int pos=0;
    	run(x,n+1);
    	for(int i=1; i<=n; i++)
		{ 
    	if(a[pin][i]!=pin) break; else pos=i;
        }
        top[pin]++;
        for(int i=1; i<=m-pos; i++) run(x,pin);
        top[pin]--;
        top[n+1]--; run(n+1,pin);
        TOP=top[x]; top[x]++; top[n+1]++;
        for(int i=1; i<=m-TOP; i++) run(n+1,x); top[x]--;
        TOP=top[pin];
        for(int i=1; i<=m-TOP; i++) run(n+1,pin);
        top[n+1]++; top[pin]--;
	}
	printf("%d\n",k);
	for(int i=0; i<k; i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
