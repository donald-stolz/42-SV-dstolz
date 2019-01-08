#!/usr/local/bin/node
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

var recursiveAsyncReadLine = function() {
  rl.question("Enter a number: ", answer => {
    if (Number(answer)) {
      if (answer % 2 == 0) {
        console.log(`The number ${answer} is even`);
      } else {
        console.log(`The number ${answer} is odd`);
      }
    } else {
      console.log(`'${answer}' is not a number`);
    }
    recursiveAsyncReadLine();
  });
};

recursiveAsyncReadLine();
