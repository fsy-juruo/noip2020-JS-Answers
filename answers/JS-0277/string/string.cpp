#include<bits/stdc++.h>
using namespace std;
const int maxn=1100007;
int T,n,cye,alp[30],s_cn,s_an;
long long ans;
char str[maxn];
string s_a,s_c;
bool isok[maxn];
vector <int> factor[1111];
bool dfs_cmp(string s){
	int ssize=s.size();
	int it=ssize+1;
//	if (ssize*cye>n){
//		return 0;
//	}
	for (int i=2;i<=cye;i++){
		for (int j=0;j<ssize;j++,it++){
			int ori=(it-1)%ssize;
			if (str[it]!=s[ori]){
				return 0;
			}
		}
	}
	return 1;
}
int count(string s){
	int cnt=0;
	for (int i=1;i<=26;i++){
		alp[i]=0;
	}
	for (int i=0;i<s.size();i++){
		alp[s[i]-'a'+1]++;
	}
	for (int i=1;i<=26;i++){
		if (alp[i]&1) cnt++;
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	for (int i=4;i<=1111;i++){
		for (int j=2;j<i;j++){
			if ((!(i%j))){
				factor[i].push_back(j);
			}
		}
	}
	while (T--){
		//reclear!
		ans=0;
		scanf("%s",str+1);
		bool ok3=1;
		for (int i=1;i<=maxn;i++){
			isok[i]=0;
			if (!str[i]){
				n=i-1;
				break;
			}
			if (i==1) continue;
			if (ok3 && str[i-1]!=str[i]) ok3=0;
		}
		if (ok3){
			for (cye=1;cye<=n/2;cye++){
				int it=2,ode; //the size of each(AB) is it
				for (;it*cye<n;it++){
					ode=(n-cye*it)&1;
					if (ode) {
						ans+=it-1;
					}
					else{
						ans+=(it-1)/2;
					}
					//cout<<cye<<" "<<it<<" "<<ode<<" "<<ans<<endl;
				}
			}
			printf("%lld\n",ans);
			continue; //T-- continue
		}
		isok[1]=1;
		for (cye=1;cye<=n/2;cye++){
			bool ok2=1;
			if (n>1000){
				for (int i=cye-1;i>=2;i--){
					if ( (!(cye%i)) && (!isok[i]) ){
						ok2=0;
						break;
					}
				}
			}
			if (n<=1000){
				for (int i=0;i<factor[cye].size();i++){
					if (!isok[factor[cye][i]]){
						ok2=0;
						break;
					}
				}
			}
			if (!ok2){
				continue;
			}
			
			string s="";
			for (int i=1;i<=n;i++){
				if (cye*i>=n)
					break;
				s+=str[i];
				if (i==1) continue;
				if (!dfs_cmp(s))
					continue;
				//pass the check
				isok[cye]=1;
				s_a=s_c="";//s_c
				for (int i=s.size()*cye+1;i<=n;i++)
					s_c+=str[i];
				s_cn=count(s_c);s_an=0;
				for (int i=1;i<=26;i++) alp[i]=0;
				for (int i=0;i<s.size()-1;i++){
					s_a+=str[i+1];
					alp[str[i+1]-'a'+1]++;
					if (alp[str[i+1]-'a'+1]&1) s_an++;
					else s_an--;
					//cout<<s_a<<" "<<s_c<<endl;
					if (s_an<=s_cn){
						//cout<<s_a<<" "<<s_c<<endl;
						ans++;
					}
				}
			}
		}
		//cout<<isok[1]<<" "<<isok[2]<<" "<<isok[3]<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*//*
6
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
kkkkkkkkkkkkkkkkkkkk
*/
