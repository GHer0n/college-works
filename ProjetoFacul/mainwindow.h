#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "conjunto.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpressionValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonGerar_clicked();

    void on_pushButton_clicked();

    void on_pushButtonBuscar_clicked();

    void on_pushButtonBinario_clicked();

    void on_pushButtonMelhorada_clicked();

private:
    Ui::MainWindow *ui;
    gft::Conjunto *obj;
};
#endif // MAINWINDOW_H
