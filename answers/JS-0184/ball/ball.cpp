#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans,a[55][405],s[55],c[55];
pair<int,int> b[55];
vector<pair<int,int> > gg;
void gao(int x){
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=s[j];j++)
			if(a[i][j]==x){
				c[i]=j;
				break;
			}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	for(int i=1;i<=n;i++){
		b[i].second=i;
		for(int j=1;j<=m;j++)
			if(a[i][j]==i){
				b[i].first+=m-j;
				break;
			}
		s[i]=m;
	}
	sort(b+1,b+n+1);
	n++;
	for(int i=1;i<n;i++){
		gao(i);
		for(int j=1;j<=n;j++){
			if(c[j]==0)continue;
			for(int k=s[j];k>=c[j];k--){
				if(a[j][k]!=b[i].second)
				for(int p=n;p>0;p--)
					if(s[p]<m){
						s[p]++;
						a[p][s[p]]=a[j][k];
						s[j]--;
						ans++;
						gg.push_back(make_pair(j,p));
						break;
					}
				else{
				for(int p=1;p<=n;p++)
					if(s[p]<m){
						s[p]++;
						a[p][s[p]]=a[j][k];
						s[j]--;
						ans++;
						gg.push_back(make_pair(j,p));
						break;
					}
				}
			}
		}
		for(int j=s[n];j>0;j--){
			for(int k=n-1;k>0;k--)
				if(s[k]<m){
					ans++;
					s[k]++;
					a[k][s[k]]=a[n][j];
					s[n]--;
					gg.push_back(make_pair(n,k));
				}
		}
		for(int j=1;j<n;j++)
			while(a[j][s[j]]==b[i].second){
				s[n]++;
				a[n][s[n]]=b[i].second;
				s[j]--;
				ans++;
				gg.push_back(make_pair(j,n));
			}
		n--;
	}
	cout << ans << endl;
	for(int i=0;i<gg.size();i++)
		cout << gg[i].first << " " << gg[i].second << endl;
	return 0;
}
//I AK IOI
