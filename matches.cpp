#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

main(){
   int nbtas, nballumettes;  // deux variables une pour le nombre d'allumettes du tas, une pour le nombre d'allumettes retirees par les joueurs
   srand(time(NULL));   // initialisation de la fonction de hazard
   cout << "With how many matches would you like to play? ";
   cin >> nbtas;
   cout << "You can start first" << endl;
   while(nbtas > 0){       // on s'arrête quand le tas d'allumettes est vide
      // l'utilisateur joue en premier
      cout << "How many matches do you pickup? (from 1 to 3) ";
      cin >> nballumettes;
      while (((nballumettes < 1) ||(nballumettes > 3 ))||(nballumettes > nbtas)){
         // on verifie que le nombre d'allumettes retirees par le joueur convient
         cout << "This value is not valid" <<endl;
         cout << "How many matches do you pickup? (from 1 to 3) ";
         cin >> nballumettes;
      }
      nbtas -= nballumettes;
      if(nbtas==0){
         cout << "No more matches"<< endl;
         cout << "I won"<< endl;
      }
      else{    // le tour de l'ordinateur
         cout << "there are "<< nbtas <<" matches left" << endl;
         nballumettes= rand()%3 +1;  // on choisit au hazard un nombre d'allumettes retirées par l'ordinateur
         if (nballumettes > nbtas)
            nballumettes = nbtas;
         cout << "i take " << nballumettes << " matches" << endl;
         nbtas -= nballumettes;
         if(nbtas==0){
            cout << "no more matches"<< endl;
            cout << "you won"<< endl;
         }
         else{
            cout << "there are "<< nbtas <<" matches left" << endl;
         }
      }
   }
}

