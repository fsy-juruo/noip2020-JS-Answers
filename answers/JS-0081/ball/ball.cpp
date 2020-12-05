#include<bits/stdc++.h>
using namespace std;

int n,m;
int mpp[51][400];
int ans[820000][2];
int dfs(int tim,int mp[][400],int an[][2],int ta){	
for(int i=0;i<=n;i++){
for(int i1=0;i1<m;i1++)
printf("%d ",mpp[i][i1]);
printf("\n");
}
	if(tim==820000){
		return -1;
	}
	int tail=0,lab=0;
	int ok[50];
	for(int i=0;i<=n;i++)
	ok[i]=-1;
	for(int i=0;i<n;i++){
		int pd=0;
		for(int i1=1;i1<m;i1++){
			if(mp[i][i1]!=mp[i][0]){
			pd=1;
			break;
			}
		}
		if(pd==0){
			ok[tail++]=i;
		}
	}
	printf("%d %d ok5\n",n,tail);
	if(tail==n){
		for(int i=0;i<tim;i++){
			ans[i][0]=an[i][0];
			ans[i][1]=an[i][1];
			return tim;
		}
	}
	for(int x=0;x<=n;x++){
			printf("%d %d ok4\n",lab,ok[lab]);			
		if(x==ok[lab]){
			lab++;
			continue;
		}
		if(mp[x][0]==0){
			continue;
		}
		for(int y=0;y<=n;y++){
			printf("ok\n");
			if(mp[y][m-1]!=0||x==y)
			continue;
			if(an[ta-1][0]==y&&an[ta-1][1]==x){
				continue;
			}
			an[ta][0]=x;
			an[ta++][1]=y;
			int ta1=0,ta2=0;
			for(int i=0;i<m;i++){

				if(mp[x][i+1]==0||i==m-1){
					printf("ok7\n");
				ta1=i;
				break;}
				}
			for(int i=0;i<m;i++){
				if(mp[y][i]==0||i==m-1){
				ta2=i;
				break;
				}	
				
			}
			printf("%d %d ok3\n",x,ta1);
			mp[y][ta2]=mp[x][ta1];
			mp[x][ta1]=0;
			printf("%d %d ok6\n",tim+1,ta);
			int aaa=dfs(tim+1,mp,an,ta);
			if(aaa!=-1)
			return aaa;
			ta--;
		}
	}
}

int main(){

freopen("ball1.in","r",stdin);
freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int i1=0;i1<m;i1++){
			scanf("%d",&mpp[i][i1]);
		}
	}

	int tim=dfs(0,mpp,ans,0);
	printf("%d\n",tim);
	for(int i=0;i<tim;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	
return 0;
}


