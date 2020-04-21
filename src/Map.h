#ifndef Map_H
#define Map_H

#include <vector>
#include <utility>
#include <string>
#include "Room.h"
#include "Personnages.h"

struct Corridor {
  std::vector<std::pair<int,int>> layer;
};

class Map {
public:
  Map(int const& size, int const& nb, int const& radius, int const& room_max_size,
      int const& room_min_size);
  Map(Hero *h);
  Map();
  ~Map();

  void initGeneration();
  void initGenerationDebug();
  void testRegression();

  void genRooms();
  void eclatement();
  void chooseRooms();
  void initLinks();

  void choisirRoomLink(int const ID);
	bool const isRoomLinked(int ID1, int ID2);
	void ajouterLinks();

	void genCorridors();
	void ajouterCorridors();
    void creerLigne(int const &IDcouloir, int const&x, int const& y, int const &bord1, int const &bord2, std::string param);
	bool const isPointInCorridor(int const &X, int const &Y, int const &ID);
    bool const isPointInRoom(int const &X, int const &Y);

  bool const allRoomsCollisions(unsigned int const ID);
  float* moyenneRooms(float mean[]);

  void ajouterRooms();
  void updateRooms();

  int newPosHero();
  int update();
  bool position_valide(const int &x, const int &y);

  void viderMap();
  void afficherMap();

  void afficherTout();
private:

  int **ptr_map;
  std::vector<Room> list_room;
  std::vector<Corridor> list_corridor;

  int map_size, nbrooms, radius, room_max_size, room_min_size, nb_ennemie;
  int hxm1, hym1;
  //Hero *hero;
  //std::vector<Ennemi*> ennemis;
};



#endif /* Map_H */
