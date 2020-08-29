#include <iostream>
#include <ConnectFour.h>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    
    ConnectFour* game = new ConnectFour();

    game->startGameFromCmdLine();

    return 0;
}