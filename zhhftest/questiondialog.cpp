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
#include "coreanimation.h"
#include "questiondialog.h"
#include "qa_coordinates.h"


extern char (*p_answer)[1024];
extern char (*p_qustion)[1024]; 
extern char (*p_g_keyword)[3][1024];
extern char g_answer[10][1024];
extern char g_qustion[10][1024]; 
extern char g_keyword[10][3][1024];

QuestionDialog::QuestionDialog(QWidget *parent, QString* string, int x, int y)
	: QWidget(parent)
{
	Q_UNUSED(parent);

	width = x;
	height = y;
	title_string = string;
	p_qustion = g_qustion ;
	p_g_keyword = g_keyword;

	resize(400, 200);
	move( (x - 400) / 2, (y - 200) / 2 );
	questionDialogInit(x, y);
	show();
}

void QuestionDialog::questionDialogInit(int x, int y)
{
	Q_UNUSED(x);
	Q_UNUSED(y);

	QFont ft;
	ft.setPointSize(12);
	QPalette pa;
	pa.setColor(QPalette::WindowText,Qt::white);

	QPalette palette;
	main_back_pixmap = new QPixmap(":/zhhftest/Resources/111.png");
	palette.setBrush(QPalette::Window, QBrush(main_back_pixmap->scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation))); 
	this->setPalette(palette);
	this->setMask(main_back_pixmap->mask());
	this->setAutoFillBackground(true);

	vlayout = new QVBoxLayout(this);
	vlayout->setAlignment(Qt::AlignCenter);

	bottom_commit = new QPushButton(this);
	bottom_commit->setText(QString::fromLocal8Bit("确认"));
	bottom_commit->setFont(ft);
	bottom_commit->setPalette(pa);
	// bottom_commit->setAlignment(Qt::AlignCenter);

	picture_label = new QLabel(this); // 对话框背景图片
	picture_label->setPixmap(*main_back_pixmap);

	text_label = new QLabel(QString::fromLocal8Bit("请回答问题!"), this); // 题标
	text_label->setFont(ft);
	text_label->setPalette(pa);
	text_label->resize(100, 100);
	text_label->setAlignment(Qt::AlignCenter);
	connect(bottom_commit, SIGNAL( clicked() ), this, SLOT(questionDialogGetAnswer()));  

	help_label = new QLabel(QString::fromLocal8Bit(*p_qustion), this); // 问题
	help_label->setFont(ft);
	help_label->setPalette(pa);
	help_label->setAlignment(Qt::AlignCenter);

	n_edit = new QTextEdit(this);

	vlayout->addWidget(text_label);
	vlayout->setSpacing(10);
	vlayout->addWidget(help_label);
	vlayout->addWidget(n_edit);
	vlayout->addWidget(bottom_commit);
	setLayout(vlayout);
}

void QuestionDialog::changeQuestion()
{
	return;
}

void QuestionDialog::questionDialogGetAnswer()
{
	/*
	if (n_edit == NULL)
		return;
	*/
	str = n_edit->toPlainText( );  // 获取答案
	m_total = getScore(p_g_keyword, "东海今天气温季度");
	if (m_total >= 60)
	{
		// anim3 = new CoreAnimation(this);
	}
	else 
	{
		// 重新答题
		return;
	}
	emit this->eeecallccc();
	return;
}

int QuestionDialog::getScore(char target[10][3][1024], char *source)  // 打分函数
{
	int n_score = 0;
	int n_total = 0;

	if (source == NULL)
	{
		return -1;
	}

	int i = 0;
	int j = 0;
	for (i = 0; i <10; i++)
	{
		for (j = 0; j < 3; j++)
		{
			n_score = strnicmp(target[i][j], source, strlen(target[i][j]));
			if (n_score > 0)
			{
				n_total += 20;
			}
			else
			{
				return n_total;
			}
		}
	}
	return n_total;
}

QuestionDialog::~QuestionDialog( ) 
{
	delete text_label; // 释放资源
	text_label = NULL;
	delete picture_label;
	picture_label = NULL;
	delete n_edit;
	n_edit = NULL;
	delete vlayout;
	vlayout = NULL;
}