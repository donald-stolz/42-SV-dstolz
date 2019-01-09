#!/usr/local/bin/node

if (process.argv.length == 3) {
  let operation = process.argv[2]
    .toString()
    .replace(/  +/g, " ") // Get rid of excess spaces
    .trim()
    .split(" ")
    .filter(word => word.length >= 1); // Get rid of empty strings

  if (operation.length != 3) {
    console.log("Syntax Error");
    return;
  }
  let num0 = Number(operation[0]);
  let num1 = Number(operation[2]);
  let op = operation[1];

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
} else {
  console.log("Incorrect Parameters");
}
