#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QTime>
#include <QTimer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_start_clicked();
    void on_reset_clicked();
    void slotTimerAlarm();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime *time;
};

#endif // MAINWINDOW_H
