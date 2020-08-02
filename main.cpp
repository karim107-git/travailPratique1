#include <iostream>
#include <string>
#include "Employee.hpp"
#include "Syndiquee.hpp"
#include "Contractuelle.hpp"
#include "Ponctuelle.hpp"
#include "ImpotsTaxes.hpp"
#include "MenuChoix.h"
using namespace std;
Syndiquee* creationEmployeeSyndiquee(); //fonction qui retourne un pointeur vers un(e) employe(e) syndique(e)
Contractuelle* creationEmployeeContractuelle(); //fonction qui retourne un pointeur vers un(e) employe(e) contractuel(le)
Ponctuelle* creationEmployeePonctuelle(); //fonction qui retourne un pointeur vers un(e) employe(e) ponctuel(le)
bool suppressionEmployee(Employee* tabEmpl[250],int nbreEltsTableau); //fonction qui supprime un(e) employe(e) dans notre tableau sur la base de matricule
int main()
{	   
    Employee* tableauEmployees[250];   //tableau de pointeurs vers les objets employees  
    int indiceTableau=0; //compteur sur le nombre d'éléments du tableau
    int choix;
   do{
    choix= choixMenu(); //appel d'une fonction Menu qui retourn le choix de l'utilisateur  
    
    switch(choix){
        case 1 : /*Ajout d'un pointeur vers un objet employeeSyndiquee
                  *cree dynamiquement dans la fonction  creationEmployeeSyndiquee() */
                 tableauEmployees[indiceTableau]=creationEmployeeSyndiquee();  
                 indiceTableau++;          
                 break;
        case 2 : /*Ajout d'un pointeur vers un objet employeeContractuelle
                 *cree dynamiquement dans la fonction  creationEmployeeContractuelle() */
                 tableauEmployees[indiceTableau]=creationEmployeeContractuelle(); 
                 indiceTableau++;                   
                 break;
        case 3 : /*Ajout d'un pointeur vers un objet employeePonctuelle
                 *cree dynamiquement dans la fonction  creationEmployeePonctuelle() */
                 tableauEmployees[indiceTableau]=creationEmployeePonctuelle();
                 indiceTableau++;                   
                 break;
        case 4 : /*Parcours du tableau s'il n'est pas vide et appel polymorphique 
                  *de deux methode afficherEtatPaie() et calculPaieBrute() */
                if(indiceTableau!=0)
                  {
                    double montantsTotauxVerses=0;                    
                    cout<<"Affichage du releve de paie : "<<endl;
                    cout<<"============================== "<<endl<<endl;
                    for(int i=0;i<indiceTableau;i++){
                        tableauEmployees[i]->afficherEtatPaie();
                        montantsTotauxVerses+=tableauEmployees[i]->calculPaieBrute();                        
                    }
                    ImpotsTaxes imp;
                    double montantTransfererCA=montantsTotauxVerses*imp.getImpotsCA();
                    double montantTransfererQC=montantsTotauxVerses*imp.getImpotsQC();
                    
                    cout<<endl;
                    cout<<"Totaux"<<endl;
                    cout<<"  Montants totaux verses de "<<montantsTotauxVerses<<" $"<<endl;
                    cout<<"  Impots a transferer CA de "<<montantTransfererCA<<" $"<<endl;
                    cout<<"  Impots a transferer QC de "<<montantTransfererQC<<" $"<<endl;
                    cout<<"========================================= "<<endl;
                  } 
                  else 
                  {
                   cout<<"Le tableau des employees est vide !, rien a afficher"<<endl;
                  }
                 break;
        case 5 : /*si le tableau n'est pas vide appel de la methode suppressionEmployee 
                  * qui permet de supprimer un(e) employe(e) */
                 if (indiceTableau!=0){
                      if (suppressionEmployee(tableauEmployees,indiceTableau)){
                        indiceTableau--;
                       }                     
                 }else{
                     cout<<"Le tableau des employees est vide !, rien a supprimer "<<endl;
                 }                                                
                 break;
        case 6 : cout<<" Merci d'avoir utiliser ce logiciel "<<endl<<endl; 
                 break;
        default : cout<<" Mauvais choix ! "<<endl; 
    }  
    
   } while(choix!=6);
    
    /*Parcours de notre tableau jusqu'à nombre d'elements qu'il contient 
     *et destruction des employees dynamiquement */
    for (int i=0;i<indiceTableau;i++){
        delete tableauEmployees[i];
    }
    
	return 0;
}

/*fonction qui recupere des informations sur un(e) employe(e) syndique(e)
 * cree un objet employe(e) syndique(e) et retourne un pointeur vers cet objet */
Syndiquee* creationEmployeeSyndiquee(){
                 cout<<"Veuillez entrer les informations de l'employe(e) syndique(e) : "<<endl; 
                 cout<<"Nom (nom de famille sans espaces) : "; 
                 string nom;
                 cin>>nom;
                 
                 int matricule;
                 do{
                 cout<<"Matricule (Numero entre : 10000 et 99999) : ";                  
                 cin>>matricule;
                 }while (matricule<10000 || matricule >99999);
                 
                 cout <<"Salaire horaire : ";
                 double salaireHoraire;
                 cin>>salaireHoraire;
                 
                 cout <<"nombre d'heures travaillees : ";
                 double nombreHeuresTravaillees;
                 cin>>nombreHeuresTravaillees;  
                 
                Syndiquee* employeeSyndiquee=new Syndiquee(nom,matricule,salaireHoraire,nombreHeuresTravaillees);
                 cout<<endl<<"l'employe(e) "<<nom<<" "<<matricule<<" est ajoute(e) avec succes "<<endl;
                 return employeeSyndiquee;
}

/*fonction qui recupere des informations sur un(e) employe(e) contractuel(le)
 * cree un objet employe(e) contractuel(le)et retourne un pointeur vers cet objet */
Contractuelle* creationEmployeeContractuelle(){
                 cout<<"Veuillez entrer les informations de l'employe(e) contractuel(le) : "<<endl; 
                 cout<<"Nom (nom de famille sans espaces) : "; 
                 string nom;
                 cin>>nom;
                 
                 int matricule;
                 do{
                 cout<<"Matricule (Numero entre : 10000 et 99999) : ";                  
                 cin>>matricule;
                 }while (matricule<10000 || matricule >99999); 
                 
                 cout <<"Montant du contrat : ";
                 int montantContrat;
                 cin>>montantContrat;
                 
                 cout <<"nombre de semaines : ";
                 double nombreSemaines;
                 cin>>nombreSemaines; 
                                 
                 Contractuelle* employeeCntractuelle =new Contractuelle(nom,matricule,montantContrat,nombreSemaines);
                 cout<<endl<<"l'employe(e) "<<nom<<" "<<matricule<<" est ajoute(e) avec succes "<<endl;
                 return employeeCntractuelle; 
}

/*fonction qui recupere des informations sur un(e) employe(e) ponctuel(le)
 * cree un objet employe(e) ponctuel(le) et retourne un pointeur vers cet objet */
Ponctuelle* creationEmployeePonctuelle(){
                 cout<<"Veuillez entrer les informations de l'employe(e) ponctuel(le) : "<<endl; 
                 cout<<"Nom (nom de famille sans espaces) : "; 
                 string nom;
                 cin>>nom;
                 
                 int matricule;
                 do{
                 cout<<"Matricule(Numero entre : 10000 et 99999) : ";                  
                 cin>>matricule;
                 }while (matricule<10000 || matricule >99999); 
                 
                 cout <<"Montant de la tache : ";
                 int montantTaches;
                 cin>>montantTaches;  
            
                 Ponctuelle* employePonctuelle=new Ponctuelle(nom,matricule,montantTaches);
                 cout<<endl<<"l'employe(e) "<<nom<<" "<<matricule<<" est ajoute(e) avec succes "<<endl;
                 return employePonctuelle; 
}
/*fonction qui recupere la matricule entree par un l'utilisateur sur un(e) 
 *employe(e) et elle parcours notre tableau et elle verifie s'il existe 
 *elle decale tous les element d'une position et elle met le dernier element
 *a null et elle retourne true et s'il n'existe pas elle retourne false*/
bool suppressionEmployee(Employee* tabEmpl[250],int nbreEltsTableau){
  
    int matricule;
    string nom;
    do{
        cout<<"Veuillez entrer la matricule de l'employe(e) a supprimer : ";
        cin>>matricule;
    }while(matricule<10000 || matricule >99999);
    
   for (int i=0;i< nbreEltsTableau;i++){
       if (tabEmpl[i]->getMatricule()==matricule){
             nom=tabEmpl[i]->getNom();
            for (int j=i;j<nbreEltsTableau-1;j++){
               tabEmpl[j]=tabEmpl[j+1];
            }
            tabEmpl[nbreEltsTableau]=NULL;            
         cout<<endl<<"l'employe(e) "<<nom<<" "<<matricule<<" est supprime(e) avec succes "<<endl;
         return true;
       }
   }
   cout<<endl<<"l'employe(e) avec la matricule "<<matricule<<" n'existe pas "<<endl;
   return false;   
}
