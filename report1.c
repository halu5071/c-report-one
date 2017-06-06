/*
ATTENTION!!!
このプログラムはメルセンヌ・ツイスタを使用しています。
かならずディレクトリ内にMT.hを含めてください

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"

#define DEBUG

// 初期値0と混同することを回避
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define WILD 4

#define PLAYER 1991
#define COMONE 2882
#define COMTWO 3773

int janken_two_people(int player1, int player2);
int janken_three_people();

// コンピュータ1, 2の手を格納するためのグローバル変数
int comOne = 0;
int comTwo = 0;
// Playerの手を格納するためのグローバル変数
int numPlayerHand = 0;

int main(void){

  printf("\n");
  printf("*****************************************************\n");
  printf("Rock-Paper-Scissors!!!\n");
  printf("\n");
  printf("Press g:Rock, c:Scissors, p:Paper, w:WildCard\n");
  printf("You can use WildCard only once. WildCard means that a player who set WildCard will win when he is only a WildCard player. However,if he is not, the last players throw again please\n");
  printf("\n");
  printf("Get Ready??\n");
  printf("*****************************************************\n");
  printf("\n");

// プレイヤーコードを格納する。各プレイヤーコードをじゃんけん用のメソッドに渡して
// プレイヤーを識別する
  const int codeComOne = COMONE;
  const int codeComTwo = COMTWO;
  const int codePlayer = PLAYER;

  while(1){

    printf("You throw >> ");
    // 入力された手を格納しておく変数 char型
    char yourHand = '\0';

    scanf("%s", &yourHand);

    // 入力された手を数字に変換しておくための変数
    // ここで正しい手を入力したかチェック
    if (yourHand == 'c') {
        numPlayerHand = SCISSORS;
    } else if (yourHand == 'g') {
        numPlayerHand = ROCK;
    } else if (yourHand == 'p') {
        numPlayerHand = PAPER;
    } else if (yourHand == 'w') {
        numPlayerHand = WILD;
    } else {
        printf("Press c g p w\n");
        continue;
    }
    // コンピュータの手をランダムに出力
    // シード値の作成
    init_genrand((unsigned)time(NULL));
    comOne = genrand_int32()%4 + 1;

    init_genrand((unsigned)time(NULL) + 100);
    comTwo = genrand_int32()%4 + 1;

    #ifdef DEBUG
    printf("com1:%d\n", comOne);
    printf("com2:%d\n", comTwo);
    printf("numPlayerHand : %d\n", numPlayerHand);

    int tmp2 = numPlayerHand + comOne + comTwo;
    printf("tmp2 : %d\n", tmp2);
    #endif

    // 実際のじゃんけん。あとでメソッドに分離
    int result = (numPlayerHand + comOne + comTwo) % 3;
    if (result == 0) {
        printf("あいこ\n");
        break;
    } else if (result == 1) {
        printf("まだ書いてないよ\n");
    } else {
        if (comOne == comTwo) {
            printf("1位 Player, 2位 com1, 2位 com2\n");
        } else if (comOne == numPlayerHand) {
            printf("1位 com2, 2位 Player, 2位 com1\n");
        } else {
            printf("1位 com1, 2位 Player, 2位 com2\n");
        }
    }

  }

  return (0);
}

// ３人でじゃんけんをする時に呼ばれるメソッド
int janken_three_people(){

}

int janken_two_people(int player1, int player2){

}
