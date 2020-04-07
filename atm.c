#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int money)
{
  unsigned int note_count = 0x00000000;
  unsigned short int remaining_balance = money;
  unsigned int no_of_notes = 0;

  no_of_notes = remaining_balance / 2000;
  remaining_balance = remaining_balance % 2000;
  note_count = note_count + (0x10000000 * no_of_notes);
  return note_count;
}