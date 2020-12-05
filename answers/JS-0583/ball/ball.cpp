#include<bits/stdc++.h>
#define INF 820000
#define N 22
#define M 401
using namespace std;
int n,m;
int d[N][M]={},top[N]= {},x[N]= {},from[INF]= {},to[INF]= {};
bool dest() {
	if(top[n+1])return 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(d[i][j]!=i)return 0;
	return 1;
}
void put() {
	for(int i=1; i<=n+1; i++) {
		cout<<top[i]<<" ";
		for(int j=1; j<=top[i]; j++) {
			cout<<d[i][j]<<(j<top[i]?" ":"\n");
		}

	}

	for(int i=1; i<=n; i++)
		cout<<x[i]<<(i<n?" ":"\n");
}
int main() {
	freopen("ball.in","r",stdin);freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			cin>>d[i][j];
			if(d[i][j]!=i)x[i]++;

		}
	int k=0;
	for(int i=1; i<=n; i++)top[i]=m;
	top[n+1]=0;
	while(1) {
		for(int i=1; i<=n; i++) {
			while(x[i]>0) {
				for(int j=n+1; j>=1; j--) {
					if(j!=i)
						while(top[j]<m&&x[i]>0) {
							d[j][++top[j]]=d[i][top[i]],k++;
							from[k]=i,to[k]=j;
						//	cout<<i<<" "<<j<<endl;

							x[i]-=(d[i][top[i]--]==i?0:1);
							if(j!=n+1)x[j]+=(d[j][top[j]]==j?0:1);//put();system("pause");
						}
				}
			}
		}
		while(top[n+1]>0) {
			int a=d[n+1][top[n+1]];top[n+1]--;
			//cout<<a<<endl;
			if(top[a]<m) {
				d[a][++top[a]]=a;
				k++;
				from[k]=n+1,to[k]=a;
			//	cout<<n+1<<" "<<a<<endl;
			//	put();
			//	system("pause");
			} else {
				for(int i=1; i<=n; i++) {
					if(top[i]<m&&i!=a) {
						d[i][++top[i]]=a,k++;
						x[i]++;
						from[k]=n+1,to[k]=i;
					//	cout<<n+1<<" "<<i<<endl;
					//	put();
						//system("pause");
					}
				}
			}
			
		}
		if(dest())break;
	}
	cout<<k<<endl;
	for(int i=1; i<=k; i++) {
		printf("%d %d\n",from[i],to[i]);
	}
	return 0;
}

