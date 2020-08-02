#ifndef MENU_H
#define MENU_H
#include <iostream>

//Fonction qui affiche un menu des actions qu'on peut effectuer
//avec ce logiciel
int choixMenu(){
  int choix=0;  
  //do{
    std::cout<<std::endl;
    std::cout<<"     *********** Menu ***********   "<<std::endl<<std::endl;
    std::cout<<" 1 . Ajouter un(e) employe(e) syndique(e)"<<std::endl;
    std::cout<<" 2 . Ajouter un(e) employe(e) contractuel(le)"<<std::endl;
    std::cout<<" 3 . Ajouter un(e) employe(e) ponctuel(le)"<<std::endl;
    std::cout<<" 4 . Afficher le resultat de la paie pour les employe(e)s entre(e)s"<<std::endl;
    std::cout<<" 5 . Supprimer un(e) employe(e)"<<std::endl;
    std::cout<<" 6 . Quitter le logiciel"<<std::endl<<std::endl; 

    do{
    std::cout<<"  Veuillez entrer votre choix (1/2/3/4/5/6): ";
    std::cin>>choix;
    std::cout<<std::endl;  
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix!=6);
    //} while(choix!=5); 
return choix;      
};
#endif //MENU_H