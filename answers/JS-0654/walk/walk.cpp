#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
const int inf=1000000000;
const int mod=1000000007;
const ll infll=1000000000000000000ll;
const ll modll=1000000007ll;

const int maxk=15,maxn=500005;
int n,k,ans;
int c[maxn],d[maxn];
int a[maxk],w[maxk],P[maxk],change[maxk];


int calc() {
	int ret=0;
	for(int t=1;;t++) {
		for(int i=1;i<=n;i++) {
			int na=a[c[i]]+d[i];
			a[c[i]]=na;
			ret++;
			if(na<1||na>w[c[i]]) return ret;
		}
		if(t==1) {//ע����ʱ�γ�ѭ��,����ѭ��֮ǰ�ͳ����� 
			for(int i=1;i<=n;i++)
				change[c[i]]+=d[i];
			bool flag=true;
			for(int i=1;i<=k;i++)
				if(change[i]!=0) {
					flag=false;
					break;
				}
			if(flag) return -1; 
		}
	} 
}

int dfs(int p) {
	if(p==k+1) {
		for(int i=1;i<=k;i++) a[i]=P[i];
		int rec=calc();		
		if(rec==-1)	return 1;
		ans+=rec;
		ans%=mod;
	}
	for(int i=1;i<=w[p];i++) {
		P[p]=i;
		if(dfs(p+1)) return 1;
	}
	return 0;
}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	int maxw=0;
	for(int i=1;i<=k;i++) {
		scanf("%d",&w[i]);
		maxw=max(maxw,w[i]);
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i],&d[i]);
	if(maxw>=inf) {
		printf("-1\n");
		return 0;
	}
	if(dfs(1)) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans);
	return 0;
}
