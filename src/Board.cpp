#include <Board.h>

using namespace std;

Board::Board()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            boardArray[i][j] = EMPTY_SLOT;
        }
    }
    lastPlayedX = -1;
    lastPlayedY = -1;
}

Board::Board(Board* temp) {
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            boardArray[i][j] = temp->getPlayerAt(j, i);
        }
    }
    lastPlayedX = -1;
    lastPlayedY = -1;
}


bool Board::validMove(int x, int y, int player)
{
    if (!onBoard(x, y))
    {
        return false;
    }

    if (boardArray[y][x] != EMPTY_SLOT)
    {
        return false;
    }

    if (y < 5 && boardArray[y + 1][x] == EMPTY_SLOT)
    {
        return false;
    }

    return true;
}

int Board::getValidRowInCol(int col, int player) {
    int validRow = -1;
    for (int j = 0; j < 7; j++) {
        if (validMove(col, j, player)) {
            validRow = j;
        }
    }

    return validRow;
}

bool Board::onBoard(int x, int y)
{
    if (x > 6 || x < 0 || y > 5 || y < 0)
    {
        return false;
    }
    return true;
}

bool Board::playerWon(int player)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (checkVictoryAt(j, i, player))
            {
                return true;
            }
        }
    }

    return false;
}

bool Board::checkVictoryAt(int x, int y, int player)
{
    bool won[9] = {true, true, true, true, true, true, true, true, true};
    if (boardArray[y][x] == player)
    {
        for (int i = 1; i < 4; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                for (int k = -1; k < 2; k++)
                {
                    int w = 3 * (j + 1) + (k + 1);
                    if (won[w] && onBoard(x + j * i, y + k * i) && boardArray[y + k * i][x + j * i] != player)
                    {
                        won[w] = false;
                    }
                    else if (won[w] && !onBoard(x + j * i, y + k * i))
                    {
                        won[w] = false;
                    }
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (won[i] == true && i != 4)
            {
                return true;
            }
        }
    }

    return false;
}

bool Board::boardIsFull() {
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (boardArray[i][j] == EMPTY_SLOT) {
                return false;
            }
        }
    }
    return true;
}

int Board::getPlayerAt(int x, int y)
{
    return boardArray[y][x];
}

int Board::setPlayerAt(int x, int y, int player)
{
    boardArray[y][x] = player;
    lastPlayedX = x;
    lastPlayedY = y;
    return 0;
}

int Board::setPlayerInCol(int col, int player)
{
    int row = getValidRowInCol(col, player);
    setPlayerAt(col, row, player);
    return 0;
}

char Board::getPlayerPiece(int player)
{
    return piece[player];
}

int Board::getOtherPlayer(int player)
{
    if (player == RED_PLAYER) {
        return YELLOW_PLAYER;
    } else if (player == YELLOW_PLAYER) {
        return RED_PLAYER;
    } else {
        return -1;
    }
}


int Board::getBoardWidth() {
    return BOARD_WIDTH;
}

int Board::getBoardHeight() {
    return BOARD_HEIGHT;
}




int Board::printBoardOnCmdLine()
{
    for (int i = 0; i < 6; i++)
    {
        cout << "||  ";
        for (int j = 0; j < 7; j++)
        {
            cout << getPlayerPiece(boardArray[i][j]);
            cout << "  ";
        }
        cout << "||" << endl;
    }

    for (int i = 0; i < 27; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "  ";
    for (int i = 0; i < 7; i++)
    {
        cout << "  " << i;
    }
    cout << endl
         << endl;

    return 0;
}