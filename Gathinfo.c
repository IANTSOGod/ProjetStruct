#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
int compare(const void *a,const void *b){
	return strcmp(((const pc*)a)->label,((const pc*)b)->label);
}
int main(){
	pc* mit=malloc(46*sizeof(pc));
	FILE* file=fopen("PcMIT.csv","r+");
	if (file==NULL){
		printf("erreur lors de l'ouverture");
		exit(EXIT_FAILURE);
	}
	char row[256];int len;
	for(len=0; fgets(row, sizeof(row), file); len++){
		sscanf(row,"%s	%s	%s",mit[len].marque,mit[len].mac,mit[len].label);
	}
	
	qsort(mit, len,sizeof(pc),compare);
	for(int i=0;i<len;i++){
		printf("Marque pc[%d]:%s\n",i,mit[i].marque);
		printf("Mac pc[%d]:%s\n",i,mit[i].mac);
		printf("label pc[%d]:%s\n",i,mit[i].label);
	}
	
	FILE* file1=fopen("pc.csv","w");
	if(file1 == NULL){
		perror("Tsy voavaha");
		exit(1);
	}
	for(int i=1;i<len;i++){
		fprintf(file1,"%s	%s	%s\n",mit[i].marque,mit[i].mac,mit[i].label);
	}	
	fclose(file1);
	fclose(file);
	return 0;
}
