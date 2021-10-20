#include <QApplication>
#include <QWidget>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	QWidget app_window;
	app_window.show();
	return app.exec();
}