#include <stdio.h>
#include "Main.h"
#include "Colonne.h"
#include "Divers.h"
#include "CDataframe.h"

int obtenir_nombre_colonnes(int taille_dataframe)
{
    return taille_dataframe;
}

int obtenir_nombre_lignes(COLONNE** dataframe, int taille_dataframe)
{
    if (taille_dataframe == 0)
        return 0;

    return dataframe[0]->taille_physique;
}

int ajouter_bloc_lignes_aux_colonnes(COLONNE** dataframe, int taille_dataframe, int num_colonne_a_ignorer)
{
    // Parcourir toutes les colonnes du dataframe
    for (int i = 0; i < taille_dataframe; ++i) {
    
        if (i == num_colonne_a_ignorer)
            continue;

        COLONNE* colonne = dataframe[i];

        // Allouer de la m�moire pour x nouvelles lignes
        int nouvelle_taille = colonne->taille_physique + NOMBRE_LIGNES_PAR_BLOC_DATA_COLONNE;
        int* nouvelle_data = realloc(colonne->data, nouvelle_taille * sizeof(int));
        if (nouvelle_data == NULL) {
            fprintf(stderr, "Erreur d'allocation de m�moire pour la colonne %s.\n", colonne->titre);
            continue; // Passer � la prochaine colonne en cas d'erreur
        }

        // Mettre � jour les donn�es de la colonne
        colonne->taille_physique = nouvelle_taille;
        colonne->data = nouvelle_data;
    }
}

int inserer_valeur_avec_gestion_memoire_data_colonnes(COLONNE*** dataframe, int* taille_dataframe, int num_col, int valeur)
{
    int ajouter_bloc_lignes_a_toutes_les_colonnes = 0;

    // Ajouter valeur � colonne
    int ret = inserer_valeur((*dataframe)[num_col], valeur, NOMBRE_LIGNES_PAR_BLOC_DATA_COLONNE, &ajouter_bloc_lignes_a_toutes_les_colonnes);
    if (ret == FAILED) {
        fprintf(stderr, "Erreur d'allocation de m�moire lors de la cr�ation du tableau data de la colonne.\n");
        return 0;
    }

    if (ajouter_bloc_lignes_a_toutes_les_colonnes == 1)
        ajouter_bloc_lignes_aux_colonnes((*dataframe), (*taille_dataframe), num_col);

    // Ici: Si nouveau bloc de lignes ajout�s aux colonnes, ini les valeurs � 0 de toutes les nouvelles lignes pr toutes les colonnes
    
    // Ini les col auxquelles on vient d'ajouter le nouveau bloc de lignes, tout en respectant les data pr�sentes
    

    return 1;
}

int nom_colonne_existe(COLONNE** dataframe, const char* nom_colonne, int taille_CDataframe)
{
    for (int i = 0; i < taille_CDataframe; i++)
    {
        const char* nom = dataframe[i]->titre;

        if (compare_chaines(nom, nom_colonne) == 0)
            return SUCCESS;
    }
    return FAILED;
}

COLONNE** creer_cdataframe_old(int *taille_CDataframe, bool *CDataframe_exists)
{
    (*taille_CDataframe) = 0;
    COLONNE** CDataframe = NULL;
    (*CDataframe_exists) = true;
    return CDataframe;
}
DATAFRAME creer_cdataframe_new(bool* CDataframe_exists, const char* nom_colonne)
{
    // Declaration du dataframe
    DATAFRAME dataframe;

    // Allocation de m�moire pour la dataframe
    dataframe.colonnes = NULL;
    dataframe.taille = 0;
    strcpy(dataframe.titre, "Nom Dataframe"); // Titre par d�faut

    // Modifier le pointeur de bool�en pour indiquer que la dataframe a �t� cr��e
    (*CDataframe_exists) = true;

    // Retourner la dataframe cr��
    return dataframe;
}

int afficher_les_colonnes(COLONNE** dataframe, int taille_dataframe)
{
    for (int num_col = 0; num_col < taille_dataframe; num_col++)
    {
        afficher_colonne(dataframe, taille_dataframe, num_col);
    }
}

int afficher_noms_colonnes(COLONNE** dataframe, int taille_dataframe)
{
    if (dataframe == NULL || taille_dataframe == -1)
    {
        printf("\nLe CDataframe est vide ou non initialise.\n");
        return FAILED;
    }

    int nombre_col = 0;

    printf("\nNoms des colonnes :\n\n");

    for (int i = 0; i < taille_dataframe; i++) {
        COLONNE* colonne = dataframe[i];
        printf(" [%d] = ", nombre_col);
        printf("%s\n", colonne->titre);
        nombre_col += 1;
    }

    return nombre_col;
}