/********************************************************************************
** Form generated from reading UI file 'bj.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BJ_H
#define UI_BJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BJ
{
public:
    QAction *actionAbout_us;
    QWidget *centralWidget;
    QGraphicsView *graph;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *BJ)
    {
        if (BJ->objectName().isEmpty())
            BJ->setObjectName(QStringLiteral("BJ"));
        BJ->resize(1024, 580);
        BJ->setMinimumSize(QSize(1024, 576));
        BJ->setMaximumSize(QSize(1024, 580));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bj.png"), QSize(), QIcon::Normal, QIcon::Off);
        BJ->setWindowIcon(icon);
        actionAbout_us = new QAction(BJ);
        actionAbout_us->setObjectName(QStringLiteral("actionAbout_us"));
        centralWidget = new QWidget(BJ);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graph = new QGraphicsView(centralWidget);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setGeometry(QRect(0, 0, 1024, 580));
        graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        BJ->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BJ);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        BJ->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionAbout_us);

        retranslateUi(BJ);

        QMetaObject::connectSlotsByName(BJ);
    } // setupUi

    void retranslateUi(QMainWindow *BJ)
    {
        BJ->setWindowTitle(QApplication::translate("BJ", "BlackJack", Q_NULLPTR));
        actionAbout_us->setText(QApplication::translate("BJ", "About us", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("BJ", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BJ: public Ui_BJ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BJ_H
