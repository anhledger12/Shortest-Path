//floyd warshall
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

string const tentepin("input.txt");
string const tentepout("output.txt");

struct shortpath {
	int dist; 
	int length;
	short dir[100];
};
struct shortpath a[100][100];
unsigned long long check;
short saveleast[500] = {0};
long save=10e8; 
int savestep=0;	
short tempdir[500]={0};
int lengthtempdir=0;
int savecount=0;
int maxcount;

int checker(int j, short tempdir[], int *lengthtempdir);
void connecting (int n, int i, int last, long *curlength,unsigned long long *check, short tempdir[], int *lengthtempdir);
void floydwarshall();
//main-------------------------------------------------
int main() {
	floydwarshall();
	return 0;
}
//main-------------------------------------------------
int checker(int j, short tempdir[], int *lengthtempdir) {
	for (int i=0;i<*lengthtempdir;i++) 
	if (tempdir[i]==j) return 0;
	return 1;
}
void connecting (int n, int i, int last, long *curlength,unsigned long long *check, short tempdir[], int *lengthtempdir) {
	if (savecount<maxcount) {
	if (*curlength<save) {
		if (*check==0) 
			if (tempdir[*lengthtempdir-1]!=last) {
				int i=tempdir[*lengthtempdir-1];
				long long temp=*check;
				int j=last;
				for (int h=0;h<a[i][j].length;h++) {
						*check=*check&(~(1<<a[i][j].dir[h]));
						tempdir[*lengthtempdir-1+h]=a[i][j].dir[h]; 
					}
					*curlength+=a[i][j].dist;
					*lengthtempdir+=a[i][j].length-1;
					connecting(n,j,last,curlength,check,tempdir,lengthtempdir);
					*check=temp;
					*curlength-=a[i][j].dist;
					*lengthtempdir-=a[i][j].length-1;
					for (int h=0;h<a[i][j].length;h++) {
						tempdir[*lengthtempdir+h]=0; 
					}
				}
			else
		{
			save=*curlength;
			for (int i=0;i<*lengthtempdir;i++)
			saveleast[i]=tempdir[i];
			savestep=*lengthtempdir;
			savecount++;
		}
		else 
			for (int j=0;j<n;j++) {
				if (j==i) continue;
				else if (checker(j,tempdir,lengthtempdir)==0) continue;
				else {
					
					long long temp=*check;
					for (int h=0;h<a[i][j].length;h++) {
						*check=*check&(~(1<<a[i][j].dir[h]));
						tempdir[*lengthtempdir-1+h]=a[i][j].dir[h];
					}
					*curlength+=a[i][j].dist;
					*lengthtempdir+=a[i][j].length-1;
					connecting(n,j,last,curlength,check,tempdir,lengthtempdir);
					*check=temp;
					*curlength-=a[i][j].dist;
					*lengthtempdir-=a[i][j].length-1;
					for (int h=0;h<a[i][j].length;h++) {
						tempdir[*lengthtempdir+h]=0; 
					}		
				}
			}
		}
	}	 
}

void floydwarshall() {
	int n,m;
	int first,last;
	int u,w,f;
	long curlength=0;
	ifstream in(tentepin.c_str());
	if(in)
	{
		in>>m>>n;
		in>>first>>last;
		
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			a[i][j].length=2;
			a[i][j].dir[0]=i;
			a[i][j].dir[1]=j;
			a[i][j].dist=10e8;
		}
			
		for (int i=0;i<m;i++) {
			in>>u>>w>>f;
			a[u][w].dist=f;
			a[w][u].dist=f;
		} 	
		
		//floyd warshall algorithm here
		for (int k=0;k<n;k++) {
			for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) 
			if (i!=j)
			{
				int temp=a[i][k].dist + a[k][j].dist;
				if (temp<a[i][j].dist) {
					int newlength=a[i][k].length+a[k][j].length-1;
					for (int h=0;h<a[i][k].length;h++) 
					a[i][j].dir[h]=a[i][k].dir[h];
					for (int h=a[i][k].length-1;h<newlength;h++)
					a[i][j].dir[h]=a[k][j].dir[h-a[i][k].length+1];
					a[i][j].length=newlength;
					a[i][j].dist=temp;
				}
			}	
		}
	}
	else {cout<<"loi khong doc duoc tep"<<endl;}
	
	if (n<15) maxcount=50;
	else if (15<=n<30) maxcount=20;
	else maxcount=2;
	
	check= pow(2,n)-1;
	tempdir[0]=first;
	check=check&(~(1<<first));
	lengthtempdir=1;
	connecting(n,first,last,&curlength,&check,tempdir,&lengthtempdir);
	
	ofstream out(tentepout.c_str());
	if (out)
	{
		//code to check"" out<<n<<" "<<savestep<<"\n";
		for (int i=0;i<savestep-1;i++)
		out<<saveleast[i]<<" ";
		out<<saveleast[savestep-1]<<"\n";
		out<<save;
	}
	else {cout<<"loi khong in duoc tep"<<endl;}
}
