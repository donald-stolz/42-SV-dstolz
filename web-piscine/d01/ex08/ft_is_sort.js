function ft_is_sort(array) {
  return array.every((item, index, array) => {
    if (index + 1 < array.length) {
      return item <= array[index + 1];
    }
    return true;
  });
}
// Array.prototype.isSorted = ft_is_sort
