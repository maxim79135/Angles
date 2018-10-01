#ifndef GAME_H
#define GAME_H

#include <QtWidgets>

#define MIN_VALUE 0
#define MAX_VALUE 255
#define EPIC_BIG_VALUE 500

class Game
{
public:
    Game();

    enum ChekerType {
        CT_NO_ONE = 0,
        CT_RED = 1,
        CT_BLUE = 2
    };

    int getStep() { return step; }
    void step_plus() { step++; }
    void setPlayMode(ChekerType gameMode) { gamemode = CT_RED; }
    ChekerType getPlayMode() { return gamemode; }

    void setActive(bool active) { this->active = active; }
    void setAILevel(int AILevel) { this->AILevel = AILevel; }
    bool isActive() { return active; }

    int getMonsterCount() { return 18; }

    void resset(); //start, restart game

   QPoint& getRabbitPosition(int chekerIndex) { return reds[chekerIndex]; }
   QPoint& getWolfPosition(int chekerIndex)
    {
        Q_ASSERT(chekerIndex < 10 && chekerIndex >= 0);
        return blues[chekerIndex];
    }

    QPoint& getMonsterPosition(int chekerIndex)
    {
        if (chekerIndex < 9)
            return getRabbitPosition(chekerIndex);
        else
            return getWolfPosition(chekerIndex - 9);
    }

    ChekerType getChekerType(int chekerIndex)
    {
        if (chekerIndex < 9)
            return CT_RED;
        else
            return CT_BLUE;
    }
    int isChekerTurn() { return chekerTurn; }

    int getChekerIndexPosition(const QPoint &pos);
    int getSelectedChekerIndex() { return selectedCheker; }
    void setSelectedChekerIndex(int chekerindex) { selectedCheker = chekerindex; }
    bool canMoveToPosition(int chekerIndex, const QPoint &pos);
    bool canBigMoveToPosition(int chekerIndex, const QPoint &pos);
    bool moveSelectedChekerToPosition(const QPoint &pos);

    bool checkRange(int x, int y) { return (x >= 0 && x <= 7 && y >= 0 && y <= 7); }
    bool checkRange(const QPoint &point) {return checkRange(point.x(), point.y()); }

    bool isGameOver(ChekerType& winner);
    bool checkHomes(ChekerType cheker);

private:
    static const int NOT_INITIALIZED = 255;

    static const int EMPTY = 0;
    static const int RED = 1;
    static const int BLUE = 255;

    QPoint blues[9]; //blues cheker (3x3)
    QPoint reds[9];  //red cheker (3x3)
    ChekerType gamemode; // state radiobutton(chose color)
    bool active; //state game
    bool chekerTurn;
    int AILevel;
    int step;
    int selectedCheker;

    int map[8][8]; // main array

    QQueue <QPoint> searchWay;
    QPoint possibleMoves[8];

    bool canMove(int x, int y);
    bool canMove(const QPoint &point) { return canMove(point.x(), point.y()); }
    bool canMove(const QPoint &currpoint, int x, int y);
    bool canMove(const QPoint &currpoint, const QPoint &point) { return canMove(currpoint, point.x(), point.y()); }

    int getHeuristicEvulation(int chekerindex);
    int runMinMax(ChekerType cheker, int recursiveLevel, int alpha, int beta);
    void temporaryChekerMovement(int chekerindex, int x, int y);
    void temporaryChekerMovement(int chekerindex, const QPoint &point) { temporaryChekerMovement(chekerindex, point.x(), point.y()); }

    void prepareMap();
    void initialize();

//signals:
//    void isTurnCheker(QPoint prevPos, QPoint newPos);
};

#endif // GAME_H
