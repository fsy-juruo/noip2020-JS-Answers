#include<bits/stdc++.h>
using namespace std;
//#define int long long

void read(int &x){
	char c=getchar();int fc=1;
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') fc=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	x*=fc;
}
int n,k,w[20],st[1000010][3],ans;
int now[10],nnow[10],xx[10];bool kkk;
bool check(){
	for(int i=1;i<=k;i++){
		if(nnow[i]>w[i]||nnow[i]<=0) return true;
	}
	return false;
}
bool aaa(){
	for(int i=1;i<=k;i++){
		if(nnow[i]!=xx[i]) return false;
	}
	return true;
}
void solve(){
	for(int i=1;i<=k;i++){
		xx[i]=nnow[i]=now[i];
	}
	while(1){
		for(int i=1;i<=n;i++){
			nnow[st[i][1]]+=st[i][2];
			ans++;ans%=1000000007;
			if(check()) return;
			if(aaa()){
				printf("-1");kkk=true;
				return;
			}
		}
	}
}
void find(int dep){
	if(dep>k){
		solve();
		return;
	}
	for(int i=1;i<=w[dep];i++){
		now[dep]=i;
		find(dep+1);
		if(kkk) return;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=k;i++){
		read(w[i]);
	}
	for(int i=1;i<=n;i++){
		read(st[i][1]);read(st[i][2]);
	}
	find(1);
	if(!kkk) printf("%d",ans%1000000007);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

