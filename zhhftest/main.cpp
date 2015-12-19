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

#include <qevent.h>
#include <qimage.h>
#include <qcommonstyle.h>

#include <QSettings>
#include <QTranslator>
#include <QTextCodec>
#include <QApplication>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QtWidgets/QApplication>


class ComfigMessageBox : public QMessageBox {
protected:
	void showEvent(QShowEvent* event) {
		QMessageBox::showEvent(event);
		setFixedSize(400, 200);
	}
};

class NoFocusRectangleStyle : public QCommonStyle  
{  
public:  
	void NoFocusRectangleStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option,  
		QPainter *painter, const QWidget *widget) const  
	{  
		if (QStyle::PE_FrameFocusRect == element && widget && widget)  
			return;  
		else  
			QCommonStyle::drawPrimitive(element,option, painter, widget);  
	}  
};  

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setStyle(new NoFocusRectangleStyle);

	QTextCodec* codec = QTextCodec::codecForName("GBK"); // 设置编码格式
	QTextCodec::setCodecForLocale(codec);

	QSettings settings("ZhenHai", "HaiFang"); // 设置程序名称
	QCoreApplication::setOrganizationName("ZhenHai");
	QCoreApplication::setApplicationName(QString::fromLocal8Bit("海防考试软件"));

	zhhftest w; // 主窗口
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect screenRect = desktopWidget->screenGeometry(); // 获取屏幕尺寸
	int n_nActScreenX = screenRect.width();
	int n_nActScreenY = screenRect.height();
	// w.setFixedSize(n_nActScreenX, n_nActScreenY); // 固定窗口大小
	// w.setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
	w.setWindowState(Qt::WindowMaximized);
	w.show();
	ComfigMessageBox::about(NULL, QString::fromLocal8Bit("镇海海防答题系统"), QString::fromLocal8Bit("欢迎使用答题系统"));
	return a.exec();
}
