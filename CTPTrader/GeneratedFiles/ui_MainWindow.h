/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "marketinfotable.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionSettings;
    QAction *actionExit;
    QAction *actionLog_in;
    QAction *actionLog_out;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAccount;
    QMenu *menuView;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dock_marketinfo;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout;
    MarketInfoTable *table_marketinfo;
    QDockWidget *dock_workspace;
    QWidget *dockWidgetContents_2;
    QDockWidget *dock_info;
    QWidget *dockWidgetContents_4;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tab_info;
    QWidget *tab_orders;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *table_orders;
    QWidget *tab_output;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1262, 799);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        MainWindowClass->setFont(font);
        MainWindowClass->setStyleSheet(QLatin1String("background-color: rgb(60, 63, 65);\n"
"color: rgb(255, 255, 255);"));
        actionSettings = new QAction(MainWindowClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLog_in = new QAction(MainWindowClass);
        actionLog_in->setObjectName(QStringLiteral("actionLog_in"));
        actionLog_out = new QAction(MainWindowClass);
        actionLog_out->setObjectName(QStringLiteral("actionLog_out"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        horizontalLayout_4->addWidget(mdiArea);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1262, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAccount = new QMenu(menuFile);
        menuAccount->setObjectName(QStringLiteral("menuAccount"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        dock_marketinfo = new QDockWidget(MainWindowClass);
        dock_marketinfo->setObjectName(QStringLiteral("dock_marketinfo"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        dock_marketinfo->setFont(font1);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        table_marketinfo = new MarketInfoTable(dockWidgetContents);
        if (table_marketinfo->columnCount() < 5)
            table_marketinfo->setColumnCount(5);
        if (table_marketinfo->rowCount() < 20)
            table_marketinfo->setRowCount(20);
        table_marketinfo->setObjectName(QStringLiteral("table_marketinfo"));
        table_marketinfo->setMinimumSize(QSize(280, 0));
        QFont font2;
        font2.setPointSize(9);
        table_marketinfo->setFont(font2);
        table_marketinfo->setStyleSheet(QLatin1String("selection-background-color: rgb(112, 112, 112);\n"
"gridline-color: rgb(109, 109, 109);"));
        table_marketinfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_marketinfo->setSelectionMode(QAbstractItemView::SingleSelection);
        table_marketinfo->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_marketinfo->setRowCount(20);
        table_marketinfo->setColumnCount(5);
        table_marketinfo->horizontalHeader()->setVisible(true);
        table_marketinfo->horizontalHeader()->setDefaultSectionSize(50);
        table_marketinfo->horizontalHeader()->setMinimumSectionSize(50);
        table_marketinfo->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_marketinfo->horizontalHeader()->setStretchLastSection(true);
        table_marketinfo->verticalHeader()->setVisible(false);
        table_marketinfo->verticalHeader()->setDefaultSectionSize(20);
        table_marketinfo->verticalHeader()->setMinimumSectionSize(25);

        horizontalLayout->addWidget(table_marketinfo);

        dock_marketinfo->setWidget(dockWidgetContents);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_marketinfo);
        dock_workspace = new QDockWidget(MainWindowClass);
        dock_workspace->setObjectName(QStringLiteral("dock_workspace"));
        dock_workspace->setFont(font1);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        dock_workspace->setWidget(dockWidgetContents_2);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_workspace);
        dock_info = new QDockWidget(MainWindowClass);
        dock_info->setObjectName(QStringLiteral("dock_info"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tab_info = new QTabWidget(dockWidgetContents_4);
        tab_info->setObjectName(QStringLiteral("tab_info"));
        tab_info->setFont(font1);
        tab_info->setTabPosition(QTabWidget::South);
        tab_orders = new QWidget();
        tab_orders->setObjectName(QStringLiteral("tab_orders"));
        horizontalLayout_3 = new QHBoxLayout(tab_orders);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        table_orders = new QTableWidget(tab_orders);
        if (table_orders->columnCount() < 13)
            table_orders->setColumnCount(13);
        if (table_orders->rowCount() < 20)
            table_orders->setRowCount(20);
        table_orders->setObjectName(QStringLiteral("table_orders"));
        table_orders->setFont(font1);
        table_orders->setStyleSheet(QLatin1String("selection-background-color: rgb(112, 112, 112);\n"
"gridline-color: rgb(109, 109, 109);"));
        table_orders->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_orders->setSelectionMode(QAbstractItemView::SingleSelection);
        table_orders->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_orders->setRowCount(20);
        table_orders->setColumnCount(13);
        table_orders->horizontalHeader()->setDefaultSectionSize(90);
        table_orders->horizontalHeader()->setMinimumSectionSize(50);
        table_orders->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_orders->horizontalHeader()->setStretchLastSection(true);
        table_orders->verticalHeader()->setVisible(false);
        table_orders->verticalHeader()->setDefaultSectionSize(20);
        table_orders->verticalHeader()->setMinimumSectionSize(20);

        horizontalLayout_3->addWidget(table_orders);

        tab_info->addTab(tab_orders, QString());
        tab_output = new QWidget();
        tab_output->setObjectName(QStringLiteral("tab_output"));
        tab_info->addTab(tab_output, QString());

        horizontalLayout_2->addWidget(tab_info);

        dock_info->setWidget(dockWidgetContents_4);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dock_info);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSettings);
        menuFile->addAction(menuAccount->menuAction());
        menuFile->addAction(actionExit);
        menuAccount->addAction(actionLog_in);
        menuAccount->addAction(actionLog_out);

        retranslateUi(MainWindowClass);

        tab_info->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("MainWindowClass", "Settings", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", Q_NULLPTR));
        actionLog_in->setText(QApplication::translate("MainWindowClass", "Log in", Q_NULLPTR));
        actionLog_out->setText(QApplication::translate("MainWindowClass", "Log out", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", Q_NULLPTR));
        menuAccount->setTitle(QApplication::translate("MainWindowClass", "Account", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindowClass", "View", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindowClass", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "Help", Q_NULLPTR));
        dock_marketinfo->setWindowTitle(QApplication::translate("MainWindowClass", "Market Information", Q_NULLPTR));
        dock_workspace->setWindowTitle(QApplication::translate("MainWindowClass", "Workspace", Q_NULLPTR));
        tab_info->setTabText(tab_info->indexOf(tab_orders), QApplication::translate("MainWindowClass", "Orders", Q_NULLPTR));
        tab_info->setTabText(tab_info->indexOf(tab_output), QApplication::translate("MainWindowClass", "Output", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
