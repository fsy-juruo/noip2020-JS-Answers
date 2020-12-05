#include <bits/stdc++.h>
using namespace std;

int T,len;
string s;
long long ans;

int oac(const string &u){
	bool al[30]={0};
	int w=0;
	for(int i=0;u[i];++i){
		al[u[i]-'a']=!al[u[i]-'a'];
	}
	for(int i=0;i<26;++i){
		w+=al[i];
	}
	return w;
}
void find(int ct,int ee){
	string ys=s.substr(0,ct);
	int ly=ys.size();
	bool fl=0;
	for(int i=2;i<=ly;++i){
		if(ly%i)continue;
		fl=1;
		for(int j=i;ys[j];++j){
			if(ys[j]!=ys[j%i]){
				fl=0;
				break;
			}
		}
		if(fl){
			for(int j=1;j<i;++j){
				if(oac(ys.substr(0,j))<=ee){
					++ans;
				}
			}
		}
	}
}

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cin>>s;
		ans=0;
		len=s.size();
		for(int i=2;i<len;++i){
			find(i,oac(s.substr(i)));
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
