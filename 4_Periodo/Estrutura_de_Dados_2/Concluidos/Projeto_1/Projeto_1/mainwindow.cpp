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
        int tam = ui->lineEditQuantElementos->text().toInt();
        gft::Conjunto obj(tam);
        ui->textEditSaida->setText(obj.obterVetor());

    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }

}


