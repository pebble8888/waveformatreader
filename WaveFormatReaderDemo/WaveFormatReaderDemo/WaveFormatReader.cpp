//
//  WaveFormatReader.cpp
//
//  Copyright (c) 2014年 pebble8888. All rights reserved.
//

#include "WaveFormatReader.h"
#include <stdio.h>
#include <string.h>

long WaveFormatReader::little_endian32bit( void* abuf )
{
    unsigned char* buf = (unsigned char*)abuf;
    long val = 0;
    val += (long)(buf[0]);
    val += (long)(buf[1] << 8);
    val += (long)(buf[2] << 16);
    val += (long)(buf[3] << 24);
    return val;
}

WaveFormatReader::WaveFormatReader()
{
}
WaveFormatReader::~WaveFormatReader()
{
    
}
void WaveFormatReader::readWithFullPath(const char* fullpath)
{
    FILE* fp = fopen(fullpath, "rb");
    if( fp == NULL ){
        printf( "can't read this file[%s]\n", fullpath );
        return;
    }
    
    unsigned char buf[12];
    size_t read_count;
    while( true ){
        read_count = fread(buf, 12, 1, fp );
        if( read_count == 0 ) break;
        
        if( memcmp( buf, "RIFF", 4 ) != 0 ){
            printf( "not wave file\n" );
            break;
        }
        if( memcmp( &buf[8], "WAVE", 4 ) != 0 ){
            printf( "not wave file\n" );
            break;
        }
    
        while( !ferror(fp) ){
    
            read_count = fread(buf, 8, 1, fp);
            if( read_count == 0 ) break;
            
            printf( "[" );
            for( int i = 0; i < 4; ++i ){
                printf( "%c", buf[i] );
            }
            printf( "]" );
            long chunk_size = little_endian32bit(&buf[4]);
            printf( "chunk_size[%ld]\n", chunk_size );
            
            fseek(fp, chunk_size, SEEK_CUR);
        }
        break;
    }
    fclose(fp);
}
