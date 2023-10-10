#include <string>
#include "Puzzles.cpp"
#include "Monsters.cpp"
#include <fstream>
using namespace std; 

class Activities: public Puzzles, public Monsters
{
    private:
    bool key; 
    bool treasure; 
    int room; 
    string rooms[5];// {"Red Room", "Blue Room", "Green Room", "Yellow Room", "Final Room"}; 
    string treasures[5][3];// {"Quartz","Embroidered silk handkerchief","50 gold","Pearl","Bronze crown","100 gold","Topaz","Gold dragon comb","500 gold","Emerald","Old masterpiece painting","1000 gold","Diamond","Golden sarcophagus","5000 gold"};
    int treasureprice[5]; 
    int angerLevel; 

 

    public: 
    Activities()
    {
      angerLevel = 0;
      room = 1;
        treasure = false; 
        key = false; 
  string temp = "";
  string filename = "Rooms.txt";
  ifstream in_file;
  in_file.open(filename);
  if (in_file.is_open())
  {
    int i = 0;
    int r = 0;
    int t = 0;
    string line = "";
    while (getline(in_file, line))
    {
      i++;
      if (i % 2 == 1)
      {
        setRoom(r, line);
        r++;
      }
      else
      {
        line += ",";
        int z = 0;
        for (int c = 0; c < line.length(); c++)
        {
          if (line[c] != ',')
          {
            temp += line[c];
          }
          else
          {
            setTreasure(t, z, temp);
            z++;
            temp = "";
          }
        }
        t++;
      }
    }
}
    }
    Activities(bool t, bool k, int r)
    {
        treasure = t; 
        key = k;
        room = r; 
    }
    void exploreRoom();
    int display(); 
    void setKey(bool k);
    bool getKey();
    void setTreasure(bool t);
    void setTreasure(int i, int a, string t);
    string getTreasure(int i, int a);
    bool getTreasure();
    void setRoom(int r, string s);
    string getRoom(int i); 
    int getR();
    void setR(int r); 
    void setAngerLevel(int a); 
    int getAngerLevel();
    int cook(); 

}; 
