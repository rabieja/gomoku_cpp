#include "tic_tac_toe_engine.h"

#include <bits/stdc++.h>
#include "board.h"
#include "paw.h"
#include <vector>

#define board_size 20

using namespace std;

int tic_tac_toe_engine::count_state(board *board_t, int i, int j, char name){
    int max_state = 0; 
    if(name == 'o'){
        name = 'x';
    }else name = 'o';

    if(*board_t->tab[i][j].name != '*') return -1;
//lewo prawo    
    if(j+1 <= board_size && *board_t->tab[i][j+1].name == name){
       if(j+2 <= board_size && *board_t->tab[i][j+2].name == name){
            if(j+3 <= board_size && *board_t->tab[i][j+3].name == name){
                if(j+4 <= board_size && *board_t->tab[i][j+4].name == name){
                    max_state = max(5, max_state);
                }
                if(j+4 <= board_size && *board_t->tab[i][j+4].name != name && *board_t->tab[i][j+4].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);
            }max_state = max(2, max_state);
        }max_state = max(1, max_state);
    }

    if(j-1 >= 0 && *board_t->tab[i][j-1].name == name){
        if(j-2 >= 0 && *board_t->tab[i][j-2].name == name){
            if(j-3 >= 0 && *board_t->tab[i][j-3].name == name){
                if(j-4 >= 0 && *board_t->tab[i][j-4].name == name){
                    max_state = max(5, max_state);
                }
                if(j-4 >= 0 && *board_t->tab[i][j-4].name != name && *board_t->tab[i][j-4].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);
            }max_state = max(2, max_state);
        }max_state = max(1, max_state);
    }
    
    if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
       j+2 <= board_size && *board_t->tab[i][j+2].name == name &&
       j-1 >= 0 && *board_t->tab[i][j-1].name == name){
        max_state = max(4, max_state);
    }

    if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
       j-2 >= 0 && *board_t->tab[i][j-2].name == name &&
       j-1 >= 0 && *board_t->tab[i][j-1].name == name){
        max_state = max(4, max_state);
    }

//gora dol
    if(i+1 <= board_size && *board_t->tab[i+1][j].name == name){
        if(i+2 <= board_size && *board_t->tab[i+2][j].name == name){
            if(i+3 <= board_size && *board_t->tab[i+3][j].name == name){
                if(i+4 <= board_size && *board_t->tab[i+4][j].name == name){
                    max_state = max(5, max_state);
                }
                if(i+4 <= board_size && *board_t->tab[i+4][j].name != name && *board_t->tab[i+4][j].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);
            }max_state = max(2, max_state);
        }max_state = max(1, max_state);        
    }

    if(i-1 >= 0 && *board_t->tab[i-1][j].name == name){
        if(i-2 >= 0 && *board_t->tab[i-2][j].name == name){
            if(i-3 >= 0 && *board_t->tab[i-3][j].name == name){
                if(i-4 >= 0 && *board_t->tab[i-4][j].name == name){
                    max_state = max(5, max_state);
                }
                if(i-4 >= 0 && *board_t->tab[i-4][j].name != name && *board_t->tab[i-4][j].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);
            }max_state = max(2, max_state);
        }max_state = max(1, max_state);
    }
    
    if(i+1 <= board_size && *board_t->tab[i+1][j].name == name &&
       i+2 <= board_size && *board_t->tab[i+2][j].name == name &&
       i-1 >= 0 && *board_t->tab[i-1][j].name == name){
        max_state = max(4, max_state);
    }

    if(i+1 <= board_size && *board_t->tab[i+1][j].name == name &&
       i-2 >= 0 && *board_t->tab[i-2][j].name == name &&
       i-1 >= 0 && *board_t->tab[i-1][j].name == name){
        max_state = max(4, max_state);
    }

//gora prawo

    if(j+1 <= board_size && i-1 >= 0 && *board_t->tab[i-1][j+1].name == name){
        if(j+2 <= board_size && i-2 >= 0 && *board_t->tab[i-2][j+2].name == name){
            if(j+3 <= board_size && i-3 >= 0 && *board_t->tab[i-3][j+3].name == name){
                if(j+4 <= board_size && i-4 >= 0 && *board_t->tab[i-4][j+4].name == name){
                    max_state = max(5, max_state);
                }
                if(j+4 <= board_size && i-4 >= 0 && *board_t->tab[i-4][j+4].name != name && *board_t->tab[i-4][j+4].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);

            }max_state = max(2, max_state);
        }max_state = max(1, max_state);        
    }

    if(j-1 >= 0 && i+1 <= board_size && *board_t->tab[i+1][j-1].name == name){
        if(j-2 >= 0 && i+2 <= board_size && *board_t->tab[i+2][j-2].name == name){
            if(j-3 >= 0 && i+3 <= board_size && *board_t->tab[i+3][j-3].name == name){
                if(j-4 >= 0 && i+4 <= board_size && *board_t->tab[i+4][j-4].name == name){
                    max_state = max(5, max_state);
                }
                if(j-4 >= 0 && i+4 <= board_size && *board_t->tab[i+4][j-4].name != name && *board_t->tab[i+4][j-4].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);
            }max_state = max(2, max_state);
        }max_state = max(1, max_state);
    }
    
    if(j+1 <= board_size && i-1 >=0 && *board_t->tab[i-1][j+1].name == name &&
       j+2 <= board_size && i-2 >=0 && *board_t->tab[i-2][j+2].name == name &&
       j-1 >= 0 && i+1 <=board_size && *board_t->tab[i+1][j-1].name == name){
        max_state = max(4, max_state);
    }

    if(j+1 <= board_size && i-1 >=0 && *board_t->tab[i-1][j+1].name == name &&
       j-2 >= 0 && i+2 <= board_size && *board_t->tab[i+2][j-2].name == name &&
       j-1 >= 0 && i+1 <= board_size && *board_t->tab[i+1][j-1].name == name){
        max_state = max(4, max_state);
    }

// gora lewo

    if(j-1 >= 0 && i-1 >= 0 && *board_t->tab[i-1][j-1].name == name){
        if(j-2  >= 0 && i-2 >= 0 && *board_t->tab[i-2][j-2].name == name){
            if(j-3  >= 0 && i-3 >= 0 && *board_t->tab[i-3][j-3].name == name){
                if(j-4 >= 0 && i-4 >= 0 && *board_t->tab[i-4][j-4].name == name){
                    max_state = max(5, max_state);
                }
                if(j-4 >=0 && i-4 >= 0 && *board_t->tab[i-4][j-4].name != name && *board_t->tab[i-4][j-4].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);
            }max_state = max(2, max_state);
        }max_state = max(1, max_state);
    }

    if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name){
        if(j+2 <= board_size && i+2 <= board_size && *board_t->tab[i+2][j+2].name == name){
            if(j+3 <= board_size && i+3 <= board_size && *board_t->tab[i+3][j+3].name == name){
                if(j+4 <= board_size && i+4 <= board_size && *board_t->tab[i+4][j+4].name == name){
                    max_state = max(5, max_state);
                }
                if(j+4 <= board_size && i+4 <= board_size && *board_t->tab[i+4][j+4].name != name && *board_t->tab[i+4][j+4].name != '*'){
                    max_state = max(2, max_state);
                }else max_state = max(3, max_state);
            }max_state = max(2, max_state);
        }max_state = max(1, max_state);
    }
    
    if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
       j+2 <= board_size && i+2 <= board_size && *board_t->tab[i+2][j+2].name == name &&
       j-1 >= 0 && i-1 >= 0 && *board_t->tab[i-1][j-1].name == name){
        max_state = max(4, max_state);
    }

    if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
       j-2 >= 0 && i-2 >=0 && *board_t->tab[i-2][j-2].name == name &&
       j-1 >= 0 && i-1 >=0 && *board_t->tab[i-1][j-1].name == name){
        max_state = max(4, max_state);
    }


//podwojne trojki
    if(i+1 <= board_size && *board_t->tab[i+1][j].name == name &&
       i+2 <= board_size && *board_t->tab[i+2][j].name == name){
        if(i+1 <= board_size && j-1 >= 0 && *board_t->tab[i+1][j-1].name == name &&
           i+2 <= board_size && j-2 >= 0 && *board_t->tab[i+2][j-2].name == name){
            max_state = max(3, max_state);
        }

        if(j-1 >= 0 && *board_t->tab[i][j-1].name == name &&
           j-2 >= 0 && *board_t->tab[i][j-2].name == name){
            max_state = max(3, max_state);
        }

        if(i-1 >= 0 && j-1 >= 0 && *board_t->tab[i-1][j-1].name == name &&
           i-2 >= 0 && j-2 >= 0 && *board_t->tab[i-2][j-2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i-1 >= 0 && *board_t->tab[i-1][j+1].name == name &&
           j+2 <= board_size && i-2 >= 0 && *board_t->tab[i-2][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
           j+2 <= board_size && *board_t->tab[i][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
           j+2 <= board_size && i+2 <= board_size && *board_t->tab[i+2][j+2].name == name){
            max_state = max(3, max_state);
        }

    }

    if(i+1 <= board_size && j-1 >= 0 && *board_t->tab[i+1][j-1].name == name &&
       i+2 <= board_size && j-2 >= 0 && *board_t->tab[i+2][j-2].name == name){

        if(j-1 >= 0 && *board_t->tab[i][j-1].name == name &&
           j-2 >= 0 && *board_t->tab[i][j-2].name == name){
            max_state = max(3, max_state);
        }

        if(i-1 >= 0 && j-1 >= 0 && *board_t->tab[i-1][j-1].name == name &&
           i-2 >= 0 && j-2 >= 0 && *board_t->tab[i-2][j-2].name == name){
            max_state = max(3, max_state);
        }

        if(i-1 >= 0 && *board_t->tab[i-1][j].name == name &&
           i-2 >= 0 && *board_t->tab[i-2][j].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
           j+2 <= board_size && *board_t->tab[i][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
           j+2 <= board_size && i+2 <= board_size && *board_t->tab[i+2][j+2].name == name){
            max_state = max(3, max_state);
        }

    }

    if(j-1 >= 0 && *board_t->tab[i][j-1].name == name &&
       j-2 >= 0 && *board_t->tab[i][j-2].name == name){

        if(i-1 >= 0 && j-1 >= 0 && *board_t->tab[i-1][j-1].name == name &&
           i-2 >= 0 && j-2 >= 0 && *board_t->tab[i-2][j-2].name == name){
            max_state = max(3, max_state);
        }

        if(i-1 >= 0 && *board_t->tab[i-1][j].name == name &&
           i-2 >= 0 && *board_t->tab[i-2][j].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i-1 >= 0 && *board_t->tab[i-1][j+1].name == name &&
           j+2 <= board_size && i-2 >= 0 && *board_t->tab[i-2][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
           j+2 <= board_size && i+2 <= board_size && *board_t->tab[i+2][j+2].name == name){
            max_state = max(3, max_state);
        }

    }

    if(i-1 >= 0 && j-1 >= 0 && *board_t->tab[i-1][j-1].name == name &&
       i-2 >= 0 && j-2 >= 0 && *board_t->tab[i-2][j-2].name == name){

        if(i-1 >= 0 && *board_t->tab[i-1][j].name == name &&
           i-2 >= 0 && *board_t->tab[i-2][j].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i-1 >= 0 && *board_t->tab[i-1][j+1].name == name &&
           j+2 <= board_size && i-2 >= 0 && *board_t->tab[i-2][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
           j+2 <= board_size && *board_t->tab[i][j+2].name == name){
            max_state = max(3, max_state);
        }

    }

    if(i-1 >= 0 && *board_t->tab[i-1][j].name == name &&
       i-2 >= 0 && *board_t->tab[i-2][j].name == name){

        if(j+1 <= board_size && i-1 >= 0 && *board_t->tab[i-1][j+1].name == name &&
           j+2 <= board_size && i-1 >= 0 && *board_t->tab[i-2][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
           j+2 <= board_size && *board_t->tab[i][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
           j+2 <= board_size && i+2 <= board_size && *board_t->tab[i+2][j+2].name == name){
            max_state = max(3, max_state);
        }

    }

    if(j+1 <= board_size && i-1 >= 0 && *board_t->tab[i-1][j+1].name == name &&
       j+2 <= board_size && i-2 >= 0 && *board_t->tab[i-2][j+2].name == name){

        if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
           j+2 <= board_size && *board_t->tab[i][j+2].name == name){
            max_state = max(3, max_state);
        }

        if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
           j+2 <= board_size && i+1 <= board_size && *board_t->tab[i+2][j+2].name == name){
            max_state = max(3, max_state);
        }

    }

    if(j+1 <= board_size && *board_t->tab[i][j+1].name == name &&
       j+2 <= board_size && *board_t->tab[i][j+2].name == name){

        if(j+1 <= board_size && i+1 <= board_size && *board_t->tab[i+1][j+1].name == name &&
           j+2 <= board_size && i+1 <= board_size && *board_t->tab[i+2][j+2].name == name){
            max_state = max(3, max_state);
        }

    }

    return max_state;
}
vector <int> tic_tac_toe_engine::count_movement(board board_t, char name){
    vector <int> tab;
    int max_win = 0;
    int max_win_win = 0;
    int tab_win_fail[board_size +1][board_size +1];
    int tab_win_win[board_size +1][board_size +1];
    for(int i=0; i<=board_size; i++){
        for(int j=0; j<=board_size; j++){
            int k = count_state(&board_t, i, j, name);
            max_win = max(k, max_win);
            tab_win_fail[i][j] = k;
        }
    }

    if(name == 'o'){
        name = 'x';
    }else name = 'o';

    for(int i=0; i<=board_size; i++){
        for(int j=0; j<=board_size; j++){
            int k = count_state(&board_t, i, j, name);
            max_win_win = max(k, max_win_win);
            tab_win_win[i][j] = k;
        }
    }



    if(max_win <=2 ){
        max_win = -1;
    }
    if(max_win_win == 5 || (max_win_win != 0 && max_win == -1)){
       for(int i=0; i<=board_size; i++){
            for(int j=0; j<=board_size; j++){
                if(max_win_win == tab_win_win[i][j]){
                    tab.push_back(i);
                    tab.push_back(j);
                }
            }
        }
    }else{
        for(int i=0; i<=board_size; i++){
            for(int j=0; j<=board_size; j++){
                if(max_win == tab_win_fail[i][j] && max_win != -1){
                    tab.push_back(i);
                    tab.push_back(j);
                }else if(max_win == -1 && max_win == tab_win_fail[i][j]){
                    for(int k=i; k<=board_size; k++){
                        for(int g=j; g<=board_size; g++){
                            if(tab_win_fail[k][g] == 0){
                                tab.push_back(k);
                                tab.push_back(g);
                            }
                        }
                    }
                }
            }
        }
    }
    
    if(tab.size() == 0){
        for(int i=0; i<=board_size; i++){
            for(int j=0; j<=board_size; j++){
                if(tab_win_fail[i][j] == 0){
                    tab.push_back(i);
                    tab.push_back(j);
                }
            }
        }
    }
    return tab;
}
bool tic_tac_toe_engine::check_winner(board board_t, int y, int x){

    for(int i=0; i<=board_size; i++){
        for(int j=0; j<=board_size; j++){
            if(board_t.tab[i][j].x == x && board_t.tab[i][j].y == y){
//lewo-prawo
                if(i+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+1][j].name[0]){
                    if(i+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+2][j].name[0]){
                        if(i+3 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+3][j].name[0]){
                            if(i+4 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+4][j].name[0]){
                                return true;
                            }else if(i-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-1][j].name[0]) return true;
                        }else if(i-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-1][j].name[0] &&
                                 i-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-2][j].name[0]) return true;
                    }else if(i-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-1][j].name[0] &&
                             i-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-2][j].name[0] &&
                             i-3 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-3][j].name[0]) return true;
                }else if(i-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-1][j].name[0] &&
                         i-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-2][j].name[0] &&
                         i-3 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-3][j].name[0] &&
                         i-4 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-4][j].name[0]) return true;
//gora dol
                if(j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i][j+1].name[0]){
                    if(j+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i][j+2].name[0]){
                        if(j+3 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i][j+3].name[0]){
                            if(j+4 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i][j+4].name[0]){
                                return true;
                            }else if(j-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-1].name[0]) return true;
                        }else if(j-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-1].name[0] &&
                                 j-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-2].name[0]) return true;
                    }else if(j-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-1].name[0] &&
                             j-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-2].name[0] &&
                             j-3 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-3].name[0]) return true;
                }else if(j-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-1].name[0] &&
                         j-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-2].name[0] &&
                         j-3 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-3].name[0] &&
                         j-4 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i][j-4].name[0]) return true;
//gora prawo
                if(i+1 <= board_size && j-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i+1][j-1].name[0]){
                    if(i+2 <= board_size && j-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i+2][j-2].name[0]){
                        if(i+3 <= board_size && j-3 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i+3][j-3].name[0]){
                            if(i+4 <= board_size && j-4 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i+4][j-4].name[0]){
                                return true;
                            }else if(i-1 >= 0 && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-1][j+1].name[0]) return true;
                        }else if(i-1 >= 0 && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-1][j+1].name[0] &&
                                 i-2 >= 0 && j+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-2][j+2].name[0]) return true;
                    }else if(i-1 >= 0 && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-1][j+1].name[0] &&
                             i-2 >= 0 && j+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-2][j+2].name[0] &&
                             i-3 >= 0 && j+3 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-3][j+3].name[0]) return true;
                }else if(i-1 >= 0 && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-1][j+1].name[0] &&
                         i-2 >= 0 && j+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-2][j+2].name[0] &&
                         i-3 >= 0 && j+3 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-3][j+3].name[0] &&
                         i-4 >= 0 && j+4 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i-4][j+4].name[0]) return true;

//gora lewo

                if(i-1  >= 0 && j-1 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-1][j-1].name[0]){
                    if(i-2  >= 0 && j-2 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-2][j-2].name[0]){
                        if(i-3 >= 0 && j-3 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-3][j-3].name[0]){
                            if(i-4 >= 0 && j-4 >= 0 && board_t.tab[i][j].name[0] == board_t.tab[i-4][j-4].name[0]){
                                return true;
                            }else if(i+1 <= board_size && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+1][j+1].name[0]) return true;
                        }else if(i-1 <= board_size && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+1][j+1].name[0] &&
                                 i-2 <= board_size && j+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+2][j+2].name[0]) return true;
                    }else if(i+1 <= board_size && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+1][j+1].name[0] &&
                             i+2 <= board_size && j+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+2][j+2].name[0] &&
                             i+3 <= board_size && j+3 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+3][j+3].name[0]) return true;
                }else if(i+1 <= board_size && j+1 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+1][j+1].name[0] &&
                         i+2 <= board_size && j+2 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+2][j+2].name[0] &&
                         i+3 <= board_size && j+3 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+3][j+3].name[0] &&
                         i+4 <= board_size && j+4 <= board_size && board_t.tab[i][j].name[0] == board_t.tab[i+4][j+4].name[0]) return true;

            }
        }
    }
    return false;
};
