#include "qregexphighlighter.h"
#include <QTextCharFormat>
QRegexpHighlighter::QRegexpHighlighter(QObject *parent) :
    QSyntaxHighlighter(parent)
{
}

void QRegexpHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat format;
    QRegExp rx(pattern);
    if (!rx.isValid()||rx.isEmpty()||rx.exactMatch("")){
        setDocument();
        setFormat(0,text.length(),format);
        return;
    }
    format.setBackground(Qt::yellow);
    int index=rx.indexIn(text);
    while (index>=0){
        int length=rx.matchedLength();
        setFormat(index,length,format);
        index=rx.indexIn(text,index+length);
    }
}
