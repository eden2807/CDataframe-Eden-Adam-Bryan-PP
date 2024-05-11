#include <stdio.h>
#include "Alimentation.h"
#include "CDataframe.h"

#pragma region CDataframe 1

int remplir_dataframe_automatiquement(DATAFRAME1* dataframe)
{
    int ajouter_bloc_lignes_a_toutes_les_colonnes = 0;
    
    // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 1");

    // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 2");

    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 0, 10);
    
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 0, 11);

    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 0, 12);

    // Ajouter une valeur � Colonne 2
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 1, 20);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 1, 21);

    // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 3");

    // Ajouter quelques valeurs � Colonne 3
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 2, 30);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 2, 31);

    // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 4");

    // Ajouter quelques valeurs � Colonne 4
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 3, 40);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 3, 41);

        // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 5");

    // Ajouter quelques valeurs � Colonne 5
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 4, 50);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 4, 51);

    ajouter_colonne(dataframe, "Colonne 6");
    
    // Ajouter quelques valeurs � Colonne 6
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 60);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 61);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 62);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 63);

    return 1;
}

#pragma endregion Fin CDataframe 1

#pragma region CDataframe 2

int populate_dataframe_automatically(DATAFRAME2* dataframe)
{
    int add_block_lines_to_all_columns = 0;

    // Ajouter une colonne au dataframe
    add_column(dataframe, INT,"Colonne 1");

    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 0, 10);

    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 0, 11);

    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 0, 12);

    // Ajouter une colonne au dataframe
    add_column(dataframe, CHAR, "Colonne 2");

    // Ajouter une valeur � Colonne 2
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 1, 20);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 1, 21);

    // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 3");

    // Ajouter quelques valeurs � Colonne 3
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 2, 30);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 2, 31);

    // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 4");

    // Ajouter quelques valeurs � Colonne 4
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 3, 40);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 3, 41);

    // Ajouter une colonne au dataframe
    ajouter_colonne(dataframe, "Colonne 5");

    // Ajouter quelques valeurs � Colonne 5
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 4, 50);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 4, 51);

    ajouter_colonne(dataframe, "Colonne 6");

    // Ajouter quelques valeurs � Colonne 6
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 60);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 61);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 62);
    inserer_valeur_avec_gestion_memoire_data_colonnes(dataframe, 5, 63);

    return 1;
}

#pragma endregion Fin CDataframe 2

