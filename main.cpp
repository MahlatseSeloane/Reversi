#include "Game_Manager.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int player1(vector<vector<int> > possibleFlips);
int player2(vector<vector<int> > possibleFlips);

int main()
{
    ifstream inData;
    ofstream outData;
    inData.open("input.txt");
    outData.open("results.txt");

    while(inData.good())
    {
        int boardSize;
        char nonDigits;

        inData >> boardSize;
        inData >> nonDigits;

        if(boardSize%2 == 0 && (boardSize >= 4 && boardSize <= 16))
        {
            outData << "size = " << boardSize << endl;
            GameManager game(boardSize);
            int index;

            while(game.isTheGameOver(outData) == false)
            {
                index = 0;

                if(game.getTurn() == false)
                    index = player1(game.getPossibleFlips());
                else if(game.getTurn() == true)
                    index = player2(game.getPossibleFlips());

                game.play(index,outData);
            }
        }
    }

    inData.close();
    outData.close();

    return 0;
}

int player1(vector<vector<int> > possibleFlips)
{
    int randomNumber;

    srand(time(NULL));
    randomNumber = rand()%(possibleFlips.size());
    return randomNumber;
}

int player2(vector<vector<int> > possibleFlips)
{
    int index = 0, highestPoints = 0, temp;
    for(int i = 0; i < possibleFlips.size(); i++)
    {
        temp = 0;
        for(int j = 2; j < 10; j++)
            temp += possibleFlips[i][j];

        if(temp > highestPoints)
        {
            highestPoints = temp;
            index = i;
        }
    }

    return index;
}
