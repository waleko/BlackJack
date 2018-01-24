/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(207, 253);
        pushButton = new QPushButton(About);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 220, 61, 23));
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 201, 201));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("About", "Close", Q_NULLPTR));
        label->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \321\201\320\276\320\267\320\264\320\260\320\275\320\260</p><p align=\"center\">\321\216\320\275\321\213\320\274 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\201\321\202\320\276\320\274</p><p align=\"center\">\320\250\321\203\321\200\320\270\320\272\320\276\320\274 \320\232\320\276\320\262\321\200\320\270\320\266\320\272\320\270\320\275\321\213\320\274,</p><p align=\"center\">\320\260 \321\202\320\260\320\272\320\266\320\265 \320\276\320\277\321\213\321\202\320\275\321\213\320\274 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\201\321\202\320\276\320\274</p><p align=\"center\">\320\232\320\276\320\275\320\264\321\200\320\260\321\210\321\221\320\262\321\213\320\274 \320\241\320\265\321\200\320\263\320\265\320\265\320\274 \320\241\320\265\321\200\320\263\320\265\320\265\320\262\320\270\321\207\320\265\320\274<br/></p><p align=\"center\">\320"
                        "\230\321\201\321\205\320\276\320\264\320\275\320\270\320\272\320\270 \320\275\320\260 <a href=\"kovrigin.unaux.com\"><span style=\" text-decoration: underline; color:#0000ff;\">kovrigin.unaux.com</span></a></p><p align=\"center\">\320\232\320\276\320\275\321\202\320\260\320\272\321\202\321\213: <a href=\"t.me/alex_kovrigin\"><span style=\" text-decoration: underline; color:#0000ff;\">Telegram </span></a><a href=\"vk.com/alex.kovrigin\"><span style=\" text-decoration: underline; color:#0000ff;\">VK</span></a></p><p align=\"center\">\320\222\320\265\321\200\321\201\320\270\321\217 5.2</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
