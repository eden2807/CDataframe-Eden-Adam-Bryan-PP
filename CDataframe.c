#include <stdio.h>
#include <string.h>
#include "CDataframe.h"
#include "Main.h"
#include "Colonne.h"
#include "Divers.h"
#include "String_manager.h"

int ajouter_colonne(DATAFRAME* dataframe, const char* nom_colonne)
{
    // Ajout d'une colonne en utilisant la fonction creer_colonne
    COLONNE* nouvelle_colonne = creer_colonne(nom_colonne);
    if (nouvelle_colonne == NULL)
    {
        printf("\nErreur lors de la cr�ation de la colonne.\n");
        return 1;
    }

    // Agrandissement du tableau CDataframe pour ajouter la nouvelle colonne
    dataframe->taille++;
    //        *colonnes = realloc(*colonnes, (*taille_dataframe) * sizeof(COLONNE*));
    dataframe->colonnes = realloc(dataframe->colonnes, (dataframe->taille) * sizeof(COLONNE*));
    if (dataframe == NULL)
    {
        printf("\nErreur d'allocation m�moire lors de l'ajout d'une colonne au CDataframe.\n");
        free(nouvelle_colonne);
        return 1;
    }

    // Ajout de la colonne au dataframe
    // (*colonnes)[*taille_dataframe - 1] = nouvelle_colonne;
    dataframe->colonnes[dataframe->taille - 1] = nouvelle_colonne;

    return 0;
}

int obtenir_nombre_lignes(DATAFRAME* dataframe)
{
    if (dataframe->taille == 0)
        return 0;

    return dataframe->colonnes[0]->taille_physique;
}

int egaliser_taille_des_tabs_data_des_colonnes(DATAFRAME* dataframe)
{
    if (dataframe->taille <= 1)
        return 0;

    int taille_du_plus_grand_tab_data = 0;
    int nombre_blocs_a_ajouter = 0;
    int delta_taille = 0;

    // Parcourir toutes les colonnes et recherchee le tab data ayant la taille physique la + �lev�e
    // Cette taille devra �tre allou�e, si ce n'est pas d�j� le cas, � tous les autres tab data des colonnes
    for (int i = 0; i < dataframe->taille; ++i)
    {
        if (dataframe->colonnes[i]->taille_physique > taille_du_plus_grand_tab_data)
        {
            taille_du_plus_grand_tab_data = dataframe->colonnes[i]->taille_physique;
        }
    }

    // Examiner et ajuster eventuellement la taille des colonnes � cette taille max si besoin
    for (int i = 0; i < dataframe->taille; ++i)
    {
        COLONNE* colonne = dataframe->colonnes[i];

        if (colonne->taille_physique == taille_du_plus_grand_tab_data)
            continue;

        if (colonne->taille_physique < taille_du_plus_grand_tab_data)
        {
            // Calculer le nombre de blocs � allouer. Il peut y avoir un ou plusieurs bloc(s).
            // Ex: Si on vient de cr�er une col alors qu'il en existe d�j� une de 512 lignes (2 blocs))
            delta_taille = taille_du_plus_grand_tab_data - colonne->taille_physique;
            nombre_blocs_a_ajouter = delta_taille / NOMBRE_LIGNES_PAR_BLOC_DATA_COLONNE;

            // Allouer le ou les blocs m�moire n�cessaires
            int nouvelle_taille = colonne->taille_physique + (NOMBRE_LIGNES_PAR_BLOC_DATA_COLONNE * nombre_blocs_a_ajouter);

            int* nouveau_tab_data = realloc(colonne->data, nouvelle_taille * sizeof(int));
            if (nouveau_tab_data == NULL)
            {
                printf("\nErreur d'allocation de m�moire pour la colonne %s.\n", colonne->titre);
                return 1;
            }

            // Mettre � jour les donn�es de la colonne
            colonne->taille_physique = nouvelle_taille;
            colonne->data = nouveau_tab_data;
        }
    }
}

int inserer_valeur_avec_gestion_memoire_data_colonnes(DATAFRAME* dataframe, int num_col, int valeur)
{
    // todo:
    //Verifier que la valeur � inserer soit dans la plage des valeurs acceptables
    // "valeur" doit donc �tre compris entre -2 147 483 648 et 2 147 483 647
    
    bool nouveau_bloc_lignes_ajoute_a_colonne = false;

    // Ajouter valeur � colonne
    int ret = inserer_valeur(dataframe->colonnes[num_col], valeur, &nouveau_bloc_lignes_ajoute_a_colonne);
    if (ret != 0)
    {
        printf("\nErreur d'allocation de m�moire lors de la cr�ation du tableau data de la colonne.\n");
        return 1;
    }

    if (nouveau_bloc_lignes_ajoute_a_colonne == true)
        egaliser_taille_des_tabs_data_des_colonnes(dataframe->colonnes, (dataframe->taille), num_col);

    return 0;
}

int nom_colonne_existe(COLONNE** dataframe, char* nom_colonne, int taille_CDataframe)
{
    for (int i = 0; i < taille_CDataframe; i++)
    {
        const char* nom = dataframe[i]->titre;

        if (compare_chaines(nom, nom_colonne) == 0)
            return 0;
    }
    return 1;
}

DATAFRAME creer_cdataframe(bool* dataframe_exists, const char* nom_dataframe)
{
    // Declaration du dataframe
    DATAFRAME dataframe;

    // Ini dataframe
    dataframe.taille = 0;
    
    // Attribution du nom (si nom_dataframe est valide)
    if (nom_dataframe != NULL) {
        strncpy(dataframe.titre, nom_dataframe, sizeof(dataframe.titre) - 1);
        dataframe.titre[sizeof(dataframe.titre) - 1] = '\0'; // Assurer que la cha�ne est termin�e par un caract�re nul
    }
    else
    {
        // Si nom_dataframe est NULL, affecter une cha�ne vide
        dataframe.titre[0] = '\0';
    }

    dataframe.colonnes = NULL;

    // Rappel : les colonnes seront cr��es par la suite, en just in time

    // Modifier le pointeur de bool�en pour indiquer que la dataframe a �t� cr��e
    (*dataframe_exists) = true;

    // Retourner le dataframe cr��
    return dataframe;
}

int afficher_les_colonnes(COLONNE** dataframe, int taille_dataframe)
{
    for (int num_col = 0; num_col < taille_dataframe; num_col++)
    {
        afficher_colonne(dataframe, taille_dataframe, num_col);
    }
}

int afficher_noms_colonnes(DATAFRAME dataframe)
{
    if (dataframe.taille == 0)
    {
        printf("\nLe CDataframe est vide ou non initialise.\n");
        return 1;
    }

    int nombre_col = 0;

    printf("\nNoms des colonnes :\n\n");

    for (int i = 0; i < dataframe.taille; i++) {
        COLONNE* colonne = dataframe.colonnes[i];
        printf(" [%d] = ", nombre_col);
        printf("%s\n", colonne->titre);
        nombre_col += 1;
    }

    return nombre_col;
}

int afficher_cdataframe(DATAFRAME* dataframe)
{
    if (dataframe == NULL)
    {
        printf("\n\n");
        printf("Veuillez d'abord creer le CDataframe et le remplir\n\n");
        return 1;
    }

    // todo: Optimisation: Chercher ici la colonne qui contient le plus de donn�es, et limiter l'affichage des donn�es
    // � cette valeur de ligne au lieu d'afficher toutes les lignes inconditionnellement.
    // rappel: ecrire une fonction nommee "obtenir_num_lignes_max_contenant_donnees(DATAFRAME* dataframe)

    printf("\n\n");

    // affichage de la ligne des noms de toutes les colonnes voulues
    for (int i = 0; i < dataframe->taille; i++)
    {
        printf("Col %d - \"%s\"  ||  ", i, dataframe->colonnes[i]->titre);
    }

    printf("\n");

    int largeur_nombre = 5;
    int ligne_courante = 0;

    // Traiter toutes les colonnes du dataframe
    for (int ligne_courante = 0; ligne_courante <= dataframe->colonnes[0]->taille_physique; ligne_courante++)
    {
        if (ligne_courante == 0)
            printf("\n");
        else
            printf("\n\n");

        // Afficher une ligne contenant les donn�es de toutes les colonnes � cet indice
        for (int col_courante = 0; col_courante < dataframe->taille; col_courante++)
        {
            // Affichage du num de ligne en d�but de ligne une seule et unique fois
            if (col_courante == 0)
            {
                printf(" [%d]", ligne_courante);
                printf("    ");
            }
            else
                printf("              ");

            // Si la colonne contient encore des donn�es pour cette ligne, les afficher
            if (ligne_courante <= dataframe->colonnes[col_courante]->taille_logique - 1)
                printf("  %*d", largeur_nombre, dataframe->colonnes[col_courante]->data[ligne_courante]);
            // Sinon afficher une val par d�faut (� la place d'une valeur quelconque incoh�rente de la cellule lorsque celle-ci ne contient rien) 
            else
                printf("  %*d", largeur_nombre, VALEUR_PAR_DEFAUT_DATA_COLONNE);
        }
    }

    printf("\n\n\n");
    printf(" ");

    // Commentaire final
    switch (dataframe->taille)
    {
    case 0:
        printf("Il n'y a aucune colonne a afficher dans le CDataframe");
        break;
    case 1:
        printf("Les valeurs d'une colonne ont ete affichee pour ce CDataframe");
        break;
    default:
        printf("Les valeurs des %d colonnes ont ete affiches pour ce CDataframe", dataframe->taille);
        break;
    }

    printf("\n\n");

    return 0;
}

int modifier_valeur(DATAFRAME* dataframe, int num_col, int num_ligne, int valeur)
{
    if (num_col > dataframe->taille - 1)
    {
        printf("La colonne num %d n'existe pas", num_col);
        return 1;
    }

    if (num_ligne > dataframe->colonnes[num_col]->taille_logique)
    {
        printf("La colonne num %d ne possede pas de valeur � la ligne %d, on ne peut donc pas la modifier", num_col, num_ligne);
        return 1;
    }

    // Modification de la valeur
    dataframe->colonnes[num_col]->data[num_ligne] = valeur;
}

int renommer_colonne(DATAFRAME* dataframe, int num_colonne, const char* nouveau_nom)
{
    // V�rifier si le num�ro de colonne est valide
    if (num_colonne < 0 || num_colonne >= dataframe->taille)
    {
        printf("\nLe num�ro de colonne %d est invalide.\n", num_colonne);
        return 1;
    }

    // V�rifier si le nouveau nom est d�j� utilis� par une autre colonne
    for (int i = 0; i < dataframe->taille; ++i)
    {
        if (i != num_colonne && strcmp(dataframe->colonnes[i]->titre, nouveau_nom) == 0)
        {
            printf("\nLe nom \"%s\" est d�j� utilis� par la colonne %d.\n", nouveau_nom, i);
            return 1;
        }
    }

    // Mettre � jour le nom de la colonne
    strncpy(dataframe->colonnes[num_colonne]->titre, nouveau_nom, sizeof(dataframe->colonnes[num_colonne]->titre) - 1);

    // Ajouter le char terminal
    dataframe->colonnes[num_colonne]->titre[sizeof(dataframe->colonnes[num_colonne]->titre) - 1] = '\0';

    return 0;
}