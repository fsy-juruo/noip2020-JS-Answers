#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!='-' and (ch>'9' or ch<'0')) ch=getchar();
	if(ch=='-') f=-f,ch=getchar();
	while(ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define nn 50*405+2
int n,m;
int head[nn],nxt[nn],color[nn],bel[nn];
int tot;
vector<int> have[nn],mx,my;
int one(int c){
	++tot;color[tot]=c;bel[c]=0;
	have[c].push_back(tot);return tot;
}
set<int> emp;int cnt[nn];
void put(int p,int c){
	if(cnt[p]>=m) assert(0);
	if(bel[c]) mx.push_back(bel[c]),my.push_back(p);
	cnt[bel[c]]--;if(cnt[bel[c]]==m-1) emp.insert(bel[c]);
	head[bel[c]]=nxt[c];
	
	nxt[c]=head[p],head[p]=c;
	cnt[p]++;bel[c]=p;
	if(cnt[c]>=m) emp.erase(c);
}
int ds[nn],id[nn];
int cmp(int x,int y){
	return ds[x]<ds[y];
}
int fb(){
	int sos=0;for(int i=1;i<=n;i++) ds[i]=0;
	for(int i=1;i<=n;i++){
		int u=1,x=head[i];
		while(x) ds[color[x]]+=u,u++,x=nxt[x];
	}
	for(int i=1;i<=n;i++) if(sos==0 or ds[i]<ds[sos]) sos=i;
	return sos;
}
void swapcolor(int x,int y){
	for(int i=1;i<=tot;i++) if(color[i]==x) color[i]=y;else if(color[i]==y) color[i]=x;
}

int drop(int x){
	assert(emp.size());
	int y=*emp.begin();put(y,x);
	return y;
}
void bandrop(int x,int z){
	while(1){
		assert(emp.size());
		int y=*emp.begin();
		if(color[head[y]]==n or y==z){
			emp.erase(y);
			continue;
		}
		put(y,x);
		break;
	}
}
void cleanpillar(int x){
	while(head[x]) drop(head[x]);
	emp.insert(x);
}

int useful[nn];
#define pii pair<int,int>
#define mp make_pair
vector<pii> find(int x){
	vector<pii> v;
	for(int i=1;i<=n;i++){
		int y=head[i];int o=0;
		while(y) {
			++o;
			if(color[y]==x) v.push_back(mp(o,y));
			y=nxt[y];
		}
	}
	
	return v;
}
int ontop[nn];
void fullfill(int x,int y){
	while(head[x] and cnt[y]<m)
	put(y,head[x]);
}
void newemp(){
	emp.clear();
	for(int i=1;i<=n+1;i++) if(cnt[i]<m) emp.insert(i);
}
signed main(){
	freopen("ball.in","r",stdin);freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+1;i++) emp.insert(i);
	for(int i=1;i<=n;i++){
		int c;
		for(int j=1;j<=m;j++) scanf("%d",&c),put(i,one(c));
	}
	while(n>1){
		cleanpillar(n+1);int x=fb();
		
		swapcolor(x,n);
		for(int i=1;i<=n+1;i++) useful[i]=0;
		for(int i=0;i<have[n].size();i++) 
			useful[bel[have[n][i]]]=1;
		
		set<int> os;
		for(int i=1;i<=n+1;i++) if(!useful[i]) os.insert(i);
		vector<pii> v=find(n);
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		
		for(int i=0;i<v.size();i++){
			int x=v[i].second;if(v[i].first==1) continue;
			while(head[bel[x]]!=x){
				int y=head[bel[x]];
				if(color[y]==n){
					int u=*os.begin();
					os.erase(u);
					if(head[u]) bandrop(head[u],bel[x]);
					put(u,y);
					int goal=0;
					for(int i=1+n,goal=0;i>=1;i--) if(color[head[i]]==n){
						if(!goal and color[head[i]]==n) goal=i;
						while(goal!=i and color[head[i]]==n and cnt[goal]<m) 
							put(goal,head[i]);
						if(cnt[goal]==m) goal=0;
						if(!goal and color[head[i]]==n) goal=i;
					}
				}
				else bandrop(y,bel[x]);
			}
	//	
			for(int i=1+n,goal=0;i>=1;i--) if(color[head[i]]==n){
				if(!goal) goal=i;
				while(goal!=i and color[head[i]]==n and cnt[goal]<m) put(goal,head[i]);
				if(cnt[goal]==m) goal=0;
						if(!goal and color[head[i]]==n) goal=i;
			}
			
		}
		newemp();
		for(int i=1+n,goal=0;i>=1;i--) if(color[head[i]]==n){
				if(!goal) goal=i;
				while(goal!=i and color[head[i]]==n and cnt[goal]<m) put(goal,head[i]);
				if(cnt[goal]==m) goal=0;
						if(!goal and color[head[i]]==n) goal=i;
			}
		for(int i=1;i<=n;i++) if(color[head[i]]!=n) fullfill(n+1,i);
		for(int i=1;i<=n;i++) while(color[head[i]]==n) put(n+1,head[i]);
		
		n--;
	}
	
	printf("%d\n",mx.size());
	for(int i=0;i<mx.size();i++) printf("%d %d\n",mx[i],my[i]);
	return 0;
}
