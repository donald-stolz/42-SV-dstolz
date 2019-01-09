#!/usr/local/bin/node
function ft_split(str) {
  return str
    .split(" ")
    .filter(word => word.length >= 1)
    .sort();
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
  result.sort();
  result.forEach(element => {
    console.log(element);
  });
}
