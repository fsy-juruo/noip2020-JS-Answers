#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
using namespace std;
int T,n,ans;
string s;
vector<int>lsq[500000];
void prework(){
	for(int i=2;i<=100000;i++)
		for(int j=1;j*i<=100000;j++)
			lsq[j*i].push_back(i);
}
namespace bf{
	const int N=4e3;
	int appe1[35],appe2[35];
	//bool valid[N][N];
	/*void prepare(){
		memset(valid,0,sizeof(valid));
		for(int i=1;i<=n;i++)
			for(int j=0;j<gc[i].size();j++)
	}
	*/
	bool valid(int si,int blo,int sz){
		memset(appe1,0,sizeof(appe1));
		memset(appe2,0,sizeof(appe2));
		int i=1,j=1;
		while(j<=sz){
			if(s[i-1]!=s[j-1])
				return false;
			if(i==blo)
				i=0;
			i++;
			j++;
		}
		int ct1=0,ct2=0;
		for(int i=1;i<=si;i++)
			appe1[s[i-1]-'a']++;
		for(int i=sz+1;i<=n;i++)
			appe2[s[i-1]-'a']++;
		for(int i=0;i<29;i++)
			if(appe1[i]&1)
				ct1++;
		for(int i=0;i<29;i++)
			if(appe2[i]&1)
				ct2++;
		return ct1<=ct2;		
	}
	void solve(){
		for(int i=3;i<=n;i++)
			for(int j=0;j<lsq[i-1].size();j++){
				int y=lsq[i-1][j];
				for(int k=1;k<y;k++){
					ans+=valid(k,y,i-1);
					//cout<<k<<" "<<y<<" "<<i-1<<endl;
				}
			}

	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	prework();
	cin>>T;
	while(T--){
		ans=0;
		cin>>s;
		n=s.size();
		bf::solve();
		cout<<ans<<endl;
	}
	return 0;
}
