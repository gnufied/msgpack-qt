#include "mainwindow.h"
#include <QApplication>

#include "msgpack.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::vector<std::string> target;
    target.push_back("hello");
    target.push_back("world");

    msgpack::sbuffer sbuf;
    msgpack::pack(&sbuf, target);

    msgpack::unpacked msg;
    msgpack::unpack(&msg, sbuf.data(), sbuf.size());

    msgpack::object obj = msg.get();

    w.show();

    return a.exec();
}
