#include "calculator.h"
#include <QGridLayout>

Calculator::Calculator(QWidget *parent) : QWidget(parent),
    Operand1(""), Operand2(""), Operator(""), expression("")
{

    expr = new QLineEdit(this);
    expr->setAlignment(Qt::AlignRight);
    expr->setReadOnly(true);

    clear = new QPushButton("C", this);
    one = new QPushButton("1", this);
    two = new QPushButton("2", this);
    three = new QPushButton("3", this);
    four = new QPushButton("4", this);
    five = new QPushButton("5", this);
    six = new QPushButton("6", this);
    seven = new QPushButton("7", this);
    eight = new QPushButton("8", this);
    nine = new QPushButton("9", this);
    zero = new QPushButton("0", this);
    dot = new QPushButton(".", this);
    plus = new QPushButton("+", this);
    minus = new QPushButton("-", this);
    mul = new QPushButton("*", this);
    div = new QPushButton("/", this);
    equal = new QPushButton("=", this);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(expr, 0, 0, 1, 3);
    layout->addWidget(clear, 0, 3);
    layout->addWidget(one, 1, 0);
    layout->addWidget(two, 1, 1);
    layout->addWidget(three, 1, 2);
    layout->addWidget(four, 2, 0);
    layout->addWidget(five, 2, 1);
    layout->addWidget(six, 2, 2);
    layout->addWidget(seven, 3, 0);
    layout->addWidget(eight, 3, 1);
    layout->addWidget(nine, 3, 2);
    layout->addWidget(zero, 4, 0);
    layout->addWidget(dot, 4, 1);
    layout->addWidget(plus, 1, 3);
    layout->addWidget(minus, 2, 3);
    layout->addWidget(mul, 3, 3);
    layout->addWidget(div, 4, 3);
    layout->addWidget(equal, 4, 2);


    setLayout(layout);

    connect(clear, &QPushButton::clicked, this, &Calculator::clearClicked);
    connect(one, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(two, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(three, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(four, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(five, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(six, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(seven, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(eight, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(nine, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(zero, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(dot, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(plus, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(minus, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(mul, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(div, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(equal, &QPushButton::clicked, this, &Calculator::equalsClicked);
}

void Calculator::clearClicked()
{
    expr->clear();
    Operand1.clear();
    Operand2.clear();
    Operator.clear();
    expression.clear();
}

void Calculator::numberClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString text = button->text();
        expression += text;
        expr->setText(expression);
        if (Operator.isEmpty()) {
            Operand1 += text;
        } else {
            Operand2 += text;
        }
    }
}

void Calculator::operatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString text = button->text();
        if (!Operand1.isEmpty() && Operand2.isEmpty()) {
            expression += text;
            expr->setText(expression);
            Operator = text;
        } else if (!Operand1.isEmpty() && !Operand2.isEmpty()) {
            equalsClicked();
            expression += text;
            expr->setText(expression);
            Operator = text;
            Operand2.clear();
        }
    }
}

void Calculator::equalsClicked()
{
    if (!Operand1.isEmpty() && !Operand2.isEmpty() && !Operator.isEmpty()) {
        double result = 0.0;
        double op1 = Operand1.toDouble();
        double op2 = Operand2.toDouble();

        if (Operator == "+")
            result = op1 + op2;
        else if (Operator == "-")
            result = op1 - op2;
        else if (Operator == "*")
            result = op1 * op2;
        else if (Operator == "/") {
            if (op2 != 0)
                result = op1 / op2;
            else {
                expr->setText("Error: Division by zero");
                Operand1.clear();
                Operand2.clear();
                Operator.clear();
                expression.clear();
                return;
            }
        }

        expr->setText(QString::number(result));
        Operand1 = QString::number(result);
        expression = QString::number(result);
        Operand2.clear();
        Operator.clear();
    }
}
