/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action1_2;
    QAction *action2_2;
    QAction *action3_2;
    QAction *action1_3;
    QAction *action2_3;
    QAction *action3_3;
    QAction *actionDefault;
    QAction *actionRules_for_game;
    QAction *actionAbut_programm;
    QAction *actionInfo;
    QAction *actionExit;
    QAction *actionApp;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pbPlay;
    QPushButton *pbStop;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuColor;
    QMenu *menuChekers;
    QMenu *menuReds;
    QMenu *menuBLues;
    QMenu *menuBackground;
    QMenu *menuMore_app;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("View"));
        View->resize(515, 415);
        View->setMinimumSize(QSize(515, 415));
        View->setMaximumSize(QSize(515, 415));
        View->setBaseSize(QSize(500, 400));
        actionSave = new QAction(View);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionOpen = new QAction(View);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        action1 = new QAction(View);
        action1->setObjectName(QStringLiteral("action1"));
        action2 = new QAction(View);
        action2->setObjectName(QStringLiteral("action2"));
        action3 = new QAction(View);
        action3->setObjectName(QStringLiteral("action3"));
        action1_2 = new QAction(View);
        action1_2->setObjectName(QStringLiteral("action1_2"));
        action2_2 = new QAction(View);
        action2_2->setObjectName(QStringLiteral("action2_2"));
        action3_2 = new QAction(View);
        action3_2->setObjectName(QStringLiteral("action3_2"));
        action1_3 = new QAction(View);
        action1_3->setObjectName(QStringLiteral("action1_3"));
        action2_3 = new QAction(View);
        action2_3->setObjectName(QStringLiteral("action2_3"));
        action3_3 = new QAction(View);
        action3_3->setObjectName(QStringLiteral("action3_3"));
        actionDefault = new QAction(View);
        actionDefault->setObjectName(QStringLiteral("actionDefault"));
        actionRules_for_game = new QAction(View);
        actionRules_for_game->setObjectName(QStringLiteral("actionRules_for_game"));
        actionAbut_programm = new QAction(View);
        actionAbut_programm->setObjectName(QStringLiteral("actionAbut_programm"));
        actionInfo = new QAction(View);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionExit = new QAction(View);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionApp = new QAction(View);
        actionApp->setObjectName(QStringLiteral("actionApp"));
        centralWidget = new QWidget(View);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(100, 0));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, 0, -1);
        pbPlay = new QPushButton(widget);
        pbPlay->setObjectName(QStringLiteral("pbPlay"));

        verticalLayout->addWidget(pbPlay);

        pbStop = new QPushButton(widget);
        pbStop->setObjectName(QStringLiteral("pbStop"));

        verticalLayout->addWidget(pbStop);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        View->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(View);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 515, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuColor = new QMenu(menuSettings);
        menuColor->setObjectName(QStringLiteral("menuColor"));
        menuColor->setEnabled(true);
        menuChekers = new QMenu(menuColor);
        menuChekers->setObjectName(QStringLiteral("menuChekers"));
        menuReds = new QMenu(menuChekers);
        menuReds->setObjectName(QStringLiteral("menuReds"));
        menuBLues = new QMenu(menuChekers);
        menuBLues->setObjectName(QStringLiteral("menuBLues"));
        menuBackground = new QMenu(menuColor);
        menuBackground->setObjectName(QStringLiteral("menuBackground"));
        menuMore_app = new QMenu(menuBar);
        menuMore_app->setObjectName(QStringLiteral("menuMore_app"));
        View->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuMore_app->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);
        menuSettings->addAction(menuColor->menuAction());
        menuColor->addAction(menuChekers->menuAction());
        menuColor->addAction(menuBackground->menuAction());
        menuColor->addAction(actionDefault);
        menuChekers->addAction(menuReds->menuAction());
        menuChekers->addAction(menuBLues->menuAction());
        menuReds->addAction(action1);
        menuReds->addAction(action2);
        menuReds->addAction(action3);
        menuBLues->addAction(action1_2);
        menuBLues->addAction(action2_2);
        menuBLues->addAction(action3_2);
        menuBackground->addAction(action1_3);
        menuBackground->addAction(action2_3);
        menuBackground->addAction(action3_3);
        menuMore_app->addAction(actionInfo);
        menuMore_app->addAction(actionApp);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QApplication::translate("View", "View", nullptr));
        actionSave->setText(QApplication::translate("View", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("View", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("View", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("View", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action1->setText(QApplication::translate("View", "1", nullptr));
        action2->setText(QApplication::translate("View", "2", nullptr));
        action3->setText(QApplication::translate("View", "3", nullptr));
        action1_2->setText(QApplication::translate("View", "1", nullptr));
        action2_2->setText(QApplication::translate("View", "2", nullptr));
        action3_2->setText(QApplication::translate("View", "3", nullptr));
        action1_3->setText(QApplication::translate("View", "1", nullptr));
        action2_3->setText(QApplication::translate("View", "2", nullptr));
        action3_3->setText(QApplication::translate("View", "3", nullptr));
        actionDefault->setText(QApplication::translate("View", "Default", nullptr));
        actionRules_for_game->setText(QApplication::translate("View", "Rules for game", nullptr));
        actionAbut_programm->setText(QApplication::translate("View", "About programm", nullptr));
        actionInfo->setText(QApplication::translate("View", "Info", nullptr));
        actionExit->setText(QApplication::translate("View", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("View", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        actionApp->setText(QApplication::translate("View", "App", nullptr));
        pbPlay->setText(QApplication::translate("View", "Start", nullptr));
        pbStop->setText(QApplication::translate("View", "Pause", nullptr));
        pushButton->setText(QApplication::translate("View", "Exit", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("View", "File", nullptr));
        menuSettings->setTitle(QApplication::translate("View", "Settings", nullptr));
        menuColor->setTitle(QApplication::translate("View", "Color", nullptr));
        menuChekers->setTitle(QApplication::translate("View", "Chekers", nullptr));
        menuReds->setTitle(QApplication::translate("View", "Reds", nullptr));
        menuBLues->setTitle(QApplication::translate("View", "Blues", nullptr));
        menuBackground->setTitle(QApplication::translate("View", "Background", nullptr));
        menuMore_app->setTitle(QApplication::translate("View", "More app", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
