#include <iostream>
#include <windows.h>

using namespace std;

class Board
{
private:
    int boardArray[6][7];
    const char piece[3] = {'_', 'O', 'X'};
    int BOARD_WIDTH = 7;
    int BOARD_HEIGHT = 6;
    int lastPlayedX;
    int lastPlayedY;

public:
    const int RED_PLAYER = 1;
    const int YELLOW_PLAYER = 2;
    const int EMPTY_SLOT = 0;

    /**
     * Constructor for the board class
     */
    Board();

    /**
     * Constructor for the board class using another board
     */
    Board(Board* temp);

    /**
     * Returns true if the move is valid for that player
     */
    bool validMove(int x, int y, int player);

    /**
     * Returns true if the col is a valid move for the player
     */
    int getValidRowInCol(int col, int player);

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
     * Check to see if the board is full
     */
    bool boardIsFull();

    /**
     * Returns the player at a specific coordinate
     */
    int getPlayerAt(int x, int y);

    /**
     * sets the player at a specific coordinate
     */
    int setPlayerAt(int x, int y, int player);

    /**
     * sets the player in a specific column
     */
    int setPlayerInCol(int col, int player);

    /**
     * return the piece of a given player
     */
    char getPlayerPiece(int player);

    /**
     * returns the other player
     */
    int getOtherPlayer(int player);

    /**
     * returns the width of the board
     */
    int getBoardWidth();

    /**
     * returns the height of the board
     */
    int getBoardHeight();

    /**
     * Prints the board with formatting on the command line
     */
    int printBoardOnCmdLine();
};