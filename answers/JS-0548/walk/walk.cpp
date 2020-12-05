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
int main(){
	n=read();
	write(n);
}
