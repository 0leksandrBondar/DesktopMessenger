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

#include "clientpage.h"
#include "ClientsSidebar/clientssidebar.h"
#include "MessageView/messageviewwidget.h"

#include <QHBoxLayout>
#include <QResizeEvent>
#include <QSplitter>

ClientPage::ClientPage(QWidget* parent)
    : QWidget(parent),
      _clientsSidebar{ new ClientsSidebar(this) },
      _messageViewWidget{ new MessageViewWidget(this) }
{
    auto* splitter = new QSplitter(Qt::Horizontal, this);
    splitter->setHandleWidth(3);

    splitter->addWidget(_clientsSidebar);
    splitter->addWidget(_messageViewWidget);

    splitter->setSizes({ 250, 600 });

    auto* layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(splitter);

    setLayout(layout);
    setStyleSheet("background-color: black;");
}

void ClientPage::resizeEvent(QResizeEvent* event)
{
    static constexpr float minWidth{ 630 };        // min width to display ClientsListWidget
    static constexpr bool isChatSelected{ false }; // temp

    QWidget* target = isChatSelected ? static_cast<QWidget*>(_clientsSidebar)
                                     : static_cast<QWidget*>(_messageViewWidget);

    const bool tooNarrow = event->size().width() <= minWidth;
    target->setVisible(!tooNarrow);
}
