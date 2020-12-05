#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
const int MAXN=57,MAXM=407;
int n,m,cis[MAXN][MAXN],cnt[MAXN],anss,co;
stack<int> s[MAXN];
vector<pa> ansl;
inline void move(int x,int y){
	ansl.push_back(pa(x,y));
	++cis[y][s[x].top()];
	++cnt[y];
	--cis[x][s[x].top()];
	--cnt[x];
	s[y].push(s[x].top());
	s[x].pop();
}
inline void back(int now){
	for(register int i=1;i<=n;++i){
		if(i==anss){
			continue;
		}
		if(i==now)
		continue;
		while(!s[anss].empty()&&cnt[i]<m&&s[anss].top()!=co){
			move(anss,i);
		}
	}
}
inline void getone(int now){
	int lst=0,lans=0;
	while(cnt[anss]<m&&s[now].top()!=co){
		move(now,anss);
	}
	for(register int i=1;i<=n;++i){
		if(i==now)
		continue;
		if(i==anss)
		continue;
		while(cnt[i]<m&&lst!=co){
			lst=s[now].top();
			lans=i;
			move(now,i);
		}
		if(lst==co)
		break;
	}
	if(lst!=co){
		int k=1;
		while(k==now||k==anss)
		++k;
//		for(register vector<pa>::iterator it=ansl.begin();it!=ansl.end();++it){
//			cerr<<it->first<<" "<<it->second<<endl;
//		}
		move(k,anss);
		move(now,k);
		back(k);
		move(k,anss);
		return;
	}
	back(lans);
	move(lans,anss);
}
inline void work(){
	for(register int i=1;i<=n;++i){
		if(cnt[anss]==m){
			return;
		}
		if(i==anss)
		continue;
		while(cis[i][co]){
			getone(i);
		}
	}
}
inline void make_empty(int now){
	for(register int i=1;i<=n;++i){
		if(i==now){
			continue;
		}
		while(cnt[i]<m&&cnt[now]){
			 move(now,i);
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	++n;
	anss=n;
	for(register int i=1;i<=n-1;++i){
		cnt[i]=m;
		for(register int j=1;j<=m;++j){
			int x;
			scanf("%d",&x);
			++cis[i][x];
			s[i].push(x);
		}
	}
//	cnt[n]=0;
	for(register int c=1;c<n-1;++c){
		co=c;
		work();
		for(register int i=1;i<=n;++i){
//			cerr<<cnt[i]<<endl;
		}
//		for(register vector<pa>::iterator it=ansl.begin();it!=ansl.end();++it){
//			cerr<<it->first<<" "<<it->second<<endl;
//		}
		int me=min_element(cnt+1,cnt+1+n)-cnt-1;
//		cerr<<(cnt[me])<<endl;
		make_empty(me);
		anss=me;
	}
	for(register int i=1;i<=n;++i){
		if(cnt[i]==m)
		continue;
		for(register int j=i+1;j<=n;++j){
			if(cnt[j]==m)
			continue;
			while(cnt[i]){
				move(i,j);
			}
		}
	}
	printf("%d\n",ansl.size());
	for(register vector<pa>::iterator it=ansl.begin();it!=ansl.end();++it){
		printf("%d %d\n",it->first,it->second);
	}
	fclose(stdin);
	fclose(stdout);
}
