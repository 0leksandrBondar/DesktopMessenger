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

#include "clientssidebar.h"

#include "clientslistwidget.h"
#include "clientssearchbar.h"

#include <QHBoxLayout>

ClientsSidebar::ClientsSidebar(QWidget* parent)
    : QWidget(parent),
      _clientsSearchBar{ new ClientsSearchBar() },
      _clientListWidget{ new ClientsListWidget() }
{
    setupDebugUI();
    setupConnections();
}

void ClientsSidebar::setupDebugUI()
{
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    layout->addWidget(_clientsSearchBar, 65);
    layout->addWidget(_clientListWidget, 35);

    setLayout(layout);

    _clientListWidget->addClient("Alice");
    _clientListWidget->addClient("Bob");
    _clientListWidget->addClient("Martin");
    _clientListWidget->addClient("Taras");
    _clientListWidget->addClient("Valerii");
    _clientListWidget->addClient("Daniil");
    _clientListWidget->addClient("Maksim");
}

void ClientsSidebar::setupConnections()
{
    connect(_clientsSearchBar, &ClientsSearchBar::filterChanged, this,
            &ClientsSidebar::onFilterChanged);
}

void ClientsSidebar::onFilterChanged(const QString& text) { _clientListWidget->filterList(text); }
