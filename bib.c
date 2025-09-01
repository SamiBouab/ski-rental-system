#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include "conio.c"
#include "conio2.h"
#include <conio.h>

#define MAX_SKIS 100
#define MIN_SKIS 50
#define MAX_NOMS 100
#define MIN_NOMS 60
#define JOUR_DEBUT_SAISON 1
#define JOUR_FIN_SAISON 151
#define MAX_NOMS_LONGUEUR 25
#define MAX_LEN 128

typedef struct reservation Reservation;
typedef struct paireSkis PaireSkis;

typedef struct reservation
{
    int deb;
    int fin;
    int ind;
    Reservation *ressuiv;
};

typedef struct paireSkis
{
    int taille;
    Reservation *loc;
    PaireSkis *skisuiv;
};

typedef struct skieur
{
    char nom[MAX_NOMS_LONGUEUR];
    int adresse;
    int psk;
} Skieur;



Skieur skieur[MAX_NOMS];

int nsk;

typedef PaireSkis *plist;
typedef Reservation *premloc;

char *wilayas[] = {
       " ",           // 0
       "Adrar",       // 1
       "Chlef",       // 2
       "Laghouat",    // 3
       "Oum El Bouaghi", // 4
       "Batna",       // 5
       "Bejaia",      // 6
       "Biskra",      // 7
       "Bechar",      // 8
       "Blida",       // 9
       "Bouira",      // 10
       "Tamanrasset", // 11
       "Tebessa",     // 12
       "Tlemcen",     // 13
       "Tiaret",      // 14
       "Tizi Ouzou",  // 15
       "Algiers",     // 16
       "Djelfa",      // 17
       "Jijel",       // 18
       "Setif",       // 19
       "Saida",       // 20
       "Skikda",      // 21
       "Sidi Bel Abbes", // 22
       "Annaba",      // 23
       "Guelma",      // 24
       "Constantine", // 25
       "Medea",       // 26
       "Mostaganem",  // 27
       "M'Sila",      // 28
       "Mascara",     // 29
       "Ouargla",     // 30
       "Oran",        // 31
       "El Bayadh",   // 32
       "Illizi",      // 33
       "Bordj Bou Arreridj", // 34
       "Boumerdes",   // 35
       "El Tarf",     // 36
       "Tindouf",     // 37
       "Tissemsilt",  // 38
       "El Oued",     // 39
       "Khenchela",   // 40
       "Souk Ahras",  // 41
       "Tipaza",      // 42
       "Mila",        // 43
       "Ain Defla",   // 44
       "Naama",       // 45
       "Temouchent",  // 46
       "Ghardaia",    // 47
       "Relizane",    // 48
       "Timimoun",  // 49
       "Bordj Baji Mokhtar",   // 50
       "Ouled Djellal",    // 51
       "Beni Abbes",     // 52
       "In Salah",   // 53
       "In Guezzam",       // 54
       "Touggourt",   // 55
       "Djanet",   // 56
       "El M'Ghair",   // 57
       "El Meniaa",   // 58
   };
//---------------------Machine Abstraite-------------------------//
/*------------------La Liste Principale-----------------------*/
// Procédure qui alloue un maillon et affecte son adresse dans p.
void Allouer_ski(plist *p)
{
    *p = malloc(sizeof(PaireSkis));
}
// Procédure qui détruit le maillon pointé par p.
void Liberer_ski(plist p)
{
    free(p);
}
// Procédure qui affecte v dans le champ taille du maillon pointé par p.
void Aff_taille(plist p, int v)
{
    p->taille = v;
}
// Procédure qui affecte q dans le champ res du maillon pointé par p.
void Aff_res(plist p, premloc q)
{
    p->loc = q;
}
// Procédure qui affecte q dans le champ skisuiv du maillon pointé par p.
void Aff_adr_ski(plist p, plist q)
{
    p->skisuiv = q;
}
// Fonction qui retourne le contenu du champ taille du maillon pointé par p.
int Taille(plist p)
{
    return p->taille;
}
// Fonction qui retourne le contenu du champ Res du maillon pointé par p.
premloc Res(plist p)
{
    return p->loc;
}
// Fonction qui retourne le contenu du champ skisuiv du maillon pointé par p.
plist Suivant_ski(plist p)
{
    return p->skisuiv;
}
/*------------------La Sous-liste-----------------------*/
// Procédure qui alloue un maillon et affecte son adresse dans p.
void Allouer_res(premloc *p)
{
    *p = malloc(sizeof(Reservation));
}
// Procédure qui détruit le maillon pointé par p.
void Liberer_res(premloc p)
{
    free(p);
}
// Procédure qui affecte v dans le champ deb du maillon pointé par p.
void Aff_deb(premloc p, int v)
{
    p->deb = v;
}
// Procédure qui affecte v dans le champ fin du maillon pointé par p.
void Aff_fin(premloc p, int v)
{
    p->fin = v;
}
// Procédure qui affecte v dans le champ ind du maillon pointé par p.
void Aff_ind(premloc p, int v)
{
    p->ind = v;
}
// Procédure qui affecte q dans le champ ressuiv du maillon pointé par p.
void Aff_adr_res(premloc p, premloc q)
{
    p->ressuiv = q;
}
// Fonction qui retourne le contenu du champ deb du maillon pointé par p.
int Deb(premloc p)
{
    return p->deb;
}
// Fonction qui retourne le contenu du champ fin du maillon pointé par p.
int Fin(premloc p)
{
    return p->fin;
}
// Fonction qui retourne le contenu du champ ind du maillon pointé par p.
int Ind(premloc p)
{
    return p->ind;
}
// Fonction qui retourne le contenu du champ ressuiv du maillon pointé par p.
premloc Suivant_res(premloc p)
{
    return p->ressuiv;
}

//---------------------------------------------------------------
//---------------------Fonctions d'affichage----------------//
int up=80,down=72,margin=30;
char password[30];
char usr[30];
// Fonction calcullateXAxis qui calcule l'axe x.
int calculateXAxis(char *format, ...) {
    char buffer[120];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, 120, format, args);
    va_end(args);
    int str_len = strlen(buffer);
    int x_axis = (120 - str_len) / 2;
    return x_axis;
}
// Fonction qui recupere la position du curseur.
void getCursorPosition(int *x, int *y) {
    CONSOLE_SCREEN_BUFFER_INFO cursorInfo;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (consoleHandle == INVALID_HANDLE_VALUE) {
        return;
    }

    if (!GetConsoleScreenBufferInfo(consoleHandle, &cursorInfo)) {
        return;
    }

    *x = cursorInfo.dwCursorPosition.X;
    *y = cursorInfo.dwCursorPosition.Y;
}
// Fonction print_image qui affiche une image (ascii-art).
void print_image(FILE *fptr, char *filename, int x, int y)
{
    char read_string[MAX_LEN];
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "error opening %s\n", filename);
        // exit with failure
        exit(1);
    }

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
    {
        gotoxy(x, y);
        delay(10);
        printf("%s", read_string);
        y++;
    }
}
// Fonction menu qui affiche le menu.
void menu(int* l)
{
    system("clear");
    system("cls");
    textbackground(0);
    int c ;
    int cpt = 1;
    int y=1;
    textbackground(7);
      for (int u=30;u<89;u++){
        gotoxy(u,2);printf(" ");
        gotoxy(u,3);printf(" ");
        gotoxy(u,4);printf(" ");
         }
    gotoxy(margin-2,y++);textcolor(2);textbackground(BLUE);printf("                                                               \n");
    y++;
    gotoxy(margin,y++);textcolor(1);textbackground(7);printf("                   Bonjour Mr %s        \n",usr);textbackground(0);textcolor(15);
    y++;
    gotoxy(margin-2,y++);textcolor(2);textbackground(BLUE);printf("                                                             \n");textcolor(15);
    y++;
    gotoxy(margin,y++);textbackground(6);printf("             CREER LES STRUCTURES ALEATOIREMENT            \n");textbackground(0);
    y++;
    gotoxy(margin,y++);printf("                  AFFICHER LES STRUCTURES                  \n");
    y++;
    gotoxy(margin,y++);printf("                  LOUER UNE PAIRE DE SKIS                  \n");
    y++;
    gotoxy(margin,y++);printf("                 RESERVER UNE PAIRE DE SKI                 \n");
    y++;
    gotoxy(margin,y++);printf("         RESERVER PLUSIEURS PAIRES DE SKI SKIS             \n");
    y++;
    gotoxy(margin,y++);printf("        ADRESSE DE PREMIER PAIRE DE SKI DE TAILLE T        \n");
    y++;
    gotoxy(margin,y++);printf("                  CHERCHER UN SKIEUR                       \n");
    y++;
    gotoxy(margin,y++);printf("           STATISTIQUES D'UNE PAIRE DE SKIS                \n");
    y++;
    gotoxy(margin,y++);printf("                      NOMBRE DE SKIS                       \n");
    y++;
    gotoxy(margin,y++);printf("            ANNULER LES RESERVATIONS D'UN SKIEUR           \n");
    y++;
    gotoxy(margin,y++);printf("                        QUITTER                            \n");
    y++;


     gotoxy(margin-2,y++);textbackground(BLUE);printf("                                                             \n");//textbackground(15);
      textbackground(1);
     for (int u=2;u<30;u++){
        gotoxy(28,u);printf("  ");
         gotoxy(89,u);printf("  ");
    }



    do{
        c=getch();
        if(c==up){cpt%=11;cpt++;}
        if(c==down){cpt--;if(cpt==0)cpt=11;}
        textbackground(1);
        y=1;
        gotoxy(margin,y++);textbackground(BLUE);printf("                                                             \n");textbackground(0);
        y++;
        gotoxy(margin,y++);textcolor(1);textbackground(7);printf("                   Bonjour Mr %s        \n",usr);textcolor(15);
        y++;
        gotoxy(margin,y++);;textbackground(BLUE);printf("                                                             \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==1)textbackground(6);printf("             CREER LES STRUCTURES ALEATOIREMENT            \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==2)textbackground(6);printf("                  AFFICHER LES STRUCTURES                  \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==3)textbackground(6);printf("                  LOUER UNE PAIRE DE SKIS                  \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==4)textbackground(6);printf("                 RESERVER UNE PAIRE DE SKI                 \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==5)textbackground(6);printf("         RESERVER PLUSIEURS PAIRES DE SKI SKIS             \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==6)textbackground(6);printf("        ADRESSE DE PREMIER PAIRE DE SKI DE TAILLE T        \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==7)textbackground(6);printf("                  CHERCHER UN SKIEUR                       \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==8)textbackground(6);printf("           STATISTIQUES D'UNE PAIRE DE SKIS                \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==9)textbackground(6);printf("                      NOMBRE DE SKIS                       \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==10)textbackground(6);printf("            ANNULER LES RESERVATIONS D'UN SKIEUR           \n");textbackground(0);
        y++;
        gotoxy(margin,y++);if(cpt==11)textbackground(6);printf("                        QUITTER                            \n");textbackground(0);
        y++;
        gotoxy(margin,y++);textbackground(BLUE);printf("                                                             \n");textbackground(15);



    } while(c!=13);
    if(c==13)
    {
      *l = cpt;
    }

}
 
 //Foction Aurevoir qui affiche un message de fin de programme.
 void Aurevoir () {
    clrscr();
    textbackground(9); // couleur de fond
    textcolor(0); // couleur du texte
    gotoxy(40, 1); printf(" Bonne journee! Nous esperons vous revoir bientot ");
    textcolor(9);textbackground(BLACK);
    FILE *imgski;
    print_image(imgski,"ascii-art.txt", 25, 3);
    textcolor(15);gotoxy(40, 1);
}
// Fonction pour modifier l'icon de la console.
void SetConsoleIcon(const char* icon_path)
{
    // Load the icon file
    HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
    if (icon_path)
    {
        hIcon = LoadImage(NULL, icon_path, IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
    }

    // Create the window
    const char CLASS_NAME[] = "ConsoleClass";
    WNDCLASS wc = { };
    wc.lpfnWndProc   = DefWindowProc;
    wc.hInstance     = NULL;
    wc.lpszClassName = CLASS_NAME;
    wc.hIcon         = hIcon;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class
        "",                             // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,       // Parent window    
        NULL,       // Menu
        NULL,       // Instance handle
        NULL        // Additional application data
    );

    // Set the console window icon to the same as the custom window
    SendMessage(GetConsoleWindow(), WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    SendMessage(GetConsoleWindow(), WM_SETICON, ICON_BIG, (LPARAM)hIcon);

    // Destroy the window
    DestroyWindow(hwnd);
    UnregisterClass(CLASS_NAME, NULL);
}
//---------------------Fonctions Principales---------------------//
// Fonction qui retourne le nombre de maillons de la liste des skis.
int nbskis(plist p)
{
    int i = 0;
    while (p != NULL)
    {
        i++;
        p = Suivant_ski(p);
    }
    return i;
}
// Fonction pour inserer un maillon dans la fin de liste des reservations.
void inserer_fin_res(premloc *p, int deb, int fin, int ind)
{
    premloc t = *p;
    if (t == NULL)
    {
        Allouer_res(&t);
        Aff_deb(t, deb);
        Aff_fin(t, fin);
        Aff_ind(t, ind);
        Aff_adr_res(t, NULL);
        *p = t;
    }
    else
    {
        while (Suivant_res(t) != NULL)
        {
            t = Suivant_res(t);
        }
        Allouer_res(&t->ressuiv);
        Aff_deb(t->ressuiv, deb);
        Aff_fin(t->ressuiv, fin);
        Aff_ind(t->ressuiv, ind);
        Aff_adr_res(t->ressuiv, NULL);
    }
}

// Fonction pour générer une taille de paire de skis aléatoire
int generer_taille()
{
    return (rand() % 25) * 5 + 80; // taille entre 80 et 200 cm
}
// Fonction pour générer un jour de début ou de fin de location aléatoire
int generer_jour()
{
    return rand() % 151 + 1; // entre 1 et 151
}
// Fonction pour générer une adresse aléatoire
int generer_adresse()
{
    return rand() % 58 + 1; // entre 1 et 58
}
// Fonction pour afficher la liste des pairs de skis
void afficher_skis(plist p)
{
    plist t = p;
    while (t != NULL)
    {
        printf("\nTaille: %d ,res %p", Taille(t), Res(t));
        t = Suivant_ski(t);
    }
}
// Fonction pour générer les noms
void Lire_noms(const char *nomFichier, char names[MAX_NOMS][MAX_NOMS_LONGUEUR])
{
    FILE *fich = fopen("Noms.txt", "r");
    if (fich == NULL)
    {
        fprintf(stderr, "Erreur: ne peut pas ouvrir le fichier %s\n", nomFichier);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < MAX_NOMS; i++)
    {
        char ligne[MAX_NOMS_LONGUEUR];
        fgets(ligne, sizeof(ligne), fich) == NULL;
    }
    int i = 0;
    char ligne[MAX_NOMS_LONGUEUR];
    while (fgets(ligne, sizeof(ligne), fich) != NULL && i < MAX_NOMS)
    {
        // Retirez le caractere Newline Talling de la ligne
        ligne[strcspn(ligne, "\n")] = '\0';

        // Copiez le nom de la ligne dans le tableau des noms
        strncpy(names[i], ligne, MAX_NOMS_LONGUEUR);
        i++;
    }

    fclose(fich);
}
// Fonction pour trier les skis par taille
void trier_skis(plist *tete)
{
    plist t = *tete;
    plist t2 = NULL;
    int temp;
    while (t != NULL)
    {
        t2 = t->skisuiv;
        while (t2 != NULL)
        {
            if (t->taille > t2->taille)
            {
                temp = t->taille;
                t->taille = t2->taille;
                t2->taille = temp;
            }
            t2 = t2->skisuiv;
        }
        t = t->skisuiv;
    }
}
// Procédure pour créer les skieurs
void creer_skieur(char Noms[MAX_NOMS][MAX_NOMS_LONGUEUR])
{
    nsk = rand() % (MAX_NOMS - MIN_NOMS + 1) + MIN_NOMS;
    Lire_noms("Noms.txt", Noms);
    for (int i = 1; i <= nsk; i++)
    {
        for (int k = 0; k < strlen(Noms[i]); k++)
        {
            skieur[i].nom[k] = Noms[i][k];
        }
        skieur[i].adresse = generer_adresse();
        skieur[i].psk = 0;
    }
}
// Procédure pour créer les skis
void creer_skis(plist *tete)
{
    plist ski = NULL, ski2 = NULL;
    *tete = NULL;
    for (int i = 0; i < (rand() % (MAX_SKIS - MIN_SKIS + 1) + MIN_SKIS); i++)
    {
        if (i == 0) // Créer le premier maillon du listes des ski
        {
            int taille = generer_taille();
            Allouer_ski(&ski);
            Aff_taille(ski, taille);
            Aff_res(ski, NULL);
            *tete = ski;
        }
        else
        {
            int taille = generer_taille();
            Allouer_ski(&ski2);
            Aff_taille(ski2, taille);
            Aff_res(ski, NULL);
            Aff_adr_ski(ski, ski2);
            ski = ski2;
        }
    }
    Aff_res(ski, NULL);
    Aff_adr_ski(ski, NULL);
    trier_skis(tete); // trier les skis par taille
}
// Procédure pour créer les réservations
void creer_res(plist *tete)
{
    plist ski = *tete;
    premloc loc = NULL, loc2 = NULL;
    int i = 0, indice = 1;
    while (ski != NULL)
    {
        int nb_res = rand() % 10; // nombre de réservations pour chaque paire de skis
        int Suiv_fin = 0;
        for (int j = 0; j < nb_res; j++)
        {
            // Générer les données pour la reservation
            int deb = generer_jour();
            int fin = generer_jour();
            if (fin < deb)
            {
                int temp = deb;
                deb = fin;
                fin = temp;
            }
            if ((fin - deb) > 30)
            {
                fin = deb + rand() % 30 + 1;
            }
            if (j == 0) // Créer le premier maillon du listes des réservations
            {
                deb = rand() % 10 + 1;
                fin = deb + rand() % 15 + 1;
                Allouer_res(&loc);
                Aff_deb(loc, deb);
                Aff_fin(loc, fin);
                Aff_ind(loc, indice);
                skieur[indice].psk++;
                indice = rand() % nsk + 1;
                Aff_adr_res(loc, NULL);
                Aff_res(ski, loc);
                Suiv_fin = fin;
            }
            else
            {
                if (deb > Suiv_fin)
                {
                    Allouer_res(&loc2);
                    Aff_deb(loc2, deb);
                    Aff_fin(loc2, fin);
                    Aff_ind(loc2, indice);
                    skieur[indice].psk++;
                    indice = rand() % nsk + 1;
                    Aff_adr_res(loc, loc2);
                    Aff_adr_res(loc2, NULL);
                    loc = loc2;
                    Suiv_fin = fin;
                }
            }
        }
        ski = Suivant_ski(ski);
    }
}
/* Procédure pour voir s'il y a un skieur sans réservation  if (skieur[i].psk == 0)  et ajouter à lui
 une réservation  apres la derniere réservation d'une paire de skis au hasard  */
void finish_res(plist *tete)
{
    for (int i = 1; i <= nsk; i++)
    {
        plist ski = *tete;
        if (skieur[i].psk == 0)
        {
            for (int t = 1; t < (rand() % nbskis(*tete)); t++)
                ski = Suivant_ski(ski);
            premloc r = Res(ski);
            do
            {
                ski = Suivant_ski(ski);
                r = Res(ski);
            } while (r == NULL);
            while (r->ressuiv != NULL)
                r = r->ressuiv;
            int fi = Fin(r);
            if (fi == 151)
                fi--;
            int deb = fi + 1;
            int fin = rand() % (151 - fi) + fi + 1;
            premloc r2 = NULL;
            Allouer_res(&r2);
            Aff_deb(r2, deb);
            Aff_fin(r2, fin);
            Aff_ind(r2, i);
            skieur[i].psk = 1;
            Aff_adr_res(r2, NULL);
            Aff_adr_res(r, r2);
        }
    }
}
// Procédure pour créer la structure
void creer_struct (plist *tete,char Noms[MAX_NOMS][MAX_NOMS_LONGUEUR]) {
    creer_skieur(Noms);
    creer_skis(tete);
    creer_res(tete);
    finish_res(tete);
    
}
// une procédure insertete qui permet d’insérer le maillon contenant deb, fin et ind en tête de Reservation si possible .
void insertete(premloc *tete, int deb, int fin, int ind)
{
    premloc rt = *tete;
    premloc r = NULL;
    Allouer_res(&r);
    Aff_deb(r, deb);
    Aff_fin(r, fin);
    Aff_ind(r, ind);
    Aff_adr_res(r, Suivant_res(rt));
    Aff_adr_res(rt, r);
}
//fonction location qui renvoie vrai si la location a été réalisée et faux sinon.Nous utiliserons la procédure  insertête.
bool location(plist *tete, int tai, int deb, int fin, int ind)
{
    plist ski = *tete;
    while (ski != NULL)
    {
        if (Taille(ski) == tai)
        {
            premloc r = Res(ski);
            if (r == NULL)
            {
                premloc rNil = NULL;
                Allouer_res(&rNil);
                Aff_deb(rNil, deb);
                Aff_fin(rNil, fin);
                Aff_ind(rNil, ind);
                Aff_adr_res(rNil, NULL);
                Aff_res(ski, rNil);
                skieur[ind].psk++;
                return true;
            }
            else
            {
                while (r->ressuiv != NULL)
                {
                    if (deb > Fin(r) && fin < Deb(r->ressuiv))
                    {
                        insertete(&r, deb, fin, ind);
                        skieur[ind].psk++;
                        return true;
                    }
                    r = Suivant_res(r);
                }

                if (deb > Fin(r) && r->ressuiv == NULL)
                {
                    premloc rNi = NULL;
                    Allouer_res(&rNi);
                    Aff_deb(rNi, deb);
                    Aff_fin(rNi, fin);
                    Aff_ind(rNi, ind);
                    Aff_adr_res(rNi, NULL);
                    Aff_adr_res(r, rNi);
                    skieur[ind].psk++;
                    return true;
                }
            }
        }
        ski = Suivant_ski(ski);
    }
}
// procédure réservation qui aura comme résultat un certain booléen possible à vrai si la réservation a été effectuée et non possible sinon.
bool reservation(plist *tete, char nm[MAX_NOMS_LONGUEUR], int ad, int t, int de, int fi)
{
    plist ski = *tete;

    for (int i = 1; i <= nsk; i++)
    {
        if ((strncmp(skieur[i].nom, nm, MAX_NOMS_LONGUEUR) == 0) && (skieur[i].adresse == ad))
        {
            return location(&ski, t, de, fi, i);
        }
    }
    nsk++;
    bool bl = location(&ski, t, de, fi, nsk);
    if (bl) {
    strcpy(skieur[nsk].nom, nm);
    skieur[nsk].adresse = ad;
    } else nsk--;
    return bl;
    
}

// declaration de la structure res
typedef struct resV
{
    int de;
    int fi;
    int t;
} resV;
resV res[100]; // declaration du vecteur res
// procédure reservations qui permet de réaliser si possible les réservations demandées
void reservations(plist *tete)
{   
    int Yaxis,Xaxis=4,lastY,Ymax;
    int nr, ad;
    char nm[MAX_NOMS_LONGUEUR];
    Yaxis = 6;
    gotoxy(38, 4);
    printf("Veuillez saisir les informations suivantes :");
    gotoxy(35, Yaxis);
    textcolor(3);
    printf("Nom : ");
    textcolor(15);
    scanf("%s", &nm);
    Yaxis++;
    gotoxy(35, Yaxis++);
    textcolor(3);
    printf("Adresse : ");
    textcolor(15);
    while (scanf("%d", &ad) != 1 || ad < 1 || ad > 58 || getchar() != '\n')
    {
        if (scanf("%*[^\n]") == EOF)
            break;
        gotoxy(35, Yaxis++);
        textcolor(1);
        printf("Adresse invalide. Veuillez entrer une adresse valide :    ");
        textcolor(15);
    }
    gotoxy(35, Yaxis++);
    textcolor(3);
    printf("Le nombre de reservations : ");
    textcolor(15);
    scanf("%d", &nr);Yaxis++;
    for (int i = 1; i <= nr; i++)
    {
        gotoxy(Xaxis, Yaxis);lastY=Yaxis;
        textbackground(1);printf("Reservation numero %d :", i);Yaxis++;textbackground(0);
        gotoxy(Xaxis, Yaxis++);
        textcolor(3);
        printf("Taille : ");
        textcolor(15);
        while (scanf("%d", &(res[i].t)) != 1 || (res[i].t) < 80 || (res[i].t) > 200 || (res[i].t) % 5 != 0)
        {
            if (scanf("%*[^\n]") == EOF)
                break;
            gotoxy(Xaxis, Yaxis++);
            textcolor(1);
            printf("Taille invalide. Veuillez entrer une taille valide :");
            textcolor(15);
        }
        gotoxy(Xaxis, Yaxis++);
        textcolor(3);
        printf("Date de debut : ");
        textcolor(15);
        while (scanf("%d", &(res[i].de)) != 1 || (res[i].de) < 1 || (res[i].de) > 151)
        {
            if (scanf("%*[^\n]") == EOF)
                break;
            gotoxy(Xaxis, Yaxis++);
            textcolor(1);
            printf("Date invalide. Veuillez entrer une date valide :    ");
            textcolor(15);
        }
        gotoxy(Xaxis, Yaxis++);
        textcolor(3);
        printf("Date de fin : ");
        textcolor(15);
        while (scanf("%d", &(res[i].fi)) != 1 || (res[i].fi) <= 0 || (res[i].fi) < (res[i].de))
        {
            if (scanf("%*[^\n]") == EOF)
                break;
            gotoxy(Xaxis, Yaxis++);
            textcolor(1);
            printf("Date invalide. Veuillez entrer une date valide :    ");
            textcolor(15);
        }
        if (i % 2 == 1 && i != nr) {Xaxis = 62;Ymax = Yaxis;Yaxis = lastY;}
        else {Xaxis = 4; if (Yaxis < Ymax) {Yaxis = Ymax+=2;}else Yaxis+=2;}
    }
    for (int i = 1; i <= nr; i++)
    {
        if (reservation(tete, nm, ad, res[i].t, res[i].de, res[i].fi)) // si la reservation est possible
        {
            gotoxy(36,Yaxis);textcolor(2);printf("la reservation num %d est possible et effectuee", i);textcolor(15);
        }
        else
        {
            gotoxy(40,Yaxis);textcolor(4);printf("la reservation num %d n'est pas possible", i);textcolor(15);
        }
        Yaxis++;
    }
     Yaxis++;gotoxy(40, Yaxis);
        printf("Appuyez sur une touche pour continuer...\n");
}

// la fonction skit, l’adresse du premier maillon contenant une paire de skis de taille t.
plist skit(plist *tete, int t)
{
    plist ski = *tete;
    while (ski != NULL)
    {
        if (Taille(ski) == t)
        {
            return ski;
        }
        ski = Suivant_ski(ski);
    }
    return NULL;
}
// fonction nbjloc qui délivre le nombre de jours de location d’une paire de skis.
int nbjloc(plist *tete, int t)
{
    plist ski = skit(tete, t);
    while (ski != NULL )
    {
        if (Taille(ski) == t) {
        premloc r = Res(ski);
        int nbj = 0;
        while (r != NULL)
        {
            nbj += Fin(r) - Deb(r) + 1;
            r = Suivant_res(r);
        }
        return nbj;
        }
        ski = Suivant_ski(ski);
    }
    return 0;
}
// fonction totjr qui délivre le nombre total de jours de location des paire de skis de meme taille .
int totjr(plist *tete, int t)
{
    plist ski = skit(tete, t);
    int nbj = 0;
    while (ski != NULL && Taille(ski) == t)
    {
        premloc r = Res(ski);
        while (r != NULL)
        {
            nbj += Fin(r) - Deb(r) + 1;
            r = Suivant_res(r);
        }
        ski = Suivant_ski(ski);
    }
    return nbj;
}
// fonction memet qui délivre le nombre de paire de skis de meme taille t 
int memet(plist *tete, int t)
{
    plist ski = skit(tete, t);
    int cpt = 0;
    while (ski != NULL && Taille(ski) == t)
    {
        cpt++;
        ski = Suivant_ski(ski);
    }
    return cpt;
}
// fonction cherchskieur qui cherche un skieur dans la liste des skieurs et renvoie son indice dans le tableau skieur.
int cherchskieur(char nom[MAX_NOMS_LONGUEUR])
{
    for (int i = 1; i <= nsk; i++)
    {
        if (strncmp(skieur[i].nom, nom,MAX_NOMS_LONGUEUR) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Procédure qui donne les statistiques sur un skieur (indice, psk, adresse,paire de ski loué, nombre de jours de location)
void statsski(plist *tete, int ind)
{
    plist ski = *tete;
    int cpt = 1,Yaxs = 7,Xaxs;
    int nbjours =0; if (ind != -1) {
    Xaxs = calculateXAxis("L'indice du skieur %s est : %d", skieur[ind].nom, ind);
    gotoxy(Xaxs,Yaxs);textcolor(3);;printf("L'indice du skieur %s est : ", skieur[ind].nom);textcolor(15);Yaxs+=2;
    printf("%d",ind);
    Xaxs = calculateXAxis("Le nombre de Skis louee par %s est : %d",skieur[ind].nom, skieur[ind].psk);
    gotoxy(Xaxs,Yaxs);textcolor(3);printf("Le nombre de Skis louee par %s est : ",skieur[ind].nom);textcolor(15);Yaxs+=2;
    printf("%d",skieur[ind].psk);
    Xaxs = calculateXAxis("Le Skieur %s a loue les paire de ski suivante:",skieur[ind].nom);
    gotoxy(Xaxs,Yaxs);textcolor(3);printf("Le Skieur %s a loue les paire de ski suivante :",skieur[ind].nom);textcolor(15);Yaxs+=2;
    } else {
        Xaxs = calculateXAxis("Le Skieur %s n'existe pas",skieur[ind].nom);
        gotoxy(Xaxs,Yaxs);textcolor(4);printf("Le Skieur %s n'existe pas",skieur[ind].nom);textcolor(15);Yaxs+=2;}
    while (ski != NULL)
    {
        premloc r = Res(ski);
        while (r != NULL)
        {
            if (Ind(r) == ind)
            {   
                Xaxs = calculateXAxis("Ski de taille %dcm numero %d de jour %d au jour %d", Taille(ski), cpt, Deb(r), Fin(r));
                gotoxy(Xaxs,Yaxs);printf("Ski de taille ");textcolor(3);printf("%dcm",Taille(ski));textcolor(15);
                printf(" numero ");textcolor(3);printf("%d",cpt);textcolor(15);
                printf(" de jour ");textcolor(3);printf("%d",Deb(r));textcolor(15);
                printf(" au jour ");textcolor(3);printf("%d",Fin(r));textcolor(15);
                nbjours += Fin(r) - Deb(r) +1;Yaxs++;
            }
            r = Suivant_res(r);
        }

        if ((Suivant_ski(ski) != NULL) && (Taille(Suivant_ski(ski)) == Taille(ski)) ) cpt ++; 
        else cpt = 1;
        ski = Suivant_ski(ski);
    }
    Yaxs++;
    Xaxs = calculateXAxis("Le skieur %s est de Wilaya : %s",skieur[ind].nom, wilayas[skieur[ind].adresse]);
    gotoxy(Xaxs,Yaxs);textcolor(3);printf("Le skieur %s est de Wilaya : ",skieur[ind].nom);
    textcolor(15);printf("%s",wilayas[skieur[ind].adresse]);
    Yaxs+=2;
    Xaxs = calculateXAxis("Le nombre total de jours de location pour %s est : %d", skieur[ind].nom, nbjours);
    gotoxy(Xaxs,Yaxs);printf("Le nombre total de jours de location pour %s est : ", skieur[ind].nom);
    textcolor(3);printf("%d", nbjours);textcolor(15);Yaxs+=3;
    gotoxy(41, Yaxs);
    printf("Appuyez sur une touche pour continuer...\n");
}
// Fonction Nonrs qui affiche les pair de skis qui sont pas encore louee
void Nonrs(plist *tete)
{
    plist ski = *tete;
    int cpt = 1,tai,verif=0,Yaxis=11;
    while (ski != NULL)
    {
        if (Res(ski) == NULL)
        {
            if (verif == 0)
            {
                gotoxy(34, 9);
                printf("Les paires de skis qui sont pas encore louees sont :");
                verif = 1;
            }
            if (tai != Taille(ski))
            {
                cpt = 1;
            }
            else
            {
                cpt++;
            }
            gotoxy(44,Yaxis);   
            printf("Le ski de taille ");textcolor(3);printf("%dcm", Taille(ski));textcolor(15);
            printf(" numero ");textcolor(3);printf("%d",cpt);textcolor(15);
            Yaxis++;
        }
        tai = Taille(ski);
        ski = Suivant_ski(ski);
    }
    if (verif == 0)
    {
        gotoxy(41, 11);
        textcolor(11);printf("Toutes les paires de skis sont louees");textcolor(15);
    }
}
// Fonction annuleres qui annule toutes les reservations d'un skieur
void annuleres(plist *tete, char nom[MAX_NOMS_LONGUEUR])
{
    int ind = cherchskieur(nom);
    if (ind != -1)
    {
        plist ski = *tete;
        while (ski != NULL)
        {
            premloc r = Res(ski);
            if (r != NULL)
            {
                if (strncmp(skieur[Ind(r)].nom, nom,MAX_NOMS_LONGUEUR) == 0)
                {
                    ski->loc = ski->loc->ressuiv;
                }
                else
                {
                    while (r != NULL)
                    {
                        if (r->ressuiv != NULL)
                        {
                            if (strncmp(skieur[Ind(r->ressuiv)].nom, nom,MAX_NOMS_LONGUEUR) == 0)
                                r->ressuiv = r->ressuiv->ressuiv;
                            r = r->ressuiv;
                        }
                        else
                        {
                            if (strncmp(skieur[Ind(r)].nom, nom,MAX_NOMS_LONGUEUR) == 0)
                                r = NULL;
                            else
                                r = r->ressuiv;
                        }
                    }
                }
            }
            ski = ski->skisuiv;
        }
        for (int i = ind; i < nsk; i++)
        {
            skieur[i] = skieur[i + 1];
        }
        nsk--;
        ski = *tete;
        while (ski != NULL)
        {
            premloc r = Res(ski);
            while (r != NULL)
            {
                (r->ind)--;
                r = Suivant_res(r);
            }
            ski = Suivant_ski(ski);
        }
    }
}
// Fonction annulerUn qui annule une reservation d'un skieur
void annulerUn(plist *tete, char nom[MAX_NOMS_LONGUEUR], int taille, int debut, int fin) 
{
    int ind = cherchskieur(nom);
    if (ind != -1)
    {
        plist ski = *tete;
        while (ski != NULL)
        {
            premloc r = Res(ski);
            if (r != NULL)
            {
                if (strncmp(skieur[Ind(r)].nom, nom,MAX_NOMS_LONGUEUR) == 0)
                {
                    if (Taille(ski) == taille && Deb(r) == debut && Fin(r) == fin) {
                        skieur[Ind(r)].psk--;
                        ski->loc = ski->loc->ressuiv;
                    }
                }
                else
                {
                    while (r != NULL)
                    {
                        if (r->ressuiv != NULL)
                        {
                            if (strncmp(skieur[Ind(r->ressuiv)].nom, nom,MAX_NOMS_LONGUEUR) == 0)
                            {
                                if (Taille(ski) == taille && Deb(r->ressuiv) == debut && Fin(r->ressuiv) == fin)
                                {
                                    skieur[Ind(r->ressuiv)].psk--;
                                    r->ressuiv = r->ressuiv->ressuiv;
                                }
                                
                            }
                            r = r->ressuiv;
                        }
                        else
                        {
                            if (strncmp(skieur[Ind(r)].nom, nom,MAX_NOMS_LONGUEUR) == 0){r = NULL;}
                            else r = r->ressuiv;
                        }
                    }
                }
            }
            ski = ski->skisuiv;
        }
    }
}
//---------------------------------------------------------//
