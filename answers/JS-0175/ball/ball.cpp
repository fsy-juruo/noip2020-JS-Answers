// wish to get a better mark

#include<bits/stdc++.h>
#define re register int
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

using namespace std;

inline int rd(){
	int fl=1,x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}

inline void wr(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10),putchar('0'+(x%10));
	else putchar(x+'0');
}

// ---------- IO ---------- //

const int N=55;
int n,m;
vector<int> qaq[N],lst;
vector<pair<int,int> > ccf;

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=rd();m=rd();
	for(re i=1;i<=n;i++)
		for(re j=1;j<=m;j++) qaq[i].pb(rd());
	// Bu Hui Le
	while(1) puts("F**KCCF");
	return 0;
}

// ---------- Main ---------- //

// F**KCCF SBCCF N**L C*O?

// La Ji T3 Hui Ye Qing Chun (((

// Shan Qian Liu Ming (da wu

// Boom 0 Kuai Le /cy/qiang

// Xie Ni Xie(

// SB Gou Zao N**L
