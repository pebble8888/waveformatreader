//
//  WaveFormatReader.h
//
//  Copyright (c) 2014年 pebble8888. All rights reserved.
//

#ifndef __WaveFormatReader__
#define __WaveFormatReader__

class WaveFormatReader
{
public:
    WaveFormatReader();
    ~WaveFormatReader();
    static long little_endian32bit(void* abuf);
    static void readWithFullPath(const char* fullpath);
};

#endif /* defined(__WaveFormatReader__) */
