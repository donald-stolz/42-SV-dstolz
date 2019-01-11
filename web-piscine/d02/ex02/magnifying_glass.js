#!/usr/local/bin/node
var fs = require("fs");

const aREG = /((?:<a[\s\S]*?>)[\s\S]*?(?!(?:<\/a>))[\s\S]*?(?:<\/a>))/gim;
const titleREG = /title=(["'])(?:(?=(\\?))\2.)*?\1/gi;
const contentREG = />([^<]*)</g;
let file = process.argv[2];
let updates;
let result;

fs.readFile(file, "utf8", function(err, data) {
  let i;
  let anchors = [];
  while ((i = aREG.exec(data))) {
    anchors.push(i[0]);
  }

  anchors.forEach((tag, index, anchors) => {
    while ((i = titleREG.exec(tag))) {
      let title = i[0].slice(7, -1);

      tag = tag.replace(title, title.toUpperCase());
    }
    while ((i = contentREG.exec(tag))) {
      let content = i[0].slice(1, -1);
      tag = tag.replace(content, content.toUpperCase());
    }
    anchors[index] = tag;
  });
  i = 0;
  result = data
    .split(aREG)
    .map((element, index, array) => {
      if (index % 2 != 0) {
        return anchors[i++];
      }
      return element;
    })
    .join(" ");
  fs.writeFile(file, result, function(err) {
    if (err) {
      console.log("error");
    } else {
      console.log("success");
    }
  });
});
