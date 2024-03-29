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
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int occu_val(COLUMN* col, int val);
int val_at_pos(COLUMN* col,int pos);
int nb_val_supp(COLUMN* col, int val);
int nb_val_inf(COLUMN* col, int val);




#endif CDATAFRAME_COLONNES_H