#include <stdio.h>
#include "atm.h"

cash_count get_money(cash money)
{
  cash_count note_count = INITIAL_NOTE_COUNT;
  cash denominations[8] = DENOMINATIONS_LIST;
  cash remaining_money = money;
  cash_count no_of_notes = INITIAL_NOTE_COUNT;

  if (remaining_money > LIMIT)
  {
    return note_count;
  }

  EIGHT_TIMES
  {
    note_count = note_count << 4;
    no_of_notes = remaining_money / denominations[i];
    note_count = note_count | no_of_notes;
    remaining_money = remaining_money % denominations[i];
  }
  return note_count;
}

void display_notes(cash money, cash_count note_count)
{
  cash denominations[8] = DENOMINATIONS_LIST;
  printf("Denomination count: \n");
  printf("Amount: %u\n", money);
  cash_count no_of_notes = INITIAL_NOTE_COUNT;
  EIGHT_TIMES
  {
    no_of_notes = note_count & INITIAL_POSITION;
    no_of_notes = no_of_notes >> 28;
    no_of_notes &&printf("%u %s of Rs %u\n", no_of_notes, no_of_notes < 2 ? "note" : "notes", denominations[i]);
    note_count = note_count << 4;
  }
  printf("\n");
}