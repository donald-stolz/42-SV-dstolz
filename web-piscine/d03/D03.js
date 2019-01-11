const express = require("express");
const app = express();
const port = 8100;

app.get("/", (req, res) => res.send("Hello World!"));

app.get("/ex01", (req, res) => res.send(process.env));

app.get("/ex02/:string", (req, res) => {
  let { originalUrl } = req;
  let start = originalUrl.indexOf("?");
  start++;
  let result = originalUrl.slice(start).split("&");
  result.forEach(element => {
    console.log(element.replace("=", ": "));
  });
  res.send(result);
});

app.listen(port, () =>
  console.log(`D03 listening at http://localhost:${port}`)
);
