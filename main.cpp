#include <bits/stdc++.h>
#include <ncurses.h>
#include <unistd.h>

#include "tic_tac_toe_gui.h"
#include "tic_tac_toe_engine.h"
#include "board.h"
#include "paw.h"

using namespace std; 

int main(){
    tic_tac_toe_gui new_game;
    new_game.init();
    new_game.build_gui_game();
    return 0;
}
