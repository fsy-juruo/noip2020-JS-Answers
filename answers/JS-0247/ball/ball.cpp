#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	int y=1;
	char a;
	a=getchar();
	while(a<'0'||a>'9'){
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=y;
}
int n,m;
int f[88][8];
int qfz[8];
int fk;
int flk;
struct fff{
	int a,b;
}fans[6888888];
int fd;
int fjg;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	bool fflag=true;;
	for(int i=1;i<=n;++i){
		read(f[1][i]);
		++qfz[i];
		bool flag=true;
		for(int j=2;j<=m;++j){
			read(f[j][i]);
			if(f[j][i]==f[j-1][i]&&flag)++qfz[i];
			else flag=false;
		}
		if(qfz[i]!=m)fflag=false;
	}
	if(fflag){
		cout<<0<<endl;
		return 0;
	}
	if(n!=2){
		cout<<"CCFÍòËê"<<endl;//CCF************************* 
		return 0;
	}
	if(qfz[1]>qfz[2])fk=1,flk=2;
	else fk=2,flk=1;
	int fz=f[1][fk];
	for(int i=m;i>qfz[fk];--i){
		++fjg;
		++fd;
		fans[fd].a=fk;
		fans[fd].b=3;
	}
	for(int i=m;i>=1;--i){
		if(f[i][flk]==fz){
			++fjg;
			++fd;
			fans[fd].a=flk;
			fans[fd].b=fk;
		}
		else {
			++fjg;
			++fd;
			fans[fd].a=flk;
			fans[fd].b=3;
		}
	}
	cout<<fjg<<endl;
	for(int i=1;i<=fd;++i){
		cout<<fans[i].a<<' '<<fans[i].b<<endl;
	}
	return 0;
}

