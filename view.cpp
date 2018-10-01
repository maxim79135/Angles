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

    backGroundcolorOne = QColor(80, 80, 80);
    backGroundcolorTwo = QColor(255, 255, 255);
    chekercolorOne = QColor(0, 0, 139);
    chekercolorTwo = QColor(139, 0, 0);

    ui->pbStop->setEnabled(false);
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
    p.setBrush(QBrush(backGroundcolorOne));
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
            if ((i + k) % 2 == 0) p.drawRect(i * 50, k * 50 + 15, 50, 50);

    p.setBrush(QBrush(backGroundcolorTwo));
    for (int i = 0; i < 8; i++)
        for (int k = 0; k < 8; k++)
            if ((i + k) % 2 != 0) p.drawRect(i * 50, k * 50 + 15, 50, 50);

    p.setPen(Qt::SolidLine);
    p.drawLine(400, 0, 400, 400);

    //draw chekers
    for (int i = 0; i < this->game->getMonsterCount(); i++) {
        if (i != game->getSelectedChekerIndex()) {
        p.setBrush(QBrush(this->game->getChekerType(i) == Game::CT_BLUE ? chekercolorOne : chekercolorTwo));
        p.drawEllipse(this->game->getMonsterPosition(i) * 50 + QPoint(25,25) + QPoint(0, 15), 20, 20);
        }
    }

    //draw moveing chekers
    if (game->getSelectedChekerIndex() >= 0) {
        if (!(mousePosition.x() < 0 || mousePosition.y() < 0
              || mousePosition.x() > 7 || mousePosition.y() > 7))
        if (game->canMoveToPosition(game->getSelectedChekerIndex(), mousePosition) ||
                game->canBigMoveToPosition(game->getSelectedChekerIndex(), mousePosition))
        {
            p.setPen(QPen(QBrush(QColor(148, 51, 145)), 5));
            p.setBrush(QBrush(QColor(mousePosition.x() + mousePosition.y() % 2 == 0 ? backGroundcolorOne : backGroundcolorTwo), Qt::NoBrush));
            p.drawRect(QRect(mousePosition * 50 + QPoint(0, 15), QSize(50, 50)));
        }
    }

    if (game->getSelectedChekerIndex() >= 0) {
        p.setPen(QPen(QBrush(QColor(255, 165, 0)), 3));
        p.setBrush(QBrush(QColor(game->getChekerType(game->getSelectedChekerIndex()) == Game::CT_BLUE ? chekercolorOne : chekercolorTwo)));
        p.drawEllipse(realMousePosition, 20, 20);
    }
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
    if (!game->moveSelectedChekerToPosition((event->pos() - QPoint(25, 25)) / 50)) {
        ui->label->setText("ERROR! Try move!");
        QTimer *t = new QTimer(this);
        t->start(2000);
        connect(t, SIGNAL(timeout()), this, SLOT(hideTextLabel()));
    }
    QString s1, s2;
    s1.setNum(game->getStep());
    ui->label_2->setText(s1);
    if (game->getStep() >= 37 && game->getStep() <= 40) {
        s2.setNum(40 - game->getStep());
        s1.clear();
        s1.append("Left ");
        s1.append(s2);
        ui->label_3->setText(s1);
    }
    game->setSelectedChekerIndex(-1);

    Game::ChekerType winner;
    if (game->isGameOver(winner))
        QMessageBox::information(0, "Attention", winner == game->getPlayMode() ? "You win" : "You lost");
}

void View::on_actionSave_triggered() {
    QFile file(QFileDialog::getSaveFileName(this, QString::fromUtf8("Save"),
                                            QDir::currentPath(),
                                            "Log (*.bat)"));
    if (file.open(QIODevice::WriteOnly)) {
        QString s;
        s = backGroundcolorOne.name();
        file.write(s.toUtf8());
        file.write("\n");
        s = backGroundcolorTwo.name();
        file.write(s.toUtf8());
        file.write("\n");
        s = chekercolorOne.name();
        file.write(s.toUtf8());
        file.write("\n");
        s = chekercolorTwo.name();
        file.write(s.toUtf8());
        file.write("\n");
        file.close();
    }
}

void View::on_actionOpen_triggered() {
    QFile file(QFileDialog::getOpenFileName(this, QString::fromUtf8("Open"),
                                 QDir::currentPath(),
                                 "Log (*.bat)"));
    if (file.open(QIODevice::ReadOnly)) {
        QQueue <QColor> colors;
        while (!file.atEnd()) {
            QString str = file.readLine();
            //QMessageBox::information(0, "1", str);
            str.remove(str.length() - 1, 1);
            QColor temp;
            temp.setNamedColor(str);
            colors.enqueue(temp);
        }
        backGroundcolorOne = colors.dequeue();
        backGroundcolorTwo = colors.dequeue();
        chekercolorOne     = colors.dequeue();
        chekercolorTwo     = colors.dequeue();
        file.close();
    }
}


void View::on_action1_triggered() {
    if (!game->isActive()) chekercolorTwo = QColor(220, 20, 60);
}

void View::on_action2_triggered() {
    if (!game->isActive()) chekercolorTwo = QColor(205, 92, 92);
}

void View::on_action3_triggered() {
    if (!game->isActive()) chekercolorTwo = QColor(178, 34, 34);
}

void View::on_actionDefault_triggered() {
    if (!game->isActive()) {
        backGroundcolorOne = Qt::darkGray;
        backGroundcolorTwo = Qt::white;
        chekercolorOne = QColor(0, 0, 139);
        chekercolorTwo = QColor(139, 0, 0);
    }
}

void View::on_action1_2_triggered() {
    if (!game->isActive()) chekercolorOne = QColor(102, 205, 170);
}
void View::on_action2_2_triggered() {
    if (!game->isActive()) chekercolorOne = QColor(0, 139, 139);
}

void View::on_action3_2_triggered() {
    if (!game->isActive()) chekercolorOne = QColor(0, 255, 255);
}

void View::on_action1_3_triggered() {
    if (!game->isActive()) {
        backGroundcolorOne = QColor(236, 235, 189);
        backGroundcolorTwo = QColor(62, 95, 138);
    }
}

void View::on_action2_3_triggered() {
    if (!game->isActive()) {
        backGroundcolorOne = QColor(115, 66, 34);
        backGroundcolorTwo = QColor(220, 220, 220);
    }

}

void View::on_action3_3_triggered() {
    if (!game->isActive()) {
        backGroundcolorOne = QColor(24, 21, 19);
        backGroundcolorTwo = QColor(250, 223, 173);
    }

}

void View::on_actionInfo_triggered() {
    QMessageBox::information(0, "Information", "Created app by Maxim Sedov");
}

void View::on_pbStop_clicked() {
    if (ui->pbStop->text() == "Pause") {
        ui->pbStop->setText("Resume");
        game->setActive(false);
    } else {
        ui->pbStop->setText("Pause");
        game->setActive(true);
    }
}

void View::on_pbPlay_clicked() {
    if (ui->pbPlay->text() == "Start") {
        ui->pbPlay->setText("Stop");
        game->setPlayMode(Game::CT_RED);
        game->resset();
        ui->pbStop->setEnabled(true);
        ui->label_3->clear();
    } else {
        ui->pbPlay->setText("Start");
        game->setActive(false);
    }
}

void View::on_pushButton_clicked() {
    this->close();
}

void View::on_actionExit_triggered() {
    this->close();
}

void View::hideTextLabel() {
    ui->label->setText("");
}

void View::on_actionApp_triggered() {
    QString s;
    s.append("The game ends if one of the following conditions is met:\n");
    s.append("One of the players moved all his checkers into the opponent's house. This player won the game.\n");
    s.append("One of the players still has several of his checkers in his house and at the same time made more than 40 moves. This player loses the game.");
    QMessageBox::information(0, "Info app", s);
}
