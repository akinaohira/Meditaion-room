open Utils;

[@react.component]
let make = (~seconds) =>
  <div className="timer">
    <span id="base-timer-label" className="base-timer__label">
      {seconds |> formatTime |> s}
    </span>
  </div>;
