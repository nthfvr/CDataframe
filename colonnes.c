#include <stdio.h>
#include <stdlib.h>
#include "colonnes.h"

#define REALOC_SIZE 256

//PARTIE 1
// On va maintenant faire une fonction qui permettra de créer une colonne vide (d'abord son prototype) (tache 4.1.1)
COLUMN *create_column(char* title)
{
    COLUMN* c = (COLUMN*)malloc(sizeof(COLUMN));
    c -> titre = title;
    c-> donnees = NULL;
    c -> taille_phy=256;
    c -> taille_log=0;
    return c;
}

// tache 4.1.2, Inserer une valeur dans une colonne.
int insert_value(COLUMN* col, int value)
{
    if (col->donnees == NULL)   // si la colonne ne contient aucune valeurs
    {
        col->donnees = (int*)malloc(col->taille_phy * sizeof(int));
    } else if(col->taille_phy == col->taille_log)   // si le tableau est "plein"
    {
        col->taille_phy += REALOC_SIZE;
        col->donnees = (int*)realloc(col->donnees,col->taille_phy);
    }

    col->donnees[col->taille_log]=value;
    (col->taille_log)++;


    if (col->donnees[col->taille_log-1] == value)     // test si la valeur est bien inséré
    {
        return 1;
    } else
    {
        return 0;
    }
}

// tache 4.1.3, Libérer l’espace allouée par une colonne.
void delete_column(COLUMN **col)
{
    free((*col)->donnees);
    free(*col);
}

// tache 4.1.4, Afficher le contenu d’une colonne
void print_col(COLUMN* col)
{
    int i;
    for(i=0;i<(col->taille_log);i++)
    {
        printf("[%d] %d\n",i,(col->donnees)[i]);
    }
}

// tache 4.1.5, Autres fonctions
// 1 - Retourner le nombre d'occurences d'une valeur x donnée en paramètre
int occu_val(COLUMN* col, int val)
{
    int i,cpt=0;
    for(i=0;i<(col->taille_log);i++)
    {
        if((col->donnees)[i] == val)
        {
            cpt++;
        }
    }
    return cpt;
}

// 2 - Retourner la valeur présente à la position x donné en paramètre
int valeur_presente_x(COLUMN* col,int pos)
{
    return((col->donnees)[pos]);
}

// 3 - Retourner le nombre de valeurs qui sont supérieures à x donné en paramètre
int valeur_superieur_x(COLUMN* col, int val)
{
    int i,cpt=0;
    for(i=0;i<(col->taille_log);i++)
    {
        if((col->donnees)[i] > val)
        {
            cpt++;
        }
    }
    return cpt;
}

// 4 - Retourner le nombre de valeurs qui sont inférieures à x donné en paramètre
int valeur_inferieur_x(COLUMN* col, int val)
{
    int i,cpt=0;
    for(i=0;i<(col->taille_log);i++)
    {
        if((col->donnees)[i] < val)
        {
            cpt++;
        }
    }
    return cpt;
}
