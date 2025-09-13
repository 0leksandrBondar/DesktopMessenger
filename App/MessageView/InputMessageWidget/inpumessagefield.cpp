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

    auto* inputFieldLayout = new QVBoxLayout(this);
    auto* sendButtonLayout = new QVBoxLayout(this);
    auto* fileButtonLayout = new QVBoxLayout(this);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    sendButtonLayout->setSpacing(0);
    sendButtonLayout->setContentsMargins(0, 0, 0, 0);

    fileButtonLayout->setSpacing(0);
    fileButtonLayout->setContentsMargins(0, 0, 0, 0);

    inputFieldLayout->setSpacing(0);
    inputFieldLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->setAlignment(Qt::AlignBottom);
    sendButtonLayout->setAlignment(Qt::AlignBottom);
    fileButtonLayout->setAlignment(Qt::AlignBottom);
    inputFieldLayout->setAlignment(Qt::AlignBottom);

    sendButtonLayout->addWidget(_sendButton);
    fileButtonLayout->addWidget(_fileExplorerButton);
    inputFieldLayout->addWidget(_inputField);

    mainLayout->addLayout(fileButtonLayout);
    mainLayout->addLayout(inputFieldLayout);
    mainLayout->addLayout(sendButtonLayout);

    setLayout(mainLayout);

    setStyleSheet("background-color: black; color: white;");

    setFixedHeight(40);
    _sendButton->setFixedHeight(40);
    _fileExplorerButton->setFixedHeight(40);

    _inputField->setFontPointSize(14);
    _inputField->setPlaceholderText("Write a message...");
    _inputField->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _inputField->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void InputMessageField::autoResizeWidget()
{
    const auto contentHeight = _inputField->document()->size();
    qDebug() << contentHeight;
    if (contentHeight.height() <= 300)
        setFixedHeight(contentHeight.height());
    if (contentHeight.height() <= 40)
        setFixedHeight(40);

    _inputField->setFontPointSize(14); // TODO: shoudl be removed - fix it
}
