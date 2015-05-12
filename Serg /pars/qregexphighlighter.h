#ifndef QREGEXPHIGHLIGHTER_H
#define QREGEXPHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class QRegexpHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit QRegexpHighlighter(QObject *parent = 0);
    void highlightBlock(const QString &text);
    void setPattern(QString str ){
        pattern=str;
    }
private:
    QString pattern;
signals:

public slots:

};

#endif // QREGEXPHIGHLIGHTER_H
