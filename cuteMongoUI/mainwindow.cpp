#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenu();

    QWidget *centralWidget = new QWidget;

    QLabel *modelLabel = new QLabel;
    modelLabel->setText(tr("<b>Mongo UI<br>(This would give GUI for Mongo DB)"));

    databaseView = new QTreeView();
    databaseView->setModel(modelFromFile(":/resources/database.txt"));
    databaseView->header()->hide();
    databaseView->expandAll();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(modelLabel, 0, 0, Qt::AlignHCenter);

    layout->addWidget(databaseView, 1, 0);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setWindowTitle(tr("Mongo UI"));
}

void MainWindow::createMenu()
{
    QAction *exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu* fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(exitAction);
}

QAbstractItemModel *MainWindow::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        QMessageBox::about(this, tr("Error"), tr("Error Opening Database file"));

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem* rootParentItem = model->invisibleRootItem();

    while (!file.atEnd()) {
        QString line = file.readLine();
        QStandardItem *item = new QStandardItem;
        item->setText(line);
        rootParentItem->appendRow(item);
    }

    return model;
}

void MainWindow::highlight(const QModelIndex &/*index*/)
{
}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About"), tr("This is MongoDB UI"));
}
