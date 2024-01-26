//Ecrire un programme qui compte le nombre d’occurrence de chaque caractère
//alphabétique présent dans le fichier sans distinction de la casse. Le résultat sera
//stocké dans un autre fichier.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	FILE *fp1; //le fichier a ouvrir
	FILE *fp2; //le nouveau fichier 
	char nom[10]; //le nom du fichier à ouvrir
	char ligne[100]; //pour désignier les lignes dans le fichier
	int t[26]={0}; //tableau pour stocker les occurences de chaque lettre
	
	//lecture du nom du fichier
	printf("donner le nom du fichier a ouvrir : ");
	gets(nom);
	
	//ouvrir le fichier en mode read
	fp1=fopen(nom,"r");
	
	//verifier si le pointeur du fichier est valide
	if (fp1 == NULL){
		printf("le fichier n'a pas pu etre ouvet");
		return 0;
	}
	
	//ouvrir le nouveau fichier en mode write 
	fp2= fopen("ex7w.txt","w");
	
	//verifier si le pointeur du nouveau fichier est valide
	if(fp2== NULL){
		printf("le nouveau fichier n'a pas pu etre creer");
		return 0;
	}
	
	//lecture du contenu du fichier
	while ((fgets(ligne,sizeof(ligne),fp1) != NULL)){
		for (int i =0 ; ligne[i] != '\0'; i++){
			if (isalpha(ligne[i]) ){
				t[tolower(ligne[i])-'a'] ++;	
			}
		}
	}
	
	//affichage des occurence dans un nouveau fichier
	for (int i=0; i<26 ;i++){
		if (t[i] != 0){
			fprintf(fp2,"le nombre d'occurence du caractere %c est : %d\n", i+'a', t[i]);
		}
	}
	
	//fermuture des fichiers
	fclose(fp1);
	fclose(fp2);

	return 0;
}
