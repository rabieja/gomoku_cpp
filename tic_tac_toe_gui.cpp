#include "tic_tac_toe_gui.h"
#include <ncurses.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <vector>

#include "paw.h"
#include "board.h"

#define board_size 20
using namespace std;


void tic_tac_toe_gui::init(){
    board c_board;
    c_board.new_board();
    tic_tac_toe_engine eng;
    this->current_board = c_board;
    this->engine = eng;
};

void tic_tac_toe_gui::refresh_board(WINDOW* okno){
    for(int i=0; i<=board_size; i++){
        for(int j=0; j<=board_size; j++){
            paw current_paw;
            current_paw = this->current_board.get_element_to_draw(i,j);
            mvprintw(current_paw.y, current_paw.x, current_paw.name);
        }
    }
};

void tic_tac_toe_gui::chose_gamer(int we){
    while(true){
        we = getch();
        if(we== 'k'){
            this->two_gamer = true;
            break;
        }else if(we == 't'){
            this->two_gamer = false;
            break;
        }
    }
};

void tic_tac_toe_gui::print_winner(WINDOW* okno, char winner){
    if(winner == 'o'){
        mvprintw(0, 0, "wygral x");    
    }else if(winner == 'x'){
        mvprintw(0, 0, "wygral o");
    }else mvprintw(0, 0, "remis");
};
void tic_tac_toe_gui::clean_board(WINDOW* okno){
    for(int i=0; i<=board_size; i++){
        for(int j=0; j<=board_size; j++){
            paw current_paw;
            current_paw = this->current_board.get_element_to_draw(i,j);
            mvprintw(current_paw.y, current_paw.x, "-");
        }
    }
};

bool tic_tac_toe_gui::check_remis(WINDOW* okno){
    bool remis = false;
    for(int i=0; i<=board_size; i++){
        for(int j=0; j<=board_size; j++){
            paw current_paw;
            current_paw = this->current_board.get_element_to_draw(i,j);
            if(current_paw.name[0] != '*'){
                remis = true;
            }else return false;
        }
    }
    return remis;
}
void tic_tac_toe_gui::build_gui_game(){
    WINDOW* okno = initscr();
    noecho();
    curs_set(0);
    nodelay(okno, 1);
    mmask_t mmask;
    MEVENT mysz;
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION,NULL);
    int we = 0;
    bool h = false;
    chose_gamer(we);
    refresh_board(okno); 
    
    while(true){
        we = getch();
        if(we == KEY_MOUSE){
            if(getmouse(&mysz) == OK){
                if(this->current_board.check_click(mysz.y,mysz.x, this->current_gamer)){
                    if(this->current_gamer == 'x'){
                        this->current_gamer = 'o';
                    }else this->current_gamer = 'x';

                    vector <int> coordinate;
                    h = this->engine.check_winner(this->current_board,mysz.y,mysz.x);
                    refresh_board(okno);
                    if(this->two_gamer == true){
                        coordinate = this->engine.count_movement(this->current_board, this->current_gamer);
                        vector <int> coordinate_computer;
                        coordinate_computer = this->current_board.add_computer_movement(coordinate,this->current_gamer);

                        if(this->current_gamer == 'x'){
                            this->current_gamer = 'o';
                        }else this->current_gamer = 'x';

                        h = this->engine.check_winner(this->current_board,coordinate_computer[0],coordinate_computer[1]);
                        if(check_remis(okno)){
                            print_winner(okno, 'r');
                            refresh();
                            sleep(3);
                            clean_board(okno);
                            refresh();
                            sleep(3);
                        }
                    }
                refresh_board(okno);
                if(h == true ){
                    print_winner(okno, this->current_gamer);
                    refresh();
                    sleep(3);
                    clean_board(okno);
                    refresh();
                    sleep(3);
                    break;
                }
                }
            }
        }else{    
            if(we == 'q') break;
        }refresh();
    }
    endwin();

};
