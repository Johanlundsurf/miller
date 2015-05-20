#ifndef MLRCLI_H
#define MLRCLI_H

#include "containers/sllv.h"
#include "input/reader.h"
#include "input/reader_mmap.h"
#include "mapping/mapper.h"
#include "output/writer.h"

typedef struct _cli_opts_t {
	char irs;
	char ifs;
	char ips;
	int  allow_repeat_ifs;

	char ors;
	char ofs;
	char ops;

	char* ofmt;

	int            use_mmap_reader;
	reader_t*      preader;
	reader_mmap_t* preader_mmap;
	sllv_t*        pmapper_list;
	writer_t*      pwriter;

	char** filenames; // null-terminated

} cli_opts_t;

cli_opts_t* parse_command_line(int argc, char** argv);
void cli_opts_free(cli_opts_t* popts);

#endif // MLRCLI_H
