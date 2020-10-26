#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#define PY_SSIZE_T_CLEAN

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pythonEmbedding()
{

        char filename[] = "/home/peter/bc/Projects/FirstApp/tensorflow";
        FILE* fp;




        Py_Initialize();

        fp = _Py_fopen(filename, "r");

        PyRun_SimpleFile(fp, filename);

        Py_Finalize();

}


void MainWindow::on_Button_clicked()
{
    MyLib lib;
    ui->label->setText(lib.test());
}

void MainWindow::on_PyButton_clicked()
{
    pythonEmbedding();
}
