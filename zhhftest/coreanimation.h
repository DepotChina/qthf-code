#ifndef COREANIMATION_H
#define COREANIMATION_H

#include <QtGui>
#include <QPoint>
#include <QObject>
#include <QPainter>
#include <QtDebug>
#include <QTranslator>
#include <QTextCodec>
#include <QApplication>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QPropertyAnimation>

class CoreAnimation : public QObject
{
	Q_OBJECT

public:
	CoreAnimation(QObject *parent);
	~CoreAnimation();
	QPropertyAnimation *anim2;
	void slotStartAnim(QWidget* widget, int x, int y);
	void continueStartAnim(QWidget* widget, int x, int y);

private:
	
};

#endif // COREANIMATION_H
