#include <stdio.h>
 
 
typedef struct _test
{
    int i;
    char a[5];
    int c;
}t_Test;
 
int main (void)
{
    FILE * f = fopen("test.bd", "wb+"); // ouvre le fichier en mode lecture/écriture binaire
 
    t_Test t1 = {12, "Lea\0", 25}, t2;
 
    if(f != NULL) // si l'ouverture s'est bien passée
    {
        if(fwrite(&t1, sizeof(t_Test), 1, f) != 1) // écris t1 dans le fichier avec fwrite
        {
            perror("Erreur lors de l'ecriture des donnees dans le fichier!!");
            fclose(f);
            return -1;
        }
 
        fseek(f, 0, SEEK_SET); // remets le curseur du fichier au début
 
        if(fread(&t2, sizeof(t_Test), 1, f) != 1) // lis t2 à partir du fichier
        {
            perror("Erreur lors de la lecture des donnees dans le fichier!!");
        }
        else
        {
            printf("%d %s %d\n", t2.i, t2.a, t2.c); // affiche le résultat
        }
 
        fclose(f);
    }
 
    return 0;
}
