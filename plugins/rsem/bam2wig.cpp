#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "wiggle.h"

using namespace std;

void printUsage() {
  printf("Usage: rsem-bam2wig sorted_bam_input wig_output wiggle_name [--no-fractional-weight]\n");
  printf("sorted_bam_input\t: Input BAM format file, must be sorted\n");
  printf("wig_output\t\t: Output wiggle file's name, e.g. output.wig\n");
  printf("wiggle_name\t\t: the name of this wiggle plot\n");
  printf("--no-fractional-weight\t: If this is set, RSEM will not look for \"ZW\" tag and each alignment appeared in the BAM file has weight 1. Set this if your BAM file is not generated by RSEM. Please note that this option must be at the end of the command line.\n");
  exit(-1);
}

int main(int argc, char* argv[]) {
	if (argc < 4 || argc > 5) { printf("Number of arguments is not correct!\n"); printUsage(); }
	if (argc == 5 && strcmp(argv[4], "--no-fractional-weight")) { printf("Cannot recognize option %s!\n", argv[4]); printUsage(); }

	no_fractional_weight = (argc == 5 && !strcmp(argv[4], "--no-fractional-weight"));
	UCSCWiggleTrackWriter track_writer(argv[2], argv[3]);
	build_wiggles(argv[1], track_writer);

	return 0;
}
