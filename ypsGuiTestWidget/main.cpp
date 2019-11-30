//Copyrigth (C) 2019 Andrey Yaromenok
#include "../src/main/yproject.h"

#include "../src/test/ymaintestwindow.h"
#include "../src/test/yissuelistw.h"

#include <QtCore>
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Andrey Yaromenok");
    QCoreApplication::setOrganizationDomain("yaromenok.info");
    QCoreApplication::setApplicationName("YaProjectSync");

    qInfo() << QCoreApplication::applicationName();
    YProject prj;

    YMainTestWindow w;
    QLabel *l1 = new QLabel("label 1");
    l1->setObjectName("lb1");
    w.addTab(l1);
    YIssueListW *il = new YIssueListW();
    w.addTab(il);
    w.show();
    return a.exec();
}
