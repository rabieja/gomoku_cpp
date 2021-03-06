#ifndef tic_tac_toe_gui_H
#define tic_tac_toe_gui_H

#include <bits/stdc++.h>
#include <vector>
#include <ncurses.h>
#include <unistd.h>
#include "board.h"
#include "tic_tac_toe_engine.h"

class tic_tac_toe_gui{
    public:
        board current_board;
        tic_tac_toe_engine engine;
        bool two_gamer;
        char current_gamer = 'x';
    public:
        void init();
        void build_gui_game();
        void refresh_board(WINDOW* okno);
        void chose_gamer(int we);
        void clean_board(WINDOW* okno);
        void print_winner(WINDOW* okno, char winner);
        bool check_remis(WINDOW* okno);
};

#endif
