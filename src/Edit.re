// open Utils;

[@react.component]
let make = (~value, ~onChange) =>
  <div className="input_container">
    <input
      className="change_time"
      type_="number"
      value={string_of_int(value)}
      onChange={e => e->ReactEvent.Form.target##value |> onChange}
    />
  </div>;
