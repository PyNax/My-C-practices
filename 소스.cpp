#include<C:\Users\User\source\repos\codeE\codeE\Blocks.h>
#include<iostream>
#include<Windows.h>
#include<time.h>
void FallDown(Game *Screen) {

	for (int y = 0; y < Screen->SY; y++) {
		for (int x = 0; x < Screen->SX; x++) {
			Screen->MoveBlock((Screen->SX - 1) - x,(Screen->SY - 1) - y, 0, 1);
		}
	}
}

void main() {
	Game Gm;
	int Blocks[4][4] = {
		{0,1,0,0},
		{0,1,0,0},
		{0,1,1,0},
		{0,}
	
	};
	Gm.CreateBlock(&Blocks,5,5);
	Gm.ShowScreen();
	Gm.EndGame();
}