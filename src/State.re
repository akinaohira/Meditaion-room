// Spacify state as typeopen State;
type phase =
  | Work
  | Play;

type state = {
  seconds: int,
  isTicking: bool,
  workTime: int,
  playTime: int,
  currentPhase: phase,
};

// define action
type action =
  | Start
  | Stop
  | Reset
  | Tick
  | SetTime(phase, int);

// initialize default state
let initalState = {
  seconds: 30,
  isTicking: false,
  workTime: 5,
  playTime: 5,
  currentPhase: Work,
};

// make reducer function
let reducer = (state, action) =>
  switch (action) {
  // when action is start, state of isTicking change to true(Clock start)
  | Start => {...state, isTicking: true}
  | Stop => {...state, isTicking: false}
  | Tick =>
    state.isTicking && state.seconds > 0
      ? {...state, seconds: state.seconds - 1} : state
  | Reset =>
    switch (state.currentPhase) {
    | Work => {...state, seconds: state.workTime * 60}
    | Play => {...state, seconds: state.playTime * 60}
    }
  | SetTime(p, i) =>
    switch (p) {
    | Work => {...state, workTime: i}
    | Play => {...state, playTime: i}
    }
  };
