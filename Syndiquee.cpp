#include "Syndiquee.hpp"
#include <iostream>

Syndiquee::Syndiquee()
{
}

Syndiquee::Syndiquee(std::string nom,int matricule,double salaire,double heures)
   :Employee(nom,matricule)
{
    this->salaire=salaire;
    this->heures=heures;
}

Syndiquee::~Syndiquee()
{
}

double Syndiquee::getSalaire() const 
{
    return salaire;
}

double Syndiquee::getHeures() const 
{
    return heures;
}
double Syndiquee::calculPaieBrute()
{
  return (this->salaire*this->heures);  
}

void Syndiquee::afficherEtatPaie()
{
   double impotsCA=this->calculPaieBrute()*this->getImpotsCA();
   double impotsQC=this->calculPaieBrute()*this->getImpotsQC();
   double paieNette=calculPaieBrute()-impotsCA-impotsQC;
   std::cout<<this->getNom()<<" "<<this->getMatricule()<<std::endl;
   std::cout<<"  Paie brute de "<<this->calculPaieBrute()<<" $"<<std::endl; 
   std::cout<<"  Impots CA de " <<impotsCA<<" $"<<std::endl;
   std::cout<<"  Impots QC de " <<impotsQC<<" $"<<std::endl;
   std::cout<<"  Paie nette de "<<paieNette<<" $"<<std::endl;    
}

