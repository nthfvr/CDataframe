#ifndef CDATAFRAME_COLONNES_H
#define CDATAFRAME_COLONNES_H

// PARTIE 2

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *titre;
    unsigned int taille_log; //logical size
    unsigned int taille_phy; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;



COLUMN *create_column(ENUM_TYPE type, char *title);
int insert_value(COLUMN *col, void *value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int occu_val(COLUMN* col, int val);
int val_at_pos(COLUMN* col,int pos);
int nb_val_supp(COLUMN* col, int val);
int nb_val_inf(COLUMN* col, int val);




#endif CDATAFRAME_COLONNES_H