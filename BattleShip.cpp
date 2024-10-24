#include "btlshp.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

btlshp::btlshp(QWidget* parent) : QMainWindow(parent)
{
    setupUi();
}

void btlshp::setupUi()
{
    //initialize the setup of the widget
    QWidget* w = new QWidget();
    setCentralWidget(w);
    QWidget* h = new QWidget(w);

    QVBoxLayout* vLay = new QVBoxLayout(w);

    QHBoxLayout* hLay = new QHBoxLayout(w);

    table = new QTableWidget(w);
    table->setColumnCount(10);
    table->setRowCount(10);
    //set up a simple matrix system that will keep track of our battleship grid
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            table->setItem(i, j, new QTableWidgetItem("x"));
            matrix[i][j] = 0;
        }
    }
    //the values of the matrix containing 1 will be the ones containing part of the ship
    matrix[6][1] = 1;
    matrix[7][1] = 1;
    matrix[8][1] = 1;
    matrix[6][5] = 1;
    matrix[6][6] = 1;
    matrix[2][6] = 1;
    matrix[2][7] = 1;
    matrix[2][8] = 1;
    matrix[2][9] = 1;

    table->resizeRowsToContents();
    table->resizeColumnsToContents();

    vLay->addWidget(table);

    //setting up the attack button, creating a connector for it with the action of clicking.
    attackButt = new QPushButton(" A t t a c k ", w);
    connect(attackButt, &QPushButton::clicked, this, &btlshp::onAttackButtonClicked);

    hLay->addWidget(attackButt);

    //sets up the moves left button
    moves = new QLabel("Moves left:");
    a=new QLabel(QString::number(move));
    connect(attackButt, &QPushButton::clicked, this, &btlshp::updateCount);

    hLay->addWidget(moves);
    hLay->addWidget(a);
    h->setLayout(hLay);
    vLay->addWidget(h);

    w->setLayout(vLay);
}

//this function takes care of all the action, and once a square is clicked it checks if it contains a 1 or a 0. From there it
//keeps track of what was already attacked, handles decrementing the moves left counter, and also changes the colors of the squares attacked based on
//if they contained a ship or not. Squares that contain water turn blue while ones containing the ship turn red.
void btlshp::onAttackButtonClicked()
{
    int i = table->currentRow();
    int j = table->currentColumn();
    if(move <= 0)
        QMessageBox::warning(this, "you suck", "Game over, oopsies :(");
    if(matrix[i][j] == 0){
        table->setItem(i, j, new QTableWidgetItem("o"));
        matrix[i][j] = -1;
        table->item(i, j)->setBackground(QColorConstants::Svg::blue);
    }
    else if(matrix[i][j] == -1){
        QMessageBox::warning(this, "Input validation", "this location was already attacked");
    }
    else if(matrix[i][j] == 1){
        table->setItem(i, j, new QTableWidgetItem("*"));
        matrix[i][j] = -1;
        found++;
        table->item(i, j)->setBackground(QColorConstants::Svg::red);
    }

    move--;
    if (found == 8){
        QMessageBox::information(this, "Congratulations!", "You won :)");
    }

}

void btlshp::updateCount()
{
    a->setText(QString::number(move));
}
