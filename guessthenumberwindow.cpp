#include "guessthenumberwindow.h"
#include <cstdlib>
#include <ctime>

GuessTheNumberWindow::GuessTheNumberWindow(QWidget *ip_parent)
    : QWidget(ip_parent)
    , m_layout{new QHBoxLayout(ip_parent)}
    , mp_output{new QLabel(QString("Guess the number"), ip_parent)}
    , mp_input{new QLineEdit(ip_parent)}
    , mp_button{new QPushButton(QString("O&k"),ip_parent)}
{
    m_layout->addWidget(mp_output);
    m_layout->addWidget(mp_input);
    m_layout->addWidget(mp_button);
    this->setLayout(m_layout);

    connect(mp_button, &QPushButton::clicked, this, &GuessTheNumberWindow::CheckNumber);
}

int GuessTheNumberWindow::GenerateNumber()
{
    std::srand(unsigned(std::time(nullptr)));
    return std::rand() % 3 + 1;
}

void GuessTheNumberWindow::CheckNumber()
{
    int num = GenerateNumber();
    if (num == mp_input->text().toInt())
    {
        QMessageBox::information(this, "", "good");
    } else {
        QMessageBox::information(this, "", "bad");
    }
}
