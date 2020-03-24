#ifndef _PERSONNAGES_H_
#define _PERSONNAGES_H_

#include <iostream>
#include <unistd.h>
#include <math.h>

class Personnage {
	public:
		Personnage();
		virtual ~Personnage();
		virtual void deplacement() = 0;
		virtual void combat();
		void affichage();
		int getAtk() const;
		int getDef() const;
		int getPv() const;
		int getLv() const;
		int* getX() const;
		int* getY() const;
	protected:
		int atk, def, pv, lv;
		int* x, y;
		char sprite;
};


class Hero: public Personnage {
	public:
		Hero();
		virtual ~Hero();
		void lvUp();
		virtual void deplacement(const char touche);
		void setName(std::string sname);
		void Haut();
		void Droite();
		void Gauche();
		void Bas();
		bool positionValide(int x, int y);
	protected:
		std::string name;
};


class Ennemi: public Personnage {
	public:
		Ennemi(const int &leveling);
		virtual ~Ennemi();
		virtual void deplacement();
};

#endif
