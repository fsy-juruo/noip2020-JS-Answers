#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;i++)
#define DF(i,a,b) for (int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
using namespace std;
inline int read(){
	int w=1,c=0; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
LL gcd(LL x,LL y){
	return y ? gcd(y,x%y) : x;
}
struct frac{
	LL x,y;
}fl[M];
frac fm(frac tmp){
	LL o=gcd(tmp.x,tmp.y);
	return (frac){tmp.x/o,tmp.y/o};
}
frac operator +(frac A,frac B){
	LL oo=gcd(A.y,B.y);
	return fm((frac){A.x*(B.y/oo)+B.x*(A.y/oo),A.y/oo*B.y});
}
int n,m,de[M],ot[M],q[M];
vector<int> v[M];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(); m=read();
	F(i,1,n){
		int x=read();
		F(j,1,x){
			int y=read();
			v[i].pb(y);
			de[y]++;
			ot[i]++;
		}
	} 
	int l=1,r=0;
	F(i,1,n){
		if (i<=m) fl[i]=(frac){1,1},q[++r]=i;
		else fl[i]=(frac){0,1};
	} 
	while (l<=r){
		int x=q[l++];
		frac tmp=fl[x];
		tmp.y=tmp.y*((int)v[x].size());
//		cout<<x<<" "<<SZ(v[x])<<"\n";
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			de[y]--;
			fl[y]=fl[y]+tmp;
//			cout<<y<<"   hh\n";
			if (!de[y]) q[++r]=y;
		}
	}
	F(i,m+1,n){
		if (!ot[i]){
			cout<<fl[i].x<<" "<<fl[i].y<<"\n";
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0

*/
