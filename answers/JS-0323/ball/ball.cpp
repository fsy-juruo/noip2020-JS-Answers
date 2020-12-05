#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int x,y;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(0));
	cin>>x>>y;
	for(int i=0;i<x*y;++i) cin>>x;
	x=rand()%10+1;
	for(int i=0;i<x;++i){
		cout<<rand()%x+1<<" "<<rand()%x+1<<endl;
	}
	return 0;
}


