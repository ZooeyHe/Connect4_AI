#include <iostream>
#include <AiAdvSearch.h>

using namespace std;

class ConnectFour
{
private:
    Board* gameBoard;
    AiAdvSearch* ai;
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
     * Handles a player turn
     */
    int handlePlayerTurn(int player);

    /**
     * Handles the Ai's turn
     */
    int handleAiTurn(int player);

    /**
     * Starts the game using the command line interface
     */
    int startGameFromCmdLine();
};