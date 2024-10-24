#ifndef BTLSHP_H
#define BTLSHP_H

#include <QTableWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QString>

class btlshp : public QMainWindow
{
    Q_OBJECT
private:
    QTableWidget* table;
    QPushButton* attackButt;
    QLabel* moves;
    QLabel* a;
    int move = 10;
    int found = 0;
    int matrix[10][10];

    void setupUi();

public:
    btlshp(QWidget* parent = nullptr);
    //print();

private slots:
    void onAttackButtonClicked();
    void updateCount();
};


#endif // BTLSHP_H
