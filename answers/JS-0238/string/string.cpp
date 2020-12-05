#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T&x){
	x=0;
	int flg=1;
	char ch=getchar();
	while((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if(ch=='-') ch=getchar(),flg=-1;
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=flg;
}
char st[1248576];
long long tot[27][1248576];
int lst[1248576],fst[1248576];
bool grd[1248576],isgrd[1248576];
inline void work(){
	memset(grd,0,sizeof grd);
	memset(isgrd,0,sizeof isgrd);
	memset(lst,0,sizeof lst);
	memset(fst,0,sizeof fst);
	memset(tot,0,sizeof tot);
	scanf("%s",st+1);
	int n=strlen(st+1);
	for(int i=n;i>=1;i--){
		for(int j=0;j<26;j++) tot[j][i]=tot[j][i+1];
		tot[st[i]-'a'][i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			if(tot[j][i]&1) lst[i]++;
		}
	}
	memset(tot,0,sizeof tot);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++) tot[j][i]=tot[j][i-1];
		tot[st[i]-'a'][i]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			if(tot[j][i]&1) fst[i]++;
		}
	}
	memset(tot,0,sizeof tot);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=26;j++){
			tot[j][i]=tot[j][i-1];
			if(fst[i]<=j) tot[j][i]++;//tot 1~i jishu<=jishude geshu
		}
	}
	string tmp="";
	for(int i=1;i<=n;i++){
		tmp.push_back(st[i]);
	}
	for(int i=1;i<(n/2+1)+1;i++){
		string tp=tmp.substr(0,i);
//		cout<<tmp[0]<<' '<<tmp[i]<<endl;
		if(i<n&&tmp[0]!=tmp[i]) continue;
		int lentmp=tmp.size(),lentp=tp.size();
		int leni=2*lentp;
		for(string ti=tp+tp;leni<=lentmp;ti=ti+tp,leni+=lentp){
			string x1=tmp.substr(0,leni);
			if(x1==ti){
				grd[i]=1;isgrd[leni]=1;
			}else break;
			if(leni+lentp<=lentmp&&tmp[0]!=tmp[leni]) break;
		}
	}
	int nxt=n+1;
	for(int i=n;i>=1;i--){
		fst[i]=nxt;
		if(grd[i]) nxt=i;
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		int rgt=lst[i];//i~n C 1~i-1 (AB)^i
		ans+=tot[rgt][i-2];
		if(!isgrd[i-1]) continue;
		for(int j=2;j<i;j=fst[j]){
			if((!grd[j])||((i-1)%j)||(i-1==j)) continue;
			ans+=tot[rgt][j-1];
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	read(T);
	while(T--){
		work();
	}
	return 0;
}

