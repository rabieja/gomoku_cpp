#ifndef board_H
#define board_H

#include "paw.h"
#include <vector>

#define board_size 20

using namespace std;

class board{
    public:
        paw tab[board_size+1][board_size+1];
    public:
        void new_board();
        paw get_element_to_draw(int i, int j);
        bool check_click(int y, int x, char current_gamer);
        vector <int> add_computer_movement(vector <int> tab, char current_gamer);
};

#endif
