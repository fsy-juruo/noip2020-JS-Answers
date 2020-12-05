#include<bits/stdc++.h>
using namespace std;
int a[6],p[105][2],pos[6];
int n,k,day=1,ans=0;
void runone(){
	for(int j=1;j<=n;j++){
		pos[p[j][1]]+=p[j][2];
		//cout<<pos[1]<<endl;//hh
		if(pos[p[j][1]]<1){
			ans+=(pos[p[j][1]]-p[j][2]);
			return;	
		}
			else if(pos[p[j][1]]>a[p[j][1]]){
				ans+=(a[p[j][1]]-(pos[p[j][1]]-p[j][2])+1);
				return;
			}
					else ans+=abs(p[j][2]);
	}
	runone();
}
void onee(){
	scanf("%d",&a[1]);
	day=a[1];
	for(int i=1,c,d;i<=n;i++){
		scanf("%d%d",&c,&d);
		p[i][1]=c;
		p[i][2]=d;
	}
	for(int i=1;i<=day;i++){
		pos[1]=i;
		runone();
	}
}
void runtwo(){
	for(int j=1;j<=n;j++){
		pos[p[j][1]]+=p[j][2];
		if(pos[p[j][1]]<1){
			ans+=(pos[p[j][1]]-p[j][2]);
			return;	
		}
			else if(pos[p[j][1]]>a[p[j][1]]){
				ans+=(a[p[j][1]]-(pos[p[j][1]]-p[j][2])+1);
				return;
			}
					else ans+=abs(p[j][2]);
	}
	runtwo();
}
void twoo(){
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);	
		day*=a[i];
	}
	for(int i=1,c,d;i<=n;i++){
		scanf("%d%d",&c,&d);
		p[i][1]=c;
		p[i][2]=d;
	}
	for(int i=1;i<=day;i++){
		int x=i,y=1;
		while(x>a[1]){
			x-=a[1];
			y++;
		}
		pos[1]=x;
		pos[2]=y;
		runtwo();
	}
}
void runthree(){
	for(int j=1;j<=n;j++){
		pos[p[j][1]]+=p[j][2];
		if(pos[p[j][1]]<1){
			ans+=(pos[p[j][1]]-p[j][2]);
			return;	
		}
			else if(pos[p[j][1]]>a[p[j][1]]){
				ans+=(a[p[j][1]]-(pos[p[j][1]]-p[j][2])+1);
				return;
			}
					else ans+=abs(p[j][2]);
	}
	runthree();
}
void threee(){
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);	
		day*=a[i];
	}
	for(int i=1,c,d;i<=n;i++){
		scanf("%d%d",&c,&d);
		p[i][1]=c;
		p[i][2]=d;
	}
	for(int i=1;i<=day;i++){
		int x=i,y=1,z=1;
		while(x>a[1]){
			while(x>a[1]*a[2]){
				x-=a[1]*a[2];
				z++;
			}
			if(x>a[1]){
				x-=a[1];
				y++;
			}
		}
		pos[1]=x;
		pos[2]=y;
		pos[3]=z;
		runthree();
	}
}
void runfour(){
	for(int j=1;j<=n;j++){
		pos[p[j][1]]+=p[j][2];
		if(pos[p[j][1]]<1){
			ans+=(pos[p[j][1]]-p[j][2]);
			return;	
		}
			else if(pos[p[j][1]]>a[p[j][1]]){
				ans+=(a[p[j][1]]-(pos[p[j][1]]-p[j][2])+1);
				return;
			}
					else ans+=abs(p[j][2]);
	}
	runfour();
}
void fourr(){
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);	
		day*=a[i];
	}
	for(int i=1,c,d;i<=n;i++){
		scanf("%d%d",&c,&d);
		p[i][1]=c;
		p[i][2]=d;
	}
	for(int i=1;i<=day;i++){
		int x=i,y=1,z=1,z1=1;
		while(x>a[1]){
			while(x>a[1]*a[2]*a[3]){
				x-=a[1]*a[2]*a[3];
				z1++;
			}
			while(x>a[1]*a[2]){
				x-=a[1]*a[2];
				z++;
			}
			if(x>a[1]){
				x-=a[1];
				y++;
			}
		}
		pos[1]=x;
		pos[2]=y;
		pos[3]=z;
		pos[4]=z1;
		runfour();
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1) onee();
	if(k==2) twoo();
	if(k==3) threee();
	if(k==4) fourr();
	printf("%d\n",ans);
	return 0;
}
