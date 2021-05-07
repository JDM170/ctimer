#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFont font("Times", 28, QFont::Bold); // создаем шрифт
    ui->label->setFont(font); // ставим лейблу шрифт
    ui->label->setText("0"); // ставим лейблу 0
    time = new QTime(0, 0, 0); // создаем время
    timer = new QTimer(); // создаем таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
}

MainWindow::~MainWindow()
{
    delete time;
    delete timer;
    delete ui;
}

void MainWindow::slotTimerAlarm()
{
    *time = time->addSecs(1); // добавляем секунду
    // ui->label->setText(time->toString("s"));
    // if(time->minute() > 0)
    //     ui->label->setText(time->toString("m:s"));
    // if(time->hour() > 0)
    //     ui->label->setText(time->toString("h:m:s"));
    ui->label->setText(
        time->toString(
            time->hour() > 0 ? "h:m:s" : (time->minute() > 0 ? "m:s" : "s")
        )
    );
}

void MainWindow::on_start_clicked()
{
    if(timer->isActive()) {
        timer->stop(); // останавливаем таймер
        ui->start->setText("Старт");
    }
    else {
        timer->start(1000); // запускаем таймер с задержкой в 1 секунду
        ui->start->setText("Стоп");
    }
}

void MainWindow::on_reset_clicked()
{
    if(timer->isActive()) { // если таймер активен
        timer->stop(); // останавливаем таймер
        ui->start->setText("Старт"); // Ставим кнопке соответствующий текст
        if(time->setHMS(0, 0, 0))
            ui->label->setText("0"); // если вернулось значение true то ставим лейблу 0
    }
}
