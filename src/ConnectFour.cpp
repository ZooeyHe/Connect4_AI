#include <ConnectFour.h>

using namespace std;

ConnectFour::ConnectFour()
{
    gameBoard = new Board();
    ai = new AiAdvSearch();
    winner = 0;
}

int ConnectFour::handlePlayerTurn(int player) {
    int col = -1;
    int validRow = -1;

    while (validRow == -1) {
        cout << "Player " << player << ", please select the column you would like to place your piece: ";
        cin >> col;
        validRow = gameBoard->getValidRowInCol(col, player);
    }

    gameBoard->setPlayerAt(col, validRow, player);

    if (gameBoard->playerWon(player)) {
        winner = player;
    }

    return 0;
}

int ConnectFour::handleAiTurn(int player) {
    int col = ai->searchBestMove(player, gameBoard);
    cout << "AI Moved: " << col << endl;
    int row = gameBoard->getValidRowInCol(col, player);
    gameBoard->setPlayerAt(col, row, player);

    if (gameBoard->playerWon(player)) {
        winner = player;
    }

    return 0;
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
        ai = new AiAdvSearch();
    }

    gameBoard->printBoardOnCmdLine();

    while (winner == 0) {
        handlePlayerTurn(gameBoard->RED_PLAYER);
        if (gameMode == PVPMODE && winner == 0) {
            gameBoard->printBoardOnCmdLine();
            handlePlayerTurn(gameBoard->YELLOW_PLAYER);
            gameBoard->printBoardOnCmdLine();
        } else if (gameMode == PVAIMODE && winner == 0) {
            //TODO: IMPLEMENT AI
            handleAiTurn(gameBoard->YELLOW_PLAYER);
            gameBoard->printBoardOnCmdLine();
        }
        
        
    }

    cout << "Congrats Player " << winner << ", YOU WON!!!" << endl;

    return 0;
}