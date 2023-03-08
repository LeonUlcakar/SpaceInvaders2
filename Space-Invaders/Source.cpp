#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int WIDTH = 60;
const int HEIGHT = 20;
int playerX = WIDTH / 2;
int playerY = HEIGHT - 1;
int enemyX[5];
int enemyY[5];
int bulletX = playerX;
int bulletY = playerY - 1;
int score = 0;
bool isFiring = false;
int numOfEnemies = 5;

void drawBoard();

int main() {
    drawBoard();
}

void drawBoard() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) {
                cout << "|";
            }
            if (i == playerY && j == playerX) {
                cout << "A";
            }
            else if (i == bulletY && j == bulletX) {
                cout << "*";
            }
            else {
                bool enemyAlive = false;
                for (int k = 0; k <= numOfEnemies; k++) {
                    if (i == enemyY[k] && j == enemyX[k]) {
                        cout << "M";
                        enemyAlive = true;
                    }
                    if (!enemyAlive) {
                        cout << " ";
                    }
                }
                if (j == WIDTH - 1) {
                    cout << "|";
                }
            }
        }
        cout << endl;
    }
    for (int i = 0; i < WIDTH + 2; i++) {
        cout << "-";
    }
    cout << endl << "Score: " << score << endl;
}