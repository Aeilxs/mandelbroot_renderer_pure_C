#include <stdio.h>
#include <stdlib.h>

#include "utils/fs.h"

FILE *open(const char *filename, const char *opts) {
  FILE *file = fopen(filename, opts);
  if (file == NULL) {
    fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
    exit(EXIT_FAILURE);
  }
  return file;
}