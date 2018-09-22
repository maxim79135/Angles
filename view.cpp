#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    this->setWindowTitle("Angles");

    QTimer* updater = new QTimer(this);
    updater->start(30);

    connect(updater, SIGNAL(timeout()), SLOT(update()));
}

void View::setGame(Game* game)
{
    this->game = game;
}

View::~View()
{
    delete ui;
}

void View::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::NoPen);

    //draw grid
    p.setBrush(QBrush(Qt::darkGray));
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
            if ((i + k) % 2 == 0) p.drawRect(i * 50, k * 50, 50, 50);

    p.setBrush(QBrush(Qt::white));
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
            if ((i + k) % 2 != 0) p.drawRect(i * 50, k * 50, 50, 50);

    p.setPen(Qt::SolidLine);
    p.drawLine(400, 0, 400, 400);

    //draw chekers
    for (int i = 0; i < this->game->getMonsterCount(); i++) {
        if (i != game->getSelectedChekerIndex()) {
        p.setBrush(QBrush(this->game->getChekerType(i) == Game::CT_BLUE ? Qt::darkBlue : Qt::darkRed));
        p.drawEllipse(this->game->getMonsterPosition(i) * 50 + QPoint(25,25) , 20, 20);
        }
    }

    //draw moveing chekers
    if (game->getSelectedChekerIndex() >= 0) {
        if (!(mousePosition.x() < 0 || mousePosition.y() < 0
              || mousePosition.x() > 7 || mousePosition.y() > 7))
        if (game->canMoveToPosition(game->getSelectedChekerIndex(), mousePosition)) {
            p.setPen(QPen(QBrush(Qt::black), 5));
            p.setBrush(QBrush(QColor(mousePosition.x() + mousePosition.y() % 2 == 0 ? Qt::darkGray : Qt::white), Qt::NoBrush));
            p.drawRect(QRect(mousePosition * 50, QSize(50, 50)));
        }
    }

    if (game->getSelectedChekerIndex() >= 0) {
        p.setPen(Qt::NoPen);
        p.setBrush(QBrush(QColor(game->getChekerType(game->getSelectedChekerIndex()) == Game::CT_BLUE ? Qt::darkBlue : Qt::darkRed)));
        p.drawEllipse(realMousePosition, 20, 20);
    }
}


void View::on_pbPlay_clicked()
{
    ui->pbPlay->setText("Restart");
    game->setPlayMode(ui->rbRed->isChecked() ? Game::CT_RED : Game::CT_BLUE);
    game->setAILevel(ui->sbAILevel->value());
    game->resset();

}

void View::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::LeftButton) return;
    if (!game->isActive() || !game->isChekerTurn()) return;

    realMousePosition = event->pos();
    int chekerIndex = game->getChekerIndexPosition((event->pos() - QPoint(25, 25)) / 50);
    if (chekerIndex < 0) return;
    if (game->getChekerType(chekerIndex) != game->getPlayMode()) return;
    game->setSelectedChekerIndex(chekerIndex);

}

void View::mouseMoveEvent(QMouseEvent *event) {
    realMousePosition = event->pos();
    mousePosition = (event->pos() - QPoint(25, 25)) / 50;
}

void View::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() != Qt::LeftButton) return;
    if (!game->isActive()) return;

    realMousePosition = event->pos();
    game->moveSelectedChekerToPosition((event->pos() - QPoint(25, 25)) / 50);
    game->setSelectedChekerIndex(-1);

    Game::ChekerType winner;
    if (game->isGameOver(winner))
        QMessageBox::information(0, "Attention", winner == game->getPlayMode() ? "You win" : "You lost");
}
