#include<bits/stdc++.h>
using namespace std;
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
vector<int>c[52];
bool kk[52];
vector<pair<int,int> >bb;
int ccc[52][401];
inline void move(int x,int y){
	bb.push_back(make_pair(x,y));
	c[y].push_back(c[x].back());
	c[x].pop_back();
	++ccc[y][c[y].back()];
	--ccc[x][c[y].back()];
	kk[x]=true;
	if(c[y].size()==m+1)kk[y]=false;
}
inline void watch(){
	for(int k=1;k<=n+1;++k){
				for(int p=1;p<c[k].size();++p){
					cout<<c[k][p]<<" ";
				}
				cout<<endl;
			}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);

}
