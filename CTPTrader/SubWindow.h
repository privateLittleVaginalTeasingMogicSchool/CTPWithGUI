#pragma once

#include <qmdisubwindow.h>
#include <QWidget.h>
#include <QtSvg\qgraphicssvgitem.h>

class CandleStick
{
public:
	CandleStick();
	CandleStick(double open, double high, double low, double close, double volume, QString& datetime, int count);
	inline double open()const;
	inline double high()const;
	inline double low()const;
	inline double close()const;
	inline double volume()const;
	inline QString&& datetime();
	inline int count()const;
	inline void open(double val);
	inline void high(double val);
	inline void low(double val);
	inline void close(double val);
	inline void volume(double val);
	inline void datetime(QString& val);
	inline void count(int val);
	inline void append(double val);
	inline void append(QString& val);


private:
	double __open;
	double __high;
	double __low;
	double __close;
	double __volume;
	QString __datetime;
	int __count;
};


/*
*  本类扩展QMdiSubWindow类，增加对k线源数据的管理及图表基本信息的管理
*/

class SubWindowView;

class SubWindow : public QMdiSubWindow
{
	Q_OBJECT
public:
	SubWindow(const QString& symbol, QWidget* parent = Q_NULLPTR);
	virtual ~SubWindow();

	inline double Max()const;
	inline double Min()const;
	inline double Count()const;
	inline QVector<CandleStick*>&& DataSeries();
	void GetRange(_In_ int left, _In_ int right, _Out_ double* max, _Out_ double* min);
	void ShowView();

private:
	void ConstructDataSeries(const std::string& dataSrcFilePath);
	void ConstructSvg();
	QVector<CandleStick*> __dataSeries;
	QGraphicsSvgItem* __svg;
	QString __symbol;
	double __max;
	double __min;
	double __count;
	SubWindowView* __view;
};

/*
*	本类扩展 QGraphicsView 类，增加对k线图本身伸缩，移动，标记的处理
*/
class SubWindowView : public QGraphicsView
{
	Q_OBJECT
public:
	SubWindowView(SubWindow* parent);
	void FitView();
	
protected slots:
	void wheelEvent(QWheelEvent *e);

private:
	int __time;
	int __rightMost;
	SubWindow* __parent;
};