#include "messagewidget.h"

#include <QDateTime>
#include <QLabel>
#include <QVBoxLayout>

MessageWidget::MessageWidget(QWidget* parent) : QWidget(parent)
{
    setFixedWidth(_maxWidth);
    setFixedHeight(_maxHeight);
    setObjectName("MessageWidgetRoot");

    setStyleSheet(
        "#MessageWidgetRoot {"
        "  background-color: black;"
        "  border: 1px solid gray;"
        "}");
    setupUi();
}

void MessageWidget::setupUi()
{
    auto mainLayout{ new QVBoxLayout(this) };
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(1, 1, 1, 1);
    setLayout(mainLayout);

    addHeader(); // logo, sender
    addBody();   // content text/image/file ...
    addFooter(); // time
}

void MessageWidget::addHeader()
{
    const auto senderName = new QLabel("Alex");

    QFont font;
    font.setPointSize(15);
    senderName->setFont(font);

    auto headerLayout = new QVBoxLayout();
    headerLayout->setSpacing(0);
    headerLayout->addWidget(senderName);
    headerLayout->setAlignment(Qt::AlignVCenter);
    headerLayout->setContentsMargins(20, 0, 0, 0);

    auto headerWidget = new QWidget();
    headerWidget->setFixedHeight(35);
    headerWidget->setLayout(headerLayout);

    layout()->addWidget(headerWidget);
}

void MessageWidget::addBody()
{
    const auto messageBody = new QLabel(
        "This is a text tested my own message widget.  TEST TEST TEST TEST TEST TEST TEST TEST "
        "TEST TESTTEST TEST TEST TEST TESTTEST TEST TEST TEST TEST");

    QFont font;
    font.setPointSize(12);
    messageBody->setFont(font);
    messageBody->setWordWrap(true);

    auto bodyLayout = new QVBoxLayout();
    bodyLayout->addWidget(messageBody);

    auto bodyWidget = new QWidget();
    bodyWidget->setLayout(bodyLayout);

    layout()->addWidget(bodyWidget);
}

void MessageWidget::addFooter()
{
    const QString timeText = QDateTime::currentDateTime().toString("HH:mm");

    auto* timeLabel = new QLabel(timeText);
    QFont font;
    font.setPointSize(10);
    timeLabel->setFont(font);
    timeLabel->setStyleSheet("color: gray;");

    auto* footerLayout = new QHBoxLayout();
    footerLayout->setContentsMargins(0, 0, 10, 0);
    footerLayout->addStretch();
    footerLayout->addWidget(timeLabel);

    auto* footerWidget = new QWidget();
    footerWidget->setFixedHeight(20);
    footerWidget->setLayout(footerLayout);

    layout()->addWidget(footerWidget);
}
