#include<bits/stdc++.h>
#include<cstring>
using namespace std;
char c[2000005];
int suf[2000005],pre[2000005];
int fai[2000005];
int cnt[35];
vector<int> id[35];
vector<int> pro[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof c);
		memset(suf,0,sizeof suf);
		memset(pre,0,sizeof pre);
		memset(cnt,0,sizeof cnt);
		memset(fai,0,sizeof fai);
		for(int i=0;i<=28;i++) id[i].clear();
		scanf("%s",c);
		int n=strlen(c);
		fai[0]=-1;
		int pos=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j+=i){
				pro[j].push_back(i);
			}
		}
		for(int i=1;i<n;i++){
			while(pos!=-1&&c[pos+1]!=c[i]) pos=fai[pos];
			if(c[pos+1]==c[i]) fai[i]=pos+1;
			else fai[i]=-1;
			pos=fai[i];
		}
//		cout<<"fail:";
//		for(int i=0;i<n;i++) cout<<fai[i]<<" ";
//		cout<<endl;
		pre[0]=1;
		cnt[c[0]-'a']++;
		int ma=0;
		for(int i=1;i<n;i++){
			if(cnt[c[i]-'a']==0) pre[i]=pre[i-1]+1; else pre[i]=pre[i-1]-1;
			ma=max(pre[i],ma);
			cnt[c[i]-'a']^=1;
		}
//		for(int i=0;i<n;i++) cout<<pre[i]<<" ";
//		cout<<endl;
		memset(cnt,0,sizeof cnt);
		for(int i=n-1;i>=0;i--){
			if(cnt[c[i]-'a']==0) suf[i]=suf[i+1]+1; else suf[i]=suf[i+1]-1;
			ma=max(suf[i],ma);
			cnt[c[i]-'a']^=1;
		}
//		for(int i=0;i<n;i++) cout<<suf[i]<<" ";
//		cout<<endl;
		long long res=0;
		for(int i=0;i<n-2;i++){
		//	sum[pre[i]]++;
			for(int j=pre[i];j<=ma;j++) id[j].push_back(i+1);
			int m=suf[i+2];
			vector<int> v;
			int relen=i+1-fai[i+1],len=i+2;
			int times=len/relen;
			if(len%relen||len==relen) v.push_back(len);
			else{
			//	int times=len/relen;
				for(int j=1;j*j<=times;j++){
					if(times%j==0){
						v.push_back(j*relen);
						if(j*j<times) v.push_back((times/j)*relen);
					}
				}
			}
			if(len%relen==0){
				for(int j=0;j<pro[times].size();j++){
					res+=(long long)(lower_bound(id[suf[i+2]].begin(),id[suf[i+2]].end(),pro[times][j]*relen)-id[suf[i+2]].begin());
				}
			}
			else res+=(long long)(lower_bound(id[suf[i+2]].begin(),id[suf[i+2]].end(),len)-id[suf[i+2]].begin());
//			for(int j=0;j<v.size();j++){
//				res+=(long long)(lower_bound(id[suf[i+2]].begin(),id[suf[i+2]].end(),v[j])-id[suf[i+2]].begin());
//				cout<<v[j]<<" ";
//			}
//			cout<<endl;
//			if(len%relen==0)
//				for(int j=0;j<pro[times].size();j++){
//					cout<<pro[times][j]*relen<<" ";
//				}
//			else cout<<len<<" ";
//			cout<<"ha"<<" "<<times<<endl;
		}
		for(int i=0;i<=n;i++) pro[i].clear();
		printf("%lld\n",res);
	}
	return 0;
}
