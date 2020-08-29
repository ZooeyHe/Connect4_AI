#include <iostream>

using namespace std;

class Board
{
private:
    int boardArray[6][7];
    const char piece[3] = {'+', 'O', 'X'};

public:
    const int RED_PLAYER = 1;
    const int YELLOW_PLAYER = 2;
    const int EMPTY_SLOT = 0;

    /**
     * Constructor for the board class
     */
    Board();

    /**
     * Returns true if the move is valid for that player
     */
    bool validMove(int x, int y, int player);

    /**
     * Returns true if the move is on the board
     */
    bool onBoard(int x, int y);

    /**
     * Check to see if the specified player has won the game
     */
    bool playerWon(int player);

    /**
     * Check to see if the specified player won at a specific position
     */
    bool checkVictoryAt(int x, int y, int player);

    /**
     * Returns the player at a specific coordinate
     */
    int getPlayerAt(int x, int y);

    /**
     * sets the player at a specific coordinate
     */
    int setPlayerAt(int x, int y, int player);

    /**
     * return the piece of a given player
     */
    char getPlayerPiece(int player);

    /**
     * Prints the board with formatting on the command line
     */
    int printBoardOnCmdLine();
};