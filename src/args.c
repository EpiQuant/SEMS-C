#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "args.h"

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

void printHelp() {
	printf("\n\
SEMS-C -- Step-Wise Epistatic Model Selection in C\n\
\n\
    SEMS-C is a program developed at the National Center for Supercomputing\n\
    Applications in collaboration with the Center for Computational\n\
    Biotechnology and Genomic Medicine to map epistatic gene interactions. It\n\
    uses step-wise linear regression model selection to build a cumulative\n\
    statistical model of epistatic interactions between SNP's and phenotypes.\n\
\n\
Usage: sems-c [OPTION...] [PHENOTYPE_FILE] [SNP_FILE]\n\
\n\
Examples:\n\
\n\
    sems-c -c p=1:2:3 pheno.txt snp.txt  # Delete columns 1, 2, and 3.\n\
    sems-c -d c,t pheno.txt snp.txt      # Set delimiter to commas and tabs.\n\
    sems-c -t p,s pheno.txt snp.txt      # Tranpose data from both files.\n\
\n\
Options:\n\
\n\
    -c    Delete Columns        Signals SEMS-C to delete certain columns. These\n\
                                options should be passed in in the form:\n\
\n\
                                -c p=#:#:#,s=#:#:#\n\
\n\
                                where '#' are the columns to delete and ':'\n\
                                delimit different column numbers. By default\n\
                                no columns are deleted.\n\
\n\
    -d    File Delimiters       Asserts that the phenotype and snp file are\n\
                                delimited by the given delimiter. Expects the\n\
                                form:\n\
\n\
                                -d [c/s/t,c/s/t]\n\
\n\
                                where 'c' is comma, 's' is space, and 't' is\n\
                                tab. Allows multiple delimiters. First is for\n\
                                phenotype and second is SNP. Defaults to comma\n\
                                delimited.\n\
\n\
    -t    Transpose Data        Transpose data from phenotype and/or snp file.\n\
\n\
                                -t [p/s,p/s]\n\
\n\
\n");
}

void printUsage() {
	printf("\n\
Usage: sems-c [OPTION...] [PHENOTYPE_FILE] [SNP_FILE]\n\
\n\
Options:\n\
    [-c <pheno=...,snp=...>]    # Delete columns.\n\
    [-d <delimiter,delimiter>]  # File delimiters.\n\
    [-h]                        # Print help text.\n\
    [-t <file,file>]            # Tranpose file data.\n\
    [-u]                        # Print usage information.\n\
\n");
}

void getColumns() {

}

void getDelimiters() {

}

void getTranpose(char *arg, bool *pTrans, bool *sTrans) {
	char * token = strtok(arg, ",");
	if (*token == 'p') {
		*pTrans = true;
	}
	while ((token = strtok(NULL, ",")) != NULL) {
		if (*token == 's') {
			*sTrans = true;
		}
	}
}

void getArgs(int argc, char *argv[], bool *pTrans, bool *sTrans) {
	if (argc == 2) {
		if (strcmp(argv[1], "-h") == 0) {
					printHelp();
					exit(1);
		} else if (strcmp(argv[1], "-u") == 0) {
					printUsage();
					exit(1);
		}
	} else if (argc == 1 || argc - 2 < 0) {
		fprintf(stderr,"\
sems-c: You must at least provide a phenotype file and snp file.\n\
        Try 'sems-c -h' or 'sems-c -u' for more information.\n");
		exit(1);
	} else {
		for (int i = 1; i < argc - 2; ++i) {
			printf("%s\n", argv[i]);
			switch(argv[i][1]) {
				case 'c':
					
				case 'd':
					
				case 't':
					++i;
					getTranpose(argv[i], pTrans, sTrans);
					break;
				default:
					fprintf(stderr, "\
sems-c: An invalid option was given to sems-c.\n\
        Try 'sems-c -h' or 'sems-c -u' for more information.\n");
					exit(1);
			}
		}
	}
}
