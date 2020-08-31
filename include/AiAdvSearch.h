#include <iostream>
#include <Board.h>

using namespace std;

class AiAdvSearch
{
private:
    int aiPlayer;
    uint64_t searched;
    const int SEARCH_DEPTH_LIMIT = 8;

public:
    /**
     * Constructor for the AiAdvSearch class
     */
    AiAdvSearch();

    /**
     * Make a move using the Ai, returns move column
     */
    int searchBestMove(int player, Board* board);

    /**
     * Returns the minimax value of a state
     */
    int minimax(int player, Board* board, int parentBestValue, int depth);

    /**
     * Determines if a state is a terminal position
     */
    int terminalTest(int player, int depth, Board* board);

    /**
     * Returns the utility of a state
     */
    int utility(int player, Board* board);

    /**
     * Score the position for the param player
     */
    int evaluatePosition(Board* board);

    /**
     * Score a sequency of four pieces
     */
    int scoreSequence(int player, int opponent, int seq[4]);
};