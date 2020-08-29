#include <iostream>
#include <Board.h>

using namespace std;

class ConnectFour
{
private:
    Board* gameBoard;
    int gameMode;
    int turn;
    int winner;

    const int PVPMODE = 0;
    const int PVAIMODE = 1;

public:
    /**
     * Constructor for the ConnectFour class
     */
    ConnectFour();

    /**
     * Starts the game using the command line interface
     */
    int startGameFromCmdLine();

    /**
     * Handles a player turn
     */
    int handlePlayerTurn(int player);
};