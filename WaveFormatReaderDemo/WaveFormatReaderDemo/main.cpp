//
//  main.c
//  WaveFormatReaderDemo
//
//  Created by pebble8888 on 2014/04/06.
//  Copyright (c) 2014年 pebble8888. All rights reserved.
//

#include <stdio.h>
#include "WaveFormatReader.h"

int main(int argc, const char * argv[])
{
    WaveFormatReader reader;
    reader.readWithFullPath("/Users/pebble8888/hoge.wav");

    return 0;
}

