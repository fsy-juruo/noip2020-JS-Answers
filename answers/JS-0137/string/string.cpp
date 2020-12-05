#include<bits/stdc++.h>
using namespace std;
int T;
char st[1050010];
int ans,num[30],appear[30],save[1050010],single[1050010],now[1050010];//single[i]->i~len
bool key;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(appear,0,sizeof(appear));
		memset(single,0,sizeof(single));
		key=false;
		scanf("%s",&st);
		int len=strlen(st);
		for(int i=1;i<=len;i++){
			save[i]=st[i-1]-'a'+1;
			num[save[i]]++;
			if(num[save[i]]==len){
				
				key=true;
				break;
			}
		}
		if(key) continue;
		for(int i=len;i>2;i--){
			appear[save[i]]++;
			single[i]=single[i+1];
			if(appear[save[i]]&1) single[i]++;
			else single[i]--;
		}
		memset(appear,0,sizeof(appear));
		for(int i=1;i<len-1;i++){
			appear[save[i]]++;
			now[i]=now[i-1];
			if(appear[save[i]]&1) now[i]++;
			else now[i]--;
		}
		for(int i=3;i<=len;i++){//C
			for(int length=2;length<=i-1;length++){
				if((i-1)%length!=0) continue;
				//A:1~j
				//B:j+1~length
				bool vis=false;
				int times=(i-1)/length;
				for(int u=0;u<times;u++){
					for(int v=1;v<=length;v++){
						if(save[v]!=save[u*length+v]){
							vis=true;
							break;
						}
					}
					if(vis) break;
				}
				if(!vis){
					for(int j=1;j<length;j++){
						if(now[j]<=single[i]) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

