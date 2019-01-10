#!/usr/local/bin/node
var fs = require("fs");

let file = process.argv[2];
let result;

fs.readFile(file, "utf8", function(err, data) {
  let aREGEX = RegExp("/<a[^>]*>([^<]+)</a>/g");
  //   console.log(data);
  console.log(data.match());
  // Search string for '>' after '<a'; toUpper next chars until '<'
  // USE REGEX
  // search for ' title=" '; toUpper next chars until ' " '
  // Assign string to result
});

// Write result to file
