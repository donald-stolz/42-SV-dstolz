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

/*
 * Check number of args
 * Split array
 * Check correct number of elements
 * Check valid day of week
 *  - Check lowercase
 * Check day 2 chars
 * Check valid month
 *  - Check lowercase
 * Assign month index
 * Check year 4 chars
 * Check hours min secs
 * Split hours min secs
 * Add hours, min, secs to array
 * Create Date
 * Log date string with proper percision
 */

if (process.argv.length == 3) {
  let dateElements = process.argv[2].split(" ");
  if (dateElements.length != 5) {
    wrong_format();
  }
  if (journees.indexOf(dateElements[0]) == -1) {
    journees.forEach((element, index) => {
      journees[index] = element.toLowerCase();
    });
    if (journees.indexOf(dateElements[0]) == -1) {
      wrong_format();
    }
  }
  if (dateElements[1].length != 2) {
    wrong_format();
  }
  if (mois.indexOf(dateElements[2]) == -1) {
    mois.forEach((element, index) => {
      mois[index] = element.toLowerCase();
    });
    if (mois.indexOf(dateElements[2]) == -1) {
      wrong_format();
    }
  }
  dateElements[2] = mois.indexOf(dateElements[2]);
  if (dateElements[3].length != 4) {
    wrong_format();
  }
  if (dateElements[4].length != 8 || !dateElements[4].match(TOD_REGEX)) {
    wrong_format();
  }
  let tod = dateElements[4].split(":");
  dateElements.splice(-1, 1);
  tod.forEach(elements => {
    dateElements.push(elements);
  });
  let result = Date.UTC(
    dateElements[3],
    dateElements[2],
    dateElements[1],
    dateElements[4],
    dateElements[5],
    dateElements[6]
  );
  console.log(result.toString().slice(0, -3));
}
