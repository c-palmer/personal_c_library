#include <stdio.h>

/* precondition: array must exist and be sorted
 * postcondition: returns 1 if val found in array in O(log(n)) time
 *                returns 0 if val not found or array does not exist
 */
int binary_search(int *array, int len, int val)
{
  if (array == NULL)
  {
    printf("error: binary_search: array is NULL\n");
    return 0;
  }

  int low = 0;
  int high = len - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (val == array[mid]) return 1;

    if (val < array[mid]) high = mid - 1;
    else if (array[mid] < val) low = mid + 1;
  }

  return 0;
}
