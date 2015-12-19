/********************************************************************************
** Form generated from reading UI file 'zhhftest.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHHFTEST_H
#define UI_ZHHFTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zhhftestClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *zhhftestClass)
    {
        if (zhhftestClass->objectName().isEmpty())
            zhhftestClass->setObjectName(QStringLiteral("zhhftestClass"));
        zhhftestClass->resize(600, 400);
        centralWidget = new QWidget(zhhftestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        zhhftestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(zhhftestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        zhhftestClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(zhhftestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        zhhftestClass->setStatusBar(statusBar);

        retranslateUi(zhhftestClass);

        QMetaObject::connectSlotsByName(zhhftestClass);
    } // setupUi

    void retranslateUi(QMainWindow *zhhftestClass)
    {
        zhhftestClass->setWindowTitle(QApplication::translate("zhhftestClass", "zhhftest", 0));
    } // retranslateUi

};

namespace Ui {
    class zhhftestClass: public Ui_zhhftestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHHFTEST_H
