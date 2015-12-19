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
#ifndef ZHHFTEST_H
#define ZHHFTEST_H

#include "ui_zhhftest.h"
#include "coreanimation.h"
#include "questiondialog.h"

#include <qstate>
#include <qstatemachine>
#include <qsignaltransition>

#include <QtGui>
#include <QObject>
#include <QtDebug>
#include <QPushButton>
#include <QtWidgets/QLabel>
#include <QPropertyAnimation>
#include <QtWidgets/QMainWindow>


class zhhftest : public QMainWindow
{
	Q_OBJECT

public:
	int m_cooldown; // ¼ÆÊýÆ÷

	zhhftest(QWidget *parent = 0);
	~zhhftest();

	QLabel *label;  
	QWidget *widget;
	QPushButton *pushButton19;
	QuestionDialog *queDialog;
    QPropertyAnimation *anim2;
	CoreAnimation* anim3;

	void paintEvent(QPaintEvent *e);

public slots:  
	void slotStartAnim(); 
	void slotShowDiallog(); 
	void continueStartAnim();

private:
	Ui::zhhftestClass ui;
};

#endif // ZHHFTEST_H
