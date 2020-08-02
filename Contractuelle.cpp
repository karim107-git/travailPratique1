#include "Contractuelle.hpp"
#include <iostream>

Contractuelle::Contractuelle()
{
}

Contractuelle::Contractuelle(std::string nom,int matricule,int montant,int semaines)
  :Employee(nom,matricule)
{
    this->montant=montant;
    this->semaines=semaines;
}

Contractuelle::~Contractuelle()
{
}

int Contractuelle::getMontant() const 
{
    return montant;
}

int Contractuelle::getSemaines() const
{
    return semaines;
}

double Contractuelle::calculPaieBrute()
{
  return (this->montant/(double)this->semaines);  
}

void Contractuelle::afficherEtatPaie()
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
