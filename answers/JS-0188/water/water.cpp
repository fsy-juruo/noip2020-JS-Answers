#include<bits/stdc++.h>
using namespace std;
int Read(){
	short f=1;
	char c;
	int fr=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f*=-1;
		c=getchar();
	}
	if(f==1){
		while(c>='0'&&c<='9'){
			fr=fr*10+c-48;
			c=getchar();
		}
	}else{
		while(c>='0'&&c<='9'){
			fr=fr*10+48-c;
			c=getchar();
		}
	}
	return fr;
}
void Write(long long xx){
	if(xx<0){
		putchar('-');
		xx*=-1;
	}
	if(xx<10){
		putchar(xx+48);
	}else{
		Write(xx/10);
		putchar(xx%10+48);
	}
}
int gcd(int aa,int bb){
	if(bb==0)return aa;
	return gcd(bb,aa%bb);
}
int n,m;
struct Info{
	long long i,o;
	vector<int>c;
	long long fm,fz;
	void ad(long long ta,long long tb){
		int gc=gcd(fm,tb);
		ta*=fm/gc;
		fz*=tb/gc;
		fm*=tb/gc;
		fz+=ta;
		gc=gcd(fm,fz);
		fm/=gc;
		fz/=gc;
	}
}a[100010];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i].i=0;
		a[i].o=0;
		a[i].fm=1;
		a[i].fz=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].o;
		if(i<=m){
			a[i].fm=1;
			a[i].fz=1;
		}
		for(int j=1;j<=a[i].o;j++){
			 int t;
			 t=Read();
			 a[i].c.push_back(t);
			 a[t].i++;
			a[t].ad(a[i].fz,a[i].fm*a[i].o);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].o==0){
			Write(a[i].fz);
			putchar(' ');
			Write(a[i].fm);
			cout<<endl;
		}
	}
	return 0;
}
