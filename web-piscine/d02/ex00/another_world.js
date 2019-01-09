#!/usr/local/bin/node
if (process.argv.length >= 3) {
  console.log(process.argv[2].replace(/  +/g, " ").trim());
}
