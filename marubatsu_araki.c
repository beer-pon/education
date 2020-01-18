#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************/
/* プロトタイプ宣言					   */
/***************************************/
void createSquare(void);				/* 盤面作成							  */
void setPosition(char);					/* 駒設定							  */
void printSquare(void);					/* 盤面の表示						  */
void judgment(void);					/* 判定処理							  */
void checkWinner(char, char, char);		/* 勝者確認							  */

/***************************************/
/*定数								   */
/***************************************/
static int MAXGAMENUM = 9;				/* 最大ゲーム数						  */
static int STARTJUDGENAM = 4;			/* 判定開始定数(0から数えて4)		  */

/***************************************/
/*グローバル変数					   */
/***************************************/
char square[3][3];						/* 盤面								  */

/***************************************/
/* メイン							   */
/***************************************/
int main(void){
	
	createSquare();						/* 盤面作成							  */
	printSquare();						/* 盤面表示							  */

	/* 9回入力で終了				  */
	// FIXME 暫定処理
	int cnt;
	for(cnt = 0; cnt < MAXGAMENUM; cnt++){
		printf("横、縦の順でマスを選択してください:\n");
		if(cnt % 2 == 0) {
			setPosition('o');			/* 先攻								  */
		} else {
			setPosition('x');			/* 後攻								  */
		}
		
		/* 勝敗判定					  */
		if(cnt >= 4) {
			judgment();
		}
	}
}

/***************************************/
/* 盤面作成関数						   */
/***************************************/
void createSquare(void)
{
	int side;	 						/* 横								  */
	int vertical;						/* 縦								  */

	for(side = 0; side < 3; side++) {
		for(vertical = 0; vertical < 3; vertical++) {
			// 盤面を初期化
			square[side][vertical] = ' ';
		}
	}
}

/***************************************/
/* マス設定関数						   */
/***************************************/
void setPosition(char mark)
{
    int side = 0;							/* 横								  */
	int vertical= 0;						/* 縦								  */

	/* プレイヤーに入力させる		  */
    scanf("%1d%1d", &side, &vertical);

	/* 指定マスにコマがある間		  */
	while(square[side][vertical] != ' '){
		printf("%1d-%1dは埋まっています。再入力（横縦）：", side, vertical);
		scanf("%1d%1d", &side, &vertical);
	}

	/* 駒セット						  */
	square[side][vertical] = mark;

    printSquare();                    /* 盤面を表示 */
}

/***************************************/
/* 盤面表示関数						   */
/***************************************/
void printSquare(void)
{
	int cnt;

	printf("\n   0   1   2\n");
	printf(" -------------\n");
	for(cnt = 0; cnt < 3; cnt++) {
		printf(
			"%1d| %c | %c | %c |\n",
			cnt,
			square[0][cnt],
			square[1][cnt], 
			square[2][cnt] 
		);
		printf(" -------------\n");
	}
}

/***************************************/
/* 判定関数							   */
/***************************************/
void judgment(void)
{
	int side;
	int vertical;
	
	/* 縦列判定						   */
	for(side = 0; side < 3; side++) {
		checkWinner(square[0][side], square[1][side], square[2][side]);
	}
	
	/* 横列判定						   */
	for(vertical = 0; vertical < 3; vertical++) {
		checkWinner(square[vertical][0], square[vertical][1], square[vertical][2]);
	}
	
	/* ななめ判定					   */
	checkWinner(square[0][0], square[1][1], square[2][2]);
	checkWinner(square[0][2], square[1][1], square[2][0]);
}

/***************************************/
/* 勝者確認							   */
/***************************************/
void checkWinner(char box1, char box2, char box3)
{
	if(box1 == ' ' || box2 == ' '  || box3 == ' ') {
		return;
	}

	if(box1 == box2 && box1 == box3) {
		if(box1 == 'o') {
			printf("先攻の勝利です\n");
		} else {
			printf("後攻の勝利です\n");
		}
		exit(1);
	}
	return;
}
