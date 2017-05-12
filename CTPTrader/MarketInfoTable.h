#pragma once

#include <qtablewidget.h>
#include <qmenu.h>
#include "SubWindow.h"


class MarketInfoTable : public QTableWidget
{
	Q_OBJECT
public:
	MarketInfoTable(QWidget* parent = Q_NULLPTR);

signals:
	void NewWindow(const QString& title);
	
public slots:
	void onRightClickPopMenu(const QPoint& point);
	void onPopMenuNewWindowTriggered();
private:
	QMenu* __menu;
	QTableWidgetItem* __selectedItem;
}; 