#!/usr/local/bin/node
var fs = require("fs");
const whoFile = "/var/run/utmpx";
fs.readFile(whoFile, "utf-8", function(err, data) {
  console.log(data);
});
