#include "mainwindow.h"
#include "conjunto.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpressionValidator *validatorNUMEROS = new QRegularExpressionValidator(this);
        validatorNUMEROS->setRegularExpression(QRegularExpression("^\\d+$"));
        ui->lineEditQuantElementos->setValidator(validatorNUMEROS);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonGerar_clicked()
{

    try {
        if(ui->lineEditQuantElementos->text().isEmpty()){
        ui->lineEditQuantElementos->setFocus();
            throw QString ("Por favor insira algum numero inteiro");
        }
        obj = new gft::Conjunto (ui->lineEditQuantElementos->text().toInt());
        ui->textEditSaida->setText(obj->obterVetor());

    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }

}

void MainWindow::on_pushButton_clicked()
{
    try {
        if(ui->lineEditQuantElementos->text().isEmpty()){
        ui->lineEditQuantElementos->setFocus();
             throw QString ("Por favor insira o numero da posicao");
                }
        ui->textEditResultado->setText("O numero que deseja esta na posicao: [" +
                                       QString::number(obj->BuscarNum(ui->lineEditValor->text().toInt())) + "]");
        ui->lineEditValor->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}

