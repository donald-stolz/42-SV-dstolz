#!/usr/local/bin/node
let journees = [
  "Lundi",
  "Mardi",
  "Mercredi",
  "Jeudi",
  "Vendredi",
  "Samedi",
  "Dimanche"
];

let mois = [
  "Janvier",
  "Fevrier",
  "Mars",
  "Avril",
  "Mai",
  "Juin",
  "Juillet",
  "Aout",
  "Septembre",
  "Octobre",
  "Novembre",
  "Decembre"
];

const TOD_REGEX = "^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]$";

function wrong_format() {
  console.log("Wrong Format");
  process.exit();
}

if (process.argv.length == 3) {
  let dateElements = process.argv[2].split(" ");
  if (dateElements.length != 5) {
    wrong_format();
  }
  if (journees.indexOf(dateElements[0]) == -1) {
    // Check lowercase
    journees.forEach((element, index) => {
      journees[index] = element.toLowerCase();
    });
    if (journees.indexOf(dateElements[0]) == -1) {
      wrong_format();
    }
  }
  // Check day 2 chars
  if (dateElements[1].length != 2) {
    wrong_format();
  }
  // Check valid month
  if (mois.indexOf(dateElements[2]) == -1) {
    // Check lowercase
    mois.forEach((element, index) => {
      mois[index] = element.toLowerCase();
    });
    if (mois.indexOf(dateElements[2]) == -1) {
      wrong_format();
    }
  }
  dateElements[2] = mois.indexOf(dateElements[2]);
  // Check year 4 chars
  if (dateElements[3].length != 4) {
    wrong_format();
  }
  // check hours min secs
  if (dateElements[4].length != 8 || !dateElements[4].match(TOD_REGEX)) {
    wrong_format();
  }
  // split hours min secs
  let tod = dateElements[4].split(":");
  dateElements.splice(-1, 1);
  tod.forEach(elements => {
    dateElements.push(elements);
  });
  // Create Date
  let result = Date.UTC(
    dateElements[3],
    dateElements[2],
    dateElements[1],
    dateElements[4],
    dateElements[5],
    dateElements[6]
  );
  // Log date
  console.log(result.toString().slice(0, -3));
}
