#include "Activities.cpp"
#include "Misfortunes.cpp"
#include "Player.cpp"
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;

vector<Player> merchant(vector<Player> leader);
vector<Player> intro();
void StatusUpdate(Activities a1, vector<Player> Team);
int cooking(int g, int c);
vector<Player> battle(vector<Player> Team, Monsters m1, Activities a1);

int main()
{
  srand(time(NULL));
  //activate all of the different classes in my main function
  Activities a1 = Activities();
  Puzzles p1 = Puzzles();
  Monsters m1 = Monsters();
  Misfortunes m2 = Misfortunes();
  vector<Player> Team = intro();
  Team = merchant(Team);
  p1.setR(0);
  //while loop continues through the multiple options the user can choose from, and keeps going until the game is won or lost. Depending on the number selected by the user it will perform different tasks by either
  //executing code or calling methods from other classes
  while (m1.getRoom() < 6)
  {

    int anger = a1.getAngerLevel();
    a1.setAngerLevel(anger + 2);
    if (a1.getAngerLevel() >= 100)
    {
      cout << "The sorcerer has reached full anger. You have no more time to escape the dungeon" << endl
           << "Good Effort but it wasn't enough" << endl
           << "Thanks for Playing" << endl;
      return 0;
    }
    if (Team.size() < 1)
    {
      cout << endl
           << endl
           << "All of you and your teammates have been destroyed, the Game is Over." << endl
           << "Better luck next time!" << endl;
      return 0;
    }
    StatusUpdate(a1, Team);
    int n = a1.display();

    //if user wants to fight a monsters
    if (n == 1)
    {
      Team = battle(Team, m1, a1);
    }
    //if user wants to talk to the npc
    if (n == 2)
    {
      int numr = (rand() % 3) + 1;
      if (numr == 1)
      {
        bool see = p1.GoodNPC();
        if (see == true)
        {
          merchant(Team);
        }
      }
      if (numr == 2)
      {
        p1.NeutralNPC();
      }
      if (numr == 3)
      {
        p1.BadNPC();
      }
    }
    //if user wants to cook and eat food
    if (n == 3)
    {
      int c = a1.cook();
      if (c == 0)
      {
        cout << endl;
      }
      else
      {
        int i1 = Team[0].getingredients();
        switch (c)
        {
        case 1:
          if (Team[0].getcookware() == "cauldron")
          {
            int w = cooking(i1, 2);
            if (w == 0)
            {
              break;
            }
            else if (w == -1)
            {
              Team[0].setcookware("");
              for (int a = 0; a < Team.size(); a++)
              {
                int z = Team[a].getfullnesspoints();
                Team[a].setfullnesspoints(z - 1);
              }
            }
            else
            {
              Team[0].setingredients(i1 - w);
              while (w > 0)
              {
                for (int i = 0; i < Team.size(); i++)
                {
                  if (w > 0)
                  {
                    int z = Team[i].getfullnesspoints();
                    Team[i].setfullnesspoints(z + 1);
                  }
                  w--;
                }
              }
            }
          }
          else
          {
            cout << "You do not have this cookware." << endl;
            break;
          }
        case 2:
          if (Team[0].getcookware() == "cast iron")
          {
            int w = cooking(i1, 10);
            if (w == 0)
            {
              break;
            }
            else if (w == -1)
            {
              Team[0].setcookware("");
              for (int a = 0; a < Team.size(); a++)
              {
                int z = Team[a].getfullnesspoints();
                Team[a].setfullnesspoints(z - 1);
              }
            }
            else
            {
              Team[0].setingredients(i1 - w);
              while (w > 0)
              {
                for (int i = 0; i < Team.size(); i++)
                {
                  if (w > 0)
                  {
                    int z = Team[i].getfullnesspoints();
                    Team[i].setfullnesspoints(z + 1);
                  }
                  w--;
                }
              }
            }
          }
          else
          {
            cout << "You do not have this cookware." << endl;
            break;
          }
        case 3:
          if (Team[0].getcookware() == "ceramic pot")
          {
            int w = cooking(i1, 25);
            if (w == 0)
            {
              break;
            }
            else if (w == -1)
            {
              Team[0].setcookware("");
              for (int a = 0; a < Team.size(); a++)
              {
                int z = Team[a].getfullnesspoints();
                Team[a].setfullnesspoints(z - 1);
              }
            }
            else
            {
              Team[0].setingredients(i1 - w);
              while (w > 0)
              {
                for (int i = 0; i < Team.size(); i++)
                {
                  if (w > 0)
                  {
                    int z = Team[i].getfullnesspoints();
                    Team[i].setfullnesspoints(z + 1);
                  }
                  w--;
                }
              }
            }
          }
          else
          {
            cout << "You do not have this cookware." << endl;
            break;
          }
        }
      }
      cout << "Fullness Levels: " << endl;
      for (int i = 0; i < Team.size(); i++)
      {
        cout << i << ". " << Team[i].getfullnesspoints() << endl;
      }
      cout << "REMAINING INGREDIENTS: " << Team[0].getingredients() << endl;
    }
    //if user wants to explore the room
    if (n == 4)
    {
      for (int a = 0; a < Team.size(); a++)
      {
        int z = Team[a].getfullnesspoints();
        Team[a].setfullnesspoints(z - 1);
      }
      int ran = (rand() % 8) + 1;
      if (ran <= 3)
      {
        cout << "You found a key!" << endl
             << "You now may open the door and continue onto the next room." << endl;
        a1.setKey(true);
      }
      if (ran == 5 || ran == 6)
      {
        cout << "You have ran into a monster. You now must fight." << endl;
        Team = battle(Team, m1, a1);
      }
      if (ran == 4 || ran == 7 || ran == 8)
      {
        cout << "You have not found anything. You have to find another way to get out of the room." << endl;
      }
    }
    //if user wants to open a door
    if (n == 5)
    {
      if (a1.getKey() == true)
      {
        cout << "You have made it to the next room congratulations!" << endl
             << "Lets see if you can make it all the way out!" << endl;
        int rom = m1.getRoom();
        m1.setRoom(rom + 1);
        a1.setR(rom + 1);
      }
      else
      {
        int ran = (rand() % 3) + 1;
        bool res = p1.door(ran);
        if (res == true)
        {
          cout << "Congratulations you have made it past this door!" << endl;
          int rom = m1.getRoom();
          m1.setRoom(rom + 1);
          a1.setR(rom + 1);
        }
        else
        {
          cout << "One of your players has been removed due to your loss." << endl;
          Team.pop_back();
        }
      }
    }
    //if user wants to exit the game
    if (n == 6)
    {
      cout << "Thank you for Playing!" << endl;
      return 0;
    }
    //implement misfortunes at each turn with 40% probabilty of one happening rez is 1 - 10
    int rez = m2.random();
    if (rez == 1)
    {
      m2.robbed();
      for (int i = 0; i < Team.size(); i++)
      {
        Team[i].setarmor(false);
        Team[i].setcookware("");
        Team[0].setingredients(0);
      }
    }
    if (rez == 2)
    {
      int q = 0;
      m2.breaks();
      for (int i = 0; i < Team.size(); i++)
      {
        string t = Team[i].getweapons();
        bool s = Team[i].getarmor();
        if (t != "")
        {
          q++;
          Team[i].setweapons("");
        }
        if (s == true)
        {
          q++;
          Team[i].setarmor(false);
        }
        if (q > 0)
        {
          break;
        }
      }
    }
    if (rez == 3)
    {
      m2.hunger();
      Team.pop_back();
      cout << Team.size() << " Members." << endl;
    }
    if (rez == 4)
    {
      m2.locked();
      Team.pop_back();
      cout << Team.size() << " Members." << endl;
    }
  }
  cout << endl
       << endl
       << "YOU HAVE BEATEN THE GAME!" << endl
       << "CONGRATULATIONS ON MAKING IT OUT OF THE DUNGEON, GREAT WORK!";
}



//intro where players can enter their name and get the rundown of what the game is about
vector<Player> intro()
{
  ifstream in_file;
  string filename = "intro.txt";
  in_file.open(filename);
  if (in_file.is_open())
  {
    string line = "";
    while (getline(in_file, line))
    {
      cout << line << endl;
    }
  }
  string name;
  cout << "Enter Player Name: " << endl;
  cin >> name;
  Player nameL = Player(name, true);
  string tmate;
  cout << "Enter Teammate 1 name:" << endl;
  cin >> tmate;
  Player tmate1c = Player(tmate, false);
  string tmate2;
  cout << "Enter Teammate 2 name:" << endl;
  cin >> tmate2;
  Player tmate2c = Player(tmate2, false);
  string tmate3;
  cout << "Enter Teammate 3 name:" << endl;
  cin >> tmate3;
  Player tmate3c = Player(tmate3, false);
  string tmate4;
  cout << "Enter Teammate 4 name:" << endl;
  cin >> tmate4;
  Player tmate4c = Player(tmate4, false);
  vector<Player> team;
  team.push_back(nameL);
  team.push_back(tmate1c);
  team.push_back(tmate2c);
  team.push_back(tmate3c);
  team.push_back(tmate4c);

  return team;
}

//This is the method where the user can interact with the merchant, buy items with gold and restock on things that are needed.
vector<Player> merchant(vector<Player> leader)
{
  bool first = false;
  while (first == false)
  {
    string temp;
    cout << endl
         << "Would you like to visit the merchant?" << endl
         << "Enter Y for Yes and Enter N for No" << endl;
    cin >> temp;

    if (temp == "y" || temp == "Y")
    {
      ifstream in_file;
      string filename = "merchant.txt";
      in_file.open(filename);
      if (in_file.is_open())
      {
        string line = "";
        while (getline(in_file, line))
        {
          cout << line << endl;
        }
      }
      first = true;
    }
    else if (temp == "n" || temp == "N")
    {
      return leader;
    }
    else
    {
      cout << "Invalid Input. Try Again." << endl;
    }
  }

  bool shop = false;
  while (shop == false)
  {
    string temp2;
    cin >> temp2;
    if (temp2 == "y" || temp2 == "Y")
    {
      string filename = "merchant2.txt";
      ifstream in_file;
      in_file.open(filename);
      string line = "";
      while (getline(in_file, line))
      {
        cout << line << endl;
      }
      string temp3;
      cin >> temp3;
      if (temp3 == "i" || temp3 == "I")
      {
        cout << "Each gold piece is worth one Kilogram of food, How many gold pieces does your team wish to spend on ingredients?" << endl
             << "Enter a number:" << endl;
        string num1;
        cin >> num1;
        bool test = true;
        for (int i = 0; i < num1.length(); i++)
        {
          if (isdigit(num1[i]) == false)
          {
            test = false;
            cout << "Invalid Input. Try Again." << endl;
            break;
          }
        }
        if (test == true)
        {
          int num = stoi(num1);
          if (num > leader[0].getGold())
          {
            cout << "You do not have enough gold." << endl;
          }
          else
          {
            leader[0].setingredients(num);
            int g = leader[0].getGold();
            g = g - num;
            leader[0].setGold(g);
            cout << "Your remaining balance of gold pieces is " << g << endl;
          }
        }
      }
      else if (temp3 == "c" || temp3 == "C")
      {
        int i = 0;
        cout << "1. A cauldron costs 20 gold pieces. You can use a cauldron to stew and boil ingredients. It is made of thick sturdy metal, so it only has a 2% chance of breaking each time you use it." << endl
             << "2. A cast iron pan costs 10 gold pieces. You can use a frying pan to sizzle ingredients. It is not as sturdy as a cauldron, with a 10% chance of breaking each time you use it." << endl
             << "3. A ceramic pot costs 5 gold pieces. You can use a ceramic pot to stew and boil ingredients. It is made from weaker material, so it has a 25% chance of breaking each time you use it." << endl
             << "Enter the number of the item you would like to purchase." << endl;
        string cook;
        cin >> cook;
        if (cook != "1" && cook != "2" && cook != "3")
        {
          cout << "Invalid Input. Try Again." << endl;
        }
        if (cook == "1")
        {
          int g = leader[0].getGold();
          if (g < 20)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 20;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[i].setcookware("cauldron");
          }
        }
        if (cook == "2")
        {
          int g = leader[0].getGold();
          if (g < 10)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 10;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[i].setcookware("cast iron");
          }
        }
        if (cook == "3")
        {
          int g = leader[0].getGold();
          if (g < 5)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 5;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[i].setcookware("ceramic pot");
          }
        }
      }
      else if (temp3 == "a" || temp3 == "A")
      {
        cout << "Which team member is this for, Enter the number:" << endl
             << "1. " << leader[0].getName() << endl
             << "2. " << leader[1].getName() << endl
             << "3. " << leader[2].getName() << endl
             << "4. " << leader[3].getName() << endl
             << "5. " << leader[4].getName() << endl;
        string arm;
        cin >> arm;
        if (arm != "5" && arm != "4" && arm != "2" && arm != "1" && arm != "3")
        {
          cout << "Invalid Input. Try Again." << endl;
        }
        if (arm == "1")
        {
          int g = leader[0].getGold();
          if (g < 5)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 5;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[0].setarmor(true);
          }
        }
        if (arm == "2")
        {
          int g = leader[0].getGold();
          if (g < 5)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 5;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[1].setarmor(true);
          }
        }
        if (arm == "3")
        {
          int g = leader[0].getGold();
          if (g < 5)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 5;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[2].setarmor(true);
          }
        }
        if (arm == "4")
        {
          int g = leader[0].getGold();
          if (g < 5)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 5;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[3].setarmor(true);
          }
        }
        if (arm == "5")
        {
          int g = leader[0].getGold();
          if (g < 5)
          {
            cout << "You do not have enough gold pieces." << endl;
          }
          else
          {
            g -= 5;
            leader[0].setGold(g);
            cout << "You have " << g << " gold pieces remaining" << endl;
            leader[4].setarmor(true);
          }
        }
      }
      else if (temp3 == "w" || temp3 == "W")
      {
        bool wep1 = false;
        int i = 0;
        cout << "Which team member is this for, Enter the number:" << endl
             << "1. " << leader[0].getName() << endl
             << "2. " << leader[1].getName() << endl
             << "3. " << leader[2].getName() << endl
             << "4. " << leader[3].getName() << endl
             << "5. " << leader[4].getName() << endl;
        string play;
        cin >> play;
        cout << endl;
        if (play != "5" && play != "4" && play != "2" && play != "1" && play != "3")
        {
          cout << "Invalid Input. Try Again." << endl;
        }
        if (play == "5")
        {
          i = 4;
          wep1 = true;
        }
        if (play == "4")
        {
          i = 3;
          wep1 = true;
        }
        if (play == "3")
        {
          i = 2;
          wep1 = true;
        }
        if (play == "2")
        {
          i = 1;
          wep1 = true;
        }
        if (play == "1")
        {
          i = 0;
          wep1 = true;
        }

        if (wep1 == true)
        {
          cout << "1. A club costs 2 gold pieces." << endl
               << "2. A spear costs 2 gold pieces." << endl
               << "3. A crossbow costs 5 gold pieces." << endl
               << "4. A battle-axe costs 5 gold pieces." << endl
               << "5. A longsword costs 5 gold pieces." << endl
               << "Enter the number of the item you would like to purchase." << endl;
          string wep;
          cin >> wep;
          if (wep != "5" && wep != "4" && wep != "2" && wep != "1" && wep != "3")
          {
            cout << "Invalid Input. Try Again." << endl;
          }
          if (wep == "5")
          {
            int g = leader[0].getGold();
            if (g < 5)
            {
              cout << "You do not have enough gold pieces." << endl;
            }
            else
            {
              g -= 5;
              leader[0].setGold(g);
              cout << "You have " << g << " gold pieces remaining" << endl;
              leader[i].setweapons("longsword");
            }
          }
          if (wep == "4")
          {
            int g = leader[0].getGold();
            if (g < 5)
            {
              cout << "You do not have enough gold pieces." << endl;
            }
            else
            {
              g -= 5;
              leader[0].setGold(g);
              cout << "You have " << g << " gold pieces remaining" << endl;
              leader[i].setweapons("battle-axe");
            }
          }
          if (wep == "3")
          {
            int g = leader[0].getGold();
            if (g < 5)
            {
              cout << "You do not have enough gold pieces." << endl;
            }
            else
            {
              g -= 5;
              leader[0].setGold(g);
              cout << "You have " << g << " gold pieces remaining" << endl;
              leader[i].setweapons("crossbow");
            }
          }
          if (wep == "2")
          {
            int g = leader[0].getGold();
            if (g < 2)
            {
              cout << "You do not have enough gold pieces." << endl;
            }
            else
            {
              g -= 2;
              leader[0].setGold(g);
              cout << "You have " << g << " gold pieces remaining" << endl;
              leader[i].setweapons("spear");
            }
          }
          if (wep == "1")
          {
            int g = leader[0].getGold();
            if (g < 2)
            {
              cout << "You do not have enough gold pieces." << endl;
            }
            else
            {
              g -= 2;
              leader[0].setGold(g);
              cout << "You have " << g << " gold pieces remaining" << endl;
              leader[i].setweapons("club");
            }
          }
        }
      }
      else if (temp3 == "l" || temp3 == "L")
      {
        shop = true;
      }
      else
      {
        cout << "You have entered an invalid letter. Try Again." << endl;
      }
    }
    else if (temp2 == "n" || temp2 == "N")
    {
      return leader;
    }
    else
    {
      cout << "Invalid Input. Try Again." << endl;
    }
    cout << "Would you like to purchase more items?" << endl
         << "Enter Y for Yes" << endl
         << "Enter N for No" << endl;
  }
  return leader;
}

//This is where I implement that status update, calling my functions from other classes to get the data in one area and print it for the user
void StatusUpdate(Activities a1, vector<Player> Team)
{
  cout << endl << endl << endl << "----STATUS UPDATE ----" << endl
       << "CURRENT ROOM: " << a1.getRoom(a1.getR()) << endl
       << "ROOM KEY FOUND: " << a1.getKey() << endl
       << "SORCERER ANGER LEVEL: " << a1.getAngerLevel() << endl
       << endl
       << "----PARTY MEMBERS ----" << endl;
  for (int i = 0; i < Team.size(); i++)
  {
    if (i == 0)
    {
      cout << "LEADER (ME) : " << Team[0].getfullnesspoints() << endl;
    }
    else
    {
      cout << "MEMBER " << i << ": " << Team[i].getfullnesspoints() << endl;
    }
  }

  cout << "----MATERIALS ----" << endl
       << "INGREDIENTS: " << Team[0].getingredients() << endl
       << "COOKWARE: ";
  int c = 0;
  int pot = 0;
  int iron = 0;
  for (int i = 0; i < Team.size(); i++)
  {
    string s = Team[i].getcookware();
    if (s == "cauldron")
    {
      c++;
    }
    if (s == "cast iron")
    {
      iron++;
    }
    if (s == "ceramic pot")
    {
      pot++;
    }
  }
  cout << c << " Cauldron(s) " << iron << " Cast Iron Pan(s) " << pot << " Ceramic Pot(s)" << endl;
  int club = 0;
  int spear = 0;
  int crossbow = 0;
  int baxe = 0;
  int longsword = 0;
  int a = 0;
  for (int i = 0; i < Team.size(); i++)
  {
    bool ar = Team[i].getarmor();
    if (ar == true)
    {
      a++;
    }
    string s = Team[i].getweapons();
    if (s == "club")
    {
      club++;
    }
    if (s == "spear")
    {
      spear++;
    }
    if (s == "crossbow")
    {
      crossbow++;
    }
    if (s == "battle-axe")
    {
      baxe++;
    }
    if (s == "longsword")
    {
      longsword++;
    }
  }
  cout << "WEAPONS: " << club << " club(s) " << spear << " spear(s) " << crossbow << " crossbow(s) " << baxe << " battle-axe " << longsword << " longsword(s)" << endl;
  cout << "ARMOR: " << a << " set(s) of Armor" << endl
       << "GOLD: " << Team[0].getGold() << " piece(s) of Gold" << endl
       << endl;
}
int cooking(int g, int c)
{
  int r = (rand() % 100) + 1;
  cout << "Enter the Amount of Ingredients you would like to cook with:" << endl;
  string ingr;
  cin >> ingr;
  bool ig = true;
  for (int i = 0; i < ingr.length(); i++)
  {
    if (!isdigit(ingr[i]))
    {
      cout << "Invalid Input. Try Again." << endl;
      ig = false;
      break;
    }
  }
  if (ig == true)
  {
    int ingr1 = stoi(ingr);
    if (ingr1 > g)
    {
      cout << "You do not have enough ingredients to cook this much." << endl;
    }
    else
    {
      if (r < c)
      {
        cout << "Your piece of cookware broke while you were cooking!" << endl;
        return -1;
      }
      else
      {
        return ingr1;
      }
    }
  }
  return 0;
}
//When the player chooses to battle, I will call this function so the battle can take place
vector<Player> battle(vector<Player> Team, Monsters m1, Activities a1)
{
  for (int a = 0; a < Team.size(); a++)
  {
    int z = Team[a].getfullnesspoints();
    Team[a].setfullnesspoints(z - 1);
  }
  int weap = 0;
  int a = 0;
  int d = 0;
  bool l = false;
  bool ba = false;
  bool cb = false;
  bool c = false;
  bool sp = false;
  for (int i = 0; i < Team.size(); i++)
  {
    bool armorr = Team[i].getarmor();
    string t = Team[i].getweapons();

    if (t == "longsword" || t == "battle-axe" || t == "crossbow")
    {
      weap += 2;
    }
    if (t == "club" || t == "spear")
    {
      weap += 1;
    }
    if (armorr == true)
    {
      a++;
    }
    if (t == "longsword")
    {
      l = true;
    }
    if (t == "battle-axe")
    {
      ba = true;
    }
    if (t == "crossbow")
    {
      cb = true;
    }
    if (t == "spear")
    {
      c = true;
    }
    if (t == "club")
    {
      sp = true;
    }
  }
  if (l == true && ba == true && cb == true && c == true && sp == true)
  {
    d = 1;
  }
  cout << "Would you like to " << endl
       << "1. Attack the Monster" << endl
       << "2. Surrender to the Monster(This will cause you to lose 1 teammate)" << endl;
  string dec;
  cin >> dec;
  if (dec != "1" && dec != "2")
  {
    cout << "Invalid Input. Try Again." << endl;
  }
  if (dec == "1")
  {
    int zzz = m1.getRoom();
    if (zzz == 1)
    {
      cout << "You have encountered a " << m1.getMonster1() << " . It lookes hostile." << endl;
    }
    if (zzz == 2)
    {
      cout << "You have encountered a " << m1.getMonster2() << " . It lookes hostile." << endl;
    }
    if (zzz == 3)
    {
      cout << "You have encountered a " << m1.getMonster3() << " . It lookes hostile." << endl;
    }
    if (zzz == 4)
    {
      cout << "You have encountered a " << m1.getMonster4() << " . It lookes hostile." << endl;
    }
    if (zzz == 5)
    {
      cout << "You have encountered a " << m1.getMonster1() << " . It lookes hostile." << endl;
    }
    bool result = m1.attack(weap, a, d);
    int g = Team[0].getGold();
    int ig = Team[0].getingredients();
    if (result == false)
    {
      cout << "You were defeated, you must find another way to unlock the door." << endl;
      Team[0].setGold(g * .75);
      if (ig > 30)
      {
        Team[0].setingredients(ig - 30);
      }
      else
      {
        Team[0].setingredients(0);
      }
    }
    else
    {
      cout << "Congratulations you have defeated the monster!" << endl
           << "Your team has earned 50 gold and 20 kg of ingredients." << endl;
      Team[0].setGold(g + 50);
      Team[0].setingredients(ig + 20);
      int rando = (rand() % 3) + 1;
      if (rando == 1)
      {
        int j = m1.getRoom();
        m1.setRoom(j + 1);
        string rombo = a1.getRoom(j + 1);
        a1.setR(j + 1);
        cout << "Your team also recovered a key, you have moved on to the " << rombo << endl;
      }
      else
      {
        cout << "Unfortunately the monster had no key, must continue trying to make it through the door" << endl;
      }
    }
  }
  if (dec == "2")
  {
    m1.surrender();
    Team.pop_back();
  }
  return Team;
}

