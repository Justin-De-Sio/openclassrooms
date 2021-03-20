#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "Arme.h"
#include <string>
#include <iostream>
class Personnage
{
public:
   Personnage();
   Personnage(std::string nomArme, int degatsArme);
   void afficherEtat() const;
   void recevoirDegats(int nbDegats);
   void attaquer(Personnage &cible);
   void boirePotionDeVie(int quantitePotion);
   void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
   bool estVivant() const;

private:
   int m_vie;
   int m_mana;
   Arme m_arme;
};

#endif