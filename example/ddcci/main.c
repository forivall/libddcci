/*
    ddc/ci command line tool

    Copyright(c) 2015 Jordan J. Klassen (forivall@gmail.com)

    Some parts adapted from ddccontrol (
      Copyright(c) 2004 Oleg I. Vdovikin (oleg@cs.msu.su)
      Copyright(c) 2004-2006 Nicolas Boichat (nicolas@boichat.ch)
    )

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>

// TODO: use gettext
static inline char* _(char* s) { return s; }

static void usage(char *name) {
	fprintf(stderr,_(
		"Usage:  %s <operation> [...]\n"
		"operations\n"
    "    {-h --help}\n"
    "    {-V --version}\n"
    "    {-S --set-vcp} device code value\n"
		"    <command> [<args>]\n"
	), name);
}

static void version(void) {
	printf(_(
		"ddcci v_ - libddcci v_\n"
	));
}

int main (int argc, char* argv[]) {
	if (argc <= 1) { usage(argv[0]);; exit(1); }

  int c;
  int digit_optind = 0;
  int aopt = 0, bopt = 0;
  char *copt = 0, *dopt = 0;
  static struct option long_options[] = {
    {"help", 0, 0, 'h'},
    {"version", 0, 0, 'V'},
    {"verbose", 0, 0, 'v'},
    {"set-vcp", 0, 0, 'S'},
    {NULL, 0, NULL, 0}
  };
  int option_index = 0;
	char op = -1;
  while ((c = getopt_long(argc, argv, "-hvVS",
                          long_options, &option_index)) != -1) {
    int this_option_optind = optind ? optind : 1;
    switch (c) {
    case 'h':
      usage(argv[0]);
			exit(0);
      break;
    case 'V':
			version();
			exit(0);
      break;
    case 'v':
      break;
    case 'S':
      printf ("TODO\n");
      break;
    case '?':
			printf("unknown");
      break;
    default:
      printf ("?? getopt returned character code 0%o ??\n", c);
    }
  }
  if (optind < argc) {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
          printf ("%s ", argv[optind++]);
      printf ("\n");
  }
  exit(0);
}
