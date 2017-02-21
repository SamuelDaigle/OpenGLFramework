#ifndef UIQT_H
#define UIQT_H

#include <QtWidgets/QMainWindow>
#include "ui_uiqt.h"

class UIQT : public QMainWindow
{
	Q_OBJECT

public:
	UIQT(QWidget *parent = 0);
	~UIQT();

private:
	Ui::UIQTClass ui;
};

#endif // UIQT_H
