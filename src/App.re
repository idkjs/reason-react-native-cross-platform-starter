open BsReactNative;

module Styles = {
  let styles =
    StyleSheet.create(
      Style.{
        "container":
          style([
            flex(1.),
            justifyContent(Center),
            alignItems(Center),
            backgroundColor(String("#F5FCFF")),
          ]),
        "welcome":
          style([
            fontSize(Float(20.)),
            textAlign(Center),
            margin(Pt(10.)),
          ]),
        "instructions":
          style([
            textAlign(Center),
            color(String("#333333")),
            marginBottom(Pt(5.)),
          ]),
      },
    );
};
module LocalCounter = {
  type state = int;
  type action =
    | Incr
    | Decr;
  let component = ReasonReact.reducerComponent("LocalCounter");
  let make = _children => {
    ...component,
    initialState: () => 0,
    reducer: (action, state) =>
      switch (action) {
      | Incr => Update(state + 1)
      | Decr => Update(state - 1)
      },
    render: ({state, send}) =>
      <View>
        <Button title="+" onPress={_ => send(Incr)} />
        <Button title="-" onPress={_ => send(Decr)} />
        <Text>
          {ReasonReact.string(" counter:" ++ string_of_int(state))}
        </Text>
      </View>,
  };
};
let app = () =>
  <View style=Styles.styles##container>
    <Text
      style=Styles.styles##welcome
      value="Let's get this party started!!!"
    />
    <LocalCounter />
  </View>;
