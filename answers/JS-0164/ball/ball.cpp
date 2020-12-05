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
int n,m,cnt=0;
vector<int>A[60];
struct Node{
	int cong,dao;
}a[2000010];
void doit(int l,int r){
	if(l>r)return;
	int des=A[l][0];
	int wz=A[l].size();
	for(int i=0;i<A[l].size();i++){
		if(A[l][i]!=des){
			wz=i;
			break;
		}
	}
//	cout<<wz<<endl;
	while(A[l].size()>wz){
		for(int i=l+1;i<=r+1;i++){
			if(A[i].size()<m){
				A[i].push_back(A[l][A[l].size()-1]);
				A[l].pop_back();
				cnt++;
				a[cnt].cong=l;a[cnt].dao=i;
//				cout<<"#1# "<<l<<' '<<i<<endl;
			}
		}
	}
//	cout<<A[l].size()<<endl;
	while(A[l].size()<m){
		int minn=0x3f3f3f3f,mini;
		for(int i=l+1;i<=r+1;i++){
			for(int j=A[i].size()-1;j>=0;j--){
				if(A[i][j]==des){
					if(A[i].size()-j<minn){
						minn=A[i].size()-j;
						mini=i;
					}
				}
			}
		}
		
		while(A[mini][A[mini].size()-1]!=l){
			for(int i=l+1;i<=r+1;i++){
//				cout<<i<<' '<<A[i].size()<<endl;
				if(i!=mini&&A[i].size()<m){
					A[i].push_back(A[mini][A[mini].size()-1]);
					A[mini].pop_back();
					cnt++;
					a[cnt].cong=mini;a[cnt].dao=i;
//					cout<<"#2# "<<mini<<' '<<i<<endl;
				}
			}
		}
		
		A[l].push_back(A[mini][A[mini].size()-1]);
		A[mini].pop_back();
		cnt++;
		a[cnt].cong=mini;a[cnt].dao=l;
//		cout<<"#3# "<<mini<<' '<<l<<endl;
	}
	doit(l+1,r);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);

	read(n);read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;read(x);
			A[i].push_back(x);
		}
	}
	
	doit(1,n);
	writeln(cnt);
	for(int i=1;i<=cnt;i++){
		write(a[i].cong);putchar(' ');writeln(a[i].dao);
	}
	return 0;
}
/*
2 3
1 1 2
2 1 2

*/

