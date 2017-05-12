#include "stdafx.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Initialize();
	__new_subwindow = Q_NULLPTR;
}

void MainWindow::Initialize()
{
	// Style
	QApplication::setStyle(QStyleFactory::create("Fusion"));

	__ArrangeLayouts();
	__SetButtons();

}

void MainWindow::AddToolBarButton(const char* iconPath, const char* name, const char* status)
{
	QAction* btn = new QAction(QIcon(tr(iconPath)), tr(name));
	btn->setStatusTip(tr(status));
	ui.mainToolBar->addAction(btn);
}

void MainWindow::NewWindow()
{

}

void MainWindow::__ArrangeLayouts()
{
	// MdiArea
	setCentralWidget(ui.mdiArea);
	ui.mdiArea->setViewMode(QMdiArea::ViewMode::TabbedView);
	ui.mdiArea->setTabPosition(QTabWidget::TabPosition::North);


	// Market Information
	QStringList infoName;
	infoName << "Symbol" << "Bid" << "Ask" << "BidV" << "AskV";
	QString symbols[5] = { "AU1701", "AU1702", "AU1703", "AU1704", "AU1705" };
	ui.table_marketinfo->setHorizontalHeaderLabels(infoName);
	ui.table_marketinfo->horizontalHeader()->resizeSection(0, 60);
	ui.table_marketinfo->setContextMenuPolicy(Qt::CustomContextMenu);
	for (int i = 0; i < 5; i++)
	{
		ui.table_marketinfo->setItem(i, 0, new QTableWidgetItem(symbols[i]));
		for (int j = 1; j < 5; j++)
		{
			ui.table_marketinfo->setItem(i, j, new QTableWidgetItem(tr("000.00")));
		}
	}

	// Orders
	QStringList orderInfoName;
	orderInfoName << "Id" << "Type" << "Lot" << "Symbol" << "Open Price" << "Open Time" << "Stop Loss" << "Take Profit" << "Current Price" << "Commission" << "Interest" << "Margin" << "Comment";
	ui.table_orders->setHorizontalHeaderLabels(orderInfoName);
}

void MainWindow::__SetButtons()
{
	// Toolbar
	AddToolBarButton("Resources\\open.png", "open", "open a file");
	AddToolBarButton("Resources\\editor.png", "editor", "open the editor");
	AddToolBarButton("Resources\\start.png", "start", "start autotrading");
	AddToolBarButton("Resources\\pause.png", "pause", "pause autotrading");
	AddToolBarButton("Resources\\remove.png", "remove", "remove autotrading program");
	AddToolBarButton("Resources\\cross.png", "measure", "");

	connect(ui.table_marketinfo, SIGNAL(NewWindow(QString)), this, SLOT(NewSubWindow(QString)));
}

void MainWindow::NewSubWindow(const QString& title)
{
	__new_subwindow = new SubWindow(ui.mdiArea);
	__new_subwindow->setWindowTitle(title);
	__new_subwindow->setAttribute(Qt::WA_DeleteOnClose);
	ui.mdiArea->addSubWindow(__new_subwindow);
	__new_subwindow->show();
}