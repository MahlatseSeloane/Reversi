#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class GameManager
{
public:
    GameManager();
    GameManager(int _boardSize);
    void setUp(int _boardSize);
    void checkEmptySpaces();

    int updateScore();
    void play(int index,ofstream &outData);

    void setTurn(bool _turn);

    vector<vector<char> > getBoard();
    vector<vector<int> > getPossibleFlips();
    bool getTurn();

    bool isTheGameOver(ofstream &outData);

    void checkPossibleFlips();

    int VerticalCheckUp(int row,int col,char myPiece,char oppPiece);
    int VerticalCheckDown(int row,int col,char myPiece,char oppPiece);
    int HorizontalCheckLeft(int row,int col,char myPiece,char oppPiece);
    int HorizontalCheckRight(int row,int col,char myPiece,char oppPiece);
    int DiagonalCheckLeftUp(int row,int col,char myPiece,char oppPiece);
    int DiagonalCheckRightDown(int row,int col,char myPiece,char oppPiece);
    int DiagonalCheckRightUp(int row,int col,char myPiece,char oppPiece);
    int DiagonalCheckLeftDown(int row,int col,char myPiece,char oppPiece);
private:
    vector<vector<char> > board;
    vector<vector<int> > possibleFlips;

    int boardSize, p1Pieces, p2Pieces;
    char myPiece, oppPiece;
    bool myTurn;
};

#endif // GAMEMANAGER_H
