#include "messagewidget.h"

#include <QDateTime>
#include <QLabel>
#include <QVBoxLayout>

MessageWidget::MessageWidget(QWidget* parent) : QWidget(parent)
{
    setMaximumSize(_maxWidth, _maxHeight);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
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
    font.setBold(true);
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
        "Текст, в своем роде, состоит из некоторого количества предложений. Одно предложение, даже "
        "очень распространённое, сложное, текстом назвать нельзя, поскольку текст можно разделить "
        "на самостоятельные предложения, а части предложения сочетаются по законам синтаксиса "
        "сложного предложения, но не текста. Главный тезис — текст состоит из двух или более "
        "предложений. Смысловая цельность текста В смысловой цельности текста отражаются те связи "
        "и зависимости, которые имеются в самой действительности (общественные события, явления "
        "природы, человек, его внешний облик и внутренний мир, предметы неживой природы и т. д.). "
        "Единство предмета речи — это тема высказывания. Тема — это смысловое ядро текста, "
        "конденсированное и обобщённое содержание текста.Понятие «содержание высказывания» связано "
        "с категорией информативности речи и присуще только тексту. Оно сообщает читателю "
        "индивидуально-авторское понимание отношений между явлениями, их значимости во всех сферах "
        "придают ему смысловую цельность. В большом тексте ведущая тема распадается на ряд "
        "составляющих подтем  подтемы членятся на более дробные, на абзацы (микротемы). "
        "Завершённость высказывания связана со смысловой цельностью текста. Показателем "
        "законченности текста является возможность подобрать к нему заголовок, отражающий его "
        "содержание. Таким образом, из смысловой цельности текста вытекают следующие признаки "
        "текста");

    QFont font;
    font.setPointSize(12);
    messageBody->setFont(font);
    messageBody->setWordWrap(true);
    messageBody->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    messageBody->setMaximumWidth(_maxWidth);
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

QSize MessageWidget::sizeHint() const
{
    QSize s = QWidget::sizeHint();
    if (s.height() > _maxHeight)
        s.setHeight(_maxHeight);
    if (s.width() > _maxWidth)
        s.setWidth(_maxWidth);
    return s;
}
