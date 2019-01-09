#!/usr/local/bin/node
function ft_split(str) {
  return str
    .split(" ")
    .filter(word => word.length >= 1)
    .sort();
}

function ft_sort_function(a, b) {
  let i = 0;
  while (a[i] && a[i] == b[i]) i++;
  if (Number(a[i]) && !Number(b[i])) {
    return 1;
  }
  if (!Number(a[i]) && Number(b[i])) {
    return -1;
  }
  return a.localeCompare(b);
}

if (process.argv.length >= 3) {
  let array = process.argv;
  let result = [];
  array.splice(0, 2);
  array.forEach(element => {
    let temp = ft_split(element);
    temp.forEach(element => {
      result.push(element);
    });
  });
  result.sort(ft_sort_function);
  result.forEach(element => {
    console.log(element);
  });
}
