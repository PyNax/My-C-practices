#include<iostream>
#include<string.h>
#include<Windows.h>
class Game {

    int** Screen = nullptr;

public:
    int SX, SY;
    Game() {
        SX = 15;
        SY = 20;
        Screen = new int* [SY];

        for (int i = 0; i < SY; i++) {
            Screen[i] = new int[SX];
        }

        for (int i = 0; i < SY; i++) {
            memset(Screen[i], 0, sizeof(int) * SX);
        }

    }
    Game(int ScreenX, int ScreenY) {
        SX = ScreenX;
        SY = ScreenY;
        Screen = new int* [ScreenY];

        for (int i = 0; i < ScreenY; i++) {
            Screen[i] = new int[ScreenX];
        }

        for (int i = 0; i < ScreenY; i++) {
            memset(Screen[i], 0, sizeof(int) * ScreenX);
        }
    }
    void ShowScreen() {
        for (int i = 0; i < SY; i++) {
            for (int j = 0; j < SX; j++) {
                switch (Screen[i][j]) {
                case 0:
                    std::cout << "бр";
                    break;
                case 1:
                    std::cout << "бс";
                    break;
                default:
                    std::cout << Screen[i][j];
                }
            }
            std::cout << std::endl;
        }
    }
    void CreateBlock(int id, int x, int y) {
        if (y < SY && y >= 0) {
            if (x < SX && x >= 0) {
                Screen[y][x] = id;
            }
        }
    }
    void CreateBlock(int(*blocks)[4][4], int sx, int sy) {
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                Screen[sy + y][sx + x] = blocks[0][y][x];
            }
        }
    }
    void MoveBlock(int x, int y, int offx, int offy) {
        int MovedY = y + offy;
        int MovedX = x + offx;
        int id = Screen[y][x];
        if ((y < SY && x < SX) && (y >= 0 && x >= 0) && (MovedY < SY && MovedX < SX) && (MovedY >= 0 && MovedX >= 0) && (id != 0) && (Screen[MovedY][MovedX] == 0) ){
            Screen[y][x] = 0;
            Screen[MovedY][MovedX] = id;
        }
    }
    void EndGame() {
        delete[] Screen;
    }
};