//Copyrigth (C) 2019 Andrey Yaromenok
#include "yissueparse.h"
#include "yissue.h"
#include "../utils/yutils.h"
#include <QtCore>

YIssueParse::YIssueParse(QObject *parent) : QObject(parent)
{

}

YIssueParse::~YIssueParse()
{

}

bool
YIssueParse::parseIssue(const QJsonArray &ja, QList<YIssue*> &il,
                        QList<YUser*> &ul,QList<YMilestone*> &ml)
{
    for (int i=0; i< ja.size(); ++i){
        YIssue* issue = new YIssue();
        QJsonObject jo = ja[i].toObject();
        if (jo.contains("id"))         {
            issue->setId(jo["id"].toInt());
            issue->setObjectName(QString::number(jo["id"].toInt()));
        }
        if (jo.contains("iid"))        { issue->setIid(jo["iid"].toInt()); }
        if (jo.contains("project_id")) { issue->setProjectId(jo["project_id"].toInt()); }
        if (jo.contains("title"))      { issue->setTitle(jo["title"].toString()); }
        if (jo.contains("description")){ issue->setDescr(jo["description"].toString()); }
        if (jo.contains("state"))      { issue->setState(jo["state"].toString().contains("open")?1:0); }
        if (jo.contains("created_at")) { issue->setCreatedAt(YUtils::timeStrToInt64(jo["created_at"].toString())); }
        if (jo.contains("updated_at")) { issue->setUpdatedAt(YUtils::timeStrToInt64(jo["updated_at"].toString())); }
        if (jo.contains("closed_at"))  { issue->setClosedAt(YUtils::timeStrToInt64(jo["closed_at"].toString())); }

        if (jo.contains("time_stats")){
            QJsonObject jtime = jo["time_stats"].toObject();
            if (jtime.contains("time_estimate")){
                issue->setTimeEst(jtime["time_estimate"].toInt());
            }
            if (jtime.contains("time_spend")){
                issue->setTimeSpend(jtime["time_spend"].toInt());
            }
        }
        if (jo.contains("weight"))       { issue->setWeight(jo["weight"].toInt()); }

        if (jo.contains("author")){
            QJsonObject jauthor = jo["author"].toObject();
            if (jauthor.contains("id")){
                issue->setAuthorId(jauthor["id"].toInt());
                bool userNotExist = true;
                if (!ul.empty()){
                     for (int i = 0; i<ul.size(); ++i){
                         if (ul.at(i)->getId() == issue->getAuthorId()){
                             userNotExist = false;
                         }
                     }
                }
                if (userNotExist){
                    YUser* user = new YUser();
                    user->setId(jauthor["id"].toInt());
                    if (jauthor.contains("name")){user->setName(jauthor["name"].toString());}
                    if (jauthor.contains("username")){user->setUserName(jauthor["username"].toString());}
                    if (jauthor.contains("state")){user->setState(jauthor["state"].toString()=="active"?1:0);}
                    if (jauthor.contains("avatar_url")){user->setAvatarUrl(jauthor["avatar_url"].toString());}
                    if (jauthor.contains("web_url")){user->setWebUrl(jauthor["web_url"].toString());}
                    ul.append(user);
                }
            }
        }

        if (jo.contains("milestone")){
            QJsonObject jml = jo["milestone"].toObject();
            if (jml.contains("id")){
                issue->setMilestoneId(jml["id"].toInt());
                bool mlNotExist = true;
                if (!ml.empty()){
                     for (int i = 0; i<ml.size(); ++i){
                         if (ml.at(i)->getId() == issue->getMilestoneId()){
                             mlNotExist = false;
                         }
                     }
                }
                if (mlNotExist){
                    YMilestone* milestone = new YMilestone();
                    milestone->setId(jml["id"].toInt());
                    if (jml.contains("iid")){milestone->setIid(jml["iid"].toInt());}
                    if (jml.contains("project_id")){milestone->setProjectId(jml["project_id"].toInt());}
                    if (jml.contains("state")){milestone->setState(jml["state"].toString()=="active"?1:0);}
                    if (jml.contains("title")){milestone->setTitle(jml["title"].toString());}
                    if (jml.contains("description")){milestone->setDescr(jml["description"].toString());}
                    if (jml.contains("web_url")){milestone->setWebUrl(jml["web_url"].toString());}
                    if (jml.contains("created_at")){YUtils::timeStrToInt64(jml["created_at"].toString());}
                    if (jml.contains("updated_at")){YUtils::timeStrToInt64(jml["updated_at"].toString());}
                    if (jml.contains("due_date")){YUtils::dateStrToInt64(jml["due_date"].toString());}
                    if (jml.contains("start_date")){YUtils::dateStrToInt64(jml["start_date"].toString());}
                    ml.append(milestone);
                }
            }
        }

        il.append(issue);
    }
    return true;
}
