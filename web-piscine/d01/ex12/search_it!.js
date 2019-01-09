#!/usr/local/bin/node
const argvLen = process.argv.length;
if (argvLen > 3) {
  let val;
  let key = process.argv[2].toString().trim();
  let i = 3;
  while (i < argvLen) {
    let current = process.argv[i];
    let cIndex = current.toString().indexOf(":");
    let tKey = current.substring(0, cIndex);
    if (key.localeCompare(tKey) == 0) {
      val = current.substring(cIndex + 1, current.length);
    }
    i++;
  }
  if (val) {
    console.log(val);
  }
}

// let cIndex = current.toString().indexOf(":");
// let tKey = current.substring(0, cIndex);
// console.log("temp " + tKey);

// if (key.localeCompare(tKey)) {
//   console.log(current.substring(cIndex + 1, current.length));
// }
// i++;
