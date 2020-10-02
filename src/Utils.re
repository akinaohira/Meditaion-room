// fuction s (str) {
// return toString(str)
// }
let s = str => React.string(str);

let padNumber = num =>
  if (int_of_string(num) < 10) {
    "0" ++ num;
  } else {
    num;
  };

let formatTime = seconds => {
  let mins = seconds / 60;
  let secs = seconds mod 60;
  // mins convert to string_of_int and it's call padNumber;
  let minStr = mins |> string_of_int |> padNumber;
  let secStr = secs |> string_of_int |> padNumber;
  minStr ++ ":" ++ secStr;
};
