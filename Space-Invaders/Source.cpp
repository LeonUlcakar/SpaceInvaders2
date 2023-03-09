#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
const int PLAYER_START_X = WIDTH / 2;
const int PLAYER_START_Y = HEIGHT - 2;
const int ENEMY_START_X = 1;
const int ENEMY_START_Y = 1;
const int ENEMY_SPACING = 6;
int playerX = WIDTH / 2;
int playerY = HEIGHT - 1;
int bulletX = playerX;
int bulletY = playerY - 1;
int score = 0;
bool playerIsFiring = false;
bool isFiring = false;
int numOfEnemies = 5;
bool enemyIsFiring = false;
int enemyX[5] = { ENEMY_START_X, ENEMY_START_X + ENEMY_SPACING, ENEMY_START_X + 2 * ENEMY_SPACING, ENEMY_START_X + 3 * ENEMY_SPACING, ENEMY_START_X + 4 * ENEMY_SPACING };
int enemyY[5] = { ENEMY_START_Y, ENEMY_START_Y, ENEMY_START_Y, ENEMY_START_Y, ENEMY_START_Y };
bool enemyFiring[5] = { false, false, false, false, false };
int enemyBulletX[5] = { 0, 0, 0, 0, 0 };
int enemyBulletY[5] = { 0, 0, 0, 0, 0 };
bool gameOver = false;

//void drawBoard();


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
                for (int k = 0; k < numOfEnemies; k++) {
                    if (i == enemyY[k] && j == enemyX[k]) {
                        cout << "M";
                        enemyAlive = true;
                    }
                    
                }
                if (!enemyAlive) {
                    cout << " ";
                }
            }
            if ((j == WIDTH - 1)) {
                cout << "|";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < WIDTH + 2; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void playerInit() {
    int playerX = WIDTH / 2;
    int playerY = HEIGHT - 1;
}
void enemyInit() {
    for (int i = 0; i < numOfEnemies; i++) {
        enemyX[i] = WIDTH / 2 + i + 1;
        enemyY[i] = 2 + 1;
        enemyIsFiring = false;
    }
}

void movePlayer(char input) {
    switch (input) {
    case 'a':
            if (playerX > 0) {
                playerX--;
            }
            break;
    case 'd':
        if (playerX < WIDTH - 1) {
            playerX++;
        }
        break;
    case ' ':
        if (!isFiring) {
            bulletX = playerX;
            bulletY = playerY + 1;
            isFiring = true;
        }
        break;
    case 'q':
        exit(0);
        break;
    }
}

void moveEnemies() {
    static int enemyDirection = 1;
    static bool enemyReachedEdge = false;
    for (int i = 0; i < numOfEnemies; i++) {
        if (enemyX[i] == 0) {
            enemyDirection = 1;
            enemyReachedEdge = true;
        }
        else if (enemyX[i] == WIDTH - 1) {
            enemyDirection = -1;
            enemyReachedEdge = true;
        }
        else {
            enemyReachedEdge = false;
        }
        if (!enemyFiring[i] && rand() % 50 == 0) {
            enemyFiring[i] = true;
            enemyBulletX[i] = enemyX[i];
            enemyBulletY[i] = enemyY[i] + 1;
        }
        if (enemyFiring[i]) {
            enemyBulletY[i]++;
            if (enemyBulletY[i] >= HEIGHT) {
                enemyFiring[i] = false;
            }
        }
        enemyX[i] += enemyDirection;
        if (enemyReachedEdge) {
            enemyY[i]++;
        }
        if (enemyY[i] >= playerY) {
            gameOver = true;
            return;
        }
    }
}

void moveBullets() {
    if (isFiring) {
        bulletY--;
        if (bulletY < 0) {
            isFiring = false;
            bulletX = ' ';
        }
        for (int i = 0; i < numOfEnemies; i++) {
            if (bulletY == enemyY[i] && bulletX == enemyX[i]) {
                isFiring = false;
                enemyX[i] = ' ';
                enemyY[i] = ' ';
                bulletX = ' ';
                bulletY = ' ';
                numOfEnemies--;
                score += 10;
            }
        }
    }
    for (int i = 0; i < numOfEnemies; i++) {
        if (enemyFiring[i]) {
            enemyBulletY[i]++;
            if (enemyBulletY[i] > HEIGHT) {
                enemyFiring[i] = false;
            }
            if (enemyBulletY[i] == playerY && enemyBulletX[i] == playerX) {
                playerInit();
                enemyInit();
                isFiring = false;
                for (int j = 0; j < numOfEnemies; j++) {
                    enemyFiring[j] = false;
                }
                score = 0;
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    playerInit();
    enemyInit();
    char input;

    while (true) {
        drawBoard();
        moveEnemies();
        moveBullets();
        if (_kbhit()) {
            input = _getch();
            movePlayer(input);
        }
        Sleep(100);
    }

    return 0;
}
