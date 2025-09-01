#include "bib.c"



int main()
{
    srand(time(NULL)); // Initialisation de rand
    SetConsoleTitle("SkiLoc"); // Titre de la console
    SetConsoleIcon("icon.ico"); // Icone de la console
    //---------------------------------------Se Connecter-------------------------------------//
    textbackground(LIGHTBLUE);
    printf("                                                                                                                       \n");
    printf("  ");
    textbackground(LIGHTGRAY);
    printf("                                                                                                                   ");
    textbackground(LIGHTBLUE);printf("  \n");printf("  ");textbackground(LIGHTGRAY);textcolor(BLACK);
    textbackground(LIGHTGRAY);textcolor(BLACK);
    printf("                          S Y S T E M E    D E    L O C A T I O N    D E    S K I S                                ");
    textbackground(LIGHTBLUE);printf("  \n");printf("  ");textbackground(LIGHTGRAY);textcolor(BLACK);
    printf("                                                                                                                   ");
    textbackground(LIGHTBLUE);printf("  \n");printf("  ");textbackground(LIGHTGRAY);textcolor(BLACK);
    printf("          <Azzouz.A>          <Bouab.S>           <1CPI_G7>             <ESI-Alger>        <2022/2023>             ");
    textbackground(LIGHTBLUE);printf("  \n");printf("  ");textbackground(LIGHTGRAY);textcolor(BLACK);
    printf("                                                                                                                   ");
    textbackground(LIGHTBLUE);printf("  \n");
    textbackground(BLACK);textbackground(LIGHTBLUE);
    printf("                                                                                                                     ");
    textbackground(LIGHTBLUE);printf("  \n");
    printf("\n");
    textbackground(BLACK);textcolor(LIGHTBLUE);
    for (int i = 0; i < 58; i++)
    {
        delay(1);
        printf("==");
    }
    printf("=\n");
    printf("\n");

    FILE *fptr;
    print_image(fptr,"ascii-art2.txt",20,10); // Affichage de l'image
    printf("\n");
   for (int i = 0; i < 58; i++) 
    {
        delay(1);
        printf("==");
    }
    printf("=\n");
    printf("\n");
    gotoxy(48,19);textbackground(LIGHTBLUE);printf("                     \n");
    gotoxy(48,20);textbackground(LIGHTBLUE);printf("  ");
    gotoxy(67,20);textbackground(LIGHTBLUE);printf("  \n");
    gotoxy(48,21);textbackground(LIGHTBLUE);printf("                     \n");
    gotoxy(50,20);
    int i = 0;
    char c;
    textbackground(WHITE);textcolor(BLUE);
    printf("   <Connecter>   ");
    gotoxy(40,24);
    printf("   Nom d'utilisateur: [");
     while (i < 30   && (c = getch()) != '\r') {
        if (c == '\b' && i > 0) { // handle backspace
            printf("\b \b");
            i--;
        } else if (c != '\b') { // ignore backspace
            usr[i++] = c;
            printf("%c",c);
        }
    }
    printf("]   \n");
    gotoxy(40,26);
    printf("   Mot de passe: [");    i = 0;
    while (i < 30   && (c = getch()) != '\r') {
        if (c == '\b' && i > 0) { // handle backspace
            printf("\b \b");
            i--;
        } else if (c != '\b') { // ignore backspace
            password[i++] = c;
            printf("*");
        }
    }
   printf("]   \n");
   textcolor(GREEN); textbackground(BLACK);
   gotoxy(50,28);
   printf("Connexion reussie");
   delay(800);
   //---------------------------------------------------------------------------------//
   //---------------------------------------Menu-------------------------------------//
   clrscr();textcolor(BLACK);
   int l;
   plist tete = NULL;
   do
   {
      menu(&l);
      textbackground(BLACK);
      switch (l)
      {
      case 1: // Creation du Structures
      {
        system("cls");
        char Noms[MAX_NOMS][MAX_NOMS_LONGUEUR];
        tete = NULL;
        creer_struct(&tete, Noms);
       if (tete != NULL) // Affichage de la barre de chargement
        {
            for (int Loading = 0;Loading<98;Loading+=3){
              gotoxy(1,1); printf("\n Loading.  ");gotoxy(15,2);printf("%d %%",Loading);delay(2);
               gotoxy(Loading+20,2);textbackground(GREEN);printf(" "); textbackground(BLACK);
              gotoxy(1,1);printf("\n Loading.. ");gotoxy(15,2);printf("%d %%",Loading+1);delay(2);
             gotoxy(Loading+21,2);textbackground(GREEN);printf(" ");textbackground(BLACK);
              gotoxy(1,1);printf("\n Loading...");gotoxy(15,2);printf("%d %%",Loading+2);delay(2);
              gotoxy(Loading+22,2);textbackground(GREEN);printf(" ");textbackground(BLACK);

                }
              gotoxy(1,1);printf("\n Loading...   100%%");

             textbackground(BLACK);gotoxy(45, 8);printf("Les structures ont ete creees");textcolor(GREEN);delay(20);gotoxy(41, 15);printf("L'operation a ete effectuee avec succes"); textcolor(WHITE);
        }
        else
        {
            gotoxy(37, 10);
            printf("Une erreur a empeche la creation des structures");
        }
        gotoxy(41, 20);
        printf("Appuyez sur une touche pour continuer...");
        break;
      }
      case 2: // Affichage des structures
      {
        system("cls");
            if (tete != NULL){
            textcolor(LIGHTBLUE);
            gotoxy(41,2);
            printf("------ AFFICHAGE DES STRUCTURES ------");
            textcolor(WHITE);
            gotoxy(33,5);
            printf("Appuyez sur");textcolor(BLUE);printf(" (1) ");textcolor(WHITE);printf("Pour acceder au ");textcolor(BLUE);printf("Tableau De Reservation");textcolor(WHITE);
            gotoxy(35,7);
            printf("Appuyez sur");textcolor(BLUE);printf(" (2) ");textcolor(WHITE);printf("pour acceder au ");textcolor(BLUE);printf("Tableau De Skieurs");textcolor(WHITE);
            gotoxy(42,9);
            printf("Appuyez sur");textcolor(BLUE);printf(" (3) ");textcolor(WHITE);printf("Pour revenir au ");textcolor(BLUE);printf("Menu");textcolor(WHITE);
            chx: 
            gotoxy(42,11); printf("Veuillez selectionner une option : ");
            int c;
            textcolor(CYAN);scanf("%d",&c);textcolor(WHITE);
            if (c==1){system("cls");}
            if (c==2){goto  tbsk; }
            if (c==3){goto mnu;}
            if (c!=1 && c!=2 && c!=3){textcolor(RED);printf("Operation invalide !!");textcolor(WHITE); printf("Essaie une autre fois.\n");goto chx;}


        tbrs:
           textbackground(BLUE);
            for (int j1=1;j1<67;j1++){printf(" ");}
            printf("\n");
            textcolor(BLACK);
            printf(" ");textbackground(LIGHTGRAY);printf("    La Taille    ");
            textbackground(BLUE);printf(" ");textbackground(LIGHTGRAY);printf("     Debut     ");
            textbackground(BLUE);printf(" ");textbackground(LIGHTGRAY);printf("     Fin     ");
            textbackground(BLUE);printf(" ");textbackground(LIGHTGRAY);printf("     Indice     ");
            textbackground(BLUE);printf(" \n");
            textbackground(BLUE);
                for (int j2=1;j2<67;j2++){printf(" ");}
                textbackground(BLACK);
                printf(" \n");
                textcolor(WHITE);

            plist ski = tete;
            while (ski != NULL)
            {
               textbackground(BLUE);printf(" ");textbackground(BLACK);printf("       %d       ", ski->taille);

               if (ski->taille<100){textbackground(BLACK);printf(" ");}
                textbackground(BLUE);printf(" ");textbackground(BLACK);
                premloc res = ski->loc;
                int cpt=0;
                if (res == NULL){printf("       /       ");textbackground(BLUE);printf(" ");textbackground(BLACK);printf("      /      ");textbackground(BLUE);printf(" ");;textbackground(BLACK);printf("       /        ");textbackground(BLUE);printf(" ");textbackground(BLACK);printf("\n");}
                 while (res != NULL)
                 {
                    if (cpt!=0){textbackground(BLUE);printf(" ");textbackground(BLACK);printf("                 ");textbackground(BLUE);printf(" ");textbackground(BLACK);}
                    cpt++;
                    if(res->deb<10){printf("  ");}if((res->deb<100) && (res->deb>9)){printf(" ");}printf("      %d      ", res->deb); textbackground(BLUE);printf(" ");textbackground(BLACK);
                    if(res->fin<10){printf("  ");}if((res->fin<100) && (res->fin>9)){printf(" ");}printf("    %d      ",res->fin); textbackground(BLUE);printf(" ");textbackground(BLACK);
                    if(res->ind<10){printf("  ");}if((res->ind<100) && (res->ind>9)){printf(" ");}printf("      %d       ",res->ind); textbackground(BLUE);printf(" ");textbackground(BLACK);
                    printf("\n");
                    res = res->ressuiv;
                }
                textbackground(BLUE);
                for (int j2=1;j2<67;j2++){printf(" ");}
                textbackground(BLACK);
                printf("\n");




                ski = ski->skisuiv;
            }
            int Yaxis,Xaxis;
            printf("\n\n");getCursorPosition(&Xaxis,&Yaxis);
            gotoxy(8,Yaxis);
            printf("Appuyez sur");textcolor(BLUE);printf(" (1) ");textcolor(WHITE);printf("pour acceder au ");textcolor(BLUE);printf("Tableau De Skieurs");textcolor(WHITE);
            gotoxy(15,Yaxis+2);
            printf("Appuyez sur");textcolor(BLUE);printf(" (2) ");textcolor(WHITE);printf("Pour revenir au ");textcolor(BLUE);printf("Menu");textcolor(WHITE);      
            goo: gotoxy(15,Yaxis+4); printf("Veuillez selectionner une option : ");
            int ch;
            scanf("%d",&ch);
            if (ch==1){system("cls");}
            if (ch==2){goto mnu;}
            if (ch!=1 && ch!=2){textcolor(RED);printf("Operation invalide !!");textcolor(WHITE); printf(" essaie une autre fois.\n");goto goo;}
             tbsk :
                 system("cls");textbackground(BLUE);
               for (int j2=1;j2<85;j2++){printf(" ");}
                textbackground(BLACK);
                printf("\n");
                  textcolor(BLACK);
             textbackground(BLUE);    printf(" ");textbackground(LIGHTGRAY);printf("      Le Nom      ");
            textbackground(BLUE);printf(" ");textbackground(LIGHTGRAY);printf("      Adresse      ");
            textbackground(BLUE);printf(" ");textbackground(LIGHTGRAY);printf("       Wilaya      ");
            textbackground(BLUE);printf(" ");textbackground(LIGHTGRAY);printf(" Paires de skis louees ");

            textbackground(BLUE);printf(" \n");
            textbackground(BLUE);
                for (int j2=1;j2<85;j2++){printf(" ");}
                textbackground(BLACK);
                printf(" \n");
                textcolor(WHITE);

             for (int i = 1; i <= nsk; i++)
            {
                textbackground(BLUE);printf(" ");textbackground(BLACK);printf(" %s", skieur[i].nom);for(int hh=strlen(skieur[i].nom);hh<17;hh++){printf(" ");};textbackground(BLUE);printf(" ");textbackground(BLACK);

                if(skieur[i].adresse<10){printf(" ");} printf("        %d         ",skieur[i].adresse);textbackground(BLUE);printf(" ");textbackground(BLACK);
                printf(" %s", wilayas[skieur[i].adresse]);for(int hh=strlen(wilayas[skieur[i].adresse]);hh<18;hh++){printf(" ");};textbackground(BLUE);printf(" ");textbackground(BLACK);
                printf("           %d           ",skieur[i].psk);textbackground(BLUE);printf(" ");textbackground(BLACK);printf("\n");

            }
            textbackground(BLUE);
            for (int j2=1;j2<85;j2++){printf(" ");}
            textbackground(BLACK);
            printf("\n\n");getCursorPosition(&Xaxis,&Yaxis);Yaxis++;
            gotoxy(16,Yaxis);
            printf("Appuyez sur");textcolor(BLUE);printf(" (1) ");textcolor(WHITE);printf("Pour acceder au ");textcolor(BLUE);printf("Tableau De Reservation");textcolor(WHITE);
            gotoxy(25,Yaxis+2);
            printf("Appuyez sur");textcolor(BLUE);printf(" (2) ");textcolor(WHITE);printf("Pour revenir au ");textcolor(BLUE);printf("Menu");textcolor(WHITE);
             mnu2: gotoxy(26,Yaxis+4); printf("Veuillez selectionner une option : ");
            int chh;
            scanf("%d",&chh);
            if (chh==1){system("cls");goto tbrs;}
            if (chh==2){goto mnu;}
            if (chh!=1 && ch!=2){textcolor(RED);printf("Operation invalide !!");textcolor(WHITE); printf(" essaie une autre fois.\n");goto mnu2;
            gotoxy(41, Yaxis+6);
            printf("Appuyez sur une touche pour continuer...");
            }
        }
        else {
           textcolor(RED);
           gotoxy(39, 10);
           printf("Veuillez creer les structures en premier.");
           textcolor(WHITE);
           gotoxy(41, 20);
           printf("Appuyez sur une touche pour continuer...");}
        break;
        }
        case 3: // Location de skis
        {
        clrscr();
        int Yaxis;
        if (tete != NULL) // Vérifie si les structures de données existent
        {

           textcolor(LIGHTBLUE);
           gotoxy(45, 2);
           printf("------ LOCATION DE SKIS ------");
           textcolor(WHITE);

           // Obtenir les informations de location
           int taille, deb, fin, ind;
           Yaxis = 6;
           int check=0;
           gotoxy(38, 4);
           printf("Veuillez saisir les informations suivantes :");
           gotoxy(35, Yaxis);

           textcolor(CYAN);
           printf("Taille : ");
           textcolor(WHITE);
           while (scanf("%d", &taille) != 1 || taille < 80 || taille > 200 || taille % 5 != 0)
           {
                if (scanf("%*[^\n]") == EOF)
                break;
                Yaxis++;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Taille invalide. Veuillez entrer une taille valide :    ");check=1;
                textcolor(WHITE);
           }
           if (check==0) Yaxis++;          
           gotoxy(35, Yaxis++);
           textcolor(CYAN);
           printf("Date de debut : ");
           textcolor(WHITE);
           while (scanf("%d", &deb) != 1 || deb < 1 || deb > 151)
           {
                if (scanf("%*[^\n]") == EOF)
                    break;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Date de debut invalide. Veuillez entrer une date valide :    ");
                textcolor(WHITE);
           }

           gotoxy(35, Yaxis++);
           textcolor(CYAN);
           printf("Date de fin : ");
           textcolor(WHITE);
           while (scanf("%d", &fin) != 1 || fin <= 0 || fin < deb)
           {
                if (scanf("%*[^\n]") == EOF)
                    break;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Date de fin invalide. Veuillez entrer une date valide :    ");
                textcolor(WHITE);
           }
           gotoxy(35, Yaxis++);
           textcolor(CYAN);
           printf("L'indice de skieur : ");
           textcolor(WHITE);
           while (scanf("%d", &ind) != 1 || ind < 0 || ind > nsk)
           {
                if (scanf("%*[^\n]") == EOF)
                    break;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Indice invalide. Veuillez entrer un indice valide :    ");
                textcolor(WHITE);
           }
           // Appelez la fonction de location et affichez le message approprie.
           bool lc = location(&tete, taille, deb, fin,ind);
           if (lc)
           {
                textcolor(GREEN);
                gotoxy(46, 17);
                printf("La location a ete effectuee.");
                textcolor(WHITE);
           }
           else
           {
                textcolor(RED);
                gotoxy(43, 17);
                printf("La location n'a pas ete effectuee.");
                textcolor(WHITE);
           }
        }
        else
        {
           textcolor(RED);
           gotoxy(39, 10);
           printf("Veuillez creer les structures en premier.");
           textcolor(WHITE);
        }

        gotoxy(41, 20);
        printf("Appuyez sur une touche pour continuer...");
        break;
        }

        case 4: // Reservation d'une paire de skis
        {
        int Yaxis;
        clrscr();

        // Utilize the reservation function.
        if (tete != NULL) // Vérifie si les structures de données existent
        {
           textcolor(LIGHTBLUE);
           gotoxy(43, 2);
           printf("------ RESERVATION DE SKIS ------");
           textcolor(WHITE);

           // Get input from user.
           int taille, deb, fin, ad;
           char nm[MAX_NOMS_LONGUEUR];
           Yaxis = 6;
           gotoxy(38, 4);
           printf("Veuillez saisir les informations suivantes :");
           gotoxy(35, Yaxis);
           textcolor(CYAN);
           printf("Nom : ");
           textcolor(WHITE);
           scanf("%s", &nm);
           Yaxis++;
           gotoxy(35, Yaxis++);
           textcolor(CYAN);
           printf("Adresse : ");
           textcolor(WHITE);
           while (scanf("%d", &ad) != 1 || ad < 1 || ad > 58 || getchar() != '\n')
           {
                if (scanf("%*[^\n]") == EOF)
                    break;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Adresse invalide. Veuillez entrer une adresse valide :    ");
                textcolor(WHITE);
           }

           gotoxy(35, Yaxis++);
           textcolor(CYAN);
           printf("Taille : ");
           textcolor(WHITE);
           while (scanf("%d", &taille) != 1 || taille < 80 || taille > 200 || taille % 5 != 0)
           {
                if (scanf("%*[^\n]") == EOF)
                    break;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Taille invalide. Veuillez entrer une taille valide :    ");
                textcolor(WHITE);
           }

           gotoxy(35, Yaxis++);
           textcolor(CYAN);
           printf("Date de debut : ");
           textcolor(WHITE);
           while (scanf("%d", &deb) != 1 || deb < 1 || deb > 151)
           {
                if (scanf("%*[^\n]") == EOF)
                    break;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Date de debut invalide. Veuillez entrer une date valide :    ");
                textcolor(WHITE);
           }

           gotoxy(35, Yaxis++);
           textcolor(CYAN);
           printf("Date de fin : ");
           textcolor(WHITE);
           while (scanf("%d", &fin) != 1 || fin <= 0 || fin < deb)
           {
                if (scanf("%*[^\n]") == EOF)
                    break;
                gotoxy(35, Yaxis++);
                textcolor(BLUE);
                printf("Date de fin invalide. Veuillez entrer une date valide :    ");
                textcolor(WHITE);
           }
           // Appelez la fonction de reservation et affichez le message approprie.
           bool rs = reservation(&tete, nm, ad, taille, deb, fin);
           if (rs)
           {
                textcolor(GREEN);
                gotoxy(40, 17);
                printf("La reservation est possible et effectuee");
                textcolor(WHITE);
           }
           else
           {
                textcolor(RED);
                gotoxy(44, 17);
                printf("La reservationn'est pas possible");
                textcolor(WHITE);
           }
        }
        else
        {
           textcolor(RED);
           gotoxy(39, 10);
           printf("Veuillez creer les structures en premier.\n");
           textcolor(WHITE);
        }

        gotoxy(41, 20);
        printf("Appuyez sur une touche pour continuer...\n");
        break;
        }

        case 5: // Reservation de plusieurs paires de skis
        {
        clrscr();
        // utilise la fonction reservations
         if (tete != NULL) // Vérifie si les structures de données existent
        {
           textcolor(LIGHTBLUE);
           gotoxy(41,2);
           printf("------ RESERVATIONS DE SKIS ------");
           textcolor(WHITE);
           reservations(&tete);
        }
        else
        {
           textcolor(RED);
           gotoxy(39, 10);
           printf("Veuillez creer les structures en premier.\n");
           textcolor(WHITE);
           gotoxy(41, 20);
           printf("Appuyez sur une touche pour continuer...");
        }
        break;
        }
        case 6 : // Addresse de ski
        {

        clrscr();
        if (tete != NULL)
        {
           textcolor(LIGHTBLUE);
           gotoxy(45,2);
           printf("------ ADRESSE DE SKIS ------");
           textcolor(WHITE);
            int ti,Yaxis,Xaxis=4,lastY,Ymax;
            Yaxis = 6;
            gotoxy(41, 4);
            printf("Veuillez saisir la taille de ski :");textcolor(CYAN);
            scanf("%d", &ti);
            plist skt = skit(&tete, ti);
            // afficher les informations de cette ski (qui a reserver et son wilaya et la date)
            if (skt != NULL)
            {
                // affichage de l'adresse skt 
                gotoxy(43, Yaxis);printf("Adresse de ski : %p", (void *)(skt));Yaxis++;
                premloc res = Res(skt);
                if (res != NULL) {
                Yaxis++;gotoxy(46,Yaxis);textbackground(BLUE);textcolor(WHITE);printf("Cet ski a ete reserve par :");Yaxis+=2;textbackground(BLACK);
                int i = 1;
                while (res != NULL)
                {   
                    gotoxy(Xaxis, Yaxis);lastY=Yaxis;
                    textcolor(CYAN);printf(" Mr/Mme : ");textcolor(WHITE);
                    printf("%s de wilaya %s", skieur[Ind(res)].nom, wilayas[skieur[Ind(res)].adresse] );Yaxis++;
                    gotoxy(Xaxis, Yaxis++);
                    textcolor(CYAN);printf(" Date debut : ");textcolor(WHITE);
                    printf("%d \t ",Deb(res));
                    textcolor(CYAN);printf("Date fin : ");textcolor(WHITE);
                    printf("%d ",Fin(res));
                    res = Suivant_res(res);
                    i++;
                    if (i % 2 == 0 && res != NULL) {Xaxis = 62;Ymax = Yaxis;Yaxis = lastY;}
                     else {Xaxis = 4; if (Yaxis < Ymax) {Yaxis = Ymax+=2;}else Yaxis+=2;}
                }
                } else {gotoxy(36, Yaxis+1);textcolor(RED);printf("Il n'y a pas de reservation pour cette ski");Yaxis++;textcolor(WHITE);}
            } else {gotoxy(36, Yaxis);textcolor(RED);printf("Il n'y a pas de paires de skis avec cette taille");Yaxis++;textcolor(WHITE);}
                 Yaxis++;gotoxy(40, Yaxis);
                printf("Appuyez sur une touche pour continuer...\n");
            break;
        }
        else
        {
           textcolor(RED);
           gotoxy(39, 10);
           printf("Veuillez creer les structures en premier.\n");
           textcolor(WHITE);
        }

        gotoxy(41, 20);
        printf("Appuyez sur une touche pour continuer...\n");
        break;
        }
        case 7: // Rechercher un skieur
        {
        clrscr();
        int Yaxis,indx;
        if (tete != NULL)
        {
            textcolor(LIGHTBLUE);
            gotoxy(43, 2);
            printf("------ RECHERCHER UN SKIEUR ------");
            textcolor(WHITE);
            Yaxis = 5;
            gotoxy(38, Yaxis);
            printf("Veuillez donner le nom du skieur : ");
            char nm[MAX_NOMS_LONGUEUR];
            scanf("%s", &nm);
            indx = cherchskieur(nm);
            if (indx == -1)
            {
                textcolor(RED);Yaxis+=3;
                gotoxy(31, Yaxis);
                printf("Il n'y a pas de reservation pour un skieur avec ce nom.");
                textcolor(WHITE);
            }
            else statsski(&tete, indx);
        }
        else
        {
           textcolor(RED);
           gotoxy(39, 10);
           printf("Veuillez creer les structures en premier.\n");
           textcolor(WHITE);
           gotoxy(41, 20);
           printf("Appuyez sur une touche pour continuer...");
        }
        break;
            }
        case 8 : // Statistiques d'une paire de skis (nombre de jours de location)
         {
            clrscr();
        int Yaxis;
        if (tete != NULL)
        {
            textcolor(LIGHTBLUE);
            gotoxy(37, 2);
            printf("------ STATISTIQUES D'UNE PAIRE DE SKIS ------");
            textcolor(WHITE);
            Yaxis = 5;
            gotoxy(41, Yaxis);
            printf("Veuillez donner la taille de ski : ");
            int ti, nbjr, cpt = 1;
            Yaxis +=3;
            int cp = 1,Xaxis;
            scanf("%d", &ti);
            plist ski = tete;
            while (ski != NULL)
            {
                if (Taille(ski) == ti)
                {
                     nbjr = nbjloc(&ski, ti);
                     Xaxis = calculateXAxis("Le nombre de jours de location des paire de skis de taille %dcm numero %d est %d jours", ti, cpt, nbjr);
                     gotoxy(Xaxis,Yaxis);
                     printf("Le nombre de jours de location des paire de skis de taille ");textcolor(CYAN);printf("%dcm",ti);textcolor(WHITE);
                     printf(" numero ");textcolor(CYAN);printf("%d",cpt);textcolor(WHITE);
                     printf(" est ");textcolor(CYAN);printf("%d",nbjr);textcolor(WHITE);printf(" jours");Yaxis++;
                     cpt++;
                     Yaxis++; 
                }
                ski = Suivant_ski(ski);
            }
            
            Yaxis++;
            if (totjr(&tete, ti) != 0 ) {
            Xaxis = calculateXAxis("Le nombre total de jours de location est : %d", totjr(&tete, ti));
            gotoxy(Xaxis,Yaxis);
            printf("Le nombre total de jours de location est : ");textcolor(CYAN);printf("%d",totjr(&tete, ti));textcolor(WHITE);
            Yaxis+=2;
            Xaxis = calculateXAxis("La moyenne de jours de location est : %.1f", (float)totjr(&tete, ti) / memet(&tete, ti));
            gotoxy(Xaxis,Yaxis);
            printf("La moyenne de jours de location est : ");textcolor(CYAN);printf("%.1f", (float)totjr(&tete, ti) / memet(&tete, ti));textcolor(WHITE);
            } else {gotoxy(36, Yaxis);textcolor(RED);printf("Il n'y a pas de paires de skis avec cette taille");Yaxis++;textcolor(WHITE);}
                 Yaxis++;gotoxy(40, Yaxis);
        }
        else
        {
            textcolor(RED);
            gotoxy(39, 10);
            printf("Veuillez creer les structures en premier.\n");
            textcolor(WHITE);
        }
        gotoxy(41, 20);
        printf("Appuyez sur une touche pour continuer...\n");
        break;
            }
            case 9: // Nombre de paires de ski
            {
        clrscr();
        int Yaxis;
        if (tete != NULL)
        {
            textcolor(LIGHTBLUE);
            gotoxy(41, 2);
            printf("------ NOMBRE DE PAIRES DE SKIS ------");
            textcolor(WHITE);
            gotoxy(37, 5);
            printf("Le nombre de pairs de skis disponibles est : ");textcolor(CYAN);printf("%d", nbskis(tete));textcolor(WHITE);
            Nonrs(&tete);
        }
        else
        {
            textcolor(RED);
            gotoxy(39, 10);
            printf("Veuillez creer les structures en premier.\n");
            textcolor(WHITE);
        }
        gotoxy(41, 24);
        printf("Appuyez sur une touche pour continuer...\n");
        break;
            }
            case 10: // Annulation de reservation (une ou toutes les reservations d'un skieur)
            {
        clrscr();
        int Yaxis=5,indx,cpt=1;
        if (tete != NULL)
        {
            textcolor(LIGHTBLUE);
            gotoxy(41, 2);
            printf("------ ANNULATION DE RESERVATION ------");
            textcolor(WHITE);
            gotoxy(32, Yaxis);
            printf("Veuillez donner le nom du skieur qui veut annulee :");
            char nm[MAX_NOMS_LONGUEUR];
            textcolor(CYAN);scanf("%s", &nm);textcolor(WHITE);
            indx = cherchskieur(nm);
            if (indx != -1 ) {
            Yaxis+=2;gotoxy(29, Yaxis);
            printf("Souhaitez-vous annuler toutes les reservations ou une seule ?");Yaxis+=2;
            textcolor(BLUE);gotoxy(54,Yaxis);printf(" (T ou U) : ");textcolor(WHITE);
            char choix;
            scanf("%s", &choix);
            if (choix == 'T' || choix == 't') {
                annuleres(&tete, skieur[indx].nom);
                int x = calculateXAxis("Toutes les reservations de %s ont ete annulees", nm);Yaxis+=2;
                textcolor(GREEN);gotoxy(x,Yaxis);printf("Toutes les reservations de %s ont ete annulees",nm);textcolor(WHITE);
            }
            else if (choix == 'U' || choix == 'u')
            {
                premloc Tabres[50];
                plist ski = tete,Tabski[50];
                int taisauv = Taille(ski),i=1;
                premloc res = Res(ski);
                textcolor(LIGHTCYAN);gotoxy(38,Yaxis);printf("Quelle reservation souhaitez-vous annuler ?");Yaxis++;textcolor(WHITE);
                while (ski != NULL)
                {
                    res = Res(ski);
                    while (res != NULL)
                    {
                    if (indx == Ind(res))
                        {
                            int x = calculateXAxis("%d) Ski de Taille %dcm, Numero %d de jour %d a %d", i, Taille(ski), cpt, Deb(res), Fin(res));Yaxis++;
                            gotoxy(x,Yaxis);printf("%d) Ski de Taille ", i);
                            textcolor(CYAN);printf("%dcm", Taille(ski));textcolor(WHITE);printf(", Numero ");
                            textcolor(CYAN);printf("%d", cpt);textcolor(WHITE);printf(" de jour ");
                            textcolor(CYAN);printf("%d", Deb(res));textcolor(WHITE);printf(" a ");textcolor(CYAN);printf("%d", Fin(res));textcolor(WHITE);
                            Tabres[i] = res;Tabski[i] = ski;i++;
                        }
                        res = Suivant_res(res);
                    }
                    if (Taille(ski) == taisauv)cpt++; else cpt = 1;
                    ski = Suivant_ski(ski);      
                }
                Yaxis+=2;gotoxy(36,Yaxis);int k;
                printf("Donnez le numero de la reservation a annuler : ");textcolor(CYAN);Yaxis++;
                while (scanf("%d", &k) != 1 || k < 1 || k > i-1) {
                    if (scanf("%*[^\n]") == EOF)
                    break;
                    gotoxy(42,Yaxis);textcolor(RED);printf("Veuillez donner un numero valide : ");textcolor(CYAN);Yaxis++;
                }
                i = k;
                textcolor(WHITE);
                annulerUn(&tete, skieur[indx].nom, Taille(Tabski[i]), Deb(Tabres[i]), Fin(Tabres[i]));
                if (skieur[indx].psk == 0) {
                    char *svNm = skieur[indx].nom ;
                    annuleres(&tete, svNm);
                    int x = calculateXAxis("Toutes les reservations de %s ont ete annulees", svNm);Yaxis+=2;
                    gotoxy(x,Yaxis);textcolor(GREEN);printf("Toutes les reservations de %s ont ete annulees",svNm);textcolor(WHITE);
                } else {
                int x = calculateXAxis("La reservation numero %d de %s a ete annulee", i, skieur[indx].nom);Yaxis+=2;
                textcolor(GREEN);gotoxy(x,Yaxis);printf("La reservation numero %d de %s a ete annulee", i, skieur[indx].nom);textcolor(WHITE);
                }
        }else {textcolor(RED);gotoxy(48,Yaxis);printf("Cet option n'existe pas!", nm);textcolor(WHITE);}
        } else {
            int x = calculateXAxis("Le skieur %s n'existe pas", nm);Yaxis+=4;
            textcolor(RED);gotoxy(x,Yaxis);printf("Le skieur %s n'existe pas", nm);textcolor(WHITE);
        }
        gotoxy(41, Yaxis+3);
        printf("Appuyez sur une touche pour continuer...\n");
        }
        else
        {
            textcolor(RED);
            gotoxy(39, 10);
            printf("Veuillez creer les structures en premier.\n");
            textcolor(WHITE);
            gotoxy(41, 20);
            printf("Appuyez sur une touche pour continuer...");
        }
        break;
            }
        case 11 : // Quitter
            {
                clrscr();
                Aurevoir();delay(1000);
                printf("\n");
                goto fin;
                break;
            }
      }
      c = getche();mnu:{}
   } while (c != 27);

   menu(&l);
   getch();
    fin: {}
    return 0;
}

