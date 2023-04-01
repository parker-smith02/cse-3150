// implement maze game
#include <vector>
// Room
class Room
{
public:
  virtual int GetPrize() const { return 1; }
};

// Room with a bomb
class RoomWithBomb : public Room
{
public:
  virtual int GetPrize() const { return -10; }
};

// Enchanted room 
class EnchantedRoom : public Room
{
public:
  virtual int GetPrize() const { return 20; }
};

// maze game
class MazeGame
{
public:
  MazeGame() {}
  virtual ~MazeGame() {
    for (auto x : listRooms) {
      delete x;
    }
  }
  
  // create a maze with two rooms and that is it!
  void CreateMaze()
  {
    Room *p1 = MakeRoom();
    listRooms.push_back(p1);
    Room *p2 = MakeRoom();
    listRooms.push_back(p2);
  }
  // get the total prize amount for the rooms
  int GetTotPrize() const
  {
    int sum = 0;
    for (auto x : listRooms) {
      sum += x->GetPrize();
    }
    return sum;
  }
  
 virtual Room* MakeRoom() {
    return new Room;
  }
  
private:
  std::vector<Room *> listRooms;
};

// bombed maze
class BombedMazeGame : public MazeGame
{
public:
  virtual Room* MakeRoom() {
    return new RoomWithBomb;
  }
};

// enchanted maze
class EnchantedMazeGame : public MazeGame
{
public:
virtual Room* MakeRoom() {
    return new EnchantedRoom;
  }
};

