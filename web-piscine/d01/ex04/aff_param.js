#!/usr/local/bin/node
for (let index = 2; index < process.argv.length; index++) {
  const element = process.argv[index];
  console.log(element);
}
