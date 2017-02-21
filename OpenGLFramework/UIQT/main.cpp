#include "uiqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UIQT w;
	w.show();
	return a.exec();
}
