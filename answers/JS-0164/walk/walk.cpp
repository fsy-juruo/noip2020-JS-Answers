#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
const long long P=1e9+7;
struct Node{
	long long fx,l;
}a[500010];
long long n,k,w[50],maxw[50],minw[50],totw[50];
long long bg[50],now[50],ans=0;
bool wujie(){
	for(long long i=1;i<=k;i++)if(totw[i])return false;
	for(long long i=1;i<=k;i++)if(maxw[i]-minw[i]+1>w[i])return false;
	return true;
}
bool check(){
	for(long long i=1;i<=k;i++){
		if(now[i]+minw[i]<1||now[i]+maxw[i]>w[i])return false;
	}
	return true;
}
void zou(){
//	cout<<bg[1]<<' '<<bg[2]<<"   ";
	for(long long i=1;i<=k;i++)now[i]=bg[i];
	long long cnt=0;
	while(check()){
		cnt+=n;
		for(long long i=1;i<=k;i++)now[i]=(now[i]+totw[i])%P;
	}
	for(long long i=1;i<=n;i++){
		now[a[i].fx]+=a[i].l;
		cnt=(cnt+1)%P;
		if(now[a[i].fx]<1||now[a[i].fx]>w[a[i].fx]){
			break;
		}
	}
//	cout<<cnt<<endl;
	ans=(ans+cnt)%P;
}
void dfs(long long dep){
	if(dep>k){
		zou();
	}else{
		for(long long i=1;i<=w[dep];i++){
			bg[dep]=i;
			dfs(dep+1);
		}
	}
}
void baoli(){
	ans=0;
	dfs(1);
	writeln(ans);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);

	read(n);read(k);
	for(long long i=1;i<=k;i++){
		read(w[i]);
	}
	for(long long i=1;i<=n;i++){
		read(a[i].fx);read(a[i].l);
		totw[a[i].fx]+=a[i].l;
		maxw[a[i].fx]=max(maxw[a[i].fx],totw[a[i].fx]);
		minw[a[i].fx]=min(minw[a[i].fx],totw[a[i].fx]);
	}
	
	if(wujie()){
		writeln(-1);
	}else if(n<=100){
		baoli();
	}else if(n<=100000&&k<=1){
		baoli();
	}else{
		writeln(-1);
	}
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

8 2
2 3
2 1
1 1
1 1
2 -1
2 -1
1 -1
1 -1
2 1

*/

