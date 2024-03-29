#include <stdio.h>
#include <stdlib.h>
#include "colonnes.h"

int main()
{
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
