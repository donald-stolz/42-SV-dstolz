#!/usr/local/bin/node

if (process.argv.length == 5) {
  let num0 = Number(process.argv[2]);
  let num1 = Number(process.argv[4]);
  let op = process.argv[3].trim();

  switch (op) {
    case "+":
      console.log(num0 + num1);
      break;
    case "-":
      console.log(num0 - num1);
      break;
    case "*":
      console.log(num0 * num1);
      break;
    case "/":
      console.log(num0 / num1);
      break;
    case "%":
      console.log(num0 % num1);
      break;
    default:
      break;
  }
}
