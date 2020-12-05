#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[110][1010],num[110];

int read(){
	int x=0,f=1; char ch;
	while (ch>'9'||ch<'0'){
		  if (ch=='-') f=-1;
		  ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		  x=(x<<3)+(x<<1)+ch-'0';
		  ch=getchar();
	}
	return x*f;
}



int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(); m=read();
	for (int i=1;i<=n;i++){
		num[i]=m;
		for (int j=1;j<=m;j++) a[i][j]=read();
	}
	if (n==2){
		cout<<1<<' '<<3<<endl;
		num[3]++; a[3][1]=a[1][3];
		num[1]--;
		while (num[3]<m){
			if (a[1][num[1]]!=a[3][1]&&a[2][num[2]]!=a[3][1]){
				int m1=0,m2=0;
				for (int i=num[1];i>=1;i--)
					if (a[1][i]==a[3][1]) {m1=i; break;}
				for (int i=num[2];i>=1;i--)
					if (a[2][i]==a[3][1]) {m2=i; break;}
				if (num[2]<=m1){
					int t=num[2];
					for (int i=t+1;i<=t+m1-1;i++){
						cout<<1<<' '<<2<<endl;
						num[2]++; a[2][num[2]]=a[1][num[1]];
						num[1]--;
					}
				} else 
				if (num[1]<=m2){
					int t=num[1];
					for (int i=t+1;i<=t+m2-1;i++){
						cout<<2<<' '<<1<<endl;
						num[1]++; a[1][num[1]]=a[2][num[2]];
						num[2]--;
					}
				}
			}
			if (a[1][num[1]]==a[3][1]){
				cout<<1<<' '<<3<<endl;
				num[3]++; a[3][num[3]]=a[1][num[1]];
				num[1]--;
			}
			if (a[2][num[2]]==a[3][1]){
				cout<<2<<' '<<3<<endl;
				num[3]++; a[3][num[3]]=a[2][num[2]];
				num[2]--;
			}
		}
		while (num[1]>0){
			cout<<1<<' '<<2<<endl;
			num[1]--;
		}
		for (int i=1;i<=m;i++) cout<<3<<' '<<1<<endl;
		return 0;
	}
	return 0;
}

