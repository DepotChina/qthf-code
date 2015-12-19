#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include "qevent.h"
#include "qapplication.h"

#include <QLabel>
#include <QString>
#include <QObject>
#include <QBitmap>
#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QPixmap>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QRegExpValidator>
#include <QPropertyAnimation>


class QuestionDialog : public QWidget
{
	Q_OBJECT

public:
	static int count;

	QString* title_string;
	QString str;

	QuestionDialog(QWidget *parent, QString* string = NULL, int x = 0, int y = 0);
	~QuestionDialog();

private:
	int width;
	int height;
	int m_total;

	int aaa;

	QLabel* title;
	QLabel* mid;
	QLabel* text_label;
	QLabel* help_label;
	QLabel* picture_label;
	QPushButton* bottom_commit; // 确认答案

	QTextEdit* n_edit;
	QLineEdit* password_edit; // 答案编辑框

	QWidget* parent_widget;
	QWidget* pop_up_widget;

	QPixmap* main_back_pixmap;
	QHBoxLayout* hlayout;
	QVBoxLayout* vlayout;

	int getScore(char target[10][3][1024], char *source);
	void changeQuestion();
	void questionDialogInit(int x = 0, int y = 0);

	public slots:
		void questionDialogGetAnswer();

signals:
		void eeecallccc();
};

#endif // QUESTIONDIALOG_H
