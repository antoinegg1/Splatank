#ifndef GAME_H
#define GAME_H
#include <board.h>


class Game
{

public:
    Game();
    int totaltime;//总游戏时长
    int reversetime;//倒计时

    bool game_end();//判断游戏是否结束（有坦克死亡）
    int who_is_the_winner(GameBoard a);//返回1则player1胜利，返回2则player2胜利

};

#endif // GAME_H
