#ifndef CDATAFRAME_COLONNES_H
#define CDATAFRAME_COLONNES_H

// PARTIE 1
typedef struct
{
    char* titre;
    int taille_phy;
    int taille_log;
    int* donnees;
} COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value) {
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int occurence(COLUMN *col, int x);
int valeur_presente_x (COLUMN *col, int x);
int valeur_superieur_x (COLUMN *col, int x);
int valeur_inferieur_x (COLUMN *col, int x);

#endif CDATAFRAME_COLONNES_H
