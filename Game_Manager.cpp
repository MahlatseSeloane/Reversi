#include "Game_Manager.h"

GameManager::GameManager()
{
    boardSize = 0;
    p1Pieces = 0;
    p2Pieces = 0;
}

GameManager::GameManager(int _boardSize)
{
    setUp(_boardSize);
}

vector<vector<char> > GameManager::getBoard()
{
    return board;
}

vector<vector<int> > GameManager::getPossibleFlips()
{
    return possibleFlips;
}

void GameManager::setTurn(bool _turn)
{
    myTurn = _turn;
    if(myTurn)
        myPiece = 'X', oppPiece = 'O';
    else
        myPiece = 'O', oppPiece = 'X';
}

bool GameManager::getTurn()
{
    return myTurn;
}

void GameManager::setUp(int _boardSize)
{
    boardSize = _boardSize;
    myTurn = true;

    board.resize(boardSize, vector<char>(boardSize,'~'));

    board[boardSize/2][boardSize/2] = 'O';
    board[boardSize/2-1][boardSize/2] = 'X';
    board[boardSize/2-1][boardSize/2-1] = 'O';
    board[boardSize/2][boardSize/2-1] = 'X';

    p1Pieces = 0;
    p2Pieces = 0;

    setTurn(!myTurn);
}

void GameManager::play(int index,ofstream &outData)
{
    int row = possibleFlips[index][0];
    int col = possibleFlips[index][1];

    board[row][col] = myPiece;
    outData << "r" << row << "c" << col << " alg" << myTurn + 1 << ",";

    int counter, x, y;

    for(int i = 2; i < 10; i++)
    {
        counter = possibleFlips[index][i];

        switch(i)
        {
        case 2:
            x = -1, y = 0;
            break;
        case 3:
            x = 1, y = 0;
            break;
        case 4:
            x = 0, y = -1;
            break;
        case 5:
            x = 0, y = 1;
            break;
        case 6:
            x = -1, y = -1;
            break;
        case 7:
            x = 1, y = 1;
            break;
        case 8:
            x = -1, y = 1;
            break;
        case 9:
            x = 1, y = -1;
            break;
        }

        while(counter > 0)
        {
            row += x;
            col += y;
            board[row][col] = myPiece;
            outData << " r" << row << "c" << col;
            counter--;
        }

        row = possibleFlips[index][0];
        col = possibleFlips[index][1];
    }

    setTurn(!myTurn);

    outData << endl;
}

void GameManager::checkPossibleFlips()
{
    possibleFlips.clear();

    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if(board[i][j] == '~')
            {
                vector<int> temp(10);

                temp[0] = i;
                temp[1] = j;
                temp[2] = VerticalCheckUp(i,j,myPiece,oppPiece);
                temp[3] = VerticalCheckDown(i,j,myPiece,oppPiece);
                temp[4] = HorizontalCheckLeft(i,j,myPiece,oppPiece);
                temp[5] = HorizontalCheckRight(i,j,myPiece,oppPiece);
                temp[6] = DiagonalCheckLeftUp(i,j,myPiece,oppPiece);
                temp[7] = DiagonalCheckRightDown(i,j,myPiece,oppPiece);
                temp[8] = DiagonalCheckRightUp(i,j,myPiece,oppPiece);
                temp[9] = DiagonalCheckLeftDown(i,j,myPiece,oppPiece);

                for(int v = 2; v < 10; v++)
                {
                    if(temp[v] != 0)
                    {
                        possibleFlips.push_back(temp);
                        break;
                    }
                }
            }
        }
    }
}

int GameManager::VerticalCheckUp(int row,int col,char myPiece,char oppPiece)
{
    //VerticalUp check
    int x = 1;
    int counter = 0;

    if(row - x > 0)
    {
        while(board[row-x][col] == oppPiece && row - x > 0)
            x++;

        if(board[row-x][col] == myPiece && x > 1)
            counter += (x - 1);
    }

    return counter;
}

int GameManager::VerticalCheckDown(int row,int col,char myPiece,char oppPiece)
{
    //VerticalDown check
    int x = 1;
    int counter = 0;

    if(row + x < boardSize - 1)
    {
        while(board[row+x][col] == oppPiece && row + x < boardSize - 1)
            x++;

        if(board[row+x][col] == myPiece && x > 1)
            counter += (x - 1);
    }

    return counter;
}

int GameManager::HorizontalCheckLeft(int row,int col,char myPiece,char oppPiece)
{
    //HorizontalLeft check
    int y = 1;
    int counter = 0;

    if(col - y > 0)
    {
        while(board[row][col-y] == oppPiece && col - y > 0)
            y++;

        if(board[row][col-y] == myPiece && y > 1)
            counter += (y - 1);
    }

    return counter;
}

int GameManager::HorizontalCheckRight(int row,int col,char myPiece,char oppPiece)
{
    //HorizontalRight
    int y = 1;
    int counter = 0;

    if(col + y < boardSize - 1)
    {
        while(board[row][col+y] == oppPiece && col + y < boardSize - 1)
            y++;

        if(board[row][col+y] == myPiece && y > 1)
            counter += (y - 1);
    }

    return counter;
}

int GameManager::DiagonalCheckLeftUp(int row,int col,char myPiece,char oppPiece)
{
    //DiagonalLeft-Up
    int x = 1, y = 1;
    int counter = 0;

    if(row - x > 0 && col - y > 0)
    {
        while(board[row-x][col-y] == oppPiece && (row - x > 0 && col - y > 0))
            x++, y++;

        if(board[row-x][col-y] == myPiece && x > 1)
            counter += (x - 1);
    }

    return counter;
}

int GameManager::DiagonalCheckRightDown(int row,int col,char myPiece,char oppPiece)
{
    //DiagonalRight-Down
    int x = 1, y = 1;
    int counter = 0;

    if(row + x < boardSize - 1 && col + y < boardSize - 1)
    {
        while(board[row+x][col+y] == oppPiece && (row + x < boardSize - 1 && col + y < boardSize - 1))
            x++, y++;

        if(board[row+x][col+y] == myPiece && x > 1)
            counter += (x - 1);
    }

    return counter;
}

int GameManager::DiagonalCheckRightUp(int row,int col,char myPiece,char oppPiece)
{
    //DiagonalRight-Up
    int x = 1, y = 1;
    int counter = 0;

    if(row - x > 0 && col + y < boardSize - 1)
    {
        while(board[row-x][col+y] == oppPiece && (row - x > 0 && col + y < boardSize - 1))
            x++, y++;

        if(board[row-x][col+y] == myPiece && x > 1)
            counter += (x - 1);
    }

    return counter;
}

int GameManager::DiagonalCheckLeftDown(int row,int col,char myPiece,char oppPiece)
{
    //DiagonalLeft-Down
    int x = 1, y = 1;
    int counter = 0;

    if(row + x < boardSize - 1 && col - y > 0)
    {
        while(board[row+x][col-y] == oppPiece && (row + x < boardSize - 1 && col - y > 0))
            x++, y++;

        if(board[row+x][col-y] == myPiece && x > 1)
            counter += (x - 1);
    }

    return counter;
}

//Fix check
bool GameManager::isTheGameOver(ofstream &outData)
{
    bool forfeit = false;

    checkPossibleFlips();
    if(possibleFlips.size() == 0)
    {
        forfeit = true;
        setTurn(!myTurn);
        checkPossibleFlips();
    }

    if(forfeit == true && possibleFlips.size() == 0)
    {
        int winner = updateScore();
        outData << "alg1 = " << p1Pieces << endl << "alg2 = " << p2Pieces << endl;

        if(winner != 0)
            outData << "win = alg" << winner << endl;
        else
            outData << "draw" << endl;

        outData << endl;
        return true;
    }

    return false;
}

int GameManager::updateScore()
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if(board[i][j] == 'O')
                p1Pieces++;
            else if(board[i][j] == 'X')
                p2Pieces++;
        }
    }

    return (p1Pieces > p2Pieces) ? 1: (p1Pieces < p2Pieces) ? 2: 0;
}
