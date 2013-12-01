#ifndef DISKWRITER_H
#define DISKWRITER_H

#include <QObject>
#include <QString>
#include <QStringList>

class DiskWriter : public QObject
{
    Q_OBJECT

public:
    DiskWriter(QObject *parent = 0) : QObject(parent) {}
    virtual ~DiskWriter() {}

public slots:
    virtual void cancelWrite() = 0;
    virtual bool writeCompressedImageToRemovableDevice(const QString &filename, const QString& device) = 0;

signals:
    void bytesWritten(int);

protected:
    bool isCancelled;

    virtual bool open(const QString& device) = 0;
    virtual void close() = 0;
    virtual bool isOpen() = 0;
};

#endif // DISKWRITER_H
