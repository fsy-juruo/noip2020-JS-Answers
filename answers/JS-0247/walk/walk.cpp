#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	int y=1;
	char a;
	a=getchar();
	while(a<'0'||a>'9'){
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=y;
}
int n,k;
int w[11];
int ff[1000008][2][11];
int fz[11];
bool ffz[1000008][2][11];
int fff[11][2];
int fans;
int fzb[11];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	int ffm=1000000007;
	for(int i=0;i<1000008;++i){
		for(int j=0;j<=10;++j)ff[i][0][j]=1e9*2,ff[i][1][j]=1e9*2;
	}
	for(int i=1;i<=k;++i){
		read(w[i]);
		fzb[i]=1;
	}
	for(int i=1;i<=n;++i){
		int c,d;
		read(c);read(d);
		fz[c]+=d;
		if(fz[c]<0){ 
			if(!ffz[-fz[c]][0][c]){
				ffz[-fz[c]][0][c]=true;
		        ff[-fz[c]][0][c]=i;
		        fff[c][0]=min(fff[c][0],fz[c]);
	       	}
		}
		if(fz[c]>=0){
	    	if(!ffz[fz[c]][1][c]){
	    		ffz[fz[c]][1][c]=true;
		        ff[fz[c]][1][c]=i;
		        fff[c][1]=max(fff[c][1],fz[c]);
	       	}  
    	}
	}
	bool flag=true;
	for(int i=1;i<=k;++i){
		if(fz[i]!=0||fff[i][1]>w[i]||fff[i][0]<1){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<-1<<endl;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=w[1];++i){
			int qfz=i;
			while((!ffz[qfz][0][1])&&(!ffz[w[1]-qfz+1][1][1])){
				fans+=n;
				fans%=ffm;
				qfz+=fz[1];
			}
			fans+=min(ff[qfz][0][1],ff[w[1]-qfz+1][1][1]);
			fans%=ffm;
		}
		cout<<fans<<endl;
		return 0;
	}
	if(k==2){
		for(int i=1;i<=w[1];++i){
			for(int j=1;j<=w[2];++j){
				int qx=i,qy=j;
				while((!ffz[qx][0][1])&&(!ffz[w[1]-qx+1][1][1])&&(!ffz[qy][0][2])&&(!ffz[w[2]-qy+1][1][2])){
					qx+=fz[1],qy+=fz[2];
					fans+=n;
					fans%=ffm;
				}
				fans+=min(ff[qx][0][1],min(ff[w[1]-qx+1][1][1],min(ff[qy][0][2],ff[w[2]-qy+1][1][2])));
				fans%=ffm;
			}
		}
		cout<<fans<<endl;
		return 0;
	}
	if(k==3){
		for(int i=1;i<=w[1];++i){
			for(int j=1;j<=w[2];++j){
				for(int l=1;l<=w[3];++l){
					int qx=i,qy=j,qz=l;
			    	while(!(ffz[qz][0][3])&&!(ffz[w[3]-qz+1][1][3])&&(!ffz[qx][0][1])&&(!ffz[w[1]-qx+1][1][1])&&(!ffz[qy][0][2])&&(!ffz[w[2]-qy+1][1][2])){
				    	qx+=fz[1],qy+=fz[2],qz+=fz[3];
				    	fans+=n;
					    fans%=ffm;
				}
				fans+=min(ff[w[3]-qz+1][1][3],min(ff[qz][0][3],min(ff[qx][0][1],min(ff[w[1]-qx+1][1][1],min(ff[qy][0][2],ff[w[2]-qy+1][1][2])))));
				fans%=ffm;
				}
			}
		}
		cout<<fans<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}

