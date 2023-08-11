#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "et.h"
int compare(const void *a,const void *b){
	return strcmp(((const etudiants*)a)->nom,((const etudiants*)b)->nom);
	}
int main(){
	etudiants* mit=malloc(100*sizeof(etudiants));
	FILE* file=fopen("data_info.csv","r+");
	if (file==NULL){
		printf("erreur lors de l'ouverture");
		exit(EXIT_FAILURE);
	}
	char row[256];int len;
	for(len=0; fgets(row, sizeof(row), file); len++){
		sscanf(row,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",mit[len].nom,mit[len].prenom,mit[len].numero,mit[len].tel,mit[len].email,mit[len].adresse,mit[len].datenaiss,mit[len].lieu,mit[len].bacc,mit[len].genre,mit[len].cin,mit[len].URL);
	}
	
	qsort(mit, len,sizeof(etudiants),compare);
	FILE* file1=fopen("final.csv","w+");
	for(int i=1;i<len;i++){
		fprintf(file1,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",mit[i].nom,mit[i].prenom,mit[i].numero,mit[i].tel,mit[i].email,mit[i].adresse,mit[i].datenaiss,mit[i].lieu,mit[i].bacc,mit[i].genre,mit[i].cin,mit[i].URL);
		}	
	fclose(file1);
	fclose(file);
	return 0;
}

