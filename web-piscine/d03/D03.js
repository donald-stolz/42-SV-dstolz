const http = require("http");
const os = require("os");
const port = 8100;
const hostname = os.hostname;
let cookies = {};

parseArgs = url => {
  let start = url.indexOf("?"); // Catch if not present
  start++;
  return url.slice(start).split("&");
};

argsToJSON = args => {
  let result = {};
  args.forEach(item => {
    keyVal = item.split("=");
    result[keyVal[0]] = keyVal[1];
  });
  return result;
};

const ex00 = (req, res) => res.end("Hello World!");

const ex01 = (req, res) => {
  let env = JSON.stringify(process.env);
  console.log(env);

  res.end(env);
};

const ex02 = (req, res) => {
  let result = parseArgs(req.originalUrl);
  result.forEach(element => {
    console.log(element.replace("=", ": "));
  });
  res.end(result);
};

const ex03 = (req, res) => {
  // Get cookie from args
  let cookie = parseArgs(req.originalUrl);
  cookie = argsToJSON(cookie);

  // Set cookie in header
  res.end(req.headers);
  //   res.send(result);
};

// Works for localhosting
const requestHandler = (req, res) => {
  let { url } = req;
  let endIndex = url.indexOf("/", 1);
  let route = url.length > 1 && endIndex > -1 ? url.slice(0, endIndex) : url;
  console.log(route);

  switch (route) {
    case "/":
      ex00(req, res);
      break;
    case "/ex01":
      ex01(req, res);
      break;
    case "/ex02":
      ex02(req, res);
      break;
    case "/ex03":
      ex03(req, res);
      break;
    default:
      res.end("Page Not Found!");
      break;
  }
};

const server = http.createServer(requestHandler);

server.listen(port, hostname, () => {
  console.log(`D03 listening at http://localhost:${port}`);
  console.log(`Server running at http://${hostname}:${port}/`);
});
