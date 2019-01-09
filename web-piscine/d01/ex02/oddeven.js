#!/usr/local/bin/node

var stdin = process.openStdin();
process.stdout.write("Enter a number: ");
stdin.addListener("data", function(answer) {
  if (!isNaN(parseFloat(answer))) {
    if (answer % 2 == 0) {
      console.log(`The number ${answer.toString().trim()} is even`);
    } else {
      console.log(`The number ${answer.toString().trim()} is odd`);
    }
  } else {
    console.log(`'${answer.toString().trim()}' is not a number`);
  }
  process.stdout.write("Enter a number: ");
});
