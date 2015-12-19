#include "coreanimation.h"

CoreAnimation::CoreAnimation(QObject *parent)
	: QObject(parent)
{

}

CoreAnimation::~CoreAnimation()
{

}

void CoreAnimation::slotStartAnim(QWidget* widget, int x, int y)
{
	widget->hide();

	anim2->setDuration(2000);
	anim2->setStartValue(QPoint(widget->x(), widget->y()));
	anim2->setEndValue(QPoint(x, y));
	anim2->setEasingCurve(QEasingCurve::InBack);
	anim2->start();
}

void CoreAnimation::continueStartAnim(QWidget* widget, int x, int y)
{
	anim2->setDuration(2000);
	anim2->setStartValue(QPoint(widget->x(), widget->y()));
	anim2->setEndValue(QPoint(x, y));
	anim2->setEasingCurve(QEasingCurve::InBack);
	anim2->start();
}
