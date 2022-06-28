#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
  int jouer = 0;
  printf("Voulez-vous jouer?\nOui = 1 \nNon = 2\n");

  while (jouer == 0) {
    do {
      scanf("%d", &jouer);

      if (jouer == 1) {
        printf("Nikel alors\n");
      } else if (jouer == 2) {
        printf("tes mechant\n");
        jouer = 0;
      } else {
        printf("ta dis quoi la?\n");
        jouer = 0;
      }
    } while (jouer == 0 || jouer == 2);

    int niveau = 0;

    printf("Choisi ton niveau\n");
    printf("1: un nombre aléatoire entre 1 et 100\n");
    printf("2: un nombre aléatoire entre 1 et 1000\n");

    while (niveau == 0) {
      scanf("%d", &niveau);

      if (niveau == 1 || niveau == 2) {
        printf("d'accord\n");
      } else {
        printf("rien compris\n");
        niveau = 0;
      }
    }

    int joueurs = 0;

    printf("1 ou 2 joueurs?\n");

    while (joueurs == 0) {
      scanf("%d", &joueurs);

      if (joueurs == 1) {
        printf("ok donc 1 joueur\n jouons! \n");
        printf("le but du jeu est de deviner un nombre\nbonne chance\n\n");

      } else if (joueurs == 2) {
        printf("\nok donc 2 joueurs\n\n");

        printf(
            "c'est parti!\nle but du jeu est de deviner un nombre aleatoire "
            "avec le moins d'essais possible\nbonne chance\n\n");
      } else {
        printf("imbecile\n");
        joueurs = 0;
      }
    }
    int nombreMystere = 0;
    int essais = 0;

    if (joueurs == 2) {
      printf("joueur1 choisi le nombre\n");

      while (nombreMystere == 0) {
        scanf("%d", &nombreMystere);

        if (niveau == 1) {
          if (nombreMystere >= 101 || nombreMystere <= 1) {
            printf("joueur1 doit choisir un nombre valide entre 1 et 100\n");
            nombreMystere = 0;
          }

        } else {
          if (nombreMystere >= 1001 || nombreMystere <= 1) {
            printf("joueur1 doit choisir un nombre valide entre 1 et 1000\n");
            nombreMystere = 0;
          }
        }
      }

      printf("joueur1 as choisi le nombre!\n");
    } else {
      int MAX = 0, MIN = 0;

      if (niveau == 1) {
        MAX = 100;
        MIN = 1;
      } else {
        MAX = 1000;
        MIN = 1;
      }
      srand(time(NULL));
      nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    }

    if (joueurs == 2) {
      printf("joueur2 trouve ce nombre\n");
    } else {
      printf("joueur solo trouve le nombre mystere\n");
    }

    int nombreEntre = 0;

    while (nombreMystere != nombreEntre) {
      scanf("%d", &nombreEntre);

      if (nombreMystere > nombreEntre) {
        printf("C'est plus !\n\n");
        essais++;
      } else if (nombreMystere < nombreEntre) {
        printf("C'est moins !\n\n");
        essais++;
      } else {
        essais++;
        printf(
            "Bravo, vous avez trouve le nombre mystere en %d essais "
            "!!!\n\nTapez 1 pour rejouer\n",
            essais);
      }
    }
    jouer = 0;
  }
  return 0;
}
