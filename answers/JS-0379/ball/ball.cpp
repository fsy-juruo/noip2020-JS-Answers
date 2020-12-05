#include<bits/stdc++.h>
#define F(i,l,r) for(int i=l;i<=r;i++)
#define D(i,l,r) for(int i=l;i>=r;i--)
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define p_b push_back
#define m_p make_pair
#define fi first
#define se second
using namespace std;
int fr() {
	int x=0,f=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int INF=0x7f7f7f7f,N=1e4+5;
int n,m;
vector<int> a[55];
vector<pair<int,int> > ans;
void work() {
	int now=1;
	while(1) {
		int tp;
		while(a[now].size()) {
			int x=a[now].back();
			a[now].pop_back();
			a[n+1].push_back(x);
			ans.p_b(m_p(now,n+1));
			if(a[n+1].size()==m) break;	
		}
		tp=a[n+1].back();
//		cout<<tp<<" "<<now<<endl;
		F(i,now+1,n+1) {
			while(a[i].back()==tp) {
				a[i].pop_back();
				a[now].push_back(tp);
				ans.push_back(m_p(i,now));
			}
		}
		F(i,now+1,n+1) {
			while(1) {
				int pos=1;
				bool flag=0;
				F(j,0,(int)a[i].size()-1) {
//					printf("%d %d %d %d %d\n",now,i,j,a[i][j],tp);
					if(a[i][j]==tp) {
						flag=1;
						break;
					}
				}
				if(!flag) break;
				while(a[i].back()!=tp) {
					int num=a[i].back();
					a[i].pop_back();
					while((int)a[pos].size()==m||pos==i) pos++;
					a[pos].push_back(num);
					ans.push_back(m_p(i,pos));
				}
				while((int)a[pos].size()==m||pos==i||pos==now) pos++;
				a[i].pop_back();
				a[pos].push_back(tp);
				ans.push_back(m_p(i,pos));
				int ls=pos;
				pos=1;
				while(a[now].back()!=tp) {
					int num=a[now].back();
					a[now].pop_back();
					while((int)a[pos].size()==m||pos==now) pos++;
					a[pos].push_back(num);
					ans.push_back(m_p(now,pos));
				}
				a[ls].pop_back();
				a[now].push_back(tp);
				ans.push_back(m_p(ls,now));
			}
		}
		if(now==n) break;
		now++;
	}
}
int main() {
	freopen("ball2.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=fr(),m=fr();
	F(i,1,n) F(j,1,m) a[i].p_b(fr());
	work();
	printf("%d\n",(int)ans.size());
	F(i,0,(int)ans.size()-1) {
		printf("%d %d\n",ans[i].fi,ans[i].se);
	}
	return 0;
}
/* 
2 2 2 2 2 2 2 2 1 1 2
1 1 1 1 1 2 1 2 1 2 1 1 2 1 1 2 1 1
2 2 2 2 1 2 2 2 1 1 1 1 1 1
*/
