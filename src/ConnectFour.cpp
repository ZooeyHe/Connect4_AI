#include <ConnectFour.h>
#include <Board.h>

using namespace std;

ConnectFour::ConnectFour()
{
    gameBoard = new Board();
    turn = gameBoard->RED_PLAYER;
    winner = 0;
}

int ConnectFour::handlePlayerTurn(int player) {
    bool validMove = false;
    int col = -1;

    while (!validMove) {
        cout << "Player " << player << ", please select the column you would like to place your piece: ";
        cin >> col;
    }
}

int ConnectFour::startGameFromCmdLine()
{
    cout << "Please enter the game mode (0)PvP or (1)PvAi: ";
    cin >> gameMode;

    while (gameMode != PVPMODE && gameMode != PVAIMODE)
    {
        cout << "Invalid Mode, Please enter the game mode again, (0)PvP or (1)PvAi: ";
        cin >> gameMode;
    }

    if (gameMode == PVPMODE)
    {
        cout << "Player 1, You will be 'O'" << endl
             << "Player 2, You will be 'X'" << endl;
    }
    else if (gameMode == PVAIMODE)
    {
        cout << "Player 1, You will be 'O'" << endl;
    } else {
        return 1;
    }

    gameBoard->printBoardOnCmdLine();

    while (winner == 0) {
        handlePlayerTurn(gameBoard->RED_PLAYER);
        if (gameMode == PVPMODE) {
            handlePlayerTurn(gameBoard->YELLOW_PLAYER);
        } else if (gameMode == PVAIMODE) {
            
        }
        
    }

    return 0;
}