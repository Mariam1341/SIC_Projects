quick_sort(array, start, end)
{
  if(start<end)
  {
    pivot_index = partition(array, start, end);
    quick_sort(array, start, pivot_index-1);
    quick_sort(array, pivot_index+1, end);
  }
}

