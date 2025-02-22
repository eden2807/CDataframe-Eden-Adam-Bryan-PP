# CDataframe

- Noms et prénoms des membres de l'équipe projet :
 
   - Eden Elfassy
   - Bryan Tewouda
   - Adam Assayag


- Lien direct vers le dépôt Git du projet :
  
   https://github.com/eden2807/CDataframe-Eden-Adam-Bryan-PP


- IMPORTANT: LE PROGRAMME EXECUTABLE SE TROUVE UN DES SOUS-DOSSIERS DES SOURCES "\x64\Release\":
  Exemple: C:\CDataframe\x64\Release\CDataframe.exe


- Fonctionnalités principales de l'application :

   - Création d'un CDataframe
   
   - possibilité d'obtenir le nombre de lignes présent dans un CDataframe
   
   - possibilité d'afficher l'ensemble des colonnes et des lignes d'un CDataframe (ou une partie seulement)

   - Ajouter une colonne / créer une colonne
   
   - Inserer une valeur dans la colonne choisit 
   
   - Afficher une colonne
   
   - Trier des colonnes
   
   - Renommer une colonne (+ comparateur de châine de caractère pour vérifier que 2 colonnes n'ont pas le même nom)
   
   - Recherche une valeur dans le CDataframe

   - Obtenir des statistiques sur une valeur particulière (Nombre d'occurrences...)

   - Sauvegarde du CDataframe dans un fichier nommé "save_dataframe.csv".
     Ce fichier est sauvegardé dans le chemin ou est situé le programme / le source
   
   

- Instructions d'installation du projet :

   1) Installer Visual Studio 2022 Community Edition avec, au minimum, la charge de travail C++

   2) Lancer Visual Studio et choisir "Cloner un dépôt"

   3) Dans la zone "Emplacement du dépôt", entrer l'adresse du projet suivante:
      https://github.com/eden2807/CDataframe-Eden-Adam-Bryan-PP

   4) Dans la zone "Chemin", choisir un dossier qui hebergera le projet localement

   5) Cliquer ensuite sur le bouton "Cloner"

   6) Lancer le projet en appuyant sur la touche F5

   7) Pour ouvrir de nouveau le projet, cliquer sur le fichier "CDataframe.sln"


- Reglages à effectuer impérativement pour pouvoir tester le code sous Visual Studio 2022:

   1) Remplacer scanf_s par scanf:

      1.1) Ouvrez votre projet dans Visual Studio 2022.

      1.2) Cliquez avec le bouton droit sur votre projet dans l'Explorateur de solutions.

      1.3) Sélectionnez "Propriétés" dans le menu contextuel.

      1.4) Dans les propriétés du projet, accédez à "Configuration Properties" > "C/C++" > "General".

      1.5) Dans la section "Use of Specific Functions", définissez "Security Development Lifecycle (SDL) checks" sur "No (/GS-)".

      1.6) Cliquez sur "Appliquer" puis sur "OK" pour enregistrer les modifications.

   2) Correction de l'erreur E1072 "une déclaration ne peut pas avoir d'étiquette":

      Modifier la norme ISO retenu pour le langage C dans les paramètres de projet de Visual Studio.
      Dans la barre de menu, choisir Projet -> Propriétés du projet -> Propriétés de configuration -> C/C++ ->
      Langage -> Norme du langage C.
   
      Choisir "Norme ISO C17 (2018) (/std:c17)".

      Notes:
        Par défaut c'est "Valeur par défaut (MSVC hérité)" qui est utilisé.
        La "Norme ISO C11 (/std:c11)" fonctionne aussi... 
      
                                                 =======
    Note concernant DATAFRAME2:

       Toutes les fonctions seront anglicisées afin de les differencier facilement de celles du chap 1, entierement en français.

       Pour chaque fichier .h et .c du projet, les lignes de codes concernant chap 1 (CDataframe1)
       et chap 2 (Cdataframe2) sont délimitées par des balises nommées comme suit: 

           #pragma region CDataframe 1

               ...Code CDataframe1 du chap 1

           #pragma endregion Fin CDataframe 1

           #pragma region CDataframe 2

               ...Code CDataframe2 du chap 2 et suivant

           #pragma endregion Fin CDataframe 2

                                                =======
     Scenario de démonstration rapide:
     
        - Lancer le programme, le menu s'affiche

        - Entrer la commande "11" : "Creation d'un CDataframe vide"
          Nommer le CDataframe et appuyer sur la touche "Entrée"

        - Entrer la commande "15" : "Remplissage automatique du CDataframe"
          Le CDataframe contiendra alors des colonnes de chaque type possible
          ainsi qu'une dizaine de ligne de données diverses pour test

        - Lancer la commande "21" : "Afficher le CDataframe" pour voir l'entiereté du CDataframe
          Note: Il contiendra alors 256 lignes, donc remonter vers le haut pour voir les
          10 premieres lignes contenant des données

        - Mieux: Lancer la commande "22" : Afficher les lignes et colonnes selon une eventuelle limite de l'utilisateur
          Entrer "-1" pour ne pas limiter le nombre de colonnes à afficher et "10" pour n'afficher que les 10 premières lignes"

        Enfin n'éhsitez pas à experimenter les actions suivantes: 

          - Afficher le nom et le type des colonnes
          - Afficher le contenu d'une colonne
          - Trier une colonne
          - Remplir une ligne
          - Ajouter une colonne
          - Remplir une colonne
          - Sauvegarder le CDataframe dans un fichier .csv
          - Lire/Modifier la valeur d'une cellule
          - Renommer une colonne
          
          ...Et tout le reste des commandes disponibles !

          Une dernière précision: N'utilisez JAMAIS la commmande "38" : "Ne jamais lancer cette commande"

              ;-)

            
                Exellente découverte à vous !

Edit: Un petit bug d'affichage s'est glissé lorsqu'on lance la commande suivante:
"12. Ajouter une colonne au CDataframe"
ainsi que la commande
"41 - Nombre de cellules contenant une valeur egale a "x""

L'ecran affiche les choix suivants:
UINT = 1, INT = 2, CHAR = 3, FLOAT = 5, DOUBLE = 6, STRING = 7, STRUCTURE = 8)")

Il y a donc une erreur entre CHAR = 3 et FLOAT = 5
Pour la creation d'une col de type FLOAT, il faut donc taper la valeur 4, et non 5
Pour la creation d'une col de type DOUBLE, il faut donc taper la valeur 5, et non 6
Pour la creation d'une col de type STRING, il faut donc taper la valeur 6, et non 7

Le bug a été corrigé dans la version 1.0.1:
UINT = 1, INT = 2, CHAR = 3, FLOAT = 4, DOUBLE = 5, STRING = 6, STRUCTURE = 7)
