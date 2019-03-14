/************************************************************************

    efmprocess.h

    ld-process-efm - EFM data decoder
    Copyright (C) 2019 Simon Inns

    This file is part of ld-decode-tools.

    ld-process-efm is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

************************************************************************/

#ifndef EFMPROCESS_H
#define EFMPROCESS_H

#include <QCoreApplication>
#include <QDebug>
#include <QFile>

#include "f3frame.h"
#include "f2frame.h"
#include "section.h"
#include "efmtof3frames.h"
#include "f3tof2frames.h"
#include "f3tosections.h"
#include "f2framestoaudio.h"

class EfmProcess
{
public:
    EfmProcess();

    bool process(QString inputFilename, QString outputFilename, bool verboseDebug);

private:
    QFile *inputFileHandle;

    EfmToF3Frames efmToF3Frames;
    F3ToF2Frames f3ToF2Frames;
    F3ToSections f3ToSections;
    F2FramesToAudio f2FramesToAudio;

    qint32 qMode0Count;
    qint32 qMode1Count;
    qint32 qMode2Count;
    qint32 qMode3Count;
    qint32 qMode4Count;
    qint32 qModeICount;

    void processSections(QVector<Section> sections);
    bool openInputFile(QString inputFileName);
    void closeInputFile(void);
    QByteArray readEfmData(void);
    void reportStatus(void);
};

#endif // EFMPROCESS_H
