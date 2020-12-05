#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=gc();int neg=1;
	for(;!isdigit(c);c=gc())if(c=='-')neg=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+c-'0';
	x*=neg;
}
const int maxn=55,maxm=410;
struct move{
	int a,b;
}mo[maxm*1000];
int c[maxn][maxm];
int color[maxn];
int top[maxn];
//int s[maxn][maxm];
int n,m;
stack<int> s[maxn];
stack<int> tmp;
unsigned ll ok;
unsigned ll check;
void dfs(int x,int fa,int step){
//	printf("%d\n",step);
	if(step>820000)return;
	if(ok&check==check){
		printf("1	%d\n",step);
		return;
	}
	int orisize=s[x].size();
	while(s[x].size()>1){
		int t=s[x].top();
		tmp.push(t);
		s[x].pop();
		for(int i=1;i<=n+1;i++){
			bool flag=0;
			if(!(i==x||i==fa||s[i].size()>=m-1)){
				s[i].push(t);
				c[x][t]--;
				c[i][t]++;
				if(c[i][t]==s[i].size())flag=1,ok|=(1ull<<i);
			}
			dfs(i,x,step+1);
			if(!(i==x||i==fa||s[i].size()>=m-1)){
				if(flag)ok^=(1ull<<i);
				s[i].pop();
				c[x][t]--;
				c[i][t]++;
			}
		}
	}
	while(orisize>1){
		s[x].push(tmp.top());
		tmp.pop();
		orisize--;
	}
}
int cnt;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	int in;
	bool flag=1;
	for(int i=1;i<=n;i++){
		check|=(1ull<<i);
		for(int j=1;j<=m;j++){
			read(in);
			c[i][in]++;
//			if(c[i][in]>c[i][color[i]]){
//				color[i]=in;
//			}
			if(s[i].size()>=1&&s[i].top()!=in)flag=0;
			s[i].push(in);
		}
		color[i]=i;
	}
	check|=(1ull<<(n+1));
	if(flag){
		printf("0\n");
		return 0;
	}
//	dfs(1,1,0);
//	if(n==2){
//		while(top[1]){
//			while(s[1][top[1]]!=color[1]&&top[1]){
//				top[1]--;
//				s[n+1][++top[n+1]]=s[1][top[1]];
//				mo[++cnt]=(move){1,n+1};
//			}
//			top[1]--;
//		}
//		while(top[2]){
//			if(s[2][top[2]]==color[1]){
//				s[1][++top[1]]=s[2][top[2]];
//				top[2]--;
//				mo[++cnt]=(move){2,1};
//			}
//			else{
//				s[n+1][++top[n+1]]=s[2][top[2]];
//				top[2]--;
//				mo[++cnt]=(move){2,n+1};
//			}
//		}
//		printf("%d\n",cnt);
//		for(int i=1;i<=cnt;i++){
//			printf("%d %d\n",mo[i].a,mo[i].b);
//		}
//	}
//	else{
//		return 0;
//	}
	return 0;
}

