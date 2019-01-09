#!/usr/local/bin/node
if (process.argv.length >= 3) {
  let array = process.argv[2].split(" ");
  let temp = array.shift();
  array.push(temp);

  console.log(array.join(" "));
}
