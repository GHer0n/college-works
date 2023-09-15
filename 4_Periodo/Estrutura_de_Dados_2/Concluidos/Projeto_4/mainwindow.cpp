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
        ui->lineEditValor->setValidator(validatorNUMEROS);
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
        ui->textEditSelectionSort->setText(obj->obterVetorSelectionSort());


    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }

}

void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        if(ui->lineEditQuantElementos->text().isEmpty()){
            ui->lineEditQuantElementos->setFocus();
            throw QString ("Por favor insira o numero da posicao");
        }
        ui->textEditResultado->setText("O numero que deseja esta na posicao: [" +
                                       QString::number(obj->buscarNumMelhorado(ui->lineEditValor->text().toInt())) + "]");
        ui->lineEditValor->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}

void MainWindow::on_pushButton_clicked()
{
    try {
        if(ui->lineEditValor->text().isEmpty()){
            ui->lineEditValor->setFocus();
            throw QString ("Por favor insira algum numero que tenha no vetor");
        }
        ui->textEditResultado->setText("O numero que deseja esta na posicao: [" +
                                       QString::number(obj->buscarNumMelhorado(ui->lineEditValor->text().toInt())) + "]");
        ui->lineEditValor->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonBinario_clicked()
{
    try {
        if(ui->lineEditValorBi->text().isEmpty()){
            ui->lineEditValorBi->setFocus();
            throw QString ("Por favor insira algum numero que tenha no vetor");
        }
        ui->textEditResultadoBi->setText("O numero que deseja esta na posicao: [" +
                                       QString::number(obj->buscaBinaria(ui->lineEditValorBi->text().toInt())) + "]");
        ui->lineEditValorBi->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}

