#include <QGraphicsScene>
#include <QMediaPlayer>

#include "./ui_MainWindow.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_videoItem(new QGraphicsVideoItem) {

	ui->setupUi(this);

	auto view = ui->graphicsView;
	auto scene = new QGraphicsScene(view);
	view->setScene(scene);
	scene->addItem(m_videoItem);

	auto player = new QMediaPlayer(this);
	player->setMedia(QUrl("test.mp4"));
	player->setVideoOutput(m_videoItem);
	player->play();

	connect(m_videoItem, &QGraphicsVideoItem::nativeSizeChanged, //
			this, &MainWindow::fitInSize);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::resizeEvent(QResizeEvent* event) {
	Q_UNUSED(event);
	fitInSize();
}

void MainWindow::fitInSize() {
	ui->graphicsView->fitInView(m_videoItem, Qt::KeepAspectRatio);
}
