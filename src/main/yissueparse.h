//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUEPARSE_H
#define YISSUEPARSE_H

#include <QObject>
#include "yissue.h"

class YIssueParse : public QObject
{
    Q_OBJECT
public:
    explicit YIssueParse(QObject *parent = nullptr);
    ~YIssueParse();
    bool parseIssue(const QJsonArray &ja, QList<YIssue*> &il);
signals:

};

#endif // YISSUEPARSE_H
