#include "Puzzles.h"
#include <iostream>

string Puzzles ::getRiddleAt(int i)
{
    return riddles[i];
}
void Puzzles ::setRiddleAt(int i, string rid)
{
    riddles[i] = rid;
}
void Puzzles ::Riddle()
{
    // must complete the riddle first and then will find out whether the NPC is good or bad and live with the consequences
}
bool Puzzles ::GoodNPC()
{
    //implement good NPC , able to talk to the merchant and barter for goods
    int r = 0;
    cout << getRiddleAt(r) << endl;
    string ans;
    cin >> ans;
    if (ans == getAnswersAt(r))
    {
        setR(r + 1);
        cout << "Your answer is correct!" << endl;
        return true;
    }
    cout << "Incorrect Answer, correct answer is " << getAnswersAt(raz) << endl;
    setR(r + 1);
    return false;
}
void Puzzles ::BadNPC()
{
    //implement evil NPC , will summon a monsters
}
void Puzzles ::NeutralNPC()
{
    int r = getR();
    cout << getRiddleAt(r) << endl;
    string ans;
    cin >> ans;
    if (ans == getAnswersAt(r))
    {
        cout << "That answer is correct, but unfortunately, you receive no prize." << endl;
        setR(r + 1);
        return;
    }
    cout << "Incorrect Answer, correct answer is " << getAnswersAt(raz) << endl;
    setR(r + 1);
    //nothing special happens here
}
void Puzzles ::setR(int r1)
{
    raz = r1;
}
int Puzzles ::getR()
{
    return raz;
}
string Puzzles ::getAnswersAt(int i)
{
    return answers[i];
}
bool Puzzles :: door(int num)
{
    //Set up rock paper scissors to see if a person can make it through the door
    cout << "You have three chances to beat the computer in Rock, Paper, Scissors. " << endl
         << "If you win, you move past this room. If you lose, you lose a teammate." << endl
         << "Choose one of the Following options:" << endl
         << "1. Rock" << endl
         << "2. Paper" << endl
         << "3. Scissors" << endl;
    bool test = false;
    int i = 0;
    while (test == false)
    {
        num = (rand() % 3) + 1;
        if(i > 3)
        {
            cout << "Better Luck Next Time" << endl;
            return false; 
        }
        string choice;
        cin >> choice;
        if (num == 1)
        {
            cout << "Rock" << endl;
        }
        else if (num == 2)
        {
            cout << "Paper" << endl;
        }
        else
        {
            cout << "Scissors" << endl;
        }
        if (choice != "1" && choice != "2" && choice != "3")
        {
            cout << "Invalid Input. Try Again." << endl;
        }
        else if (choice == "1")
        {
            if (num == 1)
            {
                cout << "Tie. Try Again." << endl;
            }
            if (num == 2)
            {
                cout << "You lost. Try Again." << endl;
            }
            if (num == 3)
            {
                cout << "You Won!" << endl;
                return true;
            }
        }
        else if (choice == "2")
        {
            if (num == 1)
            {
                cout << "You Won!" << endl;
                return true;
            }
            if (num == 2)
            {
                cout << "Tie" << endl;
            }
            if (num == 3)
            {
                cout << "You lost. Try Again." << endl;
            }
        }
        else
        {
            if (num == 1)
            {

                cout << "You lost. Try Again." << endl;
            }
            if (num == 2)
            {
                cout << "You won!" << endl;
                return true;
            }
            if (num == 3)
            {
                cout << "Tie" << endl;
            }
        }
        i++;
    }
    return false; 
}