#include "atm.h"

int main(void)
{
  cash amounts[] = {1, 10, 39, 589, 2590, 31999};
  for (int i = 0; i < 6; i++)
  {
    cash_count notes = get_money(amounts[i]);
    display_notes(amounts[i], notes);
  }

  return 0;
}
