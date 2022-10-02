#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

// created by Mewwaa as a contribution to Hacktoberfest 2022
// https://github.com/Mewwaa
// all rights reserved

using namespace std;

class Cell
{
 private:
     int state = 0;
    char position;
public:
Cell(){}

int GetState()
{
    return this->state;
}

char GetPosition()
{
    return this->position;
}
void SetSymbol(int ifState)
{
    if(ifState == 0)
    {
        this->state = 0;
        this->position = ' ';
    }
    else
    {
        this->state = 1;
        this->position = 'x';
    }
}

};

class Board
{
private:
        int boardSize;
        Cell** board;
public:
    Board(int boardSize) : boardSize{boardSize}
{
    int rows = this->boardSize;
    int cols = this->boardSize;

    this->board = new Cell*[rows];
    for(int i = 0; i < rows; i++)
    {
        board[i] = new Cell[cols];
    }
    Reset();
}

~Board()
{
    for(int i = 0; i < boardSize; i++)
    {
        delete [] board[i];
    }
    delete [] board;
}

void Reset()
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            board[i][j].SetSymbol(0);
        }
    }
}

bool CheckArea(int col, int rows)
{
    if(col <= 0 || rows <= 0 || col >= this->boardSize - 1 || rows >= this->boardSize - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void setPosition(int x , int y)
{
    this->board[x][y].SetSymbol(1);
}

int GetBoardboardSize()
{
    return this->boardSize;
}

void displayBoard()
{
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            cout<<"["<<board[i][j].GetPosition()<<"]";
        }
    cout<<endl;
    }
}
void check()
{
    for(int col = 0; col < boardSize; col++)
    {
        for(int rows = 0; rows < boardSize; rows++)
        {
            cout<< board[col][rows].GetState();
        }
    }
}

int checking(int col, int rows)
{
    int neighbors = 0;
    for (int xx = -1; xx < 2; xx++)
    {
       for (int yy = -1; yy < 2; yy++)
       {
            if(CheckArea(col + xx,rows + yy) && board[xx + col][yy + rows].GetState() != 0)//1
            {
                neighbors ++;
            }
       }
    }
    return neighbors;
}


void GameOfLife()
{
    vector<int> x;
    vector<int> y;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {


            int neighbors = 0;
            if(CheckArea(i-1, j) && board[i-1][j].GetState() != 0)//1
            {
                neighbors ++;
            }

            if(CheckArea(i-1, j + 1) && board[i-1][j + 1].GetState() != 0)//2
            {
                neighbors ++;
            }

            if(CheckArea(i, j+1) && board[i][j + 1].GetState() != 0)//3
            {
                neighbors ++;

            }
            if(CheckArea(i+1, j+1) && board[i+1][j+1].GetState() != 0)//4
            {
                neighbors ++;
            }
            if(CheckArea(i+1, j) && board[i+1][j].GetState() != 0)//5
            {
                neighbors ++;
            }

            if(CheckArea(i+1, j-1) && board[i+1][j-1].GetState() != 0)//6
            {
                neighbors ++;
            }
            if(CheckArea(i, j-1) && board[i][j - 1].GetState() != 0)//7
            {
                neighbors ++;
            }
            if(CheckArea(i-1, j-1) && board[i-1][j-1].GetState() != 0)//8
            {
                neighbors++;
            }


            if((neighbors  < 1  || neighbors  > 3) && board[i][j].GetState() == 1)
            {

            }
            else if(neighbors  == 2 && board[i][j].GetState() == 1)
            {
                x.push_back(i);
                y.push_back(j);
            }
            else if(neighbors  == 3)
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    Reset();
    for (int d = 0; d < y.size(); d++)
    {
        this->board[x[d]][y[d]].SetSymbol(1);
    }
}

};



int main()
{
    Board b(20);
    b.setPosition(1,5);
    b.setPosition(2,5);
    b.setPosition(2,4);
    b.setPosition(3,5);
    b.setPosition(3,5);
    b.displayBoard();

    int rounds;
    cout<<"How many rounds do you want to play?"<<endl;
    cin >> rounds;
    do{
        Sleep(300);
        b.GameOfLife();
        system("cls");
        b.displayBoard();
        cout<<endl;
        rounds--;

    }while(rounds != 0);
    return 0;
}
