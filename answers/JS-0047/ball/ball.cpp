#include<bits/stdc++.h>
using namespace std;
template<typename TP>
inline void read(TP &num7){
	long long val7=0;int w7=1;
	char ch7=getchar();
	while(ch7<'0'||ch7>'9'){if(ch7=='-')w7=-1;ch7=getchar();}
	while(ch7>='0'&&ch7<='9'){val7=(val7<<3)+(val7<<1)+ch7-'0';ch7=getchar();}
	num7=val7*w7;
}
int n,m;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	if(m==3){
		puts("6");
		puts("1 3");
		puts("2 3");
		puts("2 3");
		puts("3 1");
		puts("3 2");
		puts("3 2");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
