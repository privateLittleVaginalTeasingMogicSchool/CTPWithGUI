#include "stdafx.h"
#include "MarketInfoTable.h"
#include "MainWindow.h"

MarketInfoTable::MarketInfoTable(QWidget* parent)
	:QTableWidget(parent)
{
	QAction* actionNewWindow = new QAction("New Window");
	__menu = new QMenu;
	__menu->addAction(actionNewWindow);
	connect(actionNewWindow, SIGNAL(triggered()), this, SLOT(onPopMenuNewWindowTriggered()));
	setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(onRightClickPopMenu(QPoint)));
}

void MarketInfoTable::onRightClickPopMenu(const QPoint& point)
{
	int row = indexAt(point).row();
	__selectedItem = item(row, 0);
	__menu->exec(QCursor::pos());
}

void MarketInfoTable::onPopMenuNewWindowTriggered()
{
	emit NewWindow(__selectedItem->text());
}