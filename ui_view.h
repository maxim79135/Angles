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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionColor;
    QAction *actionGame;
    QAction *actionMore;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *gbPlayMode;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbRed;
    QRadioButton *rbBlue;
    QGroupBox *gbLevel;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *sbAILevel;
    QPushButton *pbPlay;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuAbout;

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
        actionColor = new QAction(View);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        actionGame = new QAction(View);
        actionGame->setObjectName(QStringLiteral("actionGame"));
        actionMore = new QAction(View);
        actionMore->setObjectName(QStringLiteral("actionMore"));
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
        gbPlayMode = new QGroupBox(widget);
        gbPlayMode->setObjectName(QStringLiteral("gbPlayMode"));
        gbPlayMode->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(gbPlayMode);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rbRed = new QRadioButton(gbPlayMode);
        rbRed->setObjectName(QStringLiteral("rbRed"));
        rbRed->setChecked(true);

        verticalLayout_2->addWidget(rbRed);

        rbBlue = new QRadioButton(gbPlayMode);
        rbBlue->setObjectName(QStringLiteral("rbBlue"));

        verticalLayout_2->addWidget(rbBlue);


        verticalLayout->addWidget(gbPlayMode);

        gbLevel = new QGroupBox(widget);
        gbLevel->setObjectName(QStringLiteral("gbLevel"));
        verticalLayout_3 = new QVBoxLayout(gbLevel);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        sbAILevel = new QSpinBox(gbLevel);
        sbAILevel->setObjectName(QStringLiteral("sbAILevel"));
        sbAILevel->setMinimum(1);
        sbAILevel->setMaximum(4);
        sbAILevel->setValue(3);

        verticalLayout_3->addWidget(sbAILevel);


        verticalLayout->addWidget(gbLevel);

        pbPlay = new QPushButton(widget);
        pbPlay->setObjectName(QStringLiteral("pbPlay"));

        verticalLayout->addWidget(pbPlay);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        View->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(View);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 515, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        View->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuOptions->addAction(actionColor);
        menuAbout->addAction(actionGame);
        menuAbout->addAction(actionMore);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QApplication::translate("View", "View", nullptr));
        actionSave->setText(QApplication::translate("View", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("View", "Alt+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("View", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("View", "Alt+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionColor->setText(QApplication::translate("View", "Color", nullptr));
#ifndef QT_NO_SHORTCUT
        actionColor->setShortcut(QApplication::translate("View", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionGame->setText(QApplication::translate("View", "Game", nullptr));
#ifndef QT_NO_SHORTCUT
        actionGame->setShortcut(QApplication::translate("View", "Alt+G", nullptr));
#endif // QT_NO_SHORTCUT
        actionMore->setText(QApplication::translate("View", "More", nullptr));
#ifndef QT_NO_SHORTCUT
        actionMore->setShortcut(QApplication::translate("View", "Alt+M", nullptr));
#endif // QT_NO_SHORTCUT
        gbPlayMode->setTitle(QApplication::translate("View", "Play mode", nullptr));
        rbRed->setText(QApplication::translate("View", "Red", nullptr));
        rbBlue->setText(QApplication::translate("View", "Blue", nullptr));
        gbLevel->setTitle(QApplication::translate("View", "Level", nullptr));
        pbPlay->setText(QApplication::translate("View", "Start", nullptr));
        menuFile->setTitle(QApplication::translate("View", "File", nullptr));
        menuOptions->setTitle(QApplication::translate("View", "Options", nullptr));
        menuAbout->setTitle(QApplication::translate("View", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
