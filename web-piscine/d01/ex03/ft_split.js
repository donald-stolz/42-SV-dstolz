function ft_split(str) {
  return str
    .split(" ")
    .filter(word => word.length >= 1)
    .sort();
}
