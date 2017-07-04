#include "stdafx.h"

#include "SubWindow.h"
#include <QtSvg\qgraphicssvgitem.h>
#include <fstream>
#include <sstream>

CandleStick::CandleStick()
	:__open(-1), __high(-1), __low(-1), __close(-1), __volume(-1), __datetime(""), __count(-1)
{

}

CandleStick::CandleStick(double open, double high, double low, double close, double volume, QString& datetime, int count)
	:__open(open), __high(high), __low(low), __close(close), __volume(volume), __datetime(datetime), __count(count)
{
	
}

inline double CandleStick::open()const
{
	return __open;
}

inline double CandleStick::high()const
{
	return __high;
}

inline double CandleStick::low()const
{
	return __low;
}

inline double CandleStick::close()const
{
	return __close;
}

inline double CandleStick::volume()const
{
	return __volume;
}

inline QString&& CandleStick::datetime()
{
	return std::move(__datetime);
}

inline int CandleStick::count()const
{
	return __count;
}

inline void CandleStick::open(double val)
{
	__open = val;
}

inline void CandleStick::high(double val)
{
	__high = val;
}

inline void CandleStick::low(double val)
{
	__low = val;
}

inline void CandleStick::close(double val)
{
	__close = val;
}

inline void CandleStick::volume(double val)
{
	__volume = val;
}

inline void CandleStick::datetime(QString& val)
{
	__datetime = val;
}

inline void CandleStick::count(int val)
{
	__count = val;
}

inline void CandleStick::append(double val)
{
	if (__open == -1)
	{
		__open = val;
	}
	else if (__high == -1)
	{
		__high = val;
	}
	else if (__low == -1)
	{
		__low = val;
	}
	else if (__close == -1)
	{
		__close = val;
	}
	else if (__volume == -1)
	{
		__volume = val;
	}
}

inline void CandleStick::append(QString& val)
{
	__datetime = val;
}

SubWindow::SubWindow(const QString& symbol, QWidget* parent)
	:QMdiSubWindow(parent), __symbol(symbol)
{
	// load data
	ConstructDataSeries("D:\\data\\EURUSD43200.csv");
}

SubWindow::~SubWindow()
{
	for (CandleStick* stick : __dataSeries)
	{
		delete stick;
	}
	if (__svg)
	{
		delete __svg;
	}
}

void SubWindow::ShowView()
{
	ConstructSvg();
	__view = new SubWindowView(this);
	QString ss = __view->styleSheet();
	ss += " background: #252525";
	__view->setStyleSheet(ss);
	QLayout* theLayout = layout();
	theLayout->addWidget(__view);
	QGraphicsScene* scene = new QGraphicsScene;
	__view->setScene(scene);
	scene->addItem(__svg);
	//__view->horizontalScrollBar()->setVisible(false);
	__view->verticalScrollBar()->setVisible(false);
	__view->FitView();
}

void SubWindow::ConstructDataSeries(const std::string& dataSrcFilePath)
{
	std::ifstream fin(dataSrcFilePath, std::ios::in);
	__max = 0;
	__min = DBL_MAX;

	int highcol = 1;
	int lowcol = 2;

	while (!fin.eof())
	{
		CandleStick* stick = new CandleStick;
		std::string str;
		std::getline(fin, str);
		std::stringstream ss(str);

		// format: datetime open high low close volume

		std::string datetime_str;
		ss >> datetime_str;
		stick->append(QString(datetime_str.c_str()));

		int col = 0;

		while (!ss.eof())
		{
			double num;
			ss >> num;
			stick->append(num);

			if (highcol == col&&num > __max)
			{
				__max = num;
			}
			if (lowcol == col&&num < __min)
			{
				__min = num;
			}
			col++;
		}
		__dataSeries.append(stick);
	}
	__dataSeries.pop_back();
	__count = __dataSeries.size();
}

void SubWindow::ConstructSvg()
{
	int len = __count;
	int interval = 2;
	int width = 4;
	int height = 1000;
	double max = __max;
	double min = __min;
	double maxdif = max - min;

	std::ofstream fsvg;
	QString fname = "Resources\\.temp.svg";
	fsvg.open(fname.toStdString(), std::ios::out);
	fsvg << "<svg width = \"" << (width + interval)*len << "%\" height = \"" << height << "%\" version = \"1.1\" xmlns = \"http://www.w3.org/2000/svg\">" << std::endl;
	fsvg << "<style type=\"text/css\">" << std::endl;
	fsvg << "<![CDATA[.rise{ fill: #ffa400; stroke_width : 1; stroke: #ffa400; }.drop{ fill: #70f3ff; stroke_width : 1; stroke: #70f3ff; }]]>" << std::endl;
	fsvg << "</style>" << std::endl;

	double open, high, low, close;

	for (int i = 0; i < len; i++)
	{
		open = __dataSeries[i]->open();
		high = __dataSeries[i]->high();
		low = __dataSeries[i]->low();
		close = __dataSeries[i]->close();

		if (open < close)
		{
			fsvg << "<rect class = \"rise\" x = \"" << i*(width + interval) << "\" y = \"" << height * (max - close) / maxdif << "\" width = \"" << width << "\" height = \" " << height * (close - open) / maxdif << "\" />" << std::endl;
			fsvg << "<line class = \"rise\" x1 = \"" << i*(width + interval) + (width) / 2 << "\" y1 = \"" << height * (max - high) / maxdif << "\" x2 = \"" << i*(width + interval) + (width) / 2 << "\" y2 = \"" << height * (max - low) / maxdif << "\" />" << std::endl;
		}
		else
		{
			fsvg << "<rect class = \"drop\" x = \"" << i*(width + interval) << "\" y = \"" << height * (max - open) / maxdif << "\" width = \"" << width << "\" height = \" " << height * (open - close) / maxdif << "\" />" << std::endl;
			fsvg << "<line class = \"drop\" x1 = \"" << i*(width + interval) + (width) / 2 << "\" y1 = \"" << height * (max - high) / maxdif << "\" x2 = \"" << i*(width + interval) + (width) / 2 << "\" y2 = \"" << height * (max - low) / maxdif << "\" />" << std::endl;
		}
	}

	fsvg << "</svg>" << std::endl;
	fsvg.close();
	__svg = new QGraphicsSvgItem(fname);
}

inline double SubWindow::Max()const
{
	return __max;
}

inline double SubWindow::Min()const
{
	return __min;
}

inline double SubWindow::Count()const
{
	return __count;
}

inline QVector<CandleStick*>&& SubWindow::DataSeries()
{
	return std::move(__dataSeries);
}

void SubWindow::GetRange(_In_ int left, _In_ int right, _Out_ double* max, _Out_ double* min)
{
	int lft = __count - left - 1;
	int rht = __count - right - 1;
	*max = 0;
	*min = DBL_MAX;
	for (int i = rht; i >= lft; i--)
	{
		if (__dataSeries[i]->high() > *max)
		{
			*max = __dataSeries[i]->high();
		}
		if (__dataSeries[i]->low() < *min)
		{
			*min = __dataSeries[i]->low();
		}
	}
}

SubWindowView::SubWindowView(SubWindow* parent)
	:__parent(parent), __time(0), __rightMost(0)
{
	__time = 5;
	//FitView();
}

void SubWindowView::wheelEvent(QWheelEvent *e)
{
	double delta = e->delta();
	if (delta > 0)
	{
		if (__time < __parent->DataSeries().size() / 10)
			__time++;
	}
	else
	{
		if(__time > 1)
			__time--;
	}

	FitView();
}

void SubWindowView::FitView()
{
	double max = __parent->Max();
	double min = __parent->Min();
	int left = 10 * __time;
	int right = __rightMost;
	double rng_max;
	double rng_min;
	__parent->GetRange(left, right, &rng_max, &rng_min);

	double h = scene()->sceneRect().height();
	double w = scene()->sceneRect().width();
	int count = __parent->DataSeries().size();
	int leftindex = count - left - 1;
	fitInView(leftindex * 6, h * (max - rng_max) / (max - min), (left - right) * 6, h*(rng_max - rng_min) / (max - min));
}