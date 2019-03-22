/**
 * @brief
 *
 * @file link.c
 * @authors Victor Perea
 * @version 1.0
 * @date 15/03/2019
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

struct _Link{
  Id id;
  char name[WORD_SIZE + 1];
  Id id[2];
  BOOL state;
}
