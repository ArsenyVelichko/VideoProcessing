#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsVideoItem>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

protected:
	void resizeEvent(QResizeEvent* event) override;

private slots:
	void fitInSize();

private:
	Ui::MainWindow* ui;
	QGraphicsVideoItem* m_videoItem;
};
#endif // MAINWINDOW_H
