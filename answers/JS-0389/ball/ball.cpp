#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f;
const int N=60,M=410;

int n,m;
int a[N][M];

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

namespace task1{
	stack<int> sta[4];
	int cnt[4];
	int k;
	queue<string> ans;
	void solve(){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				sta[i].push(a[i][j]);
			}
		}
		cnt[1]=cnt[2]=m;
		
		int c1=a[1][m],c2=3-c1;
		while (1){
//			cerr<<"0"<<endl;
			while (cnt[1] && sta[1].top()==c1){
				sta[1].pop();cnt[1]--;
//				cerr<<" 1";
				ans.push("1 3");k++;
//				cerr<<" 2";
				sta[3].push(c1);cnt[3]++;
//				cerr<<" 3";
			}
//			cerr<<"test"<<endl;
			while (cnt[2] && sta[2].top()==c1){
				sta[2].pop();cnt[2]--;
				ans.push("2 3");k++;
				sta[3].push(c1);cnt[3]++;
			}
//			cerr<<"1"<<endl;
			while (cnt[1]<m && cnt[2] && sta[2].top()==c2){
				ans.push("1 2");k++;
				sta[2].push(c2);cnt[2]++;
				sta[1].pop();cnt[1]--;
			}
			if (cnt[1]==m && sta[2].top()==c2){
				while (cnt[2]<m && cnt[1] && sta[1].top()==c2){
					ans.push("2 1");k++;
					sta[1].push(c2);cnt[1]++;
					sta[2].pop();cnt[2]++;
				}
			}
//			cerr<<"2"<<endl;
			if (!cnt[1]){
//				cerr<<"3 1"<<endl;
				while (cnt[3]){
					ans.push("3 1");k++;
					sta[3].pop();cnt[3]--;
					sta[1].push(c1);cnt[1]++;
				}
				while (cnt[2]){
					if (sta[2].top()==c1){
						ans.push("2 1");k++;
					}
					else {
						ans.push("2 3");k++;
					}
					sta[2].pop();cnt[2]--;
				}
				while (cnt[3]){
					sta[3].pop();cnt[3]--;
					ans.push("3 2");
				}
				break;
			}
			if (!cnt[2]){
//				cerr<<"3 2"<<endl;
				while (cnt[3]){
					ans.push("3 2");k++;
					sta[3].pop();cnt[3]--;
				}
				while (cnt[1]){
					if (sta[1].top()==c1){
						ans.push("1 2");k++;
					}
					else {
						ans.push("1 3");k++;
					}
					sta[1].pop();cnt[1]--;
				}
				while (cnt[3]){
					sta[3].pop();cnt[3]--;
					ans.push("3 1");
				}
				break;
			}
		}
		cout<<k<<endl;
		while (!ans.empty()){
			cout<<ans.front()<<endl;
			ans.pop();
		}
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	if (n<=2)task1::solve();
	
	return 0;
}

