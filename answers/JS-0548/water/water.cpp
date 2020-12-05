#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int r_f,r_x,r_ch;
inline int read(){
	r_x=0;
	r_f=1;
	r_ch=getchar();
	while(r_ch<'0'||r_ch>'9'){
		if(r_ch=='-')r_f=-1;
		r_ch=getchar();
	}
	while(r_ch>='0'&&r_ch<='9'){
		r_x=(r_x<<1)+(r_x<<3)+r_ch-'0';
		r_ch=getchar();
	}
	return r_x*r_f;
}
int w_c[50],w_s;
inline void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x==0){
		putchar('0');
		return;
	}
	w_s=0;
	while(x>0){
		w_c[w_s++]=x%10;
		x/=10;
	}
	for(--w_s;w_s>=0;--w_s)putchar(w_c[w_s]+'0');
}
struct fs{
	int p,q;
}ol[100001];
inline int gcd(int a,int b){
	if(a==0)return b;
	return gcd(b%a,a);
}
int jia_o;
inline fs jia(const fs &x,const fs&y){
	fs u;
	u.p=x.p*y.q+x.q*y.p;
	u.q=x.q*y.q;
	//cout<<u.p<<' '<<u.q<<endl;
	jia_o=gcd(u.p,u.q);
	u.p/=jia_o;
	u.q/=jia_o;
	//cout<<u.p<<' '<<u.q<<endl;
	return u;
}

vector<int>b[100001];
int hi[100001];
queue<int>q2;

signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	register int i,j,x,v;
	for(i=1;i<=n;++i){
		j=read();
		while(j-->0){
			x=read();
			b[i].push_back(x);
			++hi[x];
		}
	}
	queue<int>qe;
	for(i=1;i<=n;++i){
		if(hi[i]>0){
			ol[i].p=0;
			ol[i].q=1;
		}else{
			ol[i].p=1;
			ol[i].q=1;
			qe.push(i);
		}
	}
	while(qe.empty()==false){
		v=qe.front();
		qe.pop();
		q2.push(v);
		for(i=0;i<b[v].size();++i){
			if(--hi[b[v][i]]==0){
				qe.push(b[v][i]);
			}
		}
	}
	while(q2.empty()==false){
		v=q2.front();
		q2.pop();
		int ss=b[v].size();
		if(ss>0){
			ol[v].q*=ss;
			//cout<<"y"<<v<<' '<<ol[v].p<<' '<<ol[v].q<<endl;
			for(i=0;i<ss;++i){
				//cout<<"hu"<<b[v][i]<<' '<<ol[b[v][i]].p<<" "<<ol[b[v][i]].q<<endl;
				ol[b[v][i]]=jia(ol[b[v][i]],ol[v]);
				//cout<<"lu"<<b[v][i]<<' '<<ol[b[v][i]].p<<" "<<ol[b[v][i]].q<<endl;
			}
		}
	}
	//cout<<"hia";
	for(i=1;i<=n;++i){
		if(b[i].empty()){
			write(ol[i].p);
			putchar(' ');
			write(ol[i].q);
			putchar('\n');
		}
	}
}
