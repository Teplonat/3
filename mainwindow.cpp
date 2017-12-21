#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextDocumentWriter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->selectAll();
    ui->textEdit->copy();
    QTextDocumentWriter writer("filename.txt", "plaintext");
    writer.write(ui->textEdit->document());
    QFile file("filename.txt");
    if (!file.open(QIODevice::ReadOnly))
        return;

    while (!file.atEnd()){
        ui->textEdit->textCursor().insertText(QString::fromUtf8(file.readLine()));
    }
}
