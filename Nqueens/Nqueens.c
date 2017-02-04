
#include <stdio.h>
#include <stdlib.h>

int verif(int *a, int r);
void afficherSolution(int *a, int n,int count);
void nReines(int *a, int n, int r);

int main(void) {
	int n,*a = NULL;
	setbuf(stdout, NULL);

	printf("Entrer le nombre de Reines : ");
	scanf("%d",&n);
	printf("\n");

	a = (int*) calloc(n, sizeof(int));

	nReines(a,n,0);

	system("pause");
	return EXIT_SUCCESS;
}

int verif(int *a, int r){
	int i;

	for(i = 0; i < r; i++){

		if(a[i] == a[r] || abs(r-i) == abs(a[r] - a[i])){
			return 0;
		}
	}

	return 1;
}

void afficherSolution(int *a, int n, int count){

	int i;
	printf("Solution %d\n", count);
	for(i = 0; i < n; i++){

		printf("Reine : %d est placée dans la position %d\n",i+1,a[i]);
	}

	printf("\n");
}

int c;
void nReines(int *a, int n, int r){
	int i;

	for(i = 0; i < n; i++){

		a[r] = i;

		if(verif(a,r)){

			if(r+1 < n){
				nReines(a, n,r+1);
			}
			else{
				afficherSolution(a,n,c++);
				printf("\n");
			}
		}
	}
}