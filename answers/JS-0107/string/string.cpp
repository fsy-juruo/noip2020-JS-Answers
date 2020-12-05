#include<bits/stdc++.h>
using namespace std;
string s,k;
map<char,int> a;
int n,js[1048576],ans,qzh[1048577];
void pl(string v,int pp){
	ans+=v.size()-1;
	for(int i=1;i<=v.size()-1;i++)
	if(qzh[i]>js[pp]){
	ans--;
    }
}
void solve(int len,int gjl){
	for(int i=1;i<=len/2;i++)
	if(len%i==0){
		int t=len/i;
		int flag=false;
		for(int j=1;j<=t;j++){
			k.push_back(s[j]);
		}
		for(int j=2;j<=i;j++){
		for(int l=0;l<t;l++){
			if(k[t-l]!=a[t*j-l]){
				flag=true;
				break;
			}
		}
		if(flag)
		break;
	    }
	    if(!flag)
	    pl(k,gjl);
	    k="";
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
    for(int i=1;i<=n;i++){
    	cin >> s;
    	for(int j=1;j<=s.size();j++){
    		a[s[j]]++;
    		if(a[s[j]]%2==1)
    		qzh[j]=qzh[j-1]+1;
    		else
    		qzh[j]=qzh[j-1]-1;
		}
    	for(int c=1;c<=s.size()-2;c++){
    		a[s[s.size()-c+1]]++;
    		if(a[s[s.size()-c+1]]%2==1)
    		js[c]=js[c-1]+1;
    		else
    		js[c]=js[c-1]-1;
    		solve(s.size()-c,c);
		}
		cout << ans << endl;
		ans=0;
		memset(js,0,sizeof(js));
		memset(qzh,0,sizeof(qzh));
		a.clear();
	}
	return 0;
}
