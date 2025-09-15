// MIT License

// Copyright (c) 2025 Oleksandr

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "chatviewwidget.h"

#include <QListWidget>
#include <QVBoxLayout>

#include <UI/MessageView/MessageWidget/messagewidget.h>

ChatViewWidget::ChatViewWidget(QWidget* parent)
    : QWidget(parent), _messageList{ new QListWidget(this) }
{
    setupUi();
    addMessage(MessageData());
}

void ChatViewWidget::addMessage(const QString& msg, const bool isMyMsg)
{
    auto item = new QListWidgetItem(msg);

    QFont font = item->font();
    font.setPointSize(14);

    item->setFont(font);
    item->setSizeHint(QSize(0, 65));

    const auto hAlign = isMyMsg ? Qt::AlignRight : Qt::AlignLeft;
    item->setTextAlignment(hAlign | Qt::AlignVCenter);

    _messageList->addItem(item);
}

void ChatViewWidget::addMessage(const MessageData& msg, const bool isMyMsg)
{
    auto* item = new QListWidgetItem();
    auto* widget = new MessageWidget();

    item->setSizeHint(widget->size());
    _messageList->addItem(item);
    _messageList->setItemWidget(item, widget);
}

void ChatViewWidget::setupUi()
{
    auto* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(_messageList);
    setLayout(mainLayout);
    setStyleSheet("background-color: black;");

    addMessage("This is first text message");
    addMessage("This is second text message", false);
}
