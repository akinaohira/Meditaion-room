open State;
// open State is allow us to use function and element out side of file.

// "make" is Js version of default export
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initalState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div>
    <Animations on={state.isTicking} />
    <Timer seconds={state.seconds} />
    <div className="button_container">
      <button className="btn fa fa-stop" onClick={_ => dispatch(Stop)} />
      <button className="btn fa fa-play" onClick={_ => dispatch(Start)} />
      <button
        className="btn fas fa-undo-alt"
        onClick={_ => dispatch(Reset)}
      />
    </div>
    <Edit
      value={state.workTime}
      onChange={e => dispatch(SetTime(Work, e))}
    />
  </div>;
};
