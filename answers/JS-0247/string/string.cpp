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
}/*
3   1      
4   2      
5   6     f[3]+5
6   7
7   15     f[5]+9
8   16     
9   28    f[7]+13
10  29
*/
int t;
string ff[8];
unsigned long long fz[8];
int qfz;
unsigned long long fans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(t);
	for(int i=1;i<=t;++i){
		cin>>ff[i];
		fz[i]=ff[i].size();
		qfz=!(fz[i]%2);
		fz[i]=(fz[i]-1)/2;
		int fo;
		fo=(fz[i]-1)*4+1;
		fans=(1+fo)*fz[i]/2+qfz;
		cout<<fans<<endl;
	}
	return 0;
}

