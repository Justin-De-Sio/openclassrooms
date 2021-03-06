#include "Personnage.h"

using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100)
{
}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{
}

void Personnage::afficherEtat() const
{
   cout << "Vie : " << m_vie << endl;
   cout << "Mana : " << m_mana << endl;
   m_arme.afficher();
}

void Personnage::recevoirDegats(int nbDegats)
{
   m_vie -= nbDegats;
   //On enlève le nombre de dégâts reçus à la vie du personnage

   if (m_vie < 0) //Pour éviter d'avoir une vie négative
   {
      m_vie = 0; //On met la vie à 0 (cela veut dire mort)
   }
}

void Personnage::attaquer(Personnage &cible)
{
   cible.recevoirDegats(m_arme.getDegats());
   //On inflige à la cible les dégâts que cause notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
   m_vie += quantitePotion;

   if (m_vie > 100) //Interdiction de dépasser 100 de vie
   {
      m_vie = 100;
   }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
   m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
   return m_vie > 0;
}
