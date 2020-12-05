#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define RE return
#define V vector
#define MP make_pair
#define P pair
#define PB push_back
using namespace std;
int readint(){
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int s=c-'0';c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+c-'0';
		c=getchar();
	}
	RE s;
}
void output(int x){
	if(x>=10)output(x/10);
	putchar((char)(x%10+'0'));
}
int a[55][405],len[55];
int n,m;
void print(){
	FOR(i,1,n+1){
		FOR(j,1,len[i]){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	cout<<'\n';
}
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
//	freopen("ball2.in","r",stdin);
//	freopen("1.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			int x;
			cin>>x;
			a[i][++len[i]]=x;
		}
	}
	V<P<int,int> > ans;
	FOR(i,1,n){
		int fir=0;
		FOR(j,1,n){
			int p=0,cnt;
			FOR(k,1,m){
				if(a[j][k]==i)p++;
			} 
			if(!p)continue;
			cnt=p;
			fir=j;
			V<int> now;
			int l,to=0;
			for(int k=m;k>=1;k--){
				if(a[j][k]==i){
					p--;
					if(!p){
						l=k;break;
					}
				}else to++;
			}
			int tto=to;
			print();
			FOR(k,1,n){
				if(!tto)break;
				if(k!=j){
					while(tto){
						tto--;
						now.PB(k);
						a[n+1][++len[n+1]]=a[k][len[k]];
						ans.PB(MP(k,n+1));
						len[k]--;
					}
				}
			}
			cout<<ans.size()<<'\n';
			print();
			V<int> tv=now,v=now;
			for(int k=m;k>=l;k--){
				if(a[j][k]==i){
					a[n+1][++len[n+1]]=i;
					len[j]--;
					ans.PB(MP(j,n+1));
				}else{
					ans.PB(MP(j,tv.back()));
					a[tv.back()][++len[tv.back()]]=a[j][k];
					len[j]--;
					tv.pop_back();
				}
			}
			while(!now.empty()){
				ans.PB(MP(now.back(),j));
				a[j][++len[j]]=a[now.back()][len[now.back()]];
				len[now.back()]--;
				now.pop_back();
			}
			FOR(k,1,cnt){
				ans.PB(MP(n+1,j));
				a[j][++len[j]]=a[n+1][len[n+1]];
				len[n+1]--;
			}
			while(!v.empty()){
				ans.PB(MP(n+1,v.back()));
				a[v.back()][++len[v.back()]]=a[n+1][len[n+1]];
				len[n+1]--;
				v.pop_back();
			}
		}
		FOR(j,1,n){
			for(int k=m;k>=1;k--){
				if(a[j][k]!=i)break;
				ans.PB(MP(j,n+1));
				a[n+1][++len[n+1]]=a[j][k];
				len[j]--;
			}
		}
		FOR(j,1,n){
			if(j==fir)continue;
			while(len[j]<m){
				ans.PB(MP(fir,j));
				a[j][++len[j]]=a[fir][len[fir]];
				len[fir]--;
			}
		}
		FOR(j,1,m){
			ans.PB(MP(n+1,fir));
			a[fir][j]=i;
		}
		len[n+1]=0;
		len[fir]=m;
	}
	cout<<ans.size()<<'\n';
	for(V<P<int,int > >::iterator it=ans.begin();it!=ans.end();it++){
		cout<<(*it).F<<' '<<(*it).S<<'\n';
	}
	RE 0;
}

