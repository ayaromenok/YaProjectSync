//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUEPARSE_H
#define YISSUEPARSE_H

#include <QObject>
#include "yissue.h"
#include "yuser.h"
#include "ymilestone.h"

class YIssueParse : public QObject
{
    Q_OBJECT
public:
    explicit YIssueParse(QObject *parent = nullptr);
    ~YIssueParse();
    bool parseIssue(const QJsonArray &ja,
                    QList<YIssue*> &il,
                    QList<YUser*> &ul,
                    QList<YMilestone*> &ml);
signals:

};

#endif // YISSUEPARSE_H
