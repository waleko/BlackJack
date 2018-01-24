/********************************************************************************
** Form generated from reading UI file 'bet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BET_H
#define UI_BET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bet
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Bet)
    {
        if (Bet->objectName().isEmpty())
            Bet->setObjectName(QStringLiteral("Bet"));
        Bet->resize(158, 69);
        widget = new QWidget(Bet);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 0, 158, 70));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        line = new QLineEdit(widget);
        line->setObjectName(QStringLiteral("line"));

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Bet);
        QObject::connect(buttonBox, SIGNAL(accepted()), Bet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Bet, SLOT(reject()));

        QMetaObject::connectSlotsByName(Bet);
    } // setupUi

    void retranslateUi(QDialog *Bet)
    {
        Bet->setWindowTitle(QApplication::translate("Bet", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Bet", "Set bet:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Bet: public Ui_Bet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BET_H
