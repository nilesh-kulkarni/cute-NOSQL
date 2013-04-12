#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QTreeView;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
    void about();
    void highlight(const QModelIndex&);
private:
    void createMenu();
    QAbstractItemModel *modelFromFile(const QString& fileName);

    QTreeView *databaseView;
};

#endif // MAINWINDOW_H
