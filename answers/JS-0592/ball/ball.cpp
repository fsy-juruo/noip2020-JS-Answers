// First time special judge in NOIP....
// Interesting problem anyway! XD
//                        --- Zzzyt

// Btw, the checker won't actually compile in NOI Linux
// Seems to be problem with testlib
// It compiles without issue in Windows
// Using std=c++11 will make it work
// CCF, check ur assets!!!!

// And it's funny that testlib appears here XD

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007
typedef long long ll;

int n,m;
int c[55][405];
int dep[55];
int bufsz=0;
pair<int,int> buf[820005];

inline void pt(int a,int b){
//	cerr<<a+1<<"->"<<b+1<<endl;
	buf[bufsz]=make_pair(a,b);
	bufsz++;
	if(bufsz>=820003)exit(0);
}

// self to self
void swap2(int p1){
	int p2=(p1+1)%n;
	pt(p2,n);
	pt(p1,p2);
	for(int i=0;i<dep[p1]-1;i++){
		pt(p1,n);
	}
	pt(p2,p1);
	pt(n,p2);
	for(int i=0;i<dep[p1]-2;i++){
		pt(n,p1);
	}
	pt(p2,p1);
	pt(n,p2);
	swap(c[p1][m-1],c[p1][m-dep[p1]]);
	while(c[p1][m-dep[p1]]==p1&&dep[p1])dep[p1]--;
}

// self with other
void swap1(int p1,int p2){
	for(int i=0;i<dep[p2];i++){
		pt(p2,n);
	}
	pt(p1,p2);
	pt(n,p1);
	for(int i=0;i<dep[p2]-1;i++){
		pt(n,p2);
	}
	swap(c[p1][m-1],c[p2][m-dep[p2]]);
	while(c[p1][m-dep[p1]]==p1&&dep[p1])dep[p1]--;
	while(c[p2][m-dep[p2]]==p2&&dep[p2])dep[p2]--;
}

void solver1(){
	for(int i=0;i<n;i++){
		dep[i]=m;
		while(c[i][m-dep[i]]==i&&dep[i])dep[i]--;
	}
	while(true){
		int p1=-1;
		for(int i=0;i<n;i++){
			if(dep[i]!=0){
				p1=i;
				break;
			}
		}
		if(p1==-1){
			break;
		}
		int p2=c[p1][m-1];
		if(p1==p2){
			swap2(p1);
		}
		else{
			swap1(p1,p2);
		}
//		cerr<<endl;
	}
	printf("%d\n",bufsz);
	for(int i=0;i<bufsz;i++){
		printf("%d %d\n",buf[i].first+1,buf[i].second+1);
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
//	freopen("ball.err","w",stderr);
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",c[i]+j);
			c[i][j]--;
		}
	}
	
	solver1();
	
	return 0;
}

