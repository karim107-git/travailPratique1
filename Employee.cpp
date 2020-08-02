#include "Employee.hpp"

Employee::Employee()
{
}

Employee::Employee(std::string nom,int matricule)
{
    this->nom=nom;
    this->matricule=matricule;
}

Employee::~Employee()
{
}

std::string Employee::getNom() const
 {
    return nom;
}

int Employee::getMatricule() const
{
    return matricule;
}

