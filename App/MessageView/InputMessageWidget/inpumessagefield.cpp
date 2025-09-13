#include "inpumessagefield.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>

InputMessageField::InputMessageField(QWidget* parent)
    : QWidget(parent),
      _inputField{ new QTextEdit(this) },
      _sendButton{ new QPushButton("Send", this) },
      _fileExplorerButton{ new QPushButton("...", this) }
{
    setupUi();
    connect(_inputField, &QTextEdit::textChanged, this, &InputMessageField::autoResizeWidget);
}

void InputMessageField::setupUi()
{
    auto* mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    auto* fileButtonLayout = new QVBoxLayout();
    fileButtonLayout->setContentsMargins(0, 0, 0, 0);
    fileButtonLayout->addWidget(_fileExplorerButton);
    fileButtonLayout->setAlignment(Qt::AlignBottom);

    auto* sendButtonLayout = new QVBoxLayout();
    sendButtonLayout->setContentsMargins(0, 0, 0, 0);
    sendButtonLayout->addWidget(_sendButton);
    sendButtonLayout->setAlignment(Qt::AlignBottom);

    auto* inputFieldLayout = new QVBoxLayout();
    inputFieldLayout->setContentsMargins(0, 0, 0, 0);
    inputFieldLayout->addWidget(_inputField, 1);
    inputFieldLayout->setAlignment(Qt::AlignBottom);

    mainLayout->addLayout(fileButtonLayout);
    mainLayout->addLayout(inputFieldLayout, 1);
    mainLayout->addLayout(sendButtonLayout);

    setLayout(mainLayout);

    setStyleSheet("background-color: black; color: white;");

    _sendButton->setFixedHeight(40);
    _fileExplorerButton->setFixedHeight(40);

    QFont font;
    font.setPointSize(14);
    _inputField->setFont(font);
    _inputField->setFontPointSize(14);
    _inputField->setPlaceholderText("Write a message...");
    _inputField->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _inputField->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedHeight(40);
}

void InputMessageField::autoResizeWidget()
{
    int docHeight = static_cast<int>(_inputField->document()->size().height());

    if (docHeight > 300)
        docHeight = 300;
    if (docHeight < 40)
        docHeight = 40;

    setFixedHeight(docHeight);
}
