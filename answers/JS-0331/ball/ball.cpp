#include <bits/stdc++.h>
using namespace std;
int plate[60][410];
int output[820010][2];
int n,m;
int ans=0;
void ott(int st,int ed) {
	++ans;
	output[ans][0]=st;
	output[ans][1]=ed;
	//printf("%d %d\n",st,ed);
}

void mve(int sti,int stj,int edi,int edj) {
	if(stj<=edj) {
		//cout<<"st"<<sti<<" "<<stj<<"ed"<<edi<<" "<<edj<<endl;
		for(register int i=m;i>=stj;i--) {
			swap(plate[sti][i],plate[n+1][m-i+1]);
			ott(sti,n+1);
			//printf("%d %d\n",sti,n+1);
		}
		for(register int i=m;i>=edj;i--) {
			swap(plate[edi][i],plate[sti][m-i+stj]);
			ott(edi,sti);
			//printf("%d %d\n",edi,sti);
		}
		swap(plate[edi][edj],plate[n+1][m-stj+1]);
		ott(n+1,edi);
		swap(plate[sti][m-stj+edj],plate[n+1][m-stj+1]);
		ott(sti,n+1);
		for(register int i=stj+m-edj-1;i>=stj;i--) {
			swap(plate[sti][i],plate[edi][edj+(stj+m-edj-1-i)+1]);
			ott(sti,edi);
		}
		for(register int i=m-stj+1;i>=1;i--) {
			swap(plate[n+1][i],plate[sti][stj+m-stj+1-i]);
			ott(n+1,sti);
		}
	} else {
		for(register int i=m;i>=edj;i--) {
			swap(plate[edi][i],plate[n+1][m-i+1]);
			ott(edi,n+1);
		}
		for(register int i=m;i>stj;i--) {
			swap(plate[sti][i],plate[edi][edj-1+m-i+1]);
			ott(sti,edi);
		}
		swap(plate[sti][stj],plate[n+1][m-edj+1+1]);
		ott(sti,n+1);
		for(register int i=edj+m-stj-1;i>=edj;i--) {
			swap(plate[edi][i],plate[sti][stj+(edj+m-stj-1-i)]);
			ott(edi,sti);
		}
		swap(plate[n+1][m-edj+1+1],plate[edi][edj]);
		ott(n+1,edi);
		swap(plate[n+1][m-edj+1],plate[sti][m]);
		ott(n+1,sti);
		for(register int i=m-edj;i>=1;i--) {
			swap(plate[n+1][i],plate[edi][edj+(m-edj-i+1)]);
			ott(n+1,edi);
		}
	}
}

int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++) {
		for(register int j=1;j<=m;j++) {
			scanf("%d",&plate[i][j]);
		}
	}
	//cout<<"c";
	for(register int i=1;i<=n;i++) {
		int st=plate[i][1];
		for(register int j=2;j<=m;j++) {
			if(plate[i][j]==st) {
			//	cout<<"c"<<j<<endl;
				continue;
			}
			int rnk,dpt;
			bool flag=false;
			for(dpt=1;dpt<=m;dpt++) {
				for(rnk=i+1;rnk<=n;rnk++) {
					if(plate[rnk][dpt]==st) {
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) {
				/*cout<<"***"<<endl;
				for(int k=1;k<=n;k++){
					for(int l=1;l<=m;l++) {
						cout<<plate[k][l]<<" ";
					}
					cout<<endl;
				}
				cout<<"******"<<endl;*/
				mve(rnk,dpt,i,j);
			}
			//cout<<"check";
			
			//if(dpt<=j)
		}
	}
	printf("%d\n",ans);
	for(register int i=1;i<=ans;i++) {
		printf("%d %d\n",output[i][0],output[i][1]);
		//if(i==148) system("pause");
	}
	/*for(register int i=1;i<=n;i++) {
		for(register int j=1;j<=m;j++) {
			cout<<plate[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}
//checker ball.in ball.out
/*
2 3
1 1 2
2 1 2
*/
