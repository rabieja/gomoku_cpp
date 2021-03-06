#include "board.h"
#include <bits/stdc++.h>


#include "paw.h"
#include <vector>

#define board_size 20

using namespace std; 


vector <int> board::add_computer_movement(vector <int> tab_c, char current_gamer){
    vector <int> coord_tab;
    this->tab[tab_c[0]][tab_c[1]].name[0] = current_gamer;
    coord_tab.push_back(this->tab[tab_c[0]][tab_c[1]].y);
    coord_tab.push_back(this->tab[tab_c[0]][tab_c[1]].x);
    
    return coord_tab;
};

void board::new_board(){

    for(int i=0; i<=board_size; i++){
        for(int j=0; j<=board_size; j++){
            paw new_paw_element;
            new_paw_element.new_paw('*', i+3, j+7);
            this->tab[i][j] = new_paw_element;
        }
    }
};

paw board::get_element_to_draw(int i, int j){
    paw n;
    n = this->tab[i][j];
    return n;
};

bool board::check_click(int y, int x, char current_gamer){
    if(y>=this->tab[0][0].y && y<=this->tab[board_size][board_size].y &&
x>=this->tab[0][0].x && x<=this->tab[board_size][board_size].x){
        for(int i=0; i<=board_size; i++){
            for(int j=0; j<=board_size; j++){
                if(y == this->tab[i][j].y && x == this->tab[i][j].x && this->tab[i][j].name[0] == '*'){
                    this->tab[i][j].name[0] = current_gamer;
                    return true;
                }
            }
        }
    }
    return false;
}
