#ifndef DISKWRITER_UNIX_H
#define DISKWRITER_UNIX_H

#include "diskwriter.h"
#include <QFile>

class DiskWriter_unix : public DiskWriter
{
    Q_OBJECT
public:
    explicit DiskWriter_unix(QObject *parent = 0);
    ~DiskWriter_unix();


public slots:
    bool writeCompressedImageToRemovableDevice(const QString &filename, const QString& device);
    void cancelWrite();

private:
    QFile dev;

    bool open(const QString &device);
    void close();
    bool isOpen();
};

#endif // DISKWRITER_UNIX_H
