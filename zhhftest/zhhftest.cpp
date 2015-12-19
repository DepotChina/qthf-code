/************************************************************************************************
*   This file is part of the ZhenHai project						                         
*   Copyright (C) 2010 by ZhenHai                                                        
*                                                                                                             
*   This library is free software; you can redistribute it and/or modify      
*   it under the terms of the GNU Lesser General Public License as          
*   published by the Free Software Foundation; either version 2.1 of       
*   the License, or (at your option) any later version.                                 
*                                                                                                            
*   This library is distributed in the hope that it will be useful,                   
*   but WITHOUT ANY WARRANTY; without even the implied warranty of      
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     
*   Lesser General Public License for more details.                      
*                                                                        
*   You should have received a copy of the GNU Le Seer General Public  
*   License along with this library; if not, write to                    
*   the Free Software Foundation, Inc.,                                 
*   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA       

*   filename : main.cpp                                               
*   the role of document : main                                          
*   author : ZhangNeng                                                    
*   creation time : 2011.02.23                                          
*   modification time : 2011.03.09                                    
***************************************************************************************************/
#include "zhhftest.h"
#include "coreanimation.h"

#include <stdio.h>
#include <qevent.h>
#include <qimage.h>
#include <qcommonstyle.h>

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


extern int g_coordinates[10][2]; // 全局坐标 

zhhftest::zhhftest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_cooldown = 0;
	this->setAutoFillBackground(true);

	anim3 = new CoreAnimation(this);

	label = new QLabel(this);
	label->setParent(this);
	label->resize (40, 40);
	label->setAttribute(Qt::WA_TranslucentBackground);
	label->setPixmap(QPixmap(":/zhhftest/Resources/aaa.png"));

	QPoint position ;
	position = label->pos();
	position = QPoint(label->x() + 90, label->y() +90); 
	label->setGeometry(label->x() + 90, label->y() + 90, 40, 40);
	label->setAutoFillBackground(true);
	label->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint); 

	// this->drawPixmap(0,0,this->width(),this->height(),QPixmap(":/zhhftest/Resources/ditu.png"));
	/*
	QPalette palette;
	QPixmap pixmap(":/zhhftest/Resources/ditu.png");
	palette.setBrush(QPalette::Window, QBrush(pixmap));
	this->setPalette(palette);
	this->show();
	*/
	QFont ft;
	ft.setPointSize(20);
	QPalette pa;
	pa.setColor(QPalette::WindowText,Qt::white);
	pushButton19 = new QPushButton(this); 
	pushButton19->setFont(ft);
	pushButton19->setPalette(pa);
	pushButton19->setText(QString::fromLocal8Bit("开始测试"));
	pushButton19->setGeometry(QRect((1366 - 200) / 2, (736 - 100) / 2, 200, 100)); 
	connect(pushButton19, SIGNAL( clicked() ), this, SLOT( slotStartAnim() ));  
	pushButton19->show();

	anim2 = new QPropertyAnimation(label,"pos");
	connect(anim2, SIGNAL( finished() ), this, SLOT( slotShowDiallog() )); 
}

void zhhftest::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, 1366, 768, QPixmap(":/zhhftest/Resources/ditu.png"));
}

void zhhftest::slotStartAnim()
{
	pushButton19->hide();

	anim2->setDuration(2000);
	anim2->setStartValue(QPoint(label->x(), label->y()));
	anim2->setEndValue(QPoint(g_coordinates[6][0], g_coordinates[6][1]));
	anim2->setEasingCurve(QEasingCurve::InBack);
	anim2->start();
	m_cooldown += 1;
}

void zhhftest::continueStartAnim()
{
	delete queDialog;
	queDialog = NULL;

	anim2->setDuration(2000);
	anim2->setStartValue(QPoint(label->x(), label->y()));
	anim2->setEndValue(QPoint(500, 600));
	anim2->setEasingCurve(QEasingCurve::InBack);
	anim2->start();
}

void zhhftest::slotShowDiallog()
{
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect screenRect = desktopWidget->screenGeometry(); // 获取设备屏幕大小

	int n_nActScreenX = screenRect.width();
	int n_nActScreenY = screenRect.height();

	queDialog = new QuestionDialog(this, NULL, n_nActScreenX, n_nActScreenY);
	connect(queDialog, SIGNAL( eeecallccc() ), this, SLOT( continueStartAnim() )); 
	queDialog->show();
}

zhhftest::~zhhftest()
{
	delete label;
	label = NULL;
	delete queDialog;
	queDialog = NULL;
	delete pushButton19;
	pushButton19 = NULL;
}
