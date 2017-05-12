#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "subwindow.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	void Initialize();
	void AddToolBarButton(const char* iconPath, const char* name, const char* statusDscrp);
	void NewWindow();
	
private:
	Ui::MainWindowClass ui;
	SubWindow* __new_subwindow;
	void __ArrangeLayouts();
	void __SetButtons();
private slots:
	void NewSubWindow(const QString& title);
};
