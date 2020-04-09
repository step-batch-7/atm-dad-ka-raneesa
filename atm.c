#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int money)
{
  unsigned int note_count = INITIAL_NOTE_COUNT;
  unsigned short int denominations[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned short int remaining_money = money;
  unsigned int no_of_notes = 0;

  if (remaining_money > LIMIT)
  {
    return note_count;
  }

  for (int index = 0; index < 8; index++)
  {
    note_count = note_count << 4;
    no_of_notes = remaining_money / denominations[index];
    note_count = note_count | no_of_notes;
    remaining_money = remaining_money % denominations[index];
  }
  return note_count;
}

void display_notes(unsigned short int money, unsigned int note_count)
{
  unsigned short int denominations[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  printf("Denomination count: \n");
  printf("Amount: %u\n", money);
  unsigned int no_of_notes = 0;
  for (int index = 0; index < 8; index++)
  {
    no_of_notes = note_count & INITIAL_POSITION;
    no_of_notes = no_of_notes >> 28;
    no_of_notes &&printf("%u %s of Rs %u\n", no_of_notes, no_of_notes < 2 ? "note" : "notes", denominations[index]);
    note_count = note_count << 4;
  }
  printf("\n");
}