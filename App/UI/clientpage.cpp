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
#include <QLabel>
#include <QResizeEvent>
#include <QSplitter>

ClientPage::ClientPage(QWidget* parent)
    : QWidget(parent),
      _hSplitter{ new QSplitter(Qt::Horizontal, this) },
      _clientsSidebar{ new ClientsSidebar(this) },
      _emptyMessageViewWidget{ new QWidget(this) },
      _messageViewWidget{ new MessageViewWidget(this) }
{
    setupEmptyMessageViewWidget();

    _hSplitter->setHandleWidth(3);
    _hSplitter->addWidget(_clientsSidebar);
    _hSplitter->addWidget(_messageViewWidget);

    _hSplitter->setSizes({ 250, 600 });

    auto* layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(_hSplitter);

    setStyleSheet("background-color: black;");
    setupConnections();

    switchMessageViewWidget();
}

void ClientPage::setupConnections()
{
    connect(_clientsSidebar, &ClientsSidebar::chatSelected, _messageViewWidget,
            &MessageViewWidget::updateChat);

    connect(_clientsSidebar, &ClientsSidebar::chatSelected,
            [this]()
            {
                const bool isChatSelected = _clientsSidebar->isChatSelected();

                switchMessageViewWidget();
                if (_messageViewWidget->isHidden() && isChatSelected)
                {
                    _clientsSidebar->hide();
                    _messageViewWidget->show();
                }
                if (!_clientsSidebar->isVisible() && !isChatSelected)
                {
                    _clientsSidebar->show();
                }
            });
}

void ClientPage::setupEmptyMessageViewWidget() const
{
    auto* layout = new QVBoxLayout(_emptyMessageViewWidget);

    const auto label = new QLabel("Select a chat to start messaging");
    layout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    layout->addWidget(label);
    _emptyMessageViewWidget->setLayout(layout);
}

void ClientPage::switchMessageViewWidget() const
{
    const QWidget* currentRightWidget = _hSplitter->widget(1);
    QWidget* newRightWidget = _clientsSidebar->isChatSelected()
                                  ? static_cast<QWidget*>(_messageViewWidget)
                                  : static_cast<QWidget*>(_emptyMessageViewWidget);

    if (currentRightWidget != newRightWidget)
        _hSplitter->replaceWidget(1, newRightWidget);

    _hSplitter->setStretchFactor(0, 1);
    _hSplitter->setStretchFactor(1, 1);
}

void ClientPage::resizeEvent(QResizeEvent* event)
{
    static constexpr float minWidth{ 630 }; // min width to display ClientsListWidget

    QWidget* targetMessageViewWidget = _clientsSidebar->isChatSelected()
                                           ? static_cast<QWidget*>(_messageViewWidget)
                                           : static_cast<QWidget*>(_emptyMessageViewWidget);

    QWidget* target = _clientsSidebar->isChatSelected() ? static_cast<QWidget*>(_clientsSidebar)
                                                        : targetMessageViewWidget;

    const bool tooNarrow = event->size().width() <= minWidth;
    target->setVisible(!tooNarrow);
}

void ClientPage::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
        _clientsSidebar->resetChatSelection();
}
