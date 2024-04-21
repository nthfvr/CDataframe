// Création de l'objet et des attributs d'un CDATAFRAM
typedef struct {
    char titre[20];
    COLUMN **columns; // Cela nous permet ainsi de créer un tableau de colonne, nous déclarons un pointeur vers un tableau de pointeurs vers des colonnes. Cela signifie que nous pouvons stocker plusieurs pointeurs de colonnes dans columns, ce qui nous permet de représenter un tableau dynamique de colonnes.
    int taille_physique;
    int taille_logique;
} CDataframe;

CDataframe* create_CDATAFRAME(char *title);
CDataframe* create_CDATAFRAME_Saisi(char *title, int taille_logique, int taille_physique, COLUMN** tableau_colonne);
void afficher_tout_CDATAFRAME (CDataframe* Datafram);
void afficher_CDATAFRAME_ligne (CDataframe* Datafram, int nb_ligne);
void afficher_CDATAFRAME_colonne (CDataframe* Datafram, int nb_colonne);


// fonctionnalités tache 4 : 
void Afficher_nb_lignes_Cdataframe (CDataframe* Dataframe);
void Afficher_nb_colonnes_Cdataframe (CDataframe* Dataframe);
void valeurs_egale_x_CdataFrame (CDataframe* DataFrame, int x);
void valeurs_sup_x_CdataFrame (CDataframe* DataFrame, int x);
void valeurs_inf_x_CdataFrame (CDataframe* DataFrame, int x);
