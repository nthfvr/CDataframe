#include <stdio.h>
#include <stdlib.h>
#include "colonnes.h"

#define REALOC_SIZE 256

//PARTIE 2
COLUMN *create_column(ENUM_TYPE type, char *title)
{
    COLUMN* c = (COLUMN*)malloc(sizeof(COLUMN));
    if (c == NULL)
    {
        return NULL;
    }
    c -> titre = title;
    c -> taille_phy=256;
    c -> taille_log=0;
    c-> data = NULL;
    c -> column_type=type;
    c-> index = NULL;
    return c;
}

int insert_value(COLUMN *col, void *value)
{
    if (col->data == NULL)   // si la colonne ne contient aucune valeurs => on alloue dynamiquement la taille physique
    {
        col->data = (void**)malloc(col->taille_phy * sizeof(void*));
    } else if(col->taille_phy == col->taille_log)   // si le tableau est "plein" => on réalloue dynamiquement la taille physique
    {
        col->taille_phy += REALOC_SIZE;
        col->data = (void**)realloc(col->data,col->taille_phy);
    }
    switch(col->column_type){
        case INT:
            col->data[col->taille_log] = (int*) malloc (sizeof(int));
            *((int*)col->data[col->taille_log])= *((int*)value);
            break;
        case CHAR:
            col->data[col->taille_log] = (char*) malloc (sizeof(char));
            *((char*)col->data[col->taille_log])= *((char*)value);
            break;
        case FLOAT:
            col->data[col->taille_log] = (float*) malloc (sizeof(float));
            *((float*)col->data[col->taille_log])= *((float*)value);
            break;
        case STRING:
            col->data[col->taille_log] = (char**) malloc (sizeof(char*));
            *((char**)col->data[col->taille_log])= *((char**)value);
            break;
        case DOUBLE:
            col->data[col->taille_log] = (double*) malloc (sizeof(double));
            *((double*)col->data[col->taille_log])= *((double*)value);
            break;
        case UINT:
            col->data[col->taille_log] = (unsigned int*) malloc (sizeof(unsigned int));
            *((unsigned int*)col->data[col->taille_log])= *((unsigned int*)value);
            break;
        case STRUCTURE:
            col->data[col->taille_log] = (void**) malloc (sizeof(void*));
            *((void**)col->data[col->taille_log])= *((void**)value);
            break;
        default:
            return 0;
    }
    (col->taille_log)++;

    if ((col->data[col->taille_log-1]) != NULL )    // test si la valeur est bien inséré
    {
        return 1;
    } else
    {
        return 0;
    }
}

void delete_column(COLUMN **col)
{
    for (int i=0;i<(*col)->taille_phy;i++)
        free((*col)->data[i]);
    free((*col)->data);
    free((*col)->index);
    free(*col);
}
/*
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
*/