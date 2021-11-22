#include "clickfield.h"

ClickField::ClickField(QWidget* parent): QPushButton(parent)
{
    setStyleSheet("background-color: black;"
                  "border: none;"
                  "font-weight: bold;"
                  "color:white;"
                  "font-size:40px;"
                  "margin:0;"
                  "padding-top:10px;"
                  "padding-bottom:10px;");

    QSizePolicy size;
    size.setHorizontalPolicy(QSizePolicy::Expanding);
    size.setVerticalPolicy(QSizePolicy::Expanding);
    this->setSizePolicy(size);

    connect(this, &QAbstractButton::clicked, this, &ClickField::changeValue);

    m_currentValue = "*";
}

QString ClickField::getValue()
{
    return m_currentValue;
}

void ClickField::setTextField(QString text)
{
    this->setText(text);
    m_currentValue = "*";
}

void ClickField::setChangedValue(QString* value)
{
    m_value = value;
}

void ClickField::setIndex(int index)
{
    m_index = index;
}

void ClickField::changeValue()
{
    if(m_currentValue == "*")
    {
        this->setText(*m_value);
        m_currentValue = *m_value;
        *m_value = (*m_value == "X"?"O":"X");

        emit pressedButtonField();
    }
}
