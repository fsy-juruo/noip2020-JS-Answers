#include <bits/stdc++.h>
using namespace std;

long long T,ans;
string s;
int qzh[1010],len;
bool vis[200];
void work_dyy(int len){
	ans=0;
	for(int i=1;i<=len-2;i++){
		for(int j=1;j*j<=len-i;j++){
			if((len-i)%j==0){
				ans+=(j-1)/(i%2==0?2:1);
				if(j*j!=len-i) ans+=((len-i)/j-1)/(i%2==0?2:1);
			}
		}		
	}
}

int check(int l,int r,int fk,int xz){
	int dis=(r-l+1)/fk;
	for(int i=l;i<=dis-1;i++){
		char tem=s[i];
		for(int j=i;j<=r;j+=dis){
			if(s[j]!=tem) return -1;
		}
	}
	int sum=0;
	int qq[1010];
	memset(qq,0,sizeof(qq));
	bool vha[200];
	memset(vha,false,sizeof(vis));
	for(int i=1;i<=dis-1;i++){
		if(!vha[int(s[i-1])]){
			qq[i]=qq[i-1]+1;
			vha[int(s[i-1])]=true;
		}
		else{
			vha[int(s[i-1])]=false;
			qq[i]=qq[i-1]-1;
		}
		if(qq[i]<=xz) sum++;
	}
	return sum;
}

void work_xsj(){
	memset(qzh,0,sizeof(qzh));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=len-2;i++){
		if(vis[int(s[len-i])]==0){
			vis[int(s[len-i])]=1;
			qzh[i]=qzh[i-1]+1;
		}
		else{
			vis[int(s[len-i])]=0;			
			qzh[i]=qzh[i-1]-1;
		}
	}
	for(int i=1;i<=len-2;i++){
		for(int j=1;j*j<=len-i;j++){
			if((len-i)%j==0){
				int aa=check(0,len-i-1,j,qzh[i]);
				if(j*j!=len-i&&j!=1){
					int bb=check(0,len-i-1,(len-i)/j,qzh[i]);
					if(bb!=-1) ans+=bb;
				}
				if(aa!=-1) ans+=aa;
			}
		}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d\n",&T);
	for(int i=1;i<=T;i++){
		ans=0;
		getline(cin,s);
		len=s.length();
		if(len<=1000) work_xsj();
		else work_dyy(32768);			
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
