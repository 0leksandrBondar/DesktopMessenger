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

#include "clientssearchbar.h"

#include <QLineEdit>
#include <QVBoxLayout>

ClientsSearchBar::ClientsSearchBar(QWidget* parent)
    : QWidget(parent), _filterLine{ new QLineEdit() }
{
    setupDebugUI();
    setupConnections();
}

void ClientsSearchBar::setupDebugUI()
{
    // for widget
    auto* layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(5, 0, 5, 0);
    setFixedHeight(50);
    setLayout(layout);
    setStyleSheet("background-color: black;");

    // for _filterLine
    _filterLine->setFixedHeight(30);
    _filterLine->setPlaceholderText("Serch");
    _filterLine->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

    layout->setAlignment(Qt::AlignVCenter);
    layout->addWidget(_filterLine);
}

void ClientsSearchBar::setupConnections()
{
    connect(_filterLine, &QLineEdit::textChanged,
            [this](const QString& text) { emit filterChanged(text); });
}
