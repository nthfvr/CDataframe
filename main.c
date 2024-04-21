#include <stdio.h>
#include <stdlib.h>
#include "colonnes.h"
#include "cdataframe.h"

int main()
{

    int main(int argc, const char * argv[]) {
    COLUMN *mycol = create_column("My column");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    
    COLUMN *mycol2 = create_column("My column2");
    insert_value(mycol2, 5);
    insert_value(mycol2, 4);
    insert_value(mycol2, 1);
    
    COLUMN**tab = malloc(2);
    tab[0] = mycol;
    tab[1] = mycol2;

    create_CDATAFRAME("dkd");
    // CDATAFRAME_create("dfd");
    // CDATAFRAME_addColumn(myCol);
    // CDATAFRAME_addColumn(myCol2);
    
    afficher_tout_CDATAFRAME(create_CDATAFRAME_Saisi("www", 2, 250, tab));
    afficher_CDATAFRAME_ligne(create_CDATAFRAME_Saisi("www", 2, 250, tab), 2);
    afficher_CDATAFRAME_colonne(create_CDATAFRAME_Saisi("www", 2, 250, tab), 1);
    
    COLUMN *mycol = create_column("My column");
    int val = 5,i;
    if (insert_value(mycol, val)==1) {
        printf("Value added successfully to my column\n");
    }else
    {printf("Error adding value to my column\n");}
    print_col(mycol);
    printf("%d\n",occu_val(mycol, 5));
    printf("%d\n",val_at_pos(mycol, 0));
    printf("%d\n",nb_val_inf(mycol, 9));
    delete_column( &mycol);
    return 0;
}
