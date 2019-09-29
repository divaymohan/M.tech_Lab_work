#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int * matrixChainMul(int *p);
int main(int argc,char *argv[]){

	FILE *fp;
	fp = fopen(argv[1],"r");
	int t;
	fscanf(fp,"%d",&t);
	while(t--){
		int n;
		int q;
		fscanf(fp,"%d",&n);
		int input[n];
		for(int i=0;i<n;i++){
			fscanf(fp,"%d",&input[i]);
		}
		int dpMat[n+1][n+1];
		int solMat[n+1][n+1];
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				dpMat[i][j]=0;
				solMat[i][j]=0;
			}
		}

		for(int l=2;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int j=i+l-1;
				dpMat[i][j]=INT_MAX;
				for(int k=i;k<j;k++){

					q = dpMat[i][k]+dpMat[k+1][j] + input[i-1]*input[k]*input[j];
					if(q<dpMat[i][j]){
						dpMat[i][j]=q;
						solMat[i][j]=k;
					}
				}
			}
		}
		for(int i=1;i<=n ;i++){
			for(int j=1;j<=n;j++){
				printf("%d\t",dpMat[i][j]);
			}
			printf("\n");
		}

		printf("\n\n");

		 for(int i=1;i<n ;i++){
                        for(int j=1;j<n;j++){
                                printf("%d,%d %d\t",i,j,solMat[i][j]);
                        }
                        printf("\n");
                }

	}

	return 0;
}
