#ifndef STREAM_H
#define STREAM_H

#include "containers/sllv.h"
#include "input/readers.h"
#include "mapping/mappers.h"
#include "output/writers.h"

// filenames must be null-terminated
int do_stream_chained(char** filenames, int use_mmap_reader, reader_t* preader, reader_mmap_t* preader_mmap,
	sllv_t* pmapper_list, writer_t* pwriter, char* ofmt);

#endif // STREAM_H
