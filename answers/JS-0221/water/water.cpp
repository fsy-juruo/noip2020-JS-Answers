#include<bits/stdc++.h>
#define LL unsigned long long
using namespace std;
void read(int &sum){
	sum=0;char ch=getchar();int p=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')p=-1;
	for(; isdigit(ch);ch=getchar())sum=sum*10+ch-48;
	sum*=p;
}
void write(int sum){
	if(sum<0){
		putchar('-');
		sum=0-sum;
	}
	if(sum>9){
		write(sum/10);
		sum%=10;
	}
	putchar(sum+48);
}
void writek(int sum){
	write(sum);
	putchar(' ');
}
void writeln(int sum){
	write(sum);
	putchar('\n');
}
struct Edge{
	int v,Next;
}edge[500010];
int head[100010],tot=0;
void add(int x,int y){
	tot++;
	edge[tot].v=y;
	edge[tot].Next=head[x];
	head[x]=tot;
}
struct node{
	LL fz,fm;
}a[100010];
LL gcd(LL x,LL y){
	LL z=1;
	while(y){
		z=x%y;
		x=y;
		y=z;
	}
	return x;
}
void yf(node &x){
	LL gc=gcd(x.fz,x.fm);
	x.fz/=gc;
	x.fm/=gc;
}
//void tf(node &x,node &y){
//	int gc=x.fm/gcd(x.fm,y.fm)*y.fm;
//	x.fz*=gc/x.fm;
//	y.fz*=gc/y.fm;
//	y.fm=x.fm=gc;
//}
void jia(node &x,node y){
	node z;
	LL gc=gcd(x.fm,y.fm);
	z.fm=x.fm/gc*y.fm;
	z.fz=y.fm/gc*x.fz;
	z.fz+=x.fm/gc*y.fz;
	yf(z);
	x=z;
}
node fl(node x,LL y){
	LL gc=gcd(x.fz,y);
//	cout<<"GC "<<gc<<endl;
	x.fz/=gc;
	x.fm*=y/gc;
	return x;
}
int n,m,i,num[100010],j,x,y,siz[100010];
bool iflast[100010];
deque<int>q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(i=1;i<=n;i++){
		read(num[i]);
		for(j=1;j<=num[i];j++){
			read(x);
			add(i,x);
			siz[x]++;			
		}
		if(!num[i]) iflast[i]=1;
	}
//	for(i=1;i<=n;i++){
//		cout<<iflast[i]<<endl;
//	}
	for(i=1;i<=m;i++){
		a[i].fm=1;
		a[i].fz=1;
		q.push_back(i);
	}
	for(i=m+1;i<=n;i++){
		a[i].fm=1;
		a[i].fz=0;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop_front();
		node y=fl(a[x],num[x]);
//		cout<<num[x]<<endl;
//		cout<<y.fz<<' '<<y.fm<<endl;
		for(i=head[x];i;i=edge[i].Next){
			int v=edge[i].v;
			jia(a[v],y);
			siz[v]--;
			if(siz[v]==0){
				q.push_back(v);	
			}			
		}
//		cout<<x<<endl;
//		for(i=1;i<=n;i++){
//			cout<<a[i].fz<<'/'<<a[i].fm<<endl;
//		}
	}
	for(i=1;i<=n;i++){
		if(iflast[i]){
			writek(a[i].fz);
			writeln(a[i].fm);
		}
	}
	return 0;
}
