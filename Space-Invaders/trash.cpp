/*
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
            for (int i = 0; i < numOfEnemies; i++) {
                enemyY[i]++;
            }
        }
        if (enemyY[i] >= playerY) {
            gameOver = true;
            return;
        }
    }
}
*/