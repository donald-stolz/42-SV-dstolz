const http = require("http");
const os = require("os");
const port = 8100;
const hostname = os.hostname();

parseArgs = url => {
  let start;
  if (url.indexOf("?") > 0) {
    start = url.indexOf("?");
  } else {
    start = url.indexOf("/", 1);
  }
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
  env = env.replace(/,/g, "\n");
  res.end(env);
};

const ex02 = (req, res) => {
  let result = parseArgs(req.url);
  result = argsToJSON(result);
  result = JSON.stringify(result);
  let end = result.indexOf("}");
  result = result.substring(1, end);
  result = result.replace(/,/g, "\n");
  result = result.replace(/"/g, "");
  result = result.replace(/:/g, ": ");
  res.end(result);
};

const ex03 = (req, res) => {
  // Get args
  let args = parseArgs(req.url);
  if (args.shift() == "action=set") {
    // Set cookie in header
    res.setHeader("Set-Cookie", args);
    res.end();
  } else {
    // Return cookie values not specified in URL
    let { cookie } = req.headers;
    cookie = cookie.split(";");
    cookie = cookie.map(element => {
      return element.trim();
    });
    let result = cookie.filter(c => {
      return args.indexOf(c) == -1;
    });
    result = result.map(element => {
      let i = element.indexOf("=") + 1;
      return element.substring(i);
    });

    if (result.length > 0) {
      res.end(result.join("\n"));
    }
    res.end("\n");
  }
};

const requestHandler = (req, res) => {
  let { url } = req;
  if (url != "/favicon.ico") {
    let endIndex = url.indexOf("/", 1);
    let route = url.length > 1 && endIndex > -1 ? url.slice(0, endIndex) : url;
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
  }
};

const server = http.createServer(requestHandler);

server.listen(port, hostname, () => {
  console.log(`D03 listening at http://localhost:${port}`);
  console.log(`Server running at http://${hostname}:${port}/`);
});
