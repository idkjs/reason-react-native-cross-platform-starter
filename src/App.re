open ReactNative;

  let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "welcome":
        style(~fontSize=20., ~textAlign=`center, ~margin=10.->dp, ()),
      "instructions":
        style(~textAlign=`center, ~color="#333333", ~marginBottom=5.->dp, ()),
    })
  );

module LocalCounter = {
  type state = int;
  type action = Incr | Decr;
  let initialState = 0;
  let reducer = (state, action) =>
    switch (action) {
    | Incr => state + 1
    | Decr => state - 1
  };
  [@react.component]
  let make = () => {
    let (value, dispatch) = React.useReducer(reducer, initialState);
      <View>
        <Button title="+" onPress={_ => dispatch(Incr)} />
        <Button title="-" onPress={_ => dispatch(Decr)} />
        <Text>
          {ReasonReact.string(" counter:" ++ string_of_int(value))}
        </Text>
      </View>;
  };
};
[@react.component]
let app = () =>
  <View style=styles##container>
    <Text style=styles##welcome>
      "Welcome to (Reason) React Native!"->React.string
    </Text>
    <Text style=styles##instructions>
      "To get started, edit src/App.re"->React.string
    </Text>
    <Text style=styles##instructions>
      {switch (Platform.os) {
       /*
        Instructions depends on the platform this code will run on
        More at https://reasonml-community.github.io/reason-react-native/en/docs/apis/Platform/
        */
       | os when os == Platform.ios =>
         "Press Cmd+R to reload,\n" ++ "Cmd+D or shake for dev menu"
       | os when os == Platform.android =>
         "Double tap R on your keyboard to reload,\n"
         ++ "Shake or press menu button for dev menu"
       | os when os == Platform.web => "Press Cmd+R to reload."
       | _ => ""
       }}
      ->React.string
    </Text>
    <LocalCounter />
  </View>;
