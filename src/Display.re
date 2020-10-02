[@react.component]
let make = () => {
  let (view, setView) = React.useState(_ => false);
  view ? <App /> : <Start setView={value => setView(_ => value)} />;
};
