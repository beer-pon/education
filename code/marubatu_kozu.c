/*********************************************************************
ファイル名	： marubatu.c
機能		： 〇×ゲーム
作成日		： 2020/01/01
作成者		： 神津 達也 
修正履歴	：
*********************************************************************/
#include <stdio.h>

#define BORD_SIZE 9 /* 配列の最大要素数を定義 */
#define MARU 10		/* 配列の最大要素数を定義 */
#define BATU 11		/* 配列の最大要素数を定義 */
#define TRUE 1
#define FALSE 0

/* 関数のプロトタイプ宣言 */
/********************************************************************
関数名	：changePlayer
機能	：プレイヤーを切り替える
引数	：なし
戻値	：なし
*********************************************************************/
int changePlayer(int playerValue);

/********************************************************************
関数名	：inputValidation
機能	：入力値のバリデーションチェック
引数	：なし
戻値	：バリデーションエラー:TRUE(1) 　その他:FAULSE(0)
*********************************************************************/
int inputValidation(int bordData[BORD_SIZE], int iinputValue);

/********************************************************************
関数名	：checkWin
機能	：勝敗判定を行う
引数	：なし
戻値	：勝利: TRUE(1)　その他:FAULSE(0)
*********************************************************************/
int checkWin(int bordData[BORD_SIZE]);

/********************************************************************
関数名	：printWinner
機能	：勝利したプレイヤーを表示
引数	：なし
戻値	：なし
*********************************************************************/
void printWinner(int playerValue);

/********************************************************************
関数名	：printBord
機能	：横線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
void printLineEnd();

/********************************************************************
関数名	：printHorizen
機能	：横線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
void printHorizenLine();

/********************************************************************
関数名	：printVertical
機能	：縦線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
void printVertical();

/********************************************************************
関数名	：printBlock
機能	：横線を標準出力する
引数	：int 出力する数字 10:〇 11:×
戻値	：なし
*********************************************************************/
void printBlock(int number);

/********************************************************************
関数名	：printBord
機能	：横線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
/**************************
 * output image
 **************************
 *  ( init )
 *  ----------------
 *  | １ | ２ | ３ |
 *  ----------------
 *  | ４ | ５ | ６ |
 *  ----------------
 *  | ７ | ８ | ９ |
 *  ----------------
 *  
 *  ( input 〇、×)
 *  ----------------
 *  | 〇 | × | 〇 |
 *  ----------------
 *  | 〇 | × | 〇 |
 *  ----------------
 *  | 〇 | × | 〇 |
 *  ----------------
 *  
 **************************/
void printBord(int bordData[BORD_SIZE]);

/********************************************************************
関数名	：main
機能	：〇×ゲーム
引数	：なし
戻値	：なし
*********************************************************************/
int main(void)
{

	int ibordData[BORD_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int iplayerValue = MARU;
	int iinputValue = 0;
	int gameCnt = 0;
	int winFlag = FALSE;

	for (gameCnt = 0; BORD_SIZE > gameCnt;)
	{
		printBord(ibordData);
		printf("1～9の数字を1つ入力してください ");
		scanf("%d", &iinputValue);

		if (inputValidation(ibordData,iinputValue)){
			continue;
		}

		gameCnt++;
		ibordData[iinputValue - 1] = iplayerValue;

		if (checkWin(ibordData))
		{
			winFlag = TRUE;
			break;
		}

		iplayerValue = changePlayer(iplayerValue);
	}

	printBord(ibordData);
	if (winFlag)
	{
		printWinner(iplayerValue);
	}
	else
	{
		printf("お疲れ様です。引き分けです。\r\n");
	}

	return (0);
}

/********************************************************************
関数名	：changePlayer
機能	：プレイヤーを切り替える
引数	：なし
戻値	：なし
*********************************************************************/
int changePlayer(int playerValue)
{
	if (MARU == playerValue)
	{
		return BATU;
	}
	return MARU;
}

/********************************************************************
関数名	：inputValidation
機能	：入力値のバリデーションチェック
引数	：なし
戻値	：バリデーションエラー: FAULSE(0)　その他:TRUE(1)
*********************************************************************/
int inputValidation(int ibordData[BORD_SIZE], int iinputValue)
{
	if (iinputValue > BORD_SIZE)
	{
		printf("選択範囲外の数字が入力されています。再度、1～9の範囲で数字を入れ直して下さい。\r\n ");
		return TRUE;
	}
	if (ibordData[iinputValue - 1] > BORD_SIZE)
	{
		printf("すでに選択済みです。他の数字を選んでください。\r\n ");
		return TRUE;
	}
	return FALSE;
}

/********************************************************************
関数名	：checkWin
機能	：勝敗判定を行う
引数	：なし
戻値	：勝利 ; TRUE(1)　その他:FAULSE(0)
*********************************************************************/
int checkWin(int bordData[BORD_SIZE])
{
	// 横チェック
	if (bordData[0] == bordData[1] && bordData[0] == bordData[2] || bordData[3] == bordData[4] && bordData[3] == bordData[5] || bordData[6] == bordData[7] && bordData[6] == bordData[8])
	{
		return TRUE;
	}
	// 縦チェック
	if (bordData[0] == bordData[3] && bordData[0] == bordData[6] || bordData[1] == bordData[4] && bordData[1] == bordData[7] || bordData[2] == bordData[5] && bordData[2] == bordData[8])
	{
		return TRUE;
	}
	// ななめチェック
	if (bordData[0] == bordData[4] && bordData[0] == bordData[8] || bordData[2] == bordData[4] && bordData[2] == bordData[6])
	{
		return TRUE;
	}
	return FALSE;
}

/********************************************************************
関数名	：printWinner
機能	：勝利したプレイヤーを表示
引数	：なし
戻値	：なし
*********************************************************************/
void printWinner(int playerValue)
{
	if (MARU == playerValue)
	{
		printf("おめでとうございます。〇の勝ちです。");
		printLineEnd();
	}
	else
	{
		printf("おめでとうございます。×の勝ちです。");
		printLineEnd();
	}
}

/********************************************************************
関数名	：printBord
機能	：横線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
void printLineEnd()
{
	printf("\r\n");
}

/********************************************************************
関数名	：printHorizen
機能	：横線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
void printHorizenLine()
{
	printf("----------------");
	printLineEnd();
}

/********************************************************************
関数名	：printVertical
機能	：縦線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
void printVertical()
{
	printf("|");
}

/********************************************************************
関数名	：printBlock
機能	：横線を標準出力する
引数	：int 出力する数字 10:〇 11:×
戻値	：なし
*********************************************************************/
void printBlock(int number)
{
	switch (number)
	{
	case 1:
		printf(" １ ");
		break;
	case 2:
		printf(" ２ ");
		break;
	case 3:
		printf(" ３ ");
		break;
	case 4:
		printf(" ４ ");
		break;
	case 5:
		printf(" ５ ");
		break;
	case 6:
		printf(" ６ ");
		break;
	case 7:
		printf(" ７ ");
		break;
	case 8:
		printf(" ８ ");
		break;
	case 9:
		printf(" ９ ");
		break;
	case 10:
		printf(" 〇 ");
		break;
	case 11:
		printf(" ×  ");
		break;
	default:
		printf("    ");
		break;
	}
}

/********************************************************************
関数名	：printBord
機能	：横線を標準出力する
引数	：なし
戻値	：なし
*********************************************************************/
/**************************
 * output image
 **************************
 *  ( init )
 *  ----------------
 *  | １ | ２ | ３ |
 *  ----------------
 *  | ４ | ５ | ６ |
 *  ----------------
 *  | ７ | ８ | ９ |
 *  ----------------
 *  
 *  ( input 〇、×)
 *  ----------------
 *  | 〇 | × | 〇 |
 *  ----------------
 *  | 〇 | × | 〇 |
 *  ----------------
 *  | 〇 | × | 〇 |
 *  ----------------
 *  
 **************************/
void printBord(int bordData[BORD_SIZE])
{
	printHorizenLine();

	printVertical();
	printBlock(bordData[0]);
	printVertical();
	printBlock(bordData[1]);
	printVertical();
	printBlock(bordData[2]);
	printVertical();
	printLineEnd();

	printHorizenLine();

	printVertical();
	printBlock(bordData[3]);
	printVertical();
	printBlock(bordData[4]);
	printVertical();
	printBlock(bordData[5]);
	printVertical();
	printLineEnd();

	printHorizenLine();

	printVertical();
	printBlock(bordData[6]);
	printVertical();
	printBlock(bordData[7]);
	printVertical();
	printBlock(bordData[8]);
	printVertical();
	printLineEnd();

	printHorizenLine();
}
