#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
class Employee
{
public:
     Employee();
     Employee(std::string nom,int matricule);
    ~Employee();
    std::string getNom() const;
    int getMatricule() const;
    double virtual calculPaieBrute()=0; //Methode virtuelle pure pour calcul la paie brute
    void virtual afficherEtatPaie()=0; //Methode virtuelle pure pour realiser l'affichage attendu par l'organisation
    
private:
   std::string nom;
   int matricule;
};

#endif // EMPLOYEE_HPP
