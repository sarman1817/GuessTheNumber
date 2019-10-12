#pragma once
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QHBoxLayout>
#include <QMessageBox>

class GuessTheNumberWindow : public QWidget
{
    Q_OBJECT

public:
    GuessTheNumberWindow(QWidget *ip_parent = Q_NULLPTR);
    QHBoxLayout* m_layout;
    QLabel* mp_output;
    QLineEdit* mp_input;
    QPushButton* mp_button;
private:
    int GenerateNumber();
    void CheckNumber();
};
