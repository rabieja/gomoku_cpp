#ifndef tic_tac_toe_engine_H
#define tic_tac_toe_engine_H

#include <vector>
#include "board.h"
#include "paw.h"

using namespace std;

class tic_tac_toe_engine{
    public:
        bool check_winner(board board_t, int y, int x);
        vector <int> count_movement(board board_t, char name);
        int count_state(board * board_t, int i, int j, char name);
};

#endif
