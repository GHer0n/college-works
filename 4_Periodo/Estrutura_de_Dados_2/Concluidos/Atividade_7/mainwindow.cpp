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
    ui->lineEditQuantidadeElementos->setValidator(validatorNUMEROS);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonGerar_clicked()
{
    try {
        if(ui->lineEditQuantidadeElementos->text().isEmpty()){
            ui->lineEditQuantidadeElementos->setFocus();
            throw QString ("Por favor insira algum numero inteiro");
        }
        obj = new gft::Conjunto (ui->lineEditQuantidadeElementos->text().toInt());
        ui->textEditGerados->setText(obj->obterVetor());

        ui->textEditSelectionSort->setText(obj->obterVetorSelectionSort());
        ui->textEditInsertionSort->setText(obj->obterVetorInsertionSort());

        ui->textEditNExecucaoSS->setText(QString::number(obj->getExecucoesSS()));
        ui->textEditNExecucaoIS->setText(QString::number(obj->getExecucoesIS()));

        ui->textEditTempoSS->setText(QString::number(obj->TempoSelectionSort() / 1000, 'f', 3) + "µs");
        ui->textEditTempoIS->setText(QString::number(obj->TempoInserctionSort() / 1000, 'f', 3) + "µs");



    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}

//void MainWindow::on_pushButton_clicked()
//{
//    try {
//        if(ui->lineEditValor->text().isEmpty()){
//            ui->lineEditValor->setFocus();
//            throw QString ("Por favor insira algum numero que tenha no vetor");
//        }
//        if(obj->BuscarNum(ui->lineEditValor->text().toInt()) == -1){
//            ui->textEdit->setText(QString::number(obj->getExecucoes()));
//            ui->textEditResultado->clear();
//            throw QString ("Numero nao encontrado");
//        }
//        else{
//            ui->textEditResultado->setText("O numero que deseja esta na posicao: [" +
//                                                    QString::number(obj->BuscarNum(ui->lineEditValor->text().toInt())) + "]");
//            ui->textEdit->setText(QString::number(obj->getExecucoes()));
//        }
//        ui->lineEditValor->setFocus();
//    } catch (QString &erro) {
//        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
//    }
//}

//void MainWindow::on_pushButtonMelhorada_clicked()
//{
//    try {
//        if(ui->lineEditValorMelhorada->text().isEmpty()){
//            ui->lineEditValorMelhorada->setFocus();
//            throw QString ("Por favor insira algum numero que tenha no vetor");
//        }
//        if(obj->buscarNumMelhorado(ui->lineEditValorMelhorada->text().toInt()) == -1){
//            ui->textEdit_2->setText(QString::number(obj->getExecucoes()));
//            ui->textEditResultadoMelhorada->clear();
//            throw QString ("Numero nao encontrado");
//        }
//        else{
//            ui->textEditResultadoMelhorada->setText("O numero que deseja esta na posicao: [" +
//                                                    QString::number(obj->buscarNumMelhorado(ui->lineEditValorMelhorada->text().toInt())) + "]");
//            ui->textEdit_2->setText(QString::number(obj->getExecucoes()));
//        }
//        ui->lineEditValorMelhorada->setFocus();
//    } catch (QString &erro) {
//        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
//    }
//}

//void MainWindow::on_pushButtonBinario_clicked()
//{
//    try {
//        if(ui->lineEditValorBi->text().isEmpty()){
//            ui->lineEditValorBi->setFocus();
//            throw QString ("Por favor insira algum numero que tenha no vetor");
//        }
//        if(obj->buscaBinaria(ui->lineEditValorBi->text().toInt()) == -1){
//            ui->textEdit_3->setText(QString::number(obj->getExecucoes()));
//            ui->textEditResultadoBi->clear();
//            throw QString ("Numero nao encontrado");
//        }
//        else{
//            ui->textEditResultadoBi->setText("O numero que deseja esta na posicao: [" +
//                                                    QString::number(obj->buscaBinaria(ui->lineEditValorBi->text().toInt())) + "]");
//            ui->textEdit_3->setText(QString::number(obj->getExecucoes()));
//        }
//    } catch (QString &erro) {
//        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
//    }
//}
