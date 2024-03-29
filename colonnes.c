#include <stdio.h>
#include <stdlib.h>
#include "colonnes.h"

#define REALOC_SIZE 256

//PARTIE 1
COLUMN *create_column(char* title)
{
    COLUMN* c = (COLUMN*)malloc(sizeof(COLUMN));
    c -> titre = title;
    c-> donnees = NULL;
    c -> taille_phy=256;
    c -> taille_log=0;
    return c;
}

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

void delete_column(COLUMN **col)
{
    free((*col)->donnees);
    free(*col);
}

void print_col(COLUMN* col)
{
    int i;
    for(i=0;i<(col->taille_log);i++)
    {
        printf("[%d] %d\n",i,(col->donnees)[i]);
    }
}

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

int val_at_pos(COLUMN* col,int pos)
{
    return((col->donnees)[pos]);
}

int nb_val_supp(COLUMN* col, int val)
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

int nb_val_inf(COLUMN* col, int val)
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