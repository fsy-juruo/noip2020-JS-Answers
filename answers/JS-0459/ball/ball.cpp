# include<bits/stdc++.h>
using namespace std;
# define ll long long
const int maxn=820000;

ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

int a[51][401],top[60],n,m,ans,bbb[maxn],ccc[maxn];

bool check(){
	for (int i=2;i<=m;i++){
		if (a[1][i]!=a[1][i-1]) return 0;
	}
	for (int i=2;i<=m;i++){
		if (a[2][i]!=a[2][i-1]) return 0;
	}
	return 1;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	n=read();
	m=read();
//	cout<<1<<endl;
	for (int i=1;i<=n;i++){
		for (int j=m;j>=1;j--){
			a[i][j]=read();
		}
		top[i]=m;
	}
	if (n==1){
		cout<<m<<endl;
		for (int i=1;i<=m;i++){
			cout<<1<<' '<<2<<endl;
		}
		return 0;
	}
	if (n==2){
		int p=m,q=m,k=0,cnt=0;
		while (!check()){
			while (a[1][p]==a[3][cnt] || cnt==0){
				if (k<m){
					a[3][++k]=a[1][p];
					p--;
					bbb[k]=1;
					ccc[k]=3;
				}
			}
			while (a[2][p]==a[3][k] || k==0){
				if (k<m){
					a[3][++k]=a[2][p];
					p--;
					bbb[k]=2;
					ccc[k]=3;
				}
			}
		}
			
	}
////	cout<<"asdsdJKQO934892832982\n";
//	
//		for (int j=1;j<=m;j++){
//	for (int i=1;i<=n;i++){
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
	top[n+1]=0;
	for (int i=1;i<=n;i++){
		
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){// 目标点位置 
				
//					cout<<j<<' '<<k<<' '<<i<<endl;
				if (a[j][k]==i){
					int kk=i+1;
//					cout<<"ASDSADSAD";	
					for (;kk<=n+1 && kk!=j;kk++){
						if (top[kk]<m){
//							cout<<kk<<endl;
							bool t=0;
							for (int kkk=top[kk]+1;kkk<=m;kkk++){
								if (top[j]==k){
									t=1;
									break;
								}
								a[kk][kkk]=a[j][top[j]];
								a[j][top[j]]=0;
								top[j]--;
								top[kk]++;
								ans++;
								bbb[ans]=j;
								ccc[ans]=kk;
//								cout<<j<<' '<<kk<<endl;
							}
							if (t){
								break;
							}
						}
					}//露出目标 
//					cout<<"ASDASDAD1"<<endl<<endl;
					
//					cout<<kk<<endl;
					for (;kk<=n+1 && kk!=j+1;kk++){
						if (top[kk]<m){
							a[kk][top[kk]+1]=a[j+1][top[j+1]];
							a[j+1][top[j+1]]=0;
							top[j+1]--;
							top[kk]++;
							ans++;
							bbb[ans]=j+1;
							ccc[ans]=kk;
//							cout<<j+1<<' '<<kk<<endl;
							break; 
						}
					}//留出空位 
//					cout<<"ASDASDAD2"<<endl<<endl;
					
					a[j+1][++top[j+1]]=a[j][k];
					a[j][k]=0;//目标移向空位 
					ans++;
					bbb[ans]=j;
					ccc[ans]=j+1;
//					cout<<j<<' '<<j+1<<endl;
//					cout<<"ASDASDAD3"<<endl<<endl;
					kk=i;
					for (;kk<=n+1;kk++){
//						cout<<kk<<' '<<top[kk]<<' '<<endl;
						if (top[kk]<m){
							bool t=0;
							for (int kkk=top[kk]+1;kkk<=m && top[j]>k;kkk++){
								if (kk==j) continue;
								if (a[n+1][top[n+1]]==i){
									t=1;
									break;
								}
								a[kk][kkk]=a[n+1][top[n+1]];
								a[n+1][top[n+1]]=0;
								top[n+1]--;
								top[kk]++;
								ans++;
								bbb[ans]=n+1;
								ccc[ans]=kk;
//								cout<<n+1<<' '<<kk<<endl;
							}
//							cout<<t<<endl;
							if (t || top[n+1]==0){
								break;
							}
						}
					}//留下目标列 n+1
//					cout<<endl<<kk<<endl;
//					cout<<"ASDASDAD4"<<endl<<endl;
					
					if (j+1 != n+1){
						a[n+1][++top[n+1]]=a[j+1][top[j+1]];
						a[j+1][top[j+1]]=0;
						top[j+1]--;
						top[n+1]++;//目标移向目标列 
						ans++;
						bbb[ans]=j+1;
						ccc[ans]=n+1;
	//					cout<<j+1<<' '<<n+1<<endl; 
					}
				}
//					cout<<"ASDASDAD5"<<endl<<endl;
			}
			
			for (int kk=i+1;kk<=n;kk++){ 
				if (top[kk]<m){
					for (int kkk=top[kk]+1;kkk<=m;kkk++){
						a[kk][kkk]=a[i][top[i]];
						a[i][top[i]]=0;
						top[i]--;
						top[kk]++;
						ans++;
						bbb[ans]=i;
						ccc[ans]=kk;
//						cout<<i<<' '<<kk<<endl; 
					}
				}
			}//留出第i列 
//					cout<<"ASDASDAD6"<<endl<<endl;
			
			for (int j=1;j<=m;j++){
				a[i][j]=i;
				a[n+1][j]=0; 
				ans++;
				bbb[ans]=n+1;
				ccc[ans]=i;
//				cout<<n+1<<' '<<i<<endl;
			} //目标列移向第i列，留下第n+1列 
			top[i]=m;
			top[n+1]=0;
//					cout<<"ASDASDAD7"<<endl<<endl;
		}
		
	}
	cout<<ans<<endl;
	for (int i=1;i<ans;i++){
		cout<<bbb[i]<<' '<<ccc[i]<<endl;
	}

	return 0;
}

