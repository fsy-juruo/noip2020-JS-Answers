// Might be the easiest-LOOKING t4 ever
//                      ^^^^^^^
// Though I still only did brute force
//                         --- Zzzyt

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007
typedef long long ll;

int n;
int c[500005];
int d[500005];
int k;
int w[15];

int stp[15];
int cur[15];
ll ans=0;

void dfs1(int dep){
	if(dep>=k){
		for(int i=0;i<k;i++){
			cur[i]=stp[i];
		}
		int flag=0;
		while(true){
			for(int i=0;i<n;i++){
				cur[c[i]]+=d[i];
				ans++;
				if(cur[c[i]]<0||cur[c[i]]>=w[c[i]]){
					flag=-1;
					break;
				}
			}
			if(flag==-1){
				return;
			}
			if(flag==0){
				bool flag2=true;
				for(int i=0;i<k;i++){
					if(cur[i]!=stp[i]){
						flag2=false;
						break;
					}
				}
				if(flag2){
					printf("-1");
					exit(0);
				}
				flag=1;
			}
		}
	}
	for(int i=0;i<w[dep];i++){
		stp[dep]=i;
		dfs1(dep+1);
	}
}

// prue brute force
void solver1(){
	dfs1(0);
	printf("%lld\n",ans);
}

bool loopflag=true;
int mx[11][500005],mi[11][500005];
int dr[15];

inline int Abs(int x){
	return x>0?x:-x;
}

int getst(){
	int ret=INF;
	for(int i=0;i<k;i++){
		int pmi=upper_bound(mi[i],mi[i]+n+1,cur[i])-mi[i];
		int pmx=upper_bound(mx[i],mx[i]+n+1,w[i]-1-cur[i])-mx[i];
		if(pmi!=n+1){
			ret=min(ret,pmi);
		}
		if(pmx!=n+1){
			ret=min(ret,pmx);
		}
	}
	return ret;
}

void dfs2(int dep){
	if(dep>=k){
		for(int i=0;i<k;i++){
			cur[i]=stp[i];
		}
		int tmp=getst();
		if(tmp==INF){
			if(loopflag){
				printf("-1");
				exit(0);
			}
			int mini=INF;
			for(int i=0;i<k;i++){
				if(dr[i]<0){
					mini=min(mini,(cur[i]-mi[i][n])/(-dr[i]));
				}
				else if(dr[i]>0){
					mini=min(mini,(w[i]-1-(cur[i]+mx[i][n]))/(dr[i]));
				}
			}
			for(int i=0;i<k;i++){
				cur[i]+=d[i]*mini;
			}
			ans+=(ll)n*mini;
			int tmp2=getst();
			if(tmp2==INF){
				for(int i=0;i<k;i++){
					cur[i]+=d[i];
				}
				ans+=n;
				ans+=getst();
			}
			else{
				ans+=tmp2;
			}
		}
		else{
			ans+=tmp;
		}
	}
	for(int i=0;i<w[dep];i++){
		stp[dep]=i;
		dfs2(dep+1);
	}
}

// I wonder if I can finish...
void solver2(){
	for(int i=1;i<=n;i++){
		int cc=c[i-1];
		cur[cc]+=d[i-1];
		for(int j=0;j<k;j++){
			mi[j][i]=mi[j][i-1];
			mx[j][i]=mx[j][i-1];
		}
		if(cur[cc]>mx[cc][i]){
			mx[cc][i]=cur[cc];
		}
		if(-cur[cc]>mi[cc][i]){
			mi[cc][i]=-cur[cc];
		}
	}
	for(int i=0;i<k;i++){
		if(cur[i]!=0){
			loopflag=false;
		}
		dr[i]=cur[i];
	}
	dfs2(0);
	printf("%lld\n",ans);
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	int maxw=-1;
	for(int i=0;i<k;i++){
		scanf("%d",w+i);
		maxw=max(maxw,w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d%d",c+i,d+i);
		c[i]--;
	}
	if(maxw<=10){
		solver1();
	}
	else{
		// probably WA
		solver2();
	}
	
	return 0;
}

