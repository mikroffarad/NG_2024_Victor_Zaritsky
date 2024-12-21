#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket();
    m_thread = new QThread(this);
    m_socket->moveToThread(m_thread);
    m_thread->start();

    ui->sb_port->setRange(0, 16535);

    ui->pte_chat->setReadOnly(true);

    connect (ui->b_connect, &QPushButton::clicked, this, &Client::joinChat);
    connect (ui->b_send, &QPushButton::clicked, this, &Client::sendMessage);
    connect (m_socket, &QTcpSocket::connected, this, &Client::joined);
    connect (m_socket, &QTcpSocket::disconnected, this, &Client::kicked);
    connect (m_socket, &QTcpSocket::readyRead, this, &Client::gotMessage);
}

Client::~Client() {
    m_socket->disconnect();
    delete m_socket;
    delete ui;
}

void Client::joinChat() {
    m_socket->connectToHost(QHostAddress(ui->le_ip->text()), ui->sb_port->value());
}

void Client::joined() {
    ui->stackedWidget->setCurrentIndex(1);
    ui->statusbar->showMessage("You successfully joined the server!");
    m_socket->write(m_loginKey + ui->le_login->text().toUtf8());
}

void Client::kicked() {
    ui->stackedWidget->setCurrentIndex(0);
    ui->statusbar->showMessage("You're been kicked!");
}

void Client::sendMessage() {
    m_socket->write(ui->pte_message->toPlainText().toUtf8());
    ui->pte_message->clear();
}

void Client::gotMessage() {
    QByteArray message = m_socket->readAll();
    if (message.indexOf(m_userListKey) == 0) {
        // Если это сообщение со списком пользователей
        message.remove(0, m_userListKey.size());
        updateUserList(message);
    } else {
        // Если это обычное сообщение
        ui->pte_chat->setPlainText(ui->pte_chat->toPlainText() + QString(message + "\n"));
    }
}

void Client::updateUserList(const QByteArray &userList) {
    ui->lw_members->clear();
    QList<QByteArray> users = userList.split(';');
    for (const QByteArray& user : users) {
        if (!user.isEmpty()) {
            ui->lw_members->addItem(QString(user));
        }
    }
}
