#include <stdio.h>
#include <stdlib.h>
#include "colonnes.h"
/*
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
*/
int main() {
    // Example usage
    COLUMN *col = create_column(STRING, "Age");
    if (col != NULL) {
        printf("Column created successfully!\n");

        char* value = "projet en c";
        if (insert_value(col, &value)) {
            printf("Value inserted successfully!\n");
            printf("Size: %u\n", col->taille_log);
        } else {
            printf("Failed to insert value!\n");
        }
        printf("%s\n",col->data[0][0]);
        // Don't forget to free the memory allocated for the column when it's no longer needed
        delete_column(&col);
    } else {
        printf("Failed to create column!\n");
    }
    return 0;
}
