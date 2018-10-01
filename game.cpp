#include "game.h"
#include <constants.h>
#include "qmath.h"

Game::Game() : active(false), selectedCheker(-1)
{
    possibleMoves[0] = QPoint(-1, 0);
    possibleMoves[1] = QPoint(1, 0);
    possibleMoves[2] = QPoint(0, 1);
    possibleMoves[3] = QPoint(0, -1);
    possibleMoves[4] = QPoint(-2, 0);
    possibleMoves[5] = QPoint(2, 0);
    possibleMoves[6] = QPoint(0, 2);
    possibleMoves[7] = QPoint(0, -2);
    initialize();
    step = 0;
}

void Game::resset()
{
    active = true;
    initialize();

    if (gamemode != CT_RED) {

    }
    chekerTurn = true;
}

int Game::getChekerIndexPosition(const QPoint &pos)
{
    for (int i = 0; i < 9; i++) if (reds[i] == pos) return i;
    for (int i = 0; i < 9; i++) if (blues[i] == pos) return i + 9;
    return -1;
}

void Game::initialize()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            this->blues[i * 3 + j] = QPoint(i, j);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            this->reds[i * 3 + j] = QPoint(i + 5, j + 5);
}

bool Game::canMoveToPosition(int chekerIndex, const QPoint &pos) {
    Q_ASSERT(chekerIndex >= 0 || chekerIndex <= 18);

    if (!checkRange(pos)) return false;

    QPoint oldPosition = getMonsterPosition(chekerIndex);
    if (pos.x() != oldPosition.x() && pos.y() != oldPosition.y()) return false;
    QPoint diff = oldPosition - pos;
    QPoint sum = oldPosition + pos;

    //for (int i = 0; i < )

    if (abs(diff.x()) == 2 || abs(diff.y()) == 2)
        for (int i = 0; i < getMonsterCount(); i++)
            if (getChekerIndexPosition(pos) == -1 &&
                getChekerIndexPosition(QPoint(sum.x() / 2, sum.y() / 2))!= -1)
            return true;

    if (abs(diff.x()) > 1 || abs(diff.y()) > 1) return false;

    if (oldPosition == pos) return false;

    for (int i = 0; i < getMonsterCount(); i++)
        if (i != chekerIndex && getMonsterPosition(i) == pos)
            return false;
    return true;
}

bool Game::canBigMoveToPosition(int chekerIndex, const QPoint &pos) {
    prepareMap();
    searchWay.clear();
    QPoint buff = getMonsterPosition(chekerIndex);
    if (buff == pos) return false;
    searchWay.enqueue(buff);
    while (!searchWay.isEmpty()) {
        QPoint currentPosition = searchWay.dequeue();
        for (int i = 4; i < 8; i++)
            if (canMove(currentPosition, currentPosition + possibleMoves[i])) {
                QPoint newPosition = currentPosition + possibleMoves[i];
                map[newPosition.y()][newPosition.x()] = map[currentPosition.y()][currentPosition.x()] + 1;
                if (newPosition == pos) return true;
                searchWay.enqueue(newPosition);
            }
    }
    return false;
}

bool Game::moveSelectedChekerToPosition(const QPoint &pos) {
    if (selectedCheker < 0) return false;

    if (canMoveToPosition(selectedCheker, pos) ||
            canBigMoveToPosition(selectedCheker, pos)
            )
        if (selectedCheker < 9) {
            //emit isTurnCheker(reds[selectedCheker], pos);
            reds[selectedCheker] = pos;
        } else {
            //emit isTurnCheker(blues[selectedCheker - 9], pos);
            blues[selectedCheker - 9] = pos;
        }
        else
            return false;

    //if (isGameOver(CT_RED)) return true;

    chekerTurn = !chekerTurn;
    prepareMap();
    runMinMax(gamemode == CT_RED ? CT_BLUE : CT_RED, AILevel, -EPIC_BIG_VALUE, EPIC_BIG_VALUE);
    ChekerType winner;
    if (isGameOver(winner))
        QMessageBox::information(0, "Attention", winner == CT_RED ? "You win" : "You lost");
    chekerTurn = !chekerTurn;

/*
    QString s;
    s.setNum(test);
    QMessageBox::information(0, "1", s);
*/
    //isGameOver(CT_RED);
    step++;
    return true;
}

bool Game::isGameOver(ChekerType &winner) {
    winner = CT_NO_ONE;

    if (getStep() > 40)
        for (int i = 5; i < 8; i++)
            for (int j = 5; j < 8; j++)
                for (int k = 0; k < getMonsterCount() / 2; k++)
                    if (getRabbitPosition(k) == QPoint(i, j))
                    {
                        QMessageBox::information(0, "Attention", "You lose");
                        active = false;
                        return 0;
                    }

    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < getMonsterCount() / 2; k++)
                if (getRabbitPosition(k) == QPoint(i, j))
                    count++;
    if (count == 9) winner = CT_RED;

    count = 0;
    for (int i = 5; i < 8; i++)
        for (int j = 5; j < 8; j++)
            for (int k = 0; k < getMonsterCount() / 2; k++)
                if (getWolfPosition(k) == QPoint(i, j))
                    count++;
    if (count == 9) winner = CT_BLUE;
    if (winner != CT_NO_ONE) {
        active = false;
        return true;
    }
    return false;
}

bool Game::checkHomes(Game::ChekerType cheker) {
    /*if (cheker == CT_RED)
        for (int i = 5; i < 7; i++)
            for (int j = 5; j < 7; j++)
                //if (getChekerIndexPosition(QPoint(i, j))   )
                */
}

bool Game::canMove(int x, int y) {
    if (!checkRange(x, y))
        return false;

    if (map[y][x] != 0)
        return false;
    return true;
}

bool Game::canMove(const QPoint &currpoint, int x, int y) {
    if (!checkRange(x, y))
        return false;
    QPoint pos(x, y);
    if (map[y][x] == 0 && (
    map[((currpoint + pos) / 2).y()][((currpoint + pos) / 2).x()] == BLUE ||
    map[((currpoint + pos) / 2).y()][((currpoint + pos) / 2).x()] == RED
    )) return true;
    return false;
}

int Game::getHeuristicEvulation(int chekerindex) {
    int max = 0, count = 0;
    /*int minR = 0, minB = 0;
    if (cheker == CT_RED) {
    searchWay.clear();
    for (int k = 0; k < 9; k++) {
        //if (reds[i].y() >= 0 && reds[i].x() >= 0 && reds[i].y() <= 2 && reds[i].x() <= 2) return 0;
        searchWay.enqueue(reds[k]);

        while (!searchWay.empty()) {
            QPoint currentPosition = searchWay.dequeue();
            for (int i = 0; i < 4; i++)
                if (canMove(currentPosition, currentPosition + possibleMoves[i])) {
                    QPoint newPosition = currentPosition + possibleMoves[i];
                    map[newPosition.y()][newPosition.x()] = map[currentPosition.y()][currentPosition.x()] + 1;
                    if (minR < StTab[newPosition.y()][newPosition.x()] - StTab[currentPosition.y()][currentPosition.x()])
                        minR = StTab[newPosition.y()][newPosition.x()] - StTab[currentPosition.y()][currentPosition.x()];
                    searchWay.enqueue(newPosition);
                }
        }
    }
    } else {*/
    searchWay.clear();
    searchWay.enqueue(blues[chekerindex - 9]);
        while (!searchWay.empty()) {
            QPoint currentPosition = searchWay.dequeue();
            for (int i = 0; i < 8; i++)
                if (canMove(currentPosition, currentPosition + possibleMoves[i]) && count < AILevel) {
                    QPoint newPosition = currentPosition + possibleMoves[i];
                    map[newPosition.y()][newPosition.x()] = map[currentPosition.y()][currentPosition.x()] + 1;
                    if (StTab[(newPosition).y()][(newPosition).x()] -
                            StTab[(currentPosition).y()][(currentPosition).x()] > max)
                        max = StTab[(newPosition).y()][(newPosition).x()] -
                                StTab[(currentPosition).y()][(currentPosition).x()];
                    ++count;
                    searchWay.enqueue(newPosition);
                }
        }
    return max;
}

int Game::runMinMax(Game::ChekerType cheker, int recursiveLevel, int alpha, int beta) {
    //if (recursiveLevel == 0) return getHeuristicEvulation(cheker);
    int test = 0;
    prepareMap();
    int bestMove = NOT_INITIALIZED;
    bool isRed = (cheker == CT_RED);

    for (int i = (isRed ? 0 : 72); i < (isRed ? 72 : 144); i++)
    {
        int curCheker = i / 8;
        QPoint curChekerPos = curCheker < 9 ? reds[curCheker] : blues[curCheker - 9];
        QPoint curMove = possibleMoves[i % 8];

        if (canMoveToPosition(curCheker, curChekerPos + curMove)) {
            if (StTab[(curChekerPos + curMove).y()][(curChekerPos + curMove).x()] -
                    StTab[(curChekerPos).y()][(curChekerPos).x()] > test)
            {
                test = StTab[(curChekerPos + curMove).y()][(curChekerPos + curMove).x()] -
                        StTab[(curChekerPos).y()][(curChekerPos).x()];
                bestMove = i;
            }
            /*temporaryChekerMovement(curCheker, curMove);
            test = -runMinMax(isRed ? CT_BLUE : CT_RED, recursiveLevel - 1, -beta, -alpha);
            QString s;
            s.setNum(test);
            QMessageBox::information(0, "1", s);
            temporaryChekerMovement(curCheker, -curMove);

            if (test > alpha) {
                alpha = test;
                bestMove = i;
            }*/
        }
    }

    //if (recursiveLevel == AILevel && bestMove != NOT_INITIALIZED) {
    if (cheker == CT_BLUE)
        blues[bestMove / 8 - 9] += possibleMoves[bestMove % 8];
    else
        reds[bestMove / 8] += possibleMoves[bestMove % 8];
    //}
    return alpha;
}

void Game::temporaryChekerMovement(int chekerindex, int x, int y) {
    if (chekerindex < 9) {
        map[reds[chekerindex].y()][reds[chekerindex].x()] = EMPTY;
        map[reds[chekerindex].y() + y][reds[chekerindex].x() + x] = RED;
        reds[chekerindex] += QPoint(x, y);
    } else {
        map[blues[chekerindex - 9].y()][blues[chekerindex - 9].x()] = EMPTY;
        map[blues[chekerindex - 9].y() + y][blues[chekerindex - 9].x() + x] = BLUE;
        blues[chekerindex - 9] += QPoint(x, y);
    }
}

void Game::prepareMap() {
    /*for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            map[i][j] = EMPTY;*/

    for (int i = 0; i < 8; i++)
        memset(map[i],0, 8 * sizeof(int));
    for (int i = 0; i < 9; i++) {
        map[reds[i].y()][reds[i].x()] = RED;
        map[blues[i].y()][blues[i].x()] = BLUE;
    }
}
