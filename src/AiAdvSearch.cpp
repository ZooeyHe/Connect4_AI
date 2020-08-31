#include <AiAdvSearch.h>

using namespace std;

AiAdvSearch::AiAdvSearch()
{
    searched = 0;
}


int AiAdvSearch::searchBestMove(int player, Board* board) {
    int col = -1;
    int max = -300;
    int depth = 0;
    aiPlayer = player;
    int nextPlayer = board->getOtherPlayer(aiPlayer);
    searched = 0;

    for (int i = 0; i < 7; i++) {
        if (board->getValidRowInCol(i, player) != -1) {
            Board* nextBoard = new Board(board);
            nextBoard->setPlayerInCol(i, player);
            int minimaxVal = minimax(nextPlayer, nextBoard, max, depth);
            if (minimaxVal > max) {
                col = i;
                max = minimaxVal;   
            }
        }
    }

    return col;
}

int AiAdvSearch::minimax(int player, Board* board, int parentBestValue, int depth)
{
    if (terminalTest(player, depth, board)) {
        return utility(player, board);
    }

    depth++;

    int bestValue;
    int nextPlayer = board->getOtherPlayer(player);

    if (player == aiPlayer) {
        bestValue = -1000;
        for (int i = 0; i < 7; i++) {
            int validRow = board->getValidRowInCol(i, player);
            if (validRow != -1) {
                if (bestValue >= parentBestValue) {
                    return bestValue;
                }
                board->setPlayerAt(i, validRow, player);
                int moveValue = minimax(nextPlayer, board, bestValue, depth);
                board->setPlayerAt(i, validRow, board->EMPTY_SLOT);
                if (moveValue > bestValue) {
                    bestValue = moveValue;
                }
            }
        }
    } else {
        bestValue = 1000;
        for (int i = 0; i < 7; i++) {
            int validRow = board->getValidRowInCol(i, player);
            if (validRow != -1) {
                if (bestValue <= parentBestValue) {
                    return bestValue;
                }
                board->setPlayerAt(i, validRow, player);
                int moveValue = minimax(nextPlayer, board, bestValue, depth);
                board->setPlayerAt(i, validRow, board->EMPTY_SLOT);
                if (moveValue < bestValue) {
                    bestValue = moveValue;
                }
            }
        }
    }
    
    return bestValue;
}

int AiAdvSearch::terminalTest(int player, int depth, Board* board) {
    bool won = board->playerWon(board->getOtherPlayer(player));
    if (won || board->boardIsFull() || depth >= SEARCH_DEPTH_LIMIT) {
        searched++;
        return true;
    } else {
        return false;
    }
}

int AiAdvSearch::utility(int player, Board* board) {
    int score = evaluatePosition(board);
    return score;
}

int AiAdvSearch::evaluatePosition(Board* board) {
    int score = 0;
    if (board->playerWon(aiPlayer)) {
        score += 100;
    } else if (board->playerWon(board->getOtherPlayer(aiPlayer))) {
        score -= 100;
    }

    // Checking vertical
    for (int col = 0; col < board->getBoardWidth(); col++) {
        for (int row = 0; row < board->getBoardHeight() - 4; row++) {
            int sequence[4];
            for (int i = 0; i < 4; i++) {
                sequence[i] = board->getPlayerAt(col, row + i);
            }
            score += scoreSequence(aiPlayer, board->getOtherPlayer(aiPlayer), sequence);
        }
    }

    // Checking Horizontal
    for (int row = 0; row < board->getBoardHeight(); row++) {
        for (int col = 0; col < board->getBoardWidth() - 4; col++) {
            int sequence[4];
            for (int i = 0; i < 4; i++) {
                sequence[i] = board->getPlayerAt(col + i, row);
            }
            score += scoreSequence(aiPlayer, board->getOtherPlayer(aiPlayer), sequence);
        }
    }
    
    for (int row = 0; row < board->getBoardHeight() - 4; row++) {
        for (int col = 0; col < board->getBoardWidth() - 4; col++) {
            int sequence[4];
            for (int i = 0; i < 4; i++) {
                sequence[i] = board->getPlayerAt(col+i, row+i);
            }
            score += scoreSequence(aiPlayer, board->getOtherPlayer(aiPlayer), sequence);
        }
    }

    for (int row = board->getBoardHeight() - 4 + 1; row < board->getBoardHeight(); row++) {
        for (int col = 0; col < board->getBoardWidth() - 4; col++) {
            int sequence[4];
            for (int i = 0; i < 4; i++) {
                sequence[i] = board->getPlayerAt(col+i, row-i);
            }
            score += scoreSequence(aiPlayer, board->getOtherPlayer(aiPlayer), sequence);
        }
    }

    return score;
}

int AiAdvSearch::scoreSequence(int player, int opponent, int seq[4]) {
    int score = 0;
    int numPlayer = 0;
    int numOpponent = 0;
    int numEmpty = 0;

    for (int i = 0; i < 4; i++) {
        if (seq[i] == player) {
            numPlayer++;
        } else if (seq[i] == opponent) {
            numOpponent++;
        } else {
            numEmpty++;
        }
    }

    if (numPlayer == 3 && numEmpty == 1) {
        score += 4;
    } else if (numPlayer == 2 && numEmpty == 2) {
        score += 2;
    }

    if (numOpponent == 3 && numEmpty == 1) {
        score -= 4;
    } else if (numOpponent == 2  && numEmpty == 2) {
        score -= 2;
    }

    return score;
}

